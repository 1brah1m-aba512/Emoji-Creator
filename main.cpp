#include "LibEmoticon.h"

#include <iostream>

using namespace std;

int main()
{
    Emoticon objImage(500,500); // Constructor is automatically called.

    // Draw the first circle
    objImage.drawCircle(250, 250, 245, {255, 200, 54});
    
	// Draw a second circle
    objImage.drawCircle(150, 150, 25, {101, 67, 33});
    
	// Draw a third circle
    objImage.drawCircle(150, 350, 25, {101, 67, 33});
	
    // Draw the first Rectangle
    objImage.drawRect(350,150,25,200,{0,0,0});

    cout << objImage.toPMM() << endl; // Calling the member function toPMM.

    return StatusCode::SUCCESS;
}
