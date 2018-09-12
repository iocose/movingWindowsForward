#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();

    model.loadModel("finger.obj");
    bgImg.load("sol3.JPG");

    primitive.getMesh().append(model.getMesh(0));
    primitive.getMesh().enableNormals();
    float size = 160;
    primitive.setScale(glm::vec3(size, size, size));
    primitive.rotateDeg(-90, glm::vec3(0,1,0));
    primitive.setPosition(130, 40, 0);


    fbo.allocate(ofGetScreenWidth(), ofGetScreenHeight(), GL_RGBA, ofFbo::maxSamples());
    prev.allocate(ofGetScreenWidth(), ofGetScreenHeight(), GL_RGBA);

    shader.load("shaders/vert.glsl", "shaders/roma.glsl", "");
    light.enable();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(rotate){
        primitive.rotateRad(0.005, glm::vec3(1.0,0.0,0.0));
    }

}

ofTexture ofApp::getTexture() const {
    return fbo.getTexture();
}

void ofApp::evt(ofKeyEventArgs & args){
    if(args.key == 'z'){
        zoomLevel += 0.01;
    }
    if(args.key == 'x'){
        zoomLevel -= 0.01;
    }
    if(args.key == 'r'){
        rotate = !rotate;
    }

};

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString("Main Window", 20, 20);

    prev = fbo.getTexture();
    fbo.begin();
    ofClear(0,0,0,0);
    bgImg.draw(0,0);
    ofEnableDepthTest();

    camera.begin();
    shader.begin();
    shader.setUniform1f("iGlobalTime", ofGetElapsedTimef());
    shader.setUniform1f("iZoomLevel", zoomLevel);
    shader.setUniform2f("iResolution", ofGetWidth(), ofGetHeight());
    shader.setUniformTexture("tex0", prev, 0);
    primitive.draw();
    shader.end();
    camera.end();

    ofDisableDepthTest();
    fbo.end();

    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
