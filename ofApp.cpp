#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    glEnable(GL_DEPTH);
    tunnel.setup(ofGetWidth(), ofGetHeight(), 100);
    ofSetBackgroundColor(255);
    cam.setFarClip(ofGetWidth() * 50);
}

//--------------------------------------------------------------
void ofApp::update(){
    tunnel.update();
    cam.setTarget(tunnel.getViewAim());      ///TOFIX!!!!
    cam.setPosition(tunnel.getViewPos());
    tart.setPosition(tunnel.getcarPos());
}

//--------------------------------------------------------------
void ofApp::draw(){

    cam.begin();
    tunnel.draw(nShow);
    tart.draw();
    cam.end();
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 30);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_UP){
        nShow ++;

    }
    if(key == OF_KEY_DOWN){
        nShow --;
    }
    if(key == OF_KEY_LEFT){
        tart.drive("left");
    }
    if(key == OF_KEY_RIGHT){
        tart.drive("right");
    }
    if(key == 'n'){
        tunnel.addNoise = !tunnel.addNoise;
    }
    if(key == 'r'){
        tunnel.addRide = !tunnel.addRide;
    }

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
