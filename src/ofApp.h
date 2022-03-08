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

		void drawAxes();
		ofVec3f adaptCoord(float x, float y);
		float adaptWidth(float x);
		float adaptHeigth(float y);

		float f(float x); 
		float integraleRect(float a, float b);
		void drawRect(ofVec2f a, ofVec2f b);


	private:
		float h;
		float xMax;
		float xMin;
		float zoom;
		
};
