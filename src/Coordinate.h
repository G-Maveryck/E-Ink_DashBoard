/*
    Generic struct to store coordinate of partials windows.
    This is instanciate in the Display class for the various partials windows,
    such as "air Temperature" or th "fuel gauge"
*/

#ifndef COORDINATE_H
#define COORDINATE_H

struct Coordinate
{
    int x;
    int y;
    int width;
    int height;
};

#endif