#ifndef TUNNEL_H
#define TUNNEL_H

#include "ofMain.h"

class Tunnel
{
public:
    void setup(int _nImages);
    void update();
    void draw();

    int nImages;
    int ride;
    int widMult, higMult, centreX, centreY;
    ofImage image;
    vector <ofRectangle> rectangles;

};

#endif // TUNNEL_H
