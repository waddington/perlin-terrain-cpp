#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	glEnable(GL_LIGHTING);

	ofSetVerticalSync(true);
	ofEnableLighting();
	ofEnableAlphaBlending();
	ofEnableSmoothing();

	cols = 3000 / scale;
	rows = 2000 / scale;

	mesh.setMode(OF_PRIMITIVE_TRIANGLES);

	spotLight.enable();
	spotLight.setup();
	spotLight.setPointLight();
	spotLight.setPosition(400,400,400);
}

//--------------------------------------------------------------
void ofApp::update(){
	float terrain[cols][rows];

		float yoff = flyingY;
		for (int i=0; i<rows; i++)
		{
			float xoff = flyingX;
			for (int j=0; j<cols; j++)
			{
				float noise = (ofNoise(xoff,yoff) * 150) - 100;
				terrain[j][i] = noise;
				xoff += 0.1;
			}
			yoff += 0.1;
		}

		mesh.clearIndices();
		mesh.clearVertices();

		for (int y=0; y<rows; y++)
		{
			for (int x=0; x<cols; x++)
			{
				mesh.addVertex(ofPoint(x*scale, y*scale, terrain[x][y]));
//				mesh.addColor(ofFloatColor(0,0,(terrain[x][y] + 100)));
			}
		}

		for (int y2=0; y2<rows-1; y2++)
		{
			for (int x2=0; x2<cols-1; x2++)
			{
				mesh.addIndex(x2+y2*cols);
				mesh.addIndex((x2+1)+y2*cols);
				mesh.addIndex(x2+(y2+1)*cols);

				mesh.addIndex((x2+1)+y2*cols);
				mesh.addIndex((x2+1)+(y2+1)*cols);
				mesh.addIndex(x2+(y2+1)*cols);
			}
		}

}

//--------------------------------------------------------------
void ofApp::draw(){
	camera.begin();
	spotLight.enable();

	mesh.addNormals(mesh.getFaceNormals(true));

	ofSetBackgroundColor(253, 250, 240);

	ofSetColor(255,255,255);
	mesh.drawWireframe();
	ofSetColor(155,55,55);

	ofEnableLighting();
	mesh.drawFaces();
	ofDisableLighting();

	ofSetColor(255,255,255);
	spotLight.draw();

	spotLight.disable();
	camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'w')
	{
		flyingY += 0.1;
	}
	if (key == 's')
	{
		flyingY -= 0.1;
	}
	if (key == 'a')
	{
		flyingX -= 0.1;
	}
	if (key == 'd')
	{
		flyingX += 0.1;
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
