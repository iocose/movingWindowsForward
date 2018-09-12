#version 150
out vec3 vecNormal;
out vec4 vecPos;

uniform vec2 iResolution;
uniform float iGlobalTime;
uniform float iZoomLevel;

in vec4 position;
in vec4 color;
in vec4 normal;

// these are passed in from OF programmable renderer
uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 textureMatrix;
uniform mat4 normalMatrix;

void main(){
    float scale = 88.0;
    vecNormal = normal.xyz;
    vecPos = position;

    mat4 mv = mat4(vec4(1., 0., 0., 0.),
                   vec4(0., 1., 0., 0.),
                   vec4(0., 0., iZoomLevel, 0.),
                   vec4(0., 0., 0., 1.)) * modelViewMatrix;


    vec4 projPos = projectionMatrix * mv * position;
    float displacementHeight = 100.0;
    float displacementY = sin(iGlobalTime + (position.x / 100.0)) * displacementHeight;
    //projPos.y += displacementY;

    // - sined pos
    //projPos += sin(projPos * (iGlobalTime*0.01)) * 0.2;

    //- fract pos
    //projPos.y += (fract(projPos.y) * 20.9);

    gl_Position = projPos;
}
