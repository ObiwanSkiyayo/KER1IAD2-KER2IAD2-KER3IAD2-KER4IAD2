#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	for (int i = 0; i < VOICES; ++i) {

		voicePlayer[i].load("voice" +ofToString(i+1)+".wav");
		voicePlayer[i].setLoop(true);
		voicePlayer[i].setPaused(true);
		voicePlayer[i].play();

	}
	
	ofSoundSetVolume(0.2);
	
}

//--------------------------------------------------------------
void ofApp::update(){

	ofSoundUpdate();

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == '1') {
		voicePlayer[0].setPaused(voicePlayer[0].isPlaying());

	}
	else if (key == '2'){
		voicePlayer[1].setPaused(voicePlayer[1].isPlaying());
	}

	else if (key == '3') {
		voicePlayer[2].setPaused(voicePlayer[2].isPlaying());
	}

	else if (key == '4') {
		voicePlayer[3].setPaused(voicePlayer[3].isPlaying());
	}

	else if (key == '5') {
		voicePlayer[4].setPaused(voicePlayer[4].isPlaying());
	}

	else if (key == '6') {
		voicePlayer[5].setPaused(voicePlayer[5].isPlaying());
	}

	else if (key == '7') {
		voicePlayer[6].setPaused(voicePlayer[6].isPlaying());
	}


	
}

