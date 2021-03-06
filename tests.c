#include <stdio.h>
#include <assert.h>
#include "PairColors.h"

void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}


int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
    testNumberToPair(-1, INVALID_MAJOR, INVALID_MINOR);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(INVALID_MAJOR, INVALID_MINOR, -1);
    testPairToNumber(VIOLET, SLATE, 25);
    PrintColorCodeManual();
    return 0;
}
