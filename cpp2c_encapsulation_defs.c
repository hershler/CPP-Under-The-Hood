#include "cpp2c_encapsulation_defs.h"
#include <stdio.h>
//// Box ////////////


void _Z3BoxCE(Box* b){
    b->length = 1;
    b->width = 1;
    b->height = 1;
    _Z3Box5printFE(b);
}

void _Z3BoxCEd(Box* b, double dim){
    b->length = dim;
    b->width = dim;
    b->height = dim;
    _Z3Box5printFE(b);
}

void _Z3BoxCEddd(Box* b, double l, double w, double h) {
    b->length = l;
    b->width = w;
    b->height = h;
    _Z3Box5printFE(b);
}

void _Z3BoxCEBox(Box* b, Box* another){
    *b = *another;
}

Box* _Z3Box14assignOperatorFEBox(Box* b, Box* another){
    *b = *another;
    return b;
}

void _Z3BoxDE(Box* b)
{
    printf("Box destructor, %f x %f x %f\n", b->width, b->height, b->length);
}

Box* _Z3Box18operatorMultAssignFEd(Box* b, double mult)
{
    b->width *= mult;
    b->height *= mult;
    b->length *= mult;

    return b;
}

void _Z3Box5printFE(const Box* b)
{
    printf("Box: %f x %f x %f\n", b->length, b->width, b->height);
}


//// Shelf ////////////


void _Z5ShelfCE(Shelf* s){}

void _Z5ShelfDE(Shelf* s){}

const char* _Z5Shelf7messageVE = "The total volume held on the shelf is";


void _Z5Shelf6setBoxFEikBox(Shelf* s, int index, const Box* dims)
{
    s->_Z5Shelf5boxesVE[index] = *dims;
}

double _Z5Shelf9getVolumeFE(const Shelf* s)
{
    double vol = 0;
    for (size_t i = 0; i < 3; ++i)
        vol += s->_Z5Shelf5boxesVE[i].width * s->_Z5Shelf5boxesVE[i].length * s->_Z5Shelf5boxesVE[i].height;

    return vol;
}

void _Z5Shelf5printFE(const Shelf* s)
{
    printf("%s %f\n", _Z5Shelf7messageVE, _Z5Shelf9getVolumeFE(s));
}



