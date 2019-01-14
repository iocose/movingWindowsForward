#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxAutoReloadedShader.h"

/*
 
 Setup:
 Assicurarsi che le dimensioni delle finestre si adattino bene alla
 superficie di proiezione. Modificare la dimensione delle finestre e della
 main window in main.cpp. C'e' il rischio che la forma del dito sia poco
 riconoscibile se questi parametri sono sbagliati.
 Mettere come sfondo del desktop l'immagine sol3.jpg. E' in bin/data
 Preparare Terminal con uno sfondo trasparente. Preferences -> Profile -> Window -> Transparency. Il terminal occupa poco meno della meta' della parte sx del monitor.
 
 Svolgimento:
 - Lanciare la app e poi minimizzare xcode. Tutte le modifiche vengono fatte live modificando con vim gli shaders roma.glsl e roma-vert.glsl
 - All'inizio si lasciano andare per 10 secondi le finestre che scorrono, poi si preme z e lo schermo diventa nero. (z e x muovono rispettivamente il dito avanti e indietro. E' importante selezionare una delle finestre prima di premere z o x)
 - Ora, con le finestre completamente nere si comincia a seguire i commenti su roma.glsl
 - Finito li, si passa a roma-vert.glsl
 
 - si chiude col perlin noise in vertex shader e la forma del dito irriconoscibile, si cominciano a chiudere le finestre una ad una.

 */

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

    float zoomLevel = 0.00;
    bool rotate = false;
    ofFbo fbo;
    ofTexture prev;
    ofImage bgImg;
};
