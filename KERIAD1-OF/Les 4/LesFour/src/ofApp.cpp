#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofAddListener(	arduino.EInitialized, 
					this,
					&ofApp::setupArduino);

	arduino.connect("COM8");
	arduino.sendFirmwareVersionRequest();
}

//--------------------------------------------------------------
void ofApp::update(){
	
	arduino.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	arduino.sendDigital(12, ARD_HIGH);
}

void ofApp::keyReleased(int key) {
	arduino.sendDigital(12, ARD_LOW);
}



void ofApp::setupArduino(const int& version) {
	ofLogNotice() << "Arduiho klaar!" << endl;
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	ofLogNotice() << "Arduino firmware" << arduino.getMajorFirmwareVersion() << "." << arduino.getMinorFirmwareVersion();

	arduino.sendDigitalPinMode(12, ARD_OUTPUT);


}

void ofApp::digitalPinChange(const int& pinNum) {

}

void ofApp::analogPinChanged(const int& pinNum) {

}