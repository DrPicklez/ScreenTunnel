#include "tunneltravel.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////
void TunnelTravel::setup(int _width, int _height, int _nImages){

    nImages = _nImages;
    width = _width;
    height = _height;
    image.loadImage("1.png");
//    image.loadImage("2.jpg");
    image.resize(width, height);
    addNoise = 0;
    ride = 0;
    image.setAnchorPoint(image.getWidth()/2, image.getHeight()/2);

    depthMult = height * 50/ nImages;       //distance of tunnel

    for(int i = 0; i < nImages; i ++){
        float z = depthMult * i;
        z *= -1;
        ofVec3f position(width/2, height/2, z);
        positions.push_back(position);
        newPositions.push_back(position);
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////

float noiseIncX;
float noiseIncY;
void TunnelTravel::update(){
    zInc = depthMult * ofMap(ride, 0, 100, 0., 1.);

    for(int i = 0; i < newPositions.size(); i ++){
        newPositions[i].z = positions[i].z + zInc;



        if(addNoise){
            float noiseDiffPerSlide = i * 0.0001;
            float noiseRideX = (i * noiseDiffPerSlide) + noiseIncX;
            float noiseX = ofNoise(noiseRideX);
            (noiseX -= 0.5) * 2;        //scale offset 0, 1 -> -1, 1
            noiseX *= 10;             //scale

            newPositions[i].x = positions[i].x * noiseX;
            noiseIncX += 0.0001;

//            if((i == 0) && (abs(noiseX) > noiseXComp)){
//                noiseXComp = noiseIncX;
//                noiseIncX += 0.018;
////                cout << "GO" << endl;
//            }

//            cout << abs(noiseX) << endl;


            float noiseRideY = (i * noiseDiffPerSlide) + noiseIncY;
            float noiseY = ofNoise(noiseRideY);
            newPositions[i].y = positions[i].y * noiseY;


        }
    }

    if(addRide){
        ride += 10;
        ride = ride % 100;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
int nShow;
void TunnelTravel::draw(int _nShow){
    if(_nShow > -1){
        if(_nShow < nImages){
            nShow = _nShow;
        }
    }

    for(int i = 0; i < nShow; i ++){
            image.draw(newPositions[i]);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
ofVec3f TunnelTravel::getcarPos(){      //TO FIX!!!!!!!!!!!
    int positionX = newPositions[5].x;
    int positionY = newPositions[5].y - height / 5;
    int positionZ = positions[5].z;
    return ofVec3f(positionX, positionY, positionZ);
}
ofVec3f TunnelTravel::getViewAim(){      //TO FIX!!!!!!!!!!!
    int positionX = newPositions[6].x;
    int positionY = newPositions[6].y;
    int positionZ = positions[6].z;
    return ofVec3f(positionX, positionY, positionZ);
}
ofVec3f TunnelTravel::getViewPos(){      //TO FIX!!!!!!!!!!!
    int positionX = newPositions[3].x;
    int positionY = newPositions[3].y;
//    int positionZ = positions[3].z;
    int positionZ = 30;
    return ofVec3f(positionX, positionY, positionZ);
}
