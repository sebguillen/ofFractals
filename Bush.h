#ifndef Bush_h
#define Bush_h

#include <stdio.h>
#include <ofApp.h>

class Bushes {
    
public:
    
    // Constructor
    Bushes (float _posX, float _posY, float _posZ, float _rV, float _gV, float _bV, float _lifeSpan, float _sx, float _sy, float _phase, float _countX, float _stepX, float _countY, float _twistY, float _pinchY, float _rotate, int _filled, int _type, float _Rotate);
    
    void setup();
    void update();
    void drawBush();
    void stripePattern();
    void matrixPattern();
    
    void setColor(int rouge, int vert, int bleu, int alpha);
    void setSize(float getSizeX, float getSizeY);
    
    void setBlossom ();
    
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
    bool isBlossoming, isWaving, isGrowing;
    
    
    int countX;
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
    int countY;
    float stepY, twistY, pinchY;
    
    // Animation
    float phase;
    float value;
    
    
};

#endif /* Spirals_hpp */

