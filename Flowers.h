#ifndef Flowers_h
#define Flowers_h

#include <stdio.h>
#include <ofApp.h>

class Flowers {
    
public:
    
    // Constructor
    Flowers (float _posX, float _posY, float _posZ, float _rV, float _gV, float _bV, float _lifeSpan, float _sx, float _sy, float _phase, float _countX, float _stepX, float _countY, float _twistY, float _pinchY, float _rotate, int _filled, int _type, float _Rotate);
    
    void setup();
    void update();
    void drawFlower();
    void stripePattern();
    void matrixPattern();
    
    void setColor(int rouge, int vert, int bleu, int alpha);
    void setSize(float getSizeX, float getSizeY);
    
    void setBlossom ();
    bool thumbP();
    
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
    float life;
    
    float rV, gV, bV, lifeSpan, phaseFlower;
    
    int triggerBlossom, triggerLeaves, triggerGrowth;
    bool isBlossoming, isWaving, isGrowing, isSinging;
    
    
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
    
    ofxOscReceiver thumbPiano;

    
    
};

#endif /* Spirals_hpp */

