#include "ofMain.h"
#include "ofApp.h"
#include "Bush.h"

Bushes::Bushes(float _posX, float _posY, float _posZ, float _rV, float _gV, float _bV, float _lifeSpan, float _sx, float _sy, float _phase, float _countX, float _stepX, float _countY, float _twistY, float _pinchY, float _rotate, int _filled, int _type, float _Rotate){
    
    //Positions
    posX = _posX;
    posY = _posY;
    posZ = _posZ;
    //Colors
    rV = _rV;
    gV = _gV;
    bV = _bV;
    lifeSpan = _lifeSpan;
    phaseFlower = _phase;
    // Size
    sx = _sx;
    sy = _sy;
    
    //Stripes
    countX = _countX; // 0,200
    stepX = _stepX; // 0,200
    
    // Matrix
    countY = _countY; // 0,50
    twistY = _twistY; // -30,30
    pinchY = _pinchY; // 0,1
    rotate = _rotate; // -180, 180
    
    //Parameters
    filled = _filled;
    type = _type;
    
    //Rotation
    Rotate = _Rotate; // -180, 180
    
};

void Bushes::setColor(int rouge, int vert, int bleu, int alpha){
    ofSetColor (rouge, vert, bleu, alpha);
}

void Bushes::setSize(float getSizeX, float getSizeY){
    size.set (getSizeX, getSizeY);
}

void Bushes::stripePattern(){
    
    ofSetLineWidth (1);
    if (filled) ofFill(); else ofNoFill();
    // filling mode depending on the fill value
    
    for (int i=-countX; i<countX; i++){
// Iteration: countX controls the number of drawn primitives
        ofPushMatrix();
        ofTranslate (i*stepX, 0);
        // stepX controls the distance between primitives along the X axis
        ofRotate (i * twistX);
        // twistX controls the roation of the primitives depending on its index2
        
        ofTranslate (0, shiftY);
        ofRotate (rotate);
        ofScale (size.x, size.y);
        // scales the local coordinate system by the x and y components of the group of slider's size
        // it changes the width and height of the drawn primitive
        if (type) ofDrawRectangle (-50, -50, 100, 100);
        // square or triangle depending on the type value
        else ofDrawTriangle(0, 0, -50, 100, 50, 100);
        ofPopMatrix();
        // restore the coordinate system back to the original state
    }
}

void Bushes::matrixPattern(){
    
    for (int y =- countY; y <= countY; y++){
// Stores the current coordinate system by calling ofPushMatrixofPushMatrix();
        if (countY > 0){
            float scl = ofMap (y, -countY, countY, 1-pinchY, 1);
            ofScale (scl, scl);
        }
        ofTranslate (0, y * stepY);
        ofRotate (y * twistY);
        stripePattern();
        ofPopMatrix();
    }
}

// Events
// Boolean functions to trigger events

bool Bushes::flowerBlossoms(){
    float event = ofGetFrameNum() % triggerBlossom;
    if (event == 0){
        isBlossoming = !isBlossoming;
    }
    return isBlossoming;
}

bool Bushes::flowerWaves(){
    float event = ofGetFrameNum() % triggerLeaves;
    if (event == 0){
        isWaving = !isWaving;
    }
    return isWaving;
}

bool Bushes::flowerGrows(){
    float event = ofGetFrameNum() % triggerGrowth;
    if (event == 0){
        isGrowing = !isGrowing;
    }
    return isGrowing;
}

void Bushes::setBlossom (){
    
//Timer
    float timer = ofGetElapsedTimef() * phaseFlower;
    float value = sin (timer);
    
    twistX = ofMap (ofNoise (timer), 0, 1, -45, -35);
    stepY = 0;
    shiftY = -1000;
    pinchY = 0.65;

//Color and lifeSpan
    float color1 = ofMap (value, -1, 1, rV + 20, rV - 20);
    // gets the contructor red value
    float color2 = 0;
    float color3 = ofMap (value, -1, 1, bV + 100, bV - 50);
    // gets the contructor blue value
    life = ofMap (value, -1, 1, lifeSpan, 250);
    ofSetColor(color1, color2, color3, life);
    
}



void Bushes::drawBush(){
    
    ofPushMatrix();
    
//Positions
    ofTranslate (posX, posY, posZ);
    
//Timer
    float timer = ofGetElapsedTimef() * phaseFlower;
    float value = sin (timer);
    
// Scale and Rotate
    float Scale = ofMap (ofNoise (timer), 0, 1, 0.35, 0.45);
    float Scl = pow (Scale, 4.0f);
    // raises to the 4th power the scale slider value > control small values of the Scl scale more precisely
    ofScale (Scl, Scl); // scale of the coordinate system
    ofRotate (Rotate); // rotation of the coordinate system
    
// Size
    setSize(sx, sy);
    
// Move
    setBlossom();
    
// Main function
    matrixPattern();
    
    ofPopMatrix();
}

// Values to return

float Bushes::getPosX(){
    return posX;
}

float Bushes::getPosY(){
    return posY;
}

float Bushes::getLife(){
    return life;
}

float Bushes::getShiftY(){
    return shiftY;
}

float Bushes::getTwistX(){
    return twistX;
}

float Bushes::getStepY(){
    return stepY;
}









