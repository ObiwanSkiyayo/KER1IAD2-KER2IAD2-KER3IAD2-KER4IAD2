#pragma once

#include "ofMain.h"

class Ball {

    public:

        Ball();

        void setup(int startX, int startY, int startRadius, float startSpeed);

        void update();

        void draw();

        // variables
        float x;
        float y;
        float speedY;
        float speedX;

        int radius;

		float speed;



    private:

};
