/**
 *
 * cursor.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Draws a circle that follows user's cursor within a window.
 */

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

int main(void)
{
    // instantiate window
    GWindow window = newGWindow(320, 240);
//int y=20;  // y initial position for the bricks.
//int x=1; // // x initial position for the bricks.
GRect paddle = newGRect(320/2-90/2, 240-10*3, 90, 10);
 setFilled(paddle, true);
    setColor(paddle, "BLACK");
    add(window,paddle);
while(true){
        GEvent event = getNextEvent(MOUSE_EVENT);
        if (event != NULL)
        {   
            int x = getX(event) ;
            int y=getY(paddle);
            setLocation(paddle, x, y);
            
        }
        }
    // instantiate circle
   /*for(int i = 0; i < 5; i++){
            x=1;     
       for(int j = 0; j < 10; j++){       
        	GRect rect = newGRect(x, y, 320/10-3, 10);
			setFilled(rect, true);
			if (i == 0){
                setColor(rect, "RED");
            }else if (i == 1){
                setColor(rect, "ORANGE");
            }else if (i == 2){
                setColor(rect, "YELLOW");
            }else if (i == 3){
                setColor(rect, "BLUE");
            }else {
                setColor(rect, "GREEN");
            }
            add(window,rect);
            x += 320/10;
            printf("%d",x);
        }
        y += 15;
       printf("  %d \n",y);
     }*/
    // follow mouse forever
  /* while (true)
    {
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure circle follows top cursor
               int x = getX(event) ;
            int y=getY(rect);
            setLocation(rect, x,y);
            }
        }
    }*/
return 0;
}
