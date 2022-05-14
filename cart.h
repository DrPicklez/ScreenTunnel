#ifndef CART_H
#define CART_H
#include "ofMain.h"

class Cart
{
public:
    void setup();
    void setPosition(ofVec3f pos);
    void draw();
    void drive(string dir);

    ofVec3f position;
};

#endif // CART_H
