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
		averageColorLine.clear();
	/*int lineNumber = ofGetFrameNum() % int(sourceImage.getHeight());
	if (lineNumber == sourceImage.getHeight() - 1) {
		averageColorLine.clear();
	}*/
		sourceImagePixel = sourceVideo.getPixels();
		for (int i=0; i < sourceVideo.getHeight();i++) {
			ofColor tempColor = averageColorLineCalculator(sourceImagePixel, i, sourceImage.getWidth(), sourceImage.getHeight());
			ofColor tempColorHSB = averageColorLineHSBCalculator(sourceImagePixel, i, sourceImage.getWidth(), sourceImage.getHeight());
			averageColorLine.push_back(tempColor);
			averageColorLineHsb.push_back(tempColorHSB);


		}
		averageColorPicturesLines.push_back(averageColorLine);
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
			//------------------------------------------------------------------
			
			int averageRH = 0;
			int averageGH = 0;
			int averageBH = 0;

			for (ofColor tC : averageColorLineHsb) {
				averageRH += int(tC.r);
				averageGH += int(tC.g);
				averageBH += int(tC.b);
			}
			averageColorImage.r = averageRH / averageColorLine.size();
			averageColorImage.g = averageGH / averageColorLine.size();
			averageColorImage.b = averageBH / averageColorLine.size();
			averageColorImage.a = 255;
			averageColorPicturesHsb.push_back(averageColorImage);
		
			stepFrame += int(ceil(sourceVideo.getTotalNumFrames() / ofGetWidth()));
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	//sourceImage.draw(0, 0);
	//sourceVideo.draw(0, 0);
	for (int i = 0; i < averageColorPictures.size(); i++) {
		//ofNoFill();
		ofSetColor(int(averageColorPictures[i].r), int(averageColorPictures[i].g), int(averageColorPictures[i].b),255);
		ofDrawLine(i, ofGetHeight() /2 , i, ofGetHeight());
		for (int j = 0; j < sourceVideo.getHeight(); j++) {
			//ofSetColor(int(averageColorPicturesLines[i][j].r), int(averageColorPicturesLines[i][j].g), int(averageColorPicturesLines[i][j].b), 255);
			ofSetColor(averageColorPicturesLines[i][j]);
			//ofLog() <<i<<":"<< int(averageColorPicturesLines[i].size()) << endl;
			ofDrawLine(i, j, i, j+1);
		}
		//ofSetColor(int(averageColorPicturesHsb[i].r), int(averageColorPicturesHsb[i].g), int(averageColorPicturesHsb[i].b), 255);
		
		
	}
	ofSetColor(255, 255, 255);
	ofDrawLine(0, ofGetHeight() / 2, ofGetWidth(), ofGetHeight() / 2);
	string feedBack =ofToString(sourceVideo.getCurrentFrame()/25)+":"+ ofToString(sourceVideo.getTotalNumFrames()/25)+":"+ofToString(ofGetFrameRate());
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

	float totalH = 0;
	float totalS = 0;
	float totalB = 0;
	float tempH = 0;
	float tempS = 0;
	float tempB = 0;
	for (int i = 0; i < heiSource; i++) {
		ofColor tempColor = sourceImagePixel.getColor(i, nbLine);
		tempColor.getHsb(tempH, tempS, tempB);
		totalH += tempH;
		totalS += tempS;
		totalB += tempB;
	}

	/* ofLog() <<"R : "<< amountR.size() <<":"<<totalR<<":"<<totalR/sourceImage.getWidth()<< endl;
	ofLog() <<"G : "<< amountG.size() << ":" << totalG << ":" << totalG / sourceImage.getWidth() << endl;
	ofLog() <<"B : "<< amountB.size() << ":" << totalB << ":" << totalB / sourceImage.getWidth() << endl; */
	ofColor returnColor;
	returnColor.setHsb(totalH / sourceImage.getWidth(),totalS / sourceImage.getWidth(), totalB / sourceImage.getWidth());
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
