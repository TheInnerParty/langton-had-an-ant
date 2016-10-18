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
	
	gui.add(drawColor.set("Draw Color", ofColor(225,0,225), ofColor::black, ofColor::white));
	gui.add(backgroundColor.set("background Color", ofColor::white, ofColor::black, ofColor::white));
	
	gui.setShape(10, 10, gui.getShape().width + 30, gui.getShape().height);
	gui.setWidthElements(230);
	
	ofSetBackgroundColor(ofColor::black);
	
	ofSetWindowTitle("Langton's Ant");
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
    for (auto&& ant : grid->ants){
        drawAnt(grid->getAntLocation(ant));
    }
    ofDrawRectangle(std::get<0>(mouseLoc)*boxRadius, std::get<1>(mouseLoc)*boxRadius, boxRadius, boxRadius);
    
	if (enableGUI) gui.draw();
	if (!quickDraw) {
		ofSetColor(backgroundColor.get().getInverted());
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
    int xTile = 0;
    int yTile = 0;
    while ((xTile + 1)* boxRadius < x){
        xTile++;
    }
    while ((yTile + 1)* boxRadius < y){
        yTile++;
    }
    std::get<0>(mouseLoc) = xTile;
    std::get<1>(mouseLoc) = yTile;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    grid->addAnt(std::get<0>(mouseLoc),std::get<1>(mouseLoc));
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
	} else ofSetColor(tileColor);
	ofDrawRectangle(x*boxRadius, y*boxRadius, boxRadius, boxRadius);
}
void ofApp::drawAnt(std::tuple<int,int> loc){
    ofSetColor(antColor);
    ofDrawRectangle(std::get<0>(loc)*boxRadius, std::get<1>(loc)*boxRadius, boxRadius, boxRadius);
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

void ofApp::stackTrace() {
	int result = 1+1;
}
