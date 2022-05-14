#ifndef TUNNELTRAVEL_H
#define TUNNELTRAVEL_H
#include "ofMain.h"

class TunnelTravel
{
public:
    void setup(int width, int height, int _nImages);
    void update();
    void draw(int _nShow);
    void addWall();
    ofVec3f getcarPos();
    ofVec3f getViewAim();
    ofVec3f getViewPos();

    int nImages;
    int ride;
    int width, height;
    float depthMult;
    float zInc;
    bool addNoise, addRide;

    ofImage image;
    vector <ofVec3f> positions;
    vector <ofVec3f> newPositions;
};

#endif // TUNNELTRAVEL_H
