#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "ofxCenteredTrueTypeFont.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);


        void getData();

		int elementCount;

		int temp;
		int windRichting;
		int windSnelheid;

		//Int for color change
		int kleurR;
		int kleurG;
		int kleurB;

		ofImage sun;
		ofImage wind;
		ofImage richting;

        ofxJSONElement json;

		ofxCenteredTrueTypeFont kopTekst;
		ofxCenteredTrueTypeFont subTekst;
};
