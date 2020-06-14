#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

static Box largeBox = ctor(10, 20, 30);

void thisFunc()
{
    std::printf("\n--- thisFunc() ---\n\n"); 
    static Box box99 = ctor(99, 99, 99);
    operator*=(box99, 10);
}

void thatFunc()
{
    std::printf("\n--- thatFunc() ---\n\n"); 
    static Box box88 = ctor(88, 88, 88);
    operator*=(box88, 10);
}

void doBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");

    Box b1 = ctor(3);
    Box b2 = ctor(4, 5, 6);
    
    printf("b1 volume: %f\n", b1->width * b1->length * b1->height);
    printf("b2 volume: %f\n", b2->width * b2->length * b2->height);

    operator*=(b1, 1.5);
    operator*=(b2, 0.5);

    printf("b1 volume: %f\n", b1->width * b1->length * b1->height);
    printf("b2 volume: %f\n",  b2->width * b2->length * b2->height);

    Box b3 = b2;
    Box b4 = operator*=(Box b0 = b1, 3);
    printf("b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    operator*=(b3, 1.5);
    operator*=(b4, 0.5);
    printf("Now, b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");
    dtor(&b1);
    dtor(&b2);
    dtor(&b3);
    dtor(&b4);
}


void doShelves()
{
    printf("\n--- start doShelves() ---\n\n");

    Box aBox = 5;

    Shelf aShelf;

    printShelf(&aShelf);
    setBox(&aShelf, 1, largeBox);
    setBox(&aShelf, 0, aBox);

    printShelf(&aShelf);
    aShelf.message = "This is the total volume on the shelf:";
    printShelf(&aShelf);
    Shelf.message = "Shelf's volume:";
    printShelf(&aShelf);

    setBox(&aShelf, 1, ctor(2, 4, 6));

    setBox(&aShelf, 2, 2);
    printShelf(&aShelf);

    printf("\n--- end doShelves() ---\n\n");
    dtor(&aBox);
}

int main()
{
    std::printf("\n--- Start main() ---\n\n");

    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();
    thatFunc();
    thatFunc();

    doShelves();
        
    std::printf("\n--- End main() ---\n\n");

    return 0;
}

