#pragma once

#include "ofMain.h"
#include "Spirals.h"
#include "ofxOsc.h"
#include <vector>


class ofApp : public ofBaseApp{
    

	public:
    
		void setup();
		void update();
		void draw();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    private :

// Variables
    float phaseF;
    float valueF;
    float k1, k2, k3, k4, k5;
    int nFlo, nFr0, nFr1, nFr2;
    bool drawTree;

// Vectors
    std::vector <Spirals*> trees;

};
