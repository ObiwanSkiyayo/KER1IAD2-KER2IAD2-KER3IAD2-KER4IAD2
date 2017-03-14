#include "ofApp.h"

void ofApp::setup() {

	drawAnother = true;

	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());

	xI = ofRandom(0, ofGetWidth());
	yI = ofRandom(0, ofGetHeight());

	xII = ofRandom(0, ofGetWidth());
	yII = ofRandom(0, ofGetHeight());

	speedX = ofRandom(-10, 10);
	speedY = ofRandom(-10, 10);

	speedXI = ofRandom(-10, 10);
	speedYI = ofRandom(-10, 10);

	speedXII = ofRandom(-10, 10);
	speedYII = ofRandom(-10, 10);

	radius = ofRandom(1, 40);
	radiusI = ofRandom(1, 40);
	radiusII = ofRandom(1, 40);


	ofSetColor(ofColor(ofRandom(255), 0, 150));
}

void ofApp::update() {
	if (x <= 0) {
		x = 0;
		speedX = -speedX;
	}
	else if (x >= ofGetWidth()) {
		x = ofGetWidth();
		speedX = -speedX;
	}

	if (y <= 0) {
		y = 0;
		speedY = -speedY;
	}
	else if (y >= ofGetHeight()) {
		y = ofGetHeight();
		speedY = -speedY;
	}

	if (xI <= 0) {
		xI = 0;
		speedXI = -speedXI;
	}
	else if (xI >= ofGetWidth()) {
		xI = ofGetWidth();
		speedXI = -speedXI;
	}

	if (yI <= 0) {
		yI = 0;
		speedYI = -speedYI;
	}
	else if (yI >= ofGetHeight()) {
		yI = ofGetHeight();
		speedYI = -speedYI;
	}

	if (xII <= 0) {
		xII = 0;
		speedXII = -speedXII;
	}
	else if (xII >= ofGetWidth()) {
		xII = ofGetWidth();
		speedXII = -speedXII;
	}

	if (yII <= 0) {
		yII = 0;
		speedYII = -speedYII;
	}
	else if (yII >= ofGetHeight()) {
		yII = ofGetHeight();
		speedYII = -speedYII;
	}

	x += speedX;
	y += speedY;

	xI += speedXI;
	yI += speedYI;

	xII += speedXII;
	yII += speedYII;

}

void ofApp::draw() {
	
	ofDrawCircle(x, y, radius);

	ofDrawCircle(xI, yI, radiusI);

	ofDrawCircle(xII, yII, radiusII);
}



void ofApp::keyPressed(int key) {


}