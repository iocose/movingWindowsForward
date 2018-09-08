#version 150
in vec3 vecNormal;

out vec4 fragColor;
uniform float iGlobalTime;

void main(){
    vec4 materialColor = vec4(1.0,0.,0.,1.0);
    vec3 light = vec3(0.9, sin(iGlobalTime) * 0.6, 1.0);
    light = normalize(light);

    // dot product
    float dProd = max(0.0, dot(vecNormal, light));

    //color
    vec4 color = materialColor;
    vec4 col = vec4( vec3( dProd ) * vec3( color ), 1.0 );
    fragColor = vec4(vecNormal, 1.0);
}
