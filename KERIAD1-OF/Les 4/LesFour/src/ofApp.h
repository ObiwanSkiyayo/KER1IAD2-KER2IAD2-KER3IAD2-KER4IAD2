#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);

		ofArduino arduino;

		void setupArduino(const int& version);
		void digitalPinChange(const int& pinNum);
		void analogPinChanged(const int& pinNum);
		
};
