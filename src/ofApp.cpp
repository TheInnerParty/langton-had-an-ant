#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	boxRadius = 10;
	grid = new Grid(100, 100);
	stepCounter = 0;
	
	gui.setup();
	gui.add(quickDraw.set("Disable Continuous Draw", false));
	quickDraw.addListener(this, &ofApp::toggleContDraw);
	quickSteps.addListener(this, &ofApp::drawStatic);
	gui.add(quickSteps.set("Manual Step Count", 0, 0, 12000));
	
	gui.add(drawColor.set("Draw Color", ofColor::lightBlue, ofColor::black, ofColor::white));
	gui.add(backgroundColor.set("background Color", ofColor::white, ofColor::black, ofColor::white));
	
	gui.setShape(10, 10, gui.getShape().width + 30, gui.getShape().height);
	gui.setWidthElements(230);
	
	ofSetBackgroundColor(ofColor::white);
	
	ofSetWindowTitle("Langston's Ant");
	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (!quickDraw) {
		grid->update();
		stepCounter++;
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int x = 0; x< grid->width; x++) {
		for (int y = 0; y < grid->height; y++) {
			drawBox(x, y, grid->getBoxColored(x, y));
		}
	}
	gui.draw();
	if (!quickDraw) {
		ofSetColor(ofColor::black);
		ofDrawBitmapString("Steps: " + std::to_string(stepCounter), ofGetWidth() - 100, 50);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
void ofApp::drawBox(int x, int y, bool colored) {
	if (colored) {
		ofSetColor(drawColor);
	} else ofSetColor(backgroundColor);
	ofDrawRectangle(x*boxRadius, y*boxRadius, boxRadius, boxRadius);
}

void ofApp::toggleContDraw(bool& quickDraw) {
	reInitGrid();
	quickSteps = 0;
}

void ofApp::reInitGrid() {
	delete grid;
	grid = new Grid(100, 100);
	stepCounter = 0;
	
}
void ofApp::drawStatic(int& quickSteps) {
	
	if (quickDraw) {
		reInitGrid();
		for (int i = 0; i < quickSteps; i++) {
			grid->update();
		}
	}
	
	
}
