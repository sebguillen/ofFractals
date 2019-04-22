#ifndef Spirals_hpp
#define Spirals_hpp

#include <stdio.h>
#include <ofApp.h>
#include "ofxOsc.h"


class Spirals {
    
public:
    
    // Constructor
    Spirals (float _posX, float _posY, float _posZ, float _rV, float _gV, float _bV, float _lifeSpan, float _sx, float _sy, float _phase, float _countX, float _stepX, float _countY, float _twistY, float _pinchY, float _rotate, int _filled, int _type, float _Rotate);
    
    void setup();
    void update();
    void drawTree();
    void stripePattern();
    void matrixPattern();
    
    void setColor(int rouge, int vert, int bleu, int alpha);
    void setSize(float getSizeX, float getSizeY);

    void setBlossom ();
    void thumbP();
    
    bool flowerBlossoms();
    bool flowerWaves();
    bool flowerGrows();

    
    //Debug
    float getPosX ();
    float getPosY ();
    float getPosZ ();
    float getLife();
    float getShiftY();
    float getTwistX();
    float getStepY();


    
private:
    
    float posX, posY, posZ;
    
    float rV, gV, bV, lifeSpan, phaseFlower;
    float life;
    
    int triggerBlossom, triggerLeaves, triggerGrowth;
    bool isBlossoming, isWaving, isGrowing, isSinging;


    float countX;
    float stepX, twistX;
    
    float Scale, sx, sy;

    float Rotate;
    float Background;
    
    
    //Ajust the geometric primitive's drawing parameters
    float shiftY, rotate; // two float sliders
    ofVec2f size; // ofxVec2Slider size; // 2D slider's size parameter
    ofColor color;
    bool filled, type;
    
    // Matrix pattern
    float countY;
    float stepY, twistY, pinchY;
    
    // Animation
    float phase;
    float value;
    
    bool Singing;



    
};

#endif /* Spirals_hpp */
