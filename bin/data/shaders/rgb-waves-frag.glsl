#version 150
in vec3 vecNormal;
in vec4 vecPos;

out vec4 fragColor;
uniform float iGlobalTime;

float smootha(float p1, float p2, float c){
  return smoothstep(p1, p2, c) - smoothstep(p2, 1.0, c);
}

void main(){
    vec3 vPos = vecPos.xyz;
    float r, g, b;
    vec3 lightPos = vec3(0.0, 1.0, 0.1);
    float offset = 0.4;
    float t = iGlobalTime * 0.5; // 4.
    float width = 118.6;
    float s1 = 0.8;
    float s2 = 0.9;

    // zoom palmo
    // s1 = 0.3;
    // s2 = 0.6;
    // width = 3.;
    // t = iGlobalTime * 0.3;
    // offset = 0.2 + 0.7 * sin(iGlobalTime);
    // width = 118.;
    // zoom out

    r = mod(vPos.z * width + t, 1.0);
    r = smootha(s1,s2,r);

    g = mod(vPos.z * width + t + offset, 1.0);
    g = smootha(s1,s2,g);

    b = mod(vPos.z * width + t - offset, 1.0);
    b = smootha(s1,s2,b);

    //lightPos = vec3(0.0, 1.0, 9.1);
    //lightPos = vec3(0.0, 1.0, sin(iGlobalTime)* 9.1);

    float light = max(dot(lightPos, vecNormal), 0.0);

    vec3 col = vec3(r, g, b);
    //col = vec3(r, g, b) * light;
    fragColor = vec4(col, 1.0);
}
