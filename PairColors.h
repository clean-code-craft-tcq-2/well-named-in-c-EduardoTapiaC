#ifndef PAIRCOLORS_H
#define PAIRCOLORS_H

#define MAX_COLORPAIRS 25
#define MAX_COLORPAIR_NAME_CHARS 16 //precompiled, less space and visible in header   

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET, INVALID_MAJOR};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE, INVALID_MINOR};

typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(const ColorPair* colorPair);
void ColorPairToString(const ColorPair* colorPair, char* buffer);
void PrintColorCodeManual();
#endif