#include <stdio.h>
#include "PairColors.h"

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet", "Invalid"};
int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]) - 1;

const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate", "Invalid"};
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]) - 1;

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    //handle invalid data because it may cause unwanted result
    if(pairNumber < 0 || pairNumber > MAX_COLORPAIRS) {
        colorPair.majorColor = INVALID_MAJOR;
        colorPair.minorColor = INVALID_MINOR;
        return colorPair;
    }
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    int pairNumber = colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1;
    //handle invalid data because it may cause unwanted result
    if(pairNumber < 0 || pairNumber > MAX_COLORPAIRS) {
        return -1;
    }
    return pairNumber;
}

void PrintColorCodeManual() {
    int pairNumber = 1;
    for(int MajorColor = 0; MajorColor < numberOfMajorColors; MajorColor++) {
        for(int MinorColor = 0; MinorColor < numberOfMinorColors; MinorColor++) {
            printf("pair number %i: %s-%s \n", pairNumber, MajorColorNames[MajorColor], MinorColorNames[MinorColor]);
            pairNumber++;
        }
    }
}
