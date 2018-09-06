#pragma once

#include "ofMain.h"

class ofWindow : public ofBaseApp{

public:
    ofWindow(int startX, int startY, ofTexture tex, float vel = 0.2);
    void setup();
    void update();
    void draw();

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

    float posx;
    float posy;
    float vel;

    ofTexture texture;
    bool drawFinger;
    
};
