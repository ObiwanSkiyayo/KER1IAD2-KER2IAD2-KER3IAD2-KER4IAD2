#include "ofApp.h"

void ofApp::setup() {
    //Static map generated on http://staticmapmaker.com/google/
    mapImage.load("staticmap.png");
	headerImage.load("header.png");
	cursorImage.load("cursor.png");
	popUp.load("Popup.png");

	//Loading the images for the routes
	greenRouteImage.load("green.png");
	yellowRouteImage.load("yellowFull.png");
	redRouteImage.load("red.png");
	locationMarkers.load("location.png");

	//Headerbuttons
	headerButtons[0] = ofRectangle(0, 20, 155, 200);
	headerButtons[1] = ofRectangle(155, 20, 185, 200);
	headerButtons[2] = ofRectangle(340, 20, 155, 200);

	//Setup things
	ofHideCursor();
    
	//hotSpots[3] = ofRectangle(330, 0, 50, 150);
}

void ofApp::update() {

	// Green route bool, this highlites the green route, and "removes" the other ones.
	if (greenRouteBool) {
		alphaChannelGreen = 255;
		alphaChannelYellow = 0;
		alphaChannelRed = 0;
	}

	// Green route bool, this highlites the green route, and "removes" the other ones.
	if (yellowRouteBool) {
		alphaChannelGreen = 0;
		alphaChannelYellow = 255;
		alphaChannelRed = 0;
	}


	// Green route bool, this highlites the green route, and "removes" the other ones.
	if (redRouteBool) {
		alphaChannelGreen = 0;
		alphaChannelYellow = 0;
		alphaChannelRed = 255;
	}

	if (resetBool) {
		// Turn back the alpha channels
		alphaChannelGreen = 235;
		alphaChannelYellow = 235;
		alphaChannelRed = 235;

		// Hard reset all the bools
		greenRouteBool = false;
		yellowRouteBool = false;
		redRouteBool = false;
		resetBool = false;
	}

}

void ofApp::draw() {
    ofSetColor(ofColor::white);
	mapImage.draw(0, 0);
    headerImage.draw(0, 0);

	// Draw the routes with opactity, we first draw the yellow route because we want the green and red route above it, for a better blend.
	ofSetColor(255, 255, 255, alphaChannelYellow);
	yellowRouteImage.draw(0, 0);

	ofSetColor(255, 255, 255, alphaChannelGreen);
	greenRouteImage.draw(0, 0);

	ofSetColor(255, 255, 255, alphaChannelRed);
	redRouteImage.draw(0, 0);
	// END

	ofSetColor(255, 255, 255, 255);
	cursorImage.draw(ofGetMouseX() - cursorImage.getWidth() / 2, ofGetMouseY() + cursorImage.getWidth() /2);

    ofSetColor(ofColor::white);
    ofDrawBitmapString("MouseX:" + ofToString(mouseX), 900, 20);
    ofDrawBitmapString("MouseY:" + ofToString(mouseY), 900, 40);

    if (drawHotspots) {
        ofNoFill();

		// Hotspot buttons. 
        for (int i = 0; i < HOTSPOT_COUNT; i++) {
			ofSetColor(ofColor::red);
            ofDrawRectangle(hotSpots[i]);
        }
		// Header buttons. 
		for (int i = 0; i < HEADER_COUNT; i++) {
			ofSetColor(ofColor::blue);
			ofDrawRectangle(headerButtons[i]);
		}
    }

	if (showPopUp) {
		ofSetColor(255, 255, 255, 255);
		popUp.draw(0, 0);
	}

	// Route Hotspot count.
    ofSetColor(ofColor::white);
    for (int i = 0; i < HOTSPOT_COUNT; i++) {
        if (hotSpots[i].inside(mouseX, mouseY)) {
            ofDrawBitmapString("Hotspot " + ofToString(i), 900, 100);
        }
    }

	// Header Buttons count. 
	ofSetColor(ofColor::white);
	for (int i = 0; i < HEADER_COUNT; i++) {
		if (headerButtons[i].inside(mouseX, mouseY)) {
			ofDrawBitmapString("Header " + ofToString(i), 900, 100);

			// ∨∨∨ When you're inside the first button do this  ∨∨∨
			if (i == 0) {
				ofSetColor(255, 255, 255, 235);
				greenRouteImage.draw(0, 0);
			}
			// ∨∨∨ When you're inside the second button do this  ∨∨∨
			if (i == 1) {
				ofSetColor(255, 255, 255, 235);
				yellowRouteImage.draw(0, 0);
			}
			// ∨∨∨ When you're inside the third button do this  ∨∨∨
			if (i == 2) {
				ofSetColor(255, 255, 255, 235);
				redRouteImage.draw(0, 0);
			}

		}
	}

	// Markers for the locations
	ofSetColor(255, 255, 255, 255);
	locationMarkers.draw(0, 0);
}

void ofApp::keyPressed(int key) {
    if (key == 'h') {
        drawHotspots = !drawHotspots;

		resetBool = true;
    }

	if (key == 'j') {
		showPopUp = !showPopUp;
	}
}

void ofApp::mousePressed(int x, int y, int button) {

	for (int i = 0; i < HEADER_COUNT; i++) {
		
		if (headerButtons[i].inside(mouseX, mouseY)) {
			if (i == 0) {
				ofLog(OF_LOG_NOTICE) << "greenRouteClick Works ";
				greenRouteBool = true;
			}
		}
		if (headerButtons[i].inside(mouseX, mouseY)) {
			if (i == 1) {
				ofLog(OF_LOG_NOTICE) << "yellowRouteClick Works ";
				yellowRouteBool = true;
			}
		}
		if (headerButtons[i].inside(mouseX, mouseY)) {
			if (i == 2) {
				ofLog(OF_LOG_NOTICE) << "redRouteClick Works ";
				redRouteBool = true;
			}
		}
	}
}