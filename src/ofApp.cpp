#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    light.setup();
    light.setAmbientColor(ofFloatColor::white);
    light.setPointLight();
    light.setPosition(600, 600, 600);

    model.loadModel("finger.obj");
    bgImg.load("sol.JPG");

    //ofMesh mesh = model.getMesh(0);
    // scale
    primitive.getMesh().append(model.getMesh(0));
    primitive.getMesh().enableNormals();
    float size = 160;
    primitive.setScale(glm::vec3(size, size, size));
    primitive.rotateDeg(-90, glm::vec3(0,1,0));
    primitive.setPosition(130, 40, 0);


    //ofEnableDepthTest();
    fbo.allocate(ofGetScreenWidth(), ofGetScreenHeight(), GL_RGBA, ofFbo::maxSamples());

    shader.load("shaders/vert.glsl", "shaders/rgb-waves-frag.glsl", "");
    light.enable();
}

//--------------------------------------------------------------
void ofApp::update(){

}

ofTexture ofApp::getTexture() const {
    return fbo.getTexture();
}

void ofApp::zoom(ofKeyEventArgs & args){
    if(args.key == 'z'){
        zoomLevel += 0.01;
    }
    if(args.key == 'x'){
        zoomLevel -= 0.01;
    }

};

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString("Main Window", 20, 20);


    fbo.begin();
    ofClear(0,0,0,0);
    bgImg.draw(0,0);
    ofEnableDepthTest();

    camera.begin();
        //ofLog() << camera.getModelViewMatrix();
    shader.begin();
    shader.setUniform1f("iGlobalTime", ofGetElapsedTimef());
    shader.setUniform1f("iZoomLevel", zoomLevel);
    shader.setUniform2f("iResolution", ofGetWidth(), ofGetHeight());
    light.draw();

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
