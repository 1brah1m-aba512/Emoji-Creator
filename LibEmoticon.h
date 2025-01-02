#ifndef LIBEMOTICON_H_INCLUDED
#define LIBEMOTICON_H_INCLUDED

#include <string>

enum StatusCode
{
    ERROR_RANGE = -1,
    SUCCESS
};

struct Pixel
{
    int intRed;
    int intGreen;
    int intBlue;
};

class Emoticon
{
public:
    Emoticon(); // Default (No-Args) Constructor.
    Emoticon(int intRows, int intCols); // Parameterized Constructor.
    Emoticon(const Emoticon& objOriginal); // Copy constructor.
    ~Emoticon(); // Destructor.

    // Accessors and Mutators.
    int getRows() const;
    int getCols() const;
    void setPixel(int intRow, int intCol, Pixel recPixel);
    std::string toPMM() const;
    void drawCircle(int intRow, int intCol, double dblRadius, Pixel recColour); // Method to draw a circle
    void drawRect(int intRow,int intCol,int intLength,int intBreadth,Pixel recColour); //Method to draw Rectangle
    // Class constants.
    static const int ROWS = 680;
    static const int COLS = 480;
    static const int MIN_ROWS = 2;
    static const int MIN_COLS = 2;

private:
    // Helper/utility/ancillary functions.
    void alloc(int intRows, int intCols);
    void clone(const Emoticon& objOriginal);
    void dealloc();
    void enforceRange(int intValue, int intMin, int intMax) const;
    double distance(int intR1, int intR2, int intC1, int intC2) const;
    // State (member variables).
    int _rows;
    int _cols;
    Pixel** _image;
};

#endif // LIBEMOTICON_H_INCLUDED
