#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	gui.setup("Instellingen", "settings.xml");
	gui.add(count.set("Count", 50, 0, 200));

	gui.add(speedX.set("SpeedX", 5, 0, 20));
	gui.add(speedY.set("SpeedY", 5, 0, 20));
	gui.add(radius.set("Radius", 20, 1, 100));

	gui.add(color.set("Color", ofColor::white));



}



//--------------------------------------------------------------
void ofApp::update(){

	ofSetColor(ofColor(color));
	speedXStored = speedX;

	if (width <= 0) {
		width = 0;
		speedX = -speedXStored;
	}
	else if (width >= ofGetWidth()) {
		width = ofGetWidth();
		speedX = -speedXStored;
	}

	if (heigth <= 0) {
		heigth = 0;
		speedY = -speedY;
	}
	else if (heigth >= ofGetHeight()) {
		heigth = ofGetHeight();
		speedY = -speedY;
	}

	width += speedX;
	heigth += speedY;

}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();

	ofDrawCircle(width, heigth, radius);
}

void ofApp::keyPressed(int key) {

	if (key == ' ') {
		draw();
	}

}
