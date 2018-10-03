#version 150

#define SET 1
in vec3 vecNormal;
in vec4 vecPos;

out vec4 fragColor;
uniform float iGlobalTime;
uniform vec2 iResolution;

float smootha(float p1, float p2, float c){
    return smoothstep(p1, p2, c) - smoothstep(p2, 1.0, c);
}

float random (in vec2 st) {
    return fract(sin(dot(st.xy,
                         vec2(12.9898,78.233)))
                 * 43758.5453123);
}

float noise (in vec2 st) {
    vec2 i = floor(st);
    vec2 f = fract(st);
    float a = random(i);
    float b = random(i + vec2(1.0, 0.0));
    float c = random(i + vec2(0.0, 1.0));
    float d = random(i + vec2(1.0, 1.0));
    vec2 u = f*f*(3.0-2.0*f);
    return mix(a, b, u.x) +
    (c - a)* u.y * (1.0 - u.x) +
    (d - b) * u.x * u.y;
}

vec2 vectorField(vec2 uv){
    vec2 res = uv;
    float n = noise(res*vec2(3.0));
    //res.y -= iGlobalTime*0.1;
    res.x -= iGlobalTime*0.1;
    res += sin(res.yx*40.5) * 0.02;
    res += vec2(n);
    return res;
}

float plot(float val, float c, float t){
    float l = smoothstep(c,c-t,val);
    float r = smoothstep(c,c-t/5.,val);
    return r-l;
}

vec3 addLight(vec3 pos, vec3 dir, vec3 nor, vec3 col, vec3 lig){
    float NL = max(dot(nor, lig),0.);
    float NV = max(dot(nor, -dir),0.);
    NV =  pow(1.-NV, 2.);

    float bli =  max(dot(normalize(lig+-dir), nor), 0.);
    bli = pow(bli, 80.);

    float c = NL + NV * 0.5 + bli;
    return vec3(c) * col;
}


void main(){
    //general variables
    vec3 vPos = vecPos.xyz;
    float r, g, b;
    vec3 lightPos = vec3(0.0, 1.0, 5.1);
    float offset = 0.4;
    float t = iGlobalTime * 0.1; // 4. set 1
    vec3 col = vec3(0);
    vPos = vecPos.xyz;
    vec2 st = gl_FragCoord.xy / iResolution.xy;
    st.y *= iResolution.y/iResolution.x;

// rgb waves
#if SET==1
    float width = 3.6;
    float s1 = 0.8;
    float s2 = 0.9;

    // zoom, press z once
    // increase red
    // add g and b channel
    // s1 = 0.3;
    // s2 = 0.6;
    // t = iGlobalTime * 0.3;
    // offset = 0.1 + 0.05 * sin(iGlobalTime);
    // offset = 0.2 + 0.7 * sin(iGlobalTime);
    // width = 118.;
    // zoom out, x

    // width = 0.1; junction to set 2

    r = mod(vPos.z * width + t, 1.0);
    r = smootha(s1,s2,r);

    g = mod(vPos.z * width + t + offset, 1.0);
    g = smootha(s1,s2,g);

    b = mod(vPos.z * width + t - offset, 1.0);
    b = smootha(s1,s2,b);

    //col = vec3(r*0.1, 0., 0.);
    //col = vec3(r*0.9, 0., 0.);
    //col = vec3(r, 0., 0.);
    //col = vec3(r, g, 0.);
    //col = vec3(r, g, b);
#endif

// vector field
#if SET==2
    // decrease cell
    // decrease plot
    // add vector field on position
    // add lights
    // mix bn

    st = vectorField(st);
    // 3
    // st = vectorField(vPos.xy);

    float cell = 0.93;
    // 1
    // cell = 0.48;
    vec2 modSt = mod(st, vec2(cell));

    float x = plot(modSt.x, cell, 0.6);
    float y = plot(modSt.y, cell, 0.5);
    // 2
    //x = plot(modSt.x, cell, 0.4);
    //y = plot(modSt.y, cell, 0.3);

    col = vec3(0.9,0.0,0.0) * x;
    col += vec3(0.,9.,.0) * y;
    vec3 bgCol = vec3(0.,0.,.9);

    col+= bgCol*vec3(smoothstep(0.01, .001,x+y));

    // Add lights
    lightPos = vec3(0.0, 1.0, sin(iGlobalTime)* 2.1);
    // 4
    //lightPos = vec3(sin(iGlobalTime), 1.0, cos(iGlobalTime));

    // 5
    vec3 gray = vec3(0.2);
    gray = vec3(0.9);
    vec3 grayScale = addLight(vPos, vec3(0.0,0.,-1.), vecNormal, gray, lightPos);

    // 6
    //col = mix(grayScale,col, 0.9);
    // 7
    //col = mix(grayScale,col, 0.01);
    //col = mix(grayScale,col, 0.1);

    // after vertex displacement
    //col = grayScale;
    //col = mix(grayScale, vec3(1.0), 0.1);
    //col = mix(grayScale, vec3(1.0), 1.);
    // zoom close

#endif

    fragColor = vec4(col, 1.0);
}
