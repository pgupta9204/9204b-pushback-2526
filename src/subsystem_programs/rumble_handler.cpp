#include "main.h"

void rumbleHandler(bool rumbleOn, const char *pattern) 
{
    /*
    Goal - create a rumble handler function that can be called to rumble the controller in different patterns
    Inputs - rumbleOn (boolean) - whether or not to rumble the controller
           pattern (string) - the pattern to rumble in given by the user that follows the PROS formatting
    */

    if(rumbleOn) // only rumble if rumbleOn is true
    {
        controller1.rumble(pattern);
    }
}

