#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
	ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	int radius = 15;
	for (int x = -300; x <= 300; x += 30) {

		for (int y = -300; y <= 300; y += 30) {

			if (abs(x) <= 60 && abs(y) <= 60) { continue; }

			ofPushMatrix();
			ofTranslate(glm::vec2(x, y));

			auto noise_param = abs(x) > abs(y) ? abs(x) : abs(y);
			auto noise_value = ofNoise(noise_param * 0.005 - ofGetFrameNum() * 0.01);

			auto deg_start = atan2(-y, -x) * RAD_TO_DEG;
			if(noise_value > 0.4 && noise_value < 0.6){
			
				deg_start += ofMap(noise_value, 0.4, 0.6, 0, 360);
			}

			ofBeginShape();
			for (int deg = deg_start; deg < deg_start + 360; deg += 120){

				ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			}
			ofEndShape(true);

			ofPopMatrix();
		}
	}

}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
