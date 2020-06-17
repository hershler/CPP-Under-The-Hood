#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__

/*/// Box ///////////*/

typedef struct{
    double length;
    double width;
    double height;
}Box;


void _Z3BoxCE(Box* b);
void _Z3BoxCEd(Box* b, double dim);
void _Z3BoxCEddd(Box* b, double l, double w, double h);
void _Z3BoxCEBox(Box* b, Box* another);
Box* _Z3Box14assignOperatorFEBox(Box* b,const  Box* another);
void _Z3BoxDE(Box* b);

Box* _Z3Box18operatorMultAssignFEd(Box* b, double mult);


void _Z3Box5printFE(const Box* b);


/*/// Box Defs ///////////*/



/*/// Shelf ///////////*/

extern const char* _Z5Shelf7messageVE;

typedef struct {
    Box _Z5Shelf5boxesVE[3];
}Shelf;

void _Z5ShelfCE(Shelf* s);
void _Z5ShelfDE(Shelf* s);
void _Z5Shelf6setBoxFEikBox(Shelf* s, int index, const Box* dims);
double _Z5Shelf9getVolumeFE(const Shelf* s);
void _Z5Shelf5printFE(const Shelf* s);



/*/// Shelf Defs ///////////*/

#endif /* __CPP2C_ENCAPSULATION_DEFS_H__*/

