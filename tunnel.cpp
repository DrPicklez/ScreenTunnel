#include "tunnel.h"


void Tunnel::setup(int _nImages){
    centreX = ofGetWidth()/2;
    centreY = ofGetHeight()/2;
    image.loadImage("scrShot.png");

    nImages = _nImages;
    widMult = (ofGetWidth() * 1.3)/ nImages;
    higMult = (ofGetHeight() * 1.3)/ nImages;

    ofRectangle rect;
    for(int i = 0; i < nImages; i ++){
        rectangles.push_back(rect);
    }
}

void Tunnel::update(){

    float sMult = ofMap(ride, 0, 100, 1, 0);

    for(int i = 0; i < rectangles.size(); i ++){
        i+=1;

        int width = (widMult * i);
        width -= (widMult * sMult);

        int height = (higMult * i);
        height -= (higMult * sMult);

        i-=1;

        rectangles[i].setFromCenter(centreX, centreY, width, height);
    }
    ride +=5;
    ride = ride % 100;
}

void Tunnel::draw(){
    for(int i = 0; i < rectangles.size(); i ++){
        int n = rectangles.size() - (i +1);
        image.draw(rectangles[n]);
    }
}
