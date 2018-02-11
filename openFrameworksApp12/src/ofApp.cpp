#define POCO_NO_UNWINDOWS 1
#include "ofApp.h"

void ofApp::setup() {

	art.setMenu(gui);

	ofSetFrameRate(120);

	art.setup();

	ofSetBackgroundAuto(false);
}// 45shavlik11
 //https://en.wikipedia.org/wiki/HSL_and_HSV
void ofApp::update() {
	cam.update();
	art.update();
}
void ofApp::draw() {
	gui.draw();
	art.draw();
}
void ofApp::keyPressed(int key) {
	if (key == ' ') {
		// put a start/stop here
	}
	else if (key == 'a') {
		art.advanceImage();
	}
	else if (key == 'r') {
		art.setup();
	}
	else if (key == 'x') {
		string name = "save\\";
		name += ofToString("save.") + art.images[art.currentImage]->shortname;
		ofImage img;
		img.grabScreen(art.xImage, 0, art.xImage, art.yImage);
		img.saveImage(name, OF_IMAGE_QUALITY_BEST);
	}
}
void ofApp::mousePressed(int x, int y, int button) {

	if (x < art.images[art.currentImage]->img.getWidth() && y < art.images[art.currentImage]->img.getHeight()) {
		art.setTargetColor(art.images[art.currentImage]->img.getColor(x, y)); //bugbug make it scan just for this in the future
	}

}
