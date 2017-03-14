#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	soundStream.printDeviceList();
	soundStream.setDeviceID(0);
	soundStream.setup(this, 2, 0, 22050, 512, 4);

	phase = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == '1') {
		phase = phase * 2;
	}

}


void ofApp::audioOut(float * output, int bufferSize, int nChannels) {

	for (int i = 0; i <bufferSize * nChannels; i+=2) {

		float sample = sin(phase);
		output[i] = sample;

		sample = sin(phase *1.005f);
		output[i + 1] = sample;

		phase += 0.04;
	}

}