#include "Ball.h"

Ball::Ball() {
}

void Ball::setup(int startX, int startY, int startRadius, float startSpeed) {
	x = startX;
	y = startY;

	radius = startRadius;
	

    speedX = startSpeed;
    speedY = startSpeed;


}


void Ball::update() {
    if (x < 0) {
        x = 0;
        speedX *= -1;
    } else if (x > ofGetWidth()) {
        x = ofGetWidth();
        speedX *= -1;
    }

    if (y < 0) {
        y = 0;
        speedY *= -1;
    } else if (y > ofGetHeight()) {
        y = ofGetHeight();
        speedY *= -1;
    }

    x += speedX;
    y += speedY;
}

void Ball::draw() {

    ofCircle(x, y, radius);
}
