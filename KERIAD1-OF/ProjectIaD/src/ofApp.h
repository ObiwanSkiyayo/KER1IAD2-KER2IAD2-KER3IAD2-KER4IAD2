#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		
		ofArduino arduino;

		void setupArduino(const int& version);

		void digitalPinChanged(const int& pin);
		void analogPinChanged(const int& pin);

private:

	int brightness;
	int fadeAmount = 1;
	int radiusSize;
	int startCycle;

	float width;
	float height;

	int data;
 
	const int upperThreshold = 70;
	const int lowerThreshold = 50;


	bool breathOut;

	int circleRadius;


};
