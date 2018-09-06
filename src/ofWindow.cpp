#include "ofWindow.h"
ofWindow::ofWindow(int _startX, int _startY, ofTexture tex, float _vel){
    posx = _startX;
    posy = _startY;
    vel = _vel;
    texture = tex;
}

//--------------------------------------------------------------
void ofWindow::setup(){
}

//--------------------------------------------------------------
void ofWindow::update(){
    posx += vel;
}

//--------------------------------------------------------------
void ofWindow::draw(){
    ofSetWindowPosition(posx, posy);
//    auto a = ofGetWindowPositionX();
    auto c = ofGetScreenWidth();
    texture.draw(-posx,-posy);
    if(posx >= c-40){
        posx = 10 - ofGetWidth();
        ofSetWindowPosition(posx, posy);
    }
}

//--------------------------------------------------------------
void ofWindow::keyPressed(int key){
    if(key=='f'){
        drawFinger = !drawFinger;
    }
}

//--------------------------------------------------------------
void ofWindow::keyReleased(int key){

}

//--------------------------------------------------------------
void ofWindow::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofWindow::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofWindow::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofWindow::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofWindow::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofWindow::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofWindow::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofWindow::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofWindow::dragEvent(ofDragInfo dragInfo){
    
}
