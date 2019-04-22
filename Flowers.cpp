#include "ofMain.h"
#include "ofApp.h"
#include "Flowers.h"

Flowers::Flowers(float _posX, float _posY, float _posZ, float _rV, float _gV, float _bV, float _lifeSpan, float _sx, float _sy, float _phase, float _countX, float _stepX, float _countY, float _twistY, float _pinchY, float _rotate, int _filled, int _type, float _Rotate){
    
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

void Flowers::setColor(int rouge, int vert, int bleu, int alpha){
    ofSetColor (rouge, vert, bleu, alpha);
}

void Flowers::setSize(float getSizeX, float getSizeY){
    size.set (getSizeX, getSizeY);
}

void Flowers::stripePattern(){
    
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

void Flowers::matrixPattern(){
    
    for (int y =- countY; y <= countY; y++){
        ofPushMatrix();
        // stores the current coordinate system by calling ofPushMatrix
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

bool Flowers::flowerBlossoms(){
    float event = ofGetFrameNum() % triggerBlossom;
    if (event == 0){
        isBlossoming = !isBlossoming;
    }
    return isBlossoming;
}

bool Flowers::flowerWaves(){
    float event = ofGetFrameNum() % triggerLeaves;
    if (event == 0){
        isWaving = !isWaving;
    }
    return isWaving;
}

bool Flowers::flowerGrows(){
    float event = ofGetFrameNum() % triggerGrowth;
    if (event == 0){
        isGrowing = !isGrowing;
    }
    return isGrowing;
}

void Flowers::setBlossom (){
    
    //Timer
    float timer = ofGetElapsedTimef() * phaseFlower;
    float value = sin (timer);
    
    twistX = -5; ofMap (ofNoise (timer), 0, 1, -10, 0);
    stepY = 5; // ofMap (ofNoise (timer), 0, 1, 0, 10);
    shiftY = -850; ofMap (ofNoise (timer), 0, 1, -850, -800);
    pinchY = 0.5; // ofMap (ofNoise (timer), 0, 1, 0, 1);
    
    //Color and lifeSpan
    float color1 = 100; // gets the contructor red value
    float color2 = 50;
    float color3 = ofMap (value, -1, 1, bV + 100, bV); // gets the contructor blue value

    life = ofMap (value, -1, 1, lifeSpan, 150);
    ofSetColor(color1, color2, color3, life);
    
}



void Flowers::drawFlower(){
    
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

float Flowers::getPosX(){
    return posX;
}

float Flowers::getPosY(){
    return posY;
}

float Flowers::getLife(){
    return life;
}

float Flowers::getShiftY(){
    return shiftY;
}

float Flowers::getTwistX(){
    return twistX;
}

float Flowers::getStepY(){
    return stepY;
}








