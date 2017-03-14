#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT, true);

	rgbImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	hsvImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);

	hue.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	saturation.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	brightness.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);

	filtered.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);

}

//--------------------------------------------------------------
void ofApp::update(){

	grabber.update();

	if (grabber.isFrameNew()) {
		rgbImage.setFromPixels(grabber.getPixels().getData(), GRABBER_WIDTH, GRABBER_HEIGHT);
		rgbImage.mirror(false, true);

		hsvImage = rgbImage;
		hsvImage.convertRgbToHsv();

		hsvImage.convertToGrayscalePlanarImages(hue, saturation, brightness);

		for (int i = 0; i < GRABBER_WIDTH * GRABBER_HEIGHT; i++)
		{
			if (ofInRange( hue.getPixels()[i], selectedHue - HUE_MARGINE, selectedHue + HUE_MARGINE)) {
				filtered.getPixels()[i] = 255;
			} else {
				filtered.getPixels()[i] = 0;
			}
		}

		filtered.flagImageChanged();

		contours.findContours(filtered, 50, GRABBER_HEIGHT * GRABBER_WIDTH / 2, 1, false);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (showVideo) {

		rgbImage.draw(0, 0, ofGetWidth(), ofGetHeight());
	}

	if (showHSVComponents) {
		hsvImage.draw(0, 0);
		hue.draw(0, 240);
		saturation.draw(320, 240);
		brightness.draw(640, 240);

	}

	if (showFilter) {
		filtered.draw(0, 480);
	}

	if (showContours) {
		contours.draw(0, 0, ofGetWidth(), ofGetHeight());
	}

	//ofSetColor(ofColor::blue, 100);
	ofFill();

	for (int i = 0; i < contours.nBlobs; i++)
	{
		ofDrawCircle(contours.blobs[i].centroid.x * ofGetWidth() / GRABBER_WIDTH ,
			contours.blobs[i].centroid.y* ofGetWidth() / GRABBER_WIDTH,
			20);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'h') {
		showHSVComponents = !showHSVComponents;
	}
	else if (key == 'j') {
		showFilter = !showFilter;
	}
	else if (key == 'k') {
		showContours = !showContours;
	}
	else if (key == 'l') {
		showVideo = !showVideo;
	}
}



//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	selectedHue = hue.getPixels()[y * GRABBER_WIDTH + x];
	cout << "Selected: " << selectedHue << endl;
	
}