/*
 This project was created by Leo Dastur (@theinnerparty) and Samir Ghosh (@samirgauche).
 */



#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Grid.hpp"

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
	
	void drawBox(int x, int y, bool colored);
    void drawAnt(std::tuple<int,int> loc);
	void toggleContDraw(bool& quickDraw);
	void reInitGrid();
	void drawStatic(int& quickSteps);
	
	void stackTrace();
	
	
	Grid * grid;
	int stepCounter;
	int boxRadius;
	ofParameter<int> quickSteps;
	ofParameter<bool> quickDraw;
	ofParameter<ofColor> drawColor;
	ofParameter<ofColor> backgroundColor;
    ofColor antColor = ofColor::black;
    ofColor tileColor = ofColor::white;
	ofxPanel gui;
};
