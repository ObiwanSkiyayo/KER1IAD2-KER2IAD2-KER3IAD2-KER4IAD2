#include <SQLiteCpp/include/SQLiteCpp/Database.h>
#include "ofApp.h"

void ofApp::setup() {
    string databasePath = ofToDataPath("bevolking.sqlite", true);
    db = new SQLite::Database(databasePath);

	myFont.load("Gloss_And_Bloom.ttf", 40);
	subFont.load("Gloss_And_Bloom.ttf", 15);
	subFontTwee.load("Gloss_And_Bloom.ttf", 7);
}

void ofApp::update() {
    int year = ofMap(ofGetMouseY(), 0, ofGetWidth() - 100, 1900, 2016, true);

    if (year != selectedYear) {
        selectedYear = year;
        string sql = "SELECT year, north, east, south, west, north+east+south+west AS total FROM bevolking WHERE year=?";

        SQLite::Statement query(*db, sql);

        query.bind(1, selectedYear); // vervang 1e vraagteken door de waarde van de variabele
        if (query.executeStep()) {
            total = query.getColumn("total").getInt();
            year = query.getColumn("year").getInt();
            north = query.getColumn("north").getInt();
            east = query.getColumn("east").getInt();
            south = query.getColumn("south").getInt();
            west = query.getColumn("west").getInt();
            ofLog() << selectedYear << " " << total << " "
                    << north << " " << east << " " << south << " " << west
                    << endl;
        }

        query.reset();
    }

}

void ofApp::draw() {

	ofBackgroundGradient(0xFFFFFF, 0xEFEFF0, OF_GRADIENT_LINEAR);

	int screenWidth = ofGetWidth() / 2;

	//LINES
	ofSetColor(0, 0, 0, 255);
	ofDrawLine(0, ofGetMouseY(), ofGetWidth() /2 - 70, ofGetMouseY());
	ofDrawLine(ofGetWidth(), ofGetMouseY(), ofGetWidth() / 2 + 70, ofGetMouseY());

	ofSetColor(0, 0, 0, 40);
	ofDrawLine(0, ofGetMouseY() + 50, ofGetWidth() / 2 - 70, ofGetMouseY() + 50);
	ofDrawLine(ofGetWidth(), ofGetMouseY() + 50, ofGetWidth() / 2 + 70, ofGetMouseY() + 50);

	ofSetColor(0, 0, 0, 40);
	ofDrawLine(0, ofGetMouseY() - 50, ofGetWidth() / 2 - 70, ofGetMouseY() - 50);
	ofDrawLine(ofGetWidth(), ofGetMouseY() - 50, ofGetWidth() / 2 + 70, ofGetMouseY() - 50);

	ofSetColor(0, 0, 0, 10);
	ofDrawLine(0, ofGetMouseY() + 100, ofGetWidth() / 2 - 70, ofGetMouseY() + 100);
	ofDrawLine(ofGetWidth(), ofGetMouseY() + 100, ofGetWidth() / 2 + 70, ofGetMouseY() + 100);

	ofSetColor(0, 0, 0, 10);
	ofDrawLine(0, ofGetMouseY() - 100, ofGetWidth() / 2 - 70, ofGetMouseY() - 100);
	ofDrawLine(ofGetWidth(), ofGetMouseY() - 100, ofGetWidth() / 2 + 70, ofGetMouseY() - 100);


	//TEXT
	ofSetColor(0, 0, 0, 255);
	myFont.drawStringCentered("" + ofToString(selectedYear), ofGetWidth() / 2, ofGetMouseY());

	ofSetColor(0, 0, 0, 40);
	subFont.drawStringCentered("" + ofToString(selectedYear - 1), ofGetWidth() / 2, ofGetMouseY() - 50);
	
	ofSetColor(0, 0, 0, 40);
	subFont.drawStringCentered("" + ofToString(selectedYear + 1), ofGetWidth() / 2, ofGetMouseY() + 50);

	ofSetColor(0, 0, 0, 10);
	subFont.drawStringCentered("" + ofToString(selectedYear - 2), ofGetWidth() / 2, ofGetMouseY() - 100);

	ofSetColor(0, 0, 0, 10);
	subFont.drawStringCentered("" + ofToString(selectedYear + 2), ofGetWidth() / 2, ofGetMouseY() + 100);

	//NORTH
	ofSetColor(46, 49, 0, 255);
	int northCircle = north * 1.0f / total * 200;
	ofDrawCircle(screenWidth - 150, ofGetMouseY(), northCircle);

	//EAST
	ofSetColor(39, 170, 255, 255);
	int eastCircle = east * 1.0f / total * 200;
	ofDrawCircle(screenWidth - 150 * 2, ofGetMouseY(), eastCircle);

	//SOUTH
	ofSetColor(255, 255, 0, 255);
	int southCircle = south * 1.0f / total * 200;
	ofDrawCircle(screenWidth + 150, ofGetMouseY(), southCircle);

	//WEST
	ofSetColor(236, 0, 140, 255);
	int westCircle = west * 1.0f / total * 200;
    ofDrawCircle(screenWidth + 150 * 2, ofGetMouseY(), westCircle);



}

void ofApp::keyPressed(int key) {

}

void ofApp::keyReleased(int key) {

}

void ofApp::mouseMoved(int x, int y) {

}