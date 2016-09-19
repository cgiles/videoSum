#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		ofColor averageColorLineCalculator(ofPixels sourcePixels, int nbLine, int widSource,int heiSource);
		ofColor averageColorLineHSBCalculator(ofPixels sourcePixels, int nbLine, int widSource, int heiSource);

		ofImage sourceImage;
		ofPixels sourceImagePixel;
		vector<ofColor> averageColorLine;
		vector<ofColor> averageColorPictures;
		ofColor averageColorImage;
		vector<int> amountR, amountG, amountB;
		ofVideoPlayer sourceVideo;
		int stepFrame;
};