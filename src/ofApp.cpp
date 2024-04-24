#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    if(ofIsGLProgrammableRenderer()){
            shader.load("shadersGL3/shader");
        }else{
            shader.load("shadersGL2/shader");
        }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < 200; i++) {
            centers[i].set(ofRandom(1.0), ofRandom(1.0)); // ランダムな座標
            radii[i] = ofRandom(0.01, 0.05);
        }
}

//--------------------------------------------------------------
void ofApp::draw(){
    shader.begin();
    shader.setUniform2fv("centers", &centers[0].x, 200);
    shader.setUniform1fv("radii", radii, 200);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mousePos[0] = ofMap(x, 0, 1024, 0, 1);
    mousePos[1] = ofMap(y, 1024, 0, 0, 1);
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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
