#include "cart.h"

void Cart::setup(){
}

void Cart::setPosition(ofVec3f pos){
    position = pos;
}

void Cart::draw(){
    ofDrawCone(position, ofGetWidth()/20, ofGetHeight()/30);
}
void Cart::drive(string dir){

}
