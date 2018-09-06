#version 150
out vec3 vecNormal;
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
    vec4 p = position;
    p.x *=scale;
    p.y *=scale;
    p.z *=scale;
    p.w *=scale;

    mat4 mv = mat4(vec4(1., 0., 0., 0.),
                   vec4(0., 1., 0., 0.),
                   vec4(0., 0., iZoomLevel, 0.),
                   vec4(0., 0., 0., 1.)) * modelViewMatrix;

    gl_Position = projectionMatrix * mv  * p;
    //gl_Position = modelViewProjectionMatrix * p;
}





//1,       -0,        0,       -0
//-0,        1,       -0,        0
//0,       -0,        1,       -0
//-0,        0, -824.271,        1

//1,       -0,        0,       -0
//-0,        1,       -0,        0
//0,       -0,        1,       -0
//-0,        0, -278.513,        1
