#include "ofApp.h"
#include "Ball.h"

Ball ball;

void ofApp::setup() {

	gui.setup("Instellingen", "settings.xml");
	gui.add(radius.set("Radius", 20, 0, 100));
	gui.add(speed.set("Speed", 0.5f, 0, 3));
	gui.add(color.set("Color", ofColor::white));




}

void ofApp::update() {
    //ball.update();


	if (ball.radius = radius) {
		ball.radius = radius;
	}

	for (unsigned int i = 0; i < balls.size(); i++) {
		balls[i].update();
	}

}

void ofApp::draw() {
	gui.draw();


	for (unsigned int i = 0; i < balls.size(); i++) {
		balls[i].draw();
	}

}

void ofApp::keyPressed(int key) {


	if (key == ' ') {

		for (int i = 0; i < 1; i++) {
			Ball newBall;

			newBall.setup(ofRandom(ofGetWidth()),
				ofRandom(ofGetHeight()),
				radius,
				speed);

			balls.push_back(newBall);
			ofSetColor(color);
		}

	}



}