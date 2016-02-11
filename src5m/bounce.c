/**
 * bounce.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Bounces a circle back and forth in a window.
 */

// standard libraries
#include <stdio.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

int main(void)
{
    // instantiate window
    GWindow window = newGWindow(320, 240);

    // instantiate circle
    GOval circle = newGOval(320/2-7, 240/2-7, 15, 15);
    setColor(circle, "BLACK");
    setFilled(circle, true);
    add(window, circle);
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    add(window, label);
    char s[3];
    int i=0;
    sprintf(s, "%i", i);
    setLocation(label,320/2-5,240/2);
    setLabel(label, s);
    
    // initial velocity
    double velocityy = 1.5; 
    double velocityx=1.5; 
    setLocation(circle,320/2,240/2); 
    pause(100); 
    // bounce forever
   while (true)
    {
        // move circle along x-axis
        move(circle, velocityx, velocityy);

        // bounce off right edge of window
        if (getX(circle) + getWidth(circle) >= getWidth(window))
        {
            velocityx = -velocityx;
        }
        else if ((getX(circle) <= 0))
        {
            velocityx = -velocityx;
        }
        if((getY(circle) + getHeight(circle) >= getHeight(window)))
        {
            velocityy=-velocityy;
            printf("m");
        }
        else if ((getY(circle) <= 0))
        {
            velocityy = -velocityy;
        }

        // bounce off left edge of window

        // linger before moving again
        pause(10);
    }
return 0;
}
