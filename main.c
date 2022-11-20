#include <stdio.h>
#include <assert.h>
#include "ColorCoding.h"

const int MAX_COLORPAIR_NAME_CHARS = 16;

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

    ColorPair colorPair;
    printf("PRINTING MANUAL\n");
    for(int i =1 ;i<26;i++)
    {
        colorPair = GetColorFromPairNumber(i);
        printf("majorcolor-%s,minorcolor-%s,%d-pairNumber\n",MajorColorNames[colorPair.majorColor],MinorColorNames[colorPair.minorColor],i);
    }
    printf("DO TEST VERIFICATION\n");
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    return 0;
}
