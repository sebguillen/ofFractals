#include "ofApp.h"

//--------------------------------------------------------------
// Fractal sketch
// Using fractal implementation techniques to create trees and flowers
// 3 classes : Spirals, Bush and Flowers
// To imitate three different patterns found in nature
// Code inspired from the chapter 1 and 2 of the book
// 'Mastering openframeworks, creative coding demystified'


void ofApp::setup(){
        
    ofSetWindowTitle ("Forest");
    ofSetFrameRate (60);
    
// Generate a plant with random parameters
    trees.push_back (new Spirals (100, ofGetHeight()/2, ofRandom (-1000, -900), ofRandom (100, 200), 0, ofRandom (100, 200), 0, ofRandom (0, 4), ofRandom (0, 3), ofRandom (1, 1.75), 142, 66, 28, -30, 0.63, -180, 0, 0, -180));
    
    bushes.push_back (new Bushes (ofGetWidth() * 3/5, ofGetHeight()/2, ofRandom (-400, -200), ofRandom (100, 200), ofRandom (100, 200), ofRandom (100, 200), 0, 2.61, 0.94, ofRandom (0.5, 1), 67, 100, 50, -25.8, 0.85, -180, 1, 0, 180));
    
    flowers.push_back (new Flowers (ofGetWidth() * 3/4, ofGetHeight()/2, 100, ofRandom (100, 200), ofRandom (100, 200), ofRandom (100, 200), 0, 3, 1, ofRandom (2,3), 39, 67, 11, -30, 0.265, -180, 0, 0, -180));
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
        bushes[0]->drawBush();
        flowers[0]->drawFlower();
    
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


