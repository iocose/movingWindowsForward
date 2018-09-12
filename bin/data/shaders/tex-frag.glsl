#version 150
in vec3 vecNormal;
in vec4 vecPos;

out vec4 fragColor;
uniform float iGlobalTime;
uniform vec2 iResolution;
uniform sampler2D tex0;

void main(){
    vec3 lightPos = vec3(0.0, 1.0, 0.1);
    vec2 st = gl_FragCoord.xy / iResolution.xy;
    st.y *= iResolution.y/iResolution.x;
    // - texel
    vec4 texel = texture(tex0, st);

    // col
    vec4 col = mix(texel, vec4(vec3(vecPos), 1.0),0.5);
    //col += vec4(fract(vecPos.yxz * 32.5), 1.0);

    // - mixed tex
    vec4 texel2 = texture(tex0, st+vec2(sin(iGlobalTime), cos(iGlobalTime))*0.01);
    vec4 col2 = mix(texel, vec4(vec3(vecPos), 1.0),0.5);
    vec4 mixedTex = mix(col2, texel2, 0.5);

    float light = max(dot(lightPos, vecNormal), 0.0);

    // - distance from point in movement
    float dfromCenter =
        distance(vecPos.xyz,vec3(sin(iGlobalTime)*2.)
                 );
    vec3 col3 = vec3(
                     sin(dfromCenter),
                     min(dfromCenter, 1.0),
                     cos(dfromCenter)
                     );

    fragColor = vec4(col3.rgb * light, 1.0);
}
