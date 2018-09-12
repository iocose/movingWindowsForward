#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxAutoReloadedShader.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void evt(ofKeyEventArgs & args);

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    ofTexture getTexture() const;

    ofEasyCam camera;
    ofLight light;
    ofxAssimpModelLoader model;

    ofxAutoReloadedShader shader;
    of3dPrimitive primitive;

    float zoomLevel = 0.1;
    bool rotate = false;
    ofFbo fbo;
    ofTexture prev;
    ofImage bgImg;
};
