#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();


		

		void keyPressed(int key);

	private:
		float x;
		float y;

		float xI;
		float yI;

		float xII;
		float yII;

		float speedX;
		float speedY;

		float speedXI;
		float speedYI;

		float speedXII;
		float speedYII;

		int radius;
		int radiusI;
		int radiusII;

		ofColor color;

		bool drawAnother;
		bool nextOne;
		bool one = true;
		
};
