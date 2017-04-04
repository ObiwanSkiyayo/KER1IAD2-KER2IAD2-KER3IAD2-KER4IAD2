#pragma once

#include "ofMain.h"
#include "SQLiteCpp.h"
#include "ofxCenteredTrueTypeFont.h"

class ofApp : public ofBaseApp {

    public:
        void setup();

        void update();

        void draw();

        void keyPressed(int key);

        void keyReleased(int key);

        void mouseMoved(int x, int y);



    private:
        SQLite::Database* db;
        int selectedYear = 1900;

        int total;
        int north;
        int east;
        int south;
        int west;

		ofxCenteredTrueTypeFont myFont;
		ofxCenteredTrueTypeFont kopTekst;
		ofxCenteredTrueTypeFont subFont;
		ofxCenteredTrueTypeFont subFontTwee;
};
