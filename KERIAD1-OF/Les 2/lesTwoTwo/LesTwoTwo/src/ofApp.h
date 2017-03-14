#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		float speedXStored;

		ofxPanel gui;
		ofParameter<int> count;
		ofParameter<float> speedX;
		ofParameter<float> speedY;

		ofParameter<float> width;
		ofParameter<float> heigth;

		ofParameter<int> radius;

		ofParameter<ofColor> color;

		
};
