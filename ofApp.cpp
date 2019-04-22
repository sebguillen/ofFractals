#include "ofApp.h"

//--------------------------------------------------------------
// Fractal sketch
// Using fractal implementation techniques to create trees
// Code inspired from the chapter 1 and 2 of the book
// 'Mastering openframeworks, creative coding demystified'


void ofApp::setup(){
        
    ofSetWindowTitle ("Forest");
    ofSetFrameRate (60);
    
// Generate a plant with random parameters
    trees.push_back (new Spirals (ofGetWidth()/2, ofGetHeight()/2, ofRandom (-1000, -900), ofRandom (100, 200), 0, ofRandom (100, 200), 0, ofRandom (0, 4), ofRandom (0, 3), ofRandom (1, 1.75), 142, 66, 28, -30, 0.63, -180, 0, 0, -180));

    }


//--------------------------------------------------------------
void ofApp::update(){
// The animation occurs in the function of the classes
}


//--------------------------------------------------------------


void ofApp::draw(){
    
    // Draw
    ofBackground (0);
    trees[0]->drawTree();
    
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


