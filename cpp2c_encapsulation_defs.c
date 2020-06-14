#include "cpp2c_encapsulation_defs.h"
#include <stdio.h>
//// Box ////////////

Box ctor(double dim){
    Box b;
    b->length = dim;
    b->width = dim;
    b->height = dim;
    printBox(b);
    return b;
}

Box ctor(double l, double w, double h) {
    Box b;
    b.length = l;
    b.width = w;
    b.height = h;
    printBox(b);
    return b;
}

void dtor(Box& b)
{
    printf("Box destructor, %f x %f x %f\n", b->width, b->height, b->length);
}

Box* operator*=(Box* b, double mult)
{
    b->width *= mult;
    b->height *= mult;
    b->length *= mult;

    return b;
}

void printBox(const Box* b)
{
    printf("Box: %f x %f x %f\n", b->length, b->width, b->height);
}


//// Shelf ////////////

const char* const DEF_MSG = "The total volume held on the shelf is";
const char* message = DEF_MSG;

void setBox(Shelf* s, int index, const Box* dims)
{
    s->boxes[index] = dims;
}

double getVolume(const Shelf* s)
{
    double vol = 0;
    for (size_t i = 0; i < s->NUM_BOXES; ++i)
        vol += s->boxes[i].width * s->boxes[i]length * s->boxes[i]height;

    return vol;
}

void printShelf(const Shelf* s)
{
    printf("%s %f\n", s->message, getVolume(s));
}



