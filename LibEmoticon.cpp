#include "LibEmoticon.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

// Implementation of Emoticon methods

Emoticon::Emoticon() : Emoticon(ROWS, COLS) // Constructor chaining.
{
}

Emoticon::Emoticon(int intRows, int intCols)//Parameterised Constructor
{
    alloc(intRows, intCols);
}

Emoticon::Emoticon(const Emoticon& objOriginal)//Copy constructor
: Emoticon(objOriginal._rows, objOriginal._cols)
{
    clone(objOriginal);
}

Emoticon::~Emoticon()//Destructor
{
    dealloc();
}

//Circle drawing function
void Emoticon::drawCircle(int intRow, int intCol, double dblRadius, Pixel recColour)
{

//iterate through each row and coloumn and colour where the radius is as the given value
    for(int r = 0; r < _rows; r++)
    {
        for(int c = 0; c < _cols; c++)
        {
            if(distance(r, intRow, c, intCol) <= dblRadius)
            {
                setPixel(r, c, recColour);
            }
        }
    }
}

//rectangle drawing function
void Emoticon::drawRect(int intRow,int intCol,int intLength,int intBreadth,Pixel recColour){

//colours from a given point to another given point in the shape of a rctangle
for(int r = intRow; r<intRow + intLength;r++ ){

    for (int c = intCol;c<intCol + intBreadth;c++){

    setPixel(r,c,recColour);

          }
    }
}

//Function to help convert file to PPM for easier viewing
string Emoticon::toPMM() const
{
    stringstream ssPPM;
    ssPPM << "P3" << endl
          << _cols << ' ' << _rows << endl
          << 255 << endl;
    for(int r = 0; r < _rows; r++)
    {
        for(int c = 0; c < _cols; c++)
        {
            ssPPM << _image[r][c].intRed << ' '
                  << _image[r][c].intGreen << ' '
                  << _image[r][c].intBlue << ' ';
        }
        ssPPM << endl;
    }
    return ssPPM.str();
}

//Function to allocate memory for the image
void Emoticon::alloc(int intRows, int intCols)
{
    _rows = intRows;
    _cols = intCols;
    _image = new Pixel*[_rows];
    for(int r = 0; r < _rows; r++)
    {
        _image[r] = new Pixel[_cols];
        for(int c = 0; c < _cols; c++)
        {
        //set each pixel to white
            _image[r][c] = {255, 255, 255};
        }
    }
}

//function to clone another emoticon object
void Emoticon::clone(const Emoticon& objOriginal)
{
    assert(_image != nullptr && objOriginal._image != nullptr);
    for(int r = 0; r < _rows; r++)
    {
        for(int c = 0; c < _cols; c++)
        {
            _image[r][c] = objOriginal._image[r][c];
        }
    }
}

//deallocation of memory to prevent memory leaks
void Emoticon::dealloc()
{
    assert(_image != nullptr);
    for(int r = 0; r < _rows; r++)
        delete [] _image[r];
    delete [] _image;
}


void Emoticon::enforceRange(int intValue, int intMin, int intMax) const
{
    if(intValue < intMin || intValue > intMax)
    {
        cerr << intValue << " must be in [" << intMin << ", " << intMax << "]" << endl;
        exit(ERROR_RANGE);
    }
}

//getters
int Emoticon::getRows() const
{
    return _rows;
}

int Emoticon::getCols() const
{
    return _cols;
}

//Function to give a pixel a ceratin colour
void Emoticon::setPixel(int intRow, int intCol, Pixel recPixel)
{
    enforceRange(intRow, 0, _rows - 1);
    enforceRange(intCol, 0, _cols - 1);
    _image[intRow][intCol] = recPixel;
}

//function to help with the radius calculation of circle
double Emoticon::distance(int intR1, int intR2, int intC1, int intC2) const
{
    return sqrt(pow(intR1 - intR2, 2) + pow(intC1 - intC2, 2));
}
