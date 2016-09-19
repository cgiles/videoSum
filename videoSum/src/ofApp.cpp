#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sourceImage.load("source3.jpg");
	sourceImagePixel = sourceImage.getPixels();
	ofSetFrameRate(30);
	sourceVideo.loadMovie("barbarella.avi");
	sourceVideo.play();
	sourceVideo.setPaused(true);
	stepFrame = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
		sourceVideo.setFrame(stepFrame);
		sourceVideo.update();
	/*int lineNumber = ofGetFrameNum() % int(sourceImage.getHeight());
	if (lineNumber == sourceImage.getHeight() - 1) {
		averageColorLine.clear();
	}*/
		sourceImagePixel = sourceVideo.getPixels();
		for (int i=0; i < sourceVideo.getHeight();i++) {
			ofColor tempColor = averageColorLineCalculator(sourceImagePixel, i, sourceImage.getWidth(), sourceImage.getHeight());
			averageColorLine.push_back(tempColor);

		}
		
			int averageR = 0;
			int averageG = 0;
			int averageB = 0;

			for (ofColor tC : averageColorLine) {
				averageR += int(tC.r);
				averageG += int(tC.g);
				averageB += int(tC.b);
			}
			averageColorImage.r = averageR / averageColorLine.size();
			averageColorImage.g = averageG / averageColorLine.size();
			averageColorImage.b = averageB / averageColorLine.size();
			averageColorImage.a = 255;
			averageColorPictures.push_back(averageColorImage);
		
			stepFrame += int(sourceVideo.getTotalNumFrames() / ofGetWidth());
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	//sourceImage.draw(0, 0);
	//sourceVideo.draw(0, 0);
	for (int i = 0; i < averageColorPictures.size(); i++) {
		//ofNoFill();
		ofSetColor(int(averageColorPictures[i].r), int(averageColorPictures[i].g), int(averageColorPictures[i].b),255);
		ofDrawLine(i, ofGetHeight() - 500 , i, ofGetHeight());
	}
	ofSetColor(255, 255, 255);
	string feedBack =ofToString(sourceVideo.getCurrentFrame())+":"+ ofToString(sourceVideo.getTotalNumFrames())+":"+ofToString(ofGetFrameRate());
	ofDrawBitmapString(feedBack, 10, 10);
}

//--------------------------------------------------------------
ofColor ofApp::averageColorLineCalculator(ofPixels sourcePixels, int nbLine, int widSource, int heiSource) {
	
	int totalR = 0;
	int totalG = 0;
	int totalB = 0;

	for (int i = 0; i < heiSource; i++) {
		ofColor tempColor = sourceImagePixel.getColor(i, nbLine);
		totalR += int(tempColor.r);
		totalG += int(tempColor.g); 
		totalB += int(tempColor.b); 
		}
	
	/* ofLog() <<"R : "<< amountR.size() <<":"<<totalR<<":"<<totalR/sourceImage.getWidth()<< endl;
	ofLog() <<"G : "<< amountG.size() << ":" << totalG << ":" << totalG / sourceImage.getWidth() << endl;
	ofLog() <<"B : "<< amountB.size() << ":" << totalB << ":" << totalB / sourceImage.getWidth() << endl; */
	ofColor returnColor;
	returnColor.r = totalR / sourceImage.getWidth();
	returnColor.g = totalG / sourceImage.getWidth();
	returnColor.b = totalB / sourceImage.getWidth();
	returnColor.a = 255;
	return returnColor;
}
//--------------------------------------------------------------
ofColor ofApp::averageColorLineHSBCalculator(ofPixels sourcePixels, int nbLine, int widSource, int heiSource) {

	int totalR = 0;
	int totalG = 0;
	int totalB = 0;

	for (int i = 0; i < heiSource; i++) {
		ofColor tempColor = sourceImagePixel.getColor(i, nbLine);
		totalR += int(tempColor.r);
		totalG += int(tempColor.g);
		totalB += int(tempColor.b);
	}

	/* ofLog() <<"R : "<< amountR.size() <<":"<<totalR<<":"<<totalR/sourceImage.getWidth()<< endl;
	ofLog() <<"G : "<< amountG.size() << ":" << totalG << ":" << totalG / sourceImage.getWidth() << endl;
	ofLog() <<"B : "<< amountB.size() << ":" << totalB << ":" << totalB / sourceImage.getWidth() << endl; */
	ofColor returnColor;
	returnColor.r = totalR / sourceImage.getWidth();
	returnColor.g = totalG / sourceImage.getWidth();
	returnColor.b = totalB / sourceImage.getWidth();
	returnColor.a = 255;
	return returnColor;
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
