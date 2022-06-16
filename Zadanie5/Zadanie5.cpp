// Zadanie5.cpp : Ilona Topol, D3
//

#define _CRT_SECURE_NO_WARNINGS
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
    const char* nazwa_pliku;

    if (nullptr == argv[1])
        nazwa_pliku = "test.bmp";
    else
        nazwa_pliku = argv[1];

    FILE* f = fopen(nazwa_pliku, "rb");

    if (f == nullptr) {
        cout << "Blad! Problem z otwarciem pliku" << endl;
    }
    else {
        cout << "Informacje o pliku:" << endl << endl;

        fread(&bmp_header.name, 2, 1, f);
        fread(&bmp_header.size, sizeof(bmp_header.size), 1, f);
        fread(&bmp_header.reserved_1, sizeof(bmp_header.reserved_1), 1, f);
        fread(&bmp_header.reserved_2, sizeof(bmp_header.reserved_2), 1, f);
        fread(&bmp_header.offset, sizeof(bmp_header.offset), 1, f);

        cout << "Pierwsze dwa znaki :" << (char)bmp_header.name[0] << bmp_header.name[1] << "\n";
        cout << "Rozmiar pkiku: " << bmp_header.size << " bajtow\n";
        cout << "Zarezerwowane 1: " << bmp_header.reserved_1 << "\n";
        cout << "Zarezerwowane 2: " << bmp_header.reserved_1 << "\n";
        cout << "Offset: " << bmp_header.offset << "\n";

        fread(&dib_header, sizeof(struct DIB_header), 1, f);

        cout << "Wielkosc naglowka informacyjnego: " << dib_header.headerSize << "\n";
        cout << "Szerokosc obrazu: " << dib_header.width << "px\n";
        cout << "Wysokosc obrazu: " << dib_header.height << " px\n";
        cout << "Liczba warstw kolorow: " << dib_header.planes << "\n";
        cout << "Liczba bitow na piksel: " << dib_header.bitPerPixel << "\n";
        cout << "Algorytm kompresji: " << dib_header.compresion << "\n";
        cout << "Rozmiar samego rysunku: " << dib_header.imageSize << "\n";
        cout << "Rozdzielczosc pozioma: " << dib_header.xPelsPerMeter << "\n";
        cout << "Rozdzielczosc pionowa: " << dib_header.yPelsPerMeter << "\n";
        cout << "Liczba kolorow w palecie: " << dib_header.colorUsed << "\n";
        cout << "Liczba waznych kolorow w palecie: " << dib_header.colorImportant << "\n";

        fclose(f);
    }
   return 0;
}
