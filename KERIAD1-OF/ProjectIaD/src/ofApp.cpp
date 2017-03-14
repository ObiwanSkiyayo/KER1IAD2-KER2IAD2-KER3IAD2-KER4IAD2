#include "ofApp.h"

#define PIN_LED 9
#define PIN_BUTTWO 8
#define PIN_BUTONE 7

#define RFRECEIVERPIN 0

//--------------------------------------------------------------
void ofApp::setup(){

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);


	// Setup the arduino 
	arduino.connect("COM13");
	arduino.sendFirmwareVersionRequest();

	// Make the BG white
	ofBackground(255, 255, 255);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	arduino.update();

	// Check incoming data, just to be sure.
	cout << "\n" << data;


	// Start Functie
	// MAIN FUNCTION
	

	// Start cycle voor de LED en de draw Functie
	if (startCycle == 2) {

		arduino.sendPwm(PIN_LED, brightness);
		brightness = brightness + fadeAmount;
		radiusSize = radiusSize + fadeAmount;


		if (brightness <= 0 || brightness >= 255) {
			ofSleepMillis(2000);

			fadeAmount = -fadeAmount;
		}
	}

	// Cancel everything
	if (startCycle == 1) {

		brightness = 0;
		arduino.sendPwm(PIN_LED, brightness);
		radiusSize = 0;

	}

	
	if (arduino.getAnalog(RFRECEIVERPIN) >= upperThreshold) {
		//Do something on high
		//ofLogWarning("Wireless Button") << "Start(Wireless)";

		startCycle = 2;

	}
	else if (arduino.getAnalog(RFRECEIVERPIN) <= lowerThreshold) {
		// do something on low
			

	}

	



}

//--------------------------------------------------------------
void ofApp::draw(){

	// Alpha blending on
	ofEnableAlphaBlending(); 
	ofSetColor(0, 113, 188, 127);
	ofSetCircleResolution(100);

	// Draw the circle
	ofDrawCircle(ofGetWidth() / 2 - width / 2, ofGetHeight() / 2 - height / 2, radiusSize * 4);
	ofDrawCircle(ofGetWidth() / 2 - width / 2, ofGetHeight() / 2 - height / 2, radiusSize * 3);
	ofDrawCircle(ofGetWidth() / 2 - width / 2, ofGetHeight() / 2 - height / 2, radiusSize * 2);
	ofDrawCircle(ofGetWidth() / 2 - width / 2, ofGetHeight() / 2 - height / 2, radiusSize);
	
}


void ofApp::setupArduino(const int& version) {

	ofLogNotice() << "Arduino initialized" << endl;
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	// Arduino PWM van 0 tot 255, aka the brightness
	arduino.sendDigitalPinMode(PIN_LED, ARD_PWM);
	arduino.sendDigitalPinMode(PIN_BUTTWO, ARD_INPUT);
	arduino.sendDigitalPinMode(PIN_BUTONE, ARD_INPUT);

	// Receiver pin incoming
	arduino.sendAnalogPinReporting(RFRECEIVERPIN, ARD_ANALOG);

	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);

}

void ofApp::digitalPinChanged(const int& pin) {

	int value = arduino.getDigital(pin);
	
	
	// Button op de controller, deze stopt de Yoga sessie.
	if (pin == PIN_BUTONE && value == 1) {

		ofLogWarning("Button One") << "Cancel";
		startCycle = 1;

	}


	// Debug test, in werkelijke prototype gebeurt dit wireless.
	if (pin == PIN_BUTTWO && value == 1) {
		
		ofLogWarning("Button two") << "Start";
		startCycle = 2;

	}


}


void ofApp::analogPinChanged(const int& pin) {

	int value = arduino.getAnalog(pin);

	// Receiver pin input.
	if (pin == RFRECEIVERPIN) {

		data = value;

	}


}

void ofApp::keyPressed(int key) {

	// Test functie niet gebruikt
	if (key == ' ') {
		breathOut = false;
	}

}