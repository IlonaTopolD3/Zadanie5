// Zadanie5.cpp : Ilona Topol, D3
//

#include <iostream>

using namespace std;

struct BMP_header
{
    char name[2];
    unsigned int size;
    unsigned short int reserved_1;
    unsigned short int reserved_2;
    unsigned int offset;
}bmp_header;

struct DIB_header {
    unsigned int headerSize;
    unsigned int width;
    unsigned int height;
    unsigned short int planes;
    unsigned short int bitPerPixel;
    unsigned int compresion;
    unsigned int imageSize;
    unsigned int xPelsPerMeter;
    unsigned int yPelsPerMeter;
    unsigned int colorUsed;
    unsigned int colorImportant;

}dib_header;


int main(int argc, char* argv[])
{
   return 0;
}
