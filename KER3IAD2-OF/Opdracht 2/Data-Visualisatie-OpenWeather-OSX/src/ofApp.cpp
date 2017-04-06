#include "ofApp.h"

void ofApp::setup() {
	//Get json data
	getData();

	//Load correct font
	kopTekst.load("BaronNeueBold.otf", 55);
	subTekst.load("BaronNeueBold.otf", 16);

	//Load images
	sun.load("sun.png");
	wind.load("wind.png");
	richting.load("richting.png");
}


void ofApp::update() {

	if (temp > 13) {
		kleurR = 250;
		kleurG = 250;
		kleurB = 0;
	}

	if (temp < 13) {
		kleurR = 0;
		kleurG = 0;
		kleurB = 250;
	}


}

void ofApp::draw() {
	ofBackground(ofColor::white);
	
	//Draw image from center point
	ofSetRectMode(OF_RECTMODE_CENTER);

	ofSetColor(255, 255, 255);
	wind.draw(ofGetWidth() /2 - 200, ofGetHeight() /2);
	richting.draw(ofGetWidth() / 2 + 200, ofGetHeight() / 2);

	ofSetColor(kleurR, kleurG, kleurB);
	sun.draw(ofGetWidth() / 2, ofGetHeight() / 2);

	//Headline
	ofSetColor(0, 0, 0, 25);
	kopTekst.drawStringCentered("What temperature is it today?", ofGetWidth() / 2, ofGetHeight() / 2  - 200);

	//Headline
	ofSetColor(0, 0, 0, 235);
	subTekst.drawStringCentered(ofToString(temp) + " Graden", ofGetWidth() / 2, ofGetHeight() / 2 + 150);

	//Wind
	ofSetColor(0, 0, 0, 235);
	subTekst.drawStringCentered(ofToString(windSnelheid) + "", ofGetWidth() / 2 - 200, ofGetHeight() / 2 + 100);

	//Richting
	ofSetColor(0, 0, 0, 235);
	subTekst.drawStringCentered(ofToString(windRichting) + "", ofGetWidth() / 2 + 200, ofGetHeight() / 2 + 100);


}

void ofApp::keyPressed(int key) {
    getData();
}



void ofApp::getData() {
    string url = "http://api.openweathermap.org/data/2.5/forecast?q=Amsterdam,nl&appid=37f584c9d170b496e7abe382b2237a5a&units=metric";

    bool success = json.open(url);
    if (success) {
		elementCount = 1;
        //int elementCount = json["cnt"].asInt();
        //ofLog() << json["cnt"].asInt() << " elementen gekregen" << endl;

		temp = json["list"][0]["main"]["temp"].asInt();
		windSnelheid = json["list"][0]["wind"]["speed"].asInt();
		windRichting = json["list"][0]["wind"]["deg"].asInt();

        for (int i = 0; i < elementCount; i++) {
            ofLog() << "Datum van element #" << i << " : " << json["list"][i]["wind"]["speed"] << endl;
			ofLog() << "Datum van element #" << i << " : " << json["list"][i]["wind"]["deg"] << endl;
			ofLog() << "Datum van element #" << i << " : " << json["list"][i]["main"]["temp"] << endl;
        }

    } else {
        ofLog() << "Oops. No data!" << endl;
    }
}