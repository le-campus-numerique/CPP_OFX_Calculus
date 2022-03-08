#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
	ofSetColor(20);

	//ofSetFrameRate(1);

	h = 0.1;
	xMin = 0;
	xMax = PI;
	zoom = 100;
}

ofVec3f ofApp::adaptCoord(float x, float y)
{
	return ofVec3f(adaptWidth(x), adaptHeigth(y),0);

}

float ofApp::adaptWidth(float x)
{
	return ofGetWidth() / 2. + x*zoom;
}

float ofApp::adaptHeigth(float y)
{
	return ofGetHeight() / 2. - y*zoom;
}

float ofApp::f(float x)
{
	return sin(x);
}


float ofApp::integraleRect(float a, float b)
{
// TODO
	return 0;
}


void ofApp::drawRect(ofVec2f a, ofVec2f b)
{
	ofPolyline l;
	l.addVertex(a.x,a.y,0);
	l.addVertex(a.x,b.y,0);
	l.addVertex(b.x,b.y,0);
	l.addVertex(b.x,a.y,0);
	l.close();
	l.draw();
}



//--------------------------------------------------------------
void ofApp::update() {

}


void ofApp::drawAxes()
{
	ofSetColor(0);
	ofPolyline x_axis;
	x_axis.addVertex(ofVec3f(ofGetWidth() / 2, 0));
	x_axis.addVertex(ofVec3f(ofGetWidth() / 2, ofGetHeight()));
	x_axis.draw();
	ofPolyline y_axis;
	y_axis.addVertex(ofVec3f(0, ofGetHeight() / 2));
	y_axis.addVertex(ofVec3f(ofGetWidth(), ofGetHeight() / 2));
	y_axis.draw();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackgroundGradient(ofColor(240), ofColor(210), OF_GRADIENT_BAR);
	drawAxes();


	ofSetColor(170);
	ofPolyline f_x;
	ofPolyline fprim_x;
	ofPolyline fsec_x;


	for (float x = xMin; x <= xMax; x += h)
	{	
		float y = f(x);
		f_x.addVertex(adaptCoord(x, y));
	}


	ofSetColor(0, 170, 170);
	float ra = integraleRect(xMin, xMax);


	ofSetColor(170);
	f_x.draw();

	std::stringstream sts;
	sts << "Rect : " << ra << std::endl;
	ofDrawBitmapString(sts.str(), 10, 100);
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '+')
	{
		zoom *= 1.1;
	}
	else if (key == '-')
	{
		zoom *= 0.9;
	}
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
