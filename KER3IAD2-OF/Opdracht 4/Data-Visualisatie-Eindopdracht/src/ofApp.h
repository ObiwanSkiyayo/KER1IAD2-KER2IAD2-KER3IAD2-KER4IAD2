#pragma once

#include "ofMain.h"

#define HOTSPOT_COUNT 4
#define HEADER_COUNT 3

class ofApp : public ofBaseApp {

    public:
        void setup();

        void update();

        void draw();

        void keyPressed(int key);

        void mousePressed(int x, int y, int button);

    private:
        ofImage mapImage;
		ofImage headerImage;
		ofImage cursorImage;
		ofImage popUp;

		ofImage locationMarkers;

		ofImage greenRouteImage;
		ofImage yellowRouteImage;
		ofImage redRouteImage;

		ofRectangle hotSpots[HOTSPOT_COUNT];
        ofRectangle headerButtons[HEADER_COUNT];

		bool greenRouteBool = false;
		bool yellowRouteBool = false;
		bool redRouteBool = false;

		bool resetBool = false;

		int alphaChannelGreen = 235;
		int alphaChannelYellow = 235;
		int alphaChannelRed = 235;

        bool drawHotspots;
		bool showPopUp;
};
