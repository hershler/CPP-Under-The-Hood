#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

static Box largeBox;
int isBox99 = 0;
int isBox88 = 0;

void thisFunc()
{
    static Box box99;

    if(isBox99 == -1){
        _Z3BoxDE(&box99);
        return;
    }
    printf("\n--- thisFunc() ---\n\n");

    if(!isBox99) {
        _Z3BoxCEddd(&box99, 99, 99, 99);
        isBox99 = 1;
    }
    _Z3Box18operatorMultAssignFEd(&box99, 10);
}

void thatFunc()
{
    static Box box88;

    if(isBox88 == -1){
        _Z3BoxDE(&box88);
        return;
    }
    printf("\n--- thatFunc() ---\n\n");

    if(!isBox88) {
        _Z3BoxCEddd(&box88, 88, 88, 88);
        isBox88 = 1;
    }
    _Z3Box18operatorMultAssignFEd(&box88, 10);
}

void doBoxes()
{
    Box b1, b2, b3, b4, ret;

    printf("\n--- Start doBoxes() ---\n\n");

    _Z3BoxCEd(&b1, 3);
    _Z3BoxCEddd(&b2, 4, 5, 6);
    
    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    _Z3Box18operatorMultAssignFEd(&b1, 1.5);
    _Z3Box18operatorMultAssignFEd(&b2, 0.5);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n",  b2.width * b2.length * b2.height);

    _Z3BoxCEBox(&b3, &b2);

    _Z3BoxCEBox(&ret, &b4);
    _Z3Box18operatorMultAssignFEd(&ret, 3);
    _Z3BoxCEBox(&b4, &ret);
    _Z3BoxDE(&ret);
    printf("b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    _Z3Box18operatorMultAssignFEd(&b3, 1.5);
    _Z3Box18operatorMultAssignFEd(&b4, 0.5);
    printf("Now, b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");
    _Z3BoxDE(&b1);
    _Z3BoxDE(&b2);
    _Z3BoxDE(&b3);
    _Z3BoxDE(&b4);
}


void doShelves()
{
    Box aBox, temp1, temp2;
    Shelf aShelf;

    printf("\n--- start doShelves() ---\n\n");

    _Z3BoxCEd(&aBox, 5);

    _Z5ShelfCE(&aShelf);

    _Z5Shelf5printFE(&aShelf);
    _Z5Shelf6setBoxFEikBox(&aShelf, 1, &largeBox);
    _Z5Shelf6setBoxFEikBox(&aShelf, 0, &aBox);
    _Z5Shelf5printFE(&aShelf);
    _Z5Shelf7messageVE = "This is the total volume on the shelf:";
    _Z5Shelf5printFE(&aShelf);
    _Z5Shelf7messageVE = "Shelf's volume:";
    _Z5Shelf5printFE(&aShelf);

    _Z3BoxCEddd(&temp1, 2, 4, 6);
    _Z5Shelf6setBoxFEikBox(&aShelf, 1, &temp1);
    _Z3BoxDE(&temp1);

    _Z3BoxCEddd(&temp2, 2, 4, 6);
    _Z5Shelf6setBoxFEikBox(&aShelf, 2, &temp2);
    _Z3BoxDE(&temp2);
    _Z5Shelf5printFE(&aShelf);

    printf("\n--- end doShelves() ---\n\n");
    _Z3BoxDE(&aBox);
    _Z5ShelfDE(&aShelf);
}

/*int main()
{

    _Z3BoxCEddd(&largeBox, 10, 20, 30);

    printf("\n--- Start main() ---\n\n");

    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();
    thatFunc();
    thatFunc();

    doShelves();

    printf("\n--- End main() ---\n\n");
    _Z3BoxDE(&largeBox);
    if(isBox99){
        isBox99 = -1;
        thisFunc();
    }
    if(isBox88){
        isBox88 = -1;
        thisFunc();
    }
    return 0;
}*/

