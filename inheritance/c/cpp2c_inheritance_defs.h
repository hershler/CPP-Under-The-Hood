#ifndef __CPP2C_INHERITANCE_DEFS_H__
#define __CPP2C_INHERITANCE_DEFS_H__

#include <stdio.h>


/* Box */

typedef struct{
    double length;
    double width;
    double height;
}Box;


void _Z3BoxCE(Box* b);
void _Z3BoxCEd(Box* b, double dim);
void _Z3BoxCEddd(Box* b, double l, double w, double h);
void _Z3BoxCEBox(Box* b, Box* other);
const Box* const _Z3Box14assignOperatorFEBox(Box* b, const Box* const other);
void _Z3BoxDE(Box* b);

Box* _Z3Box18operatorMultAssignFEd(Box* b, double mult);


void _Z3Box5printFE(const Box* b);


/* Shelf */

extern const char* _Z5Shelf7messageVE;

typedef struct {
    Box _Z5Shelf5boxesVE[3];
}Shelf;

void _Z5ShelfCE(Shelf* s);
void _Z5ShelfDE(Shelf* s);
void _Z5Shelf6setBoxFEikBox(Shelf* s, int index, const Box* dims);
double _Z5Shelf9getVolumeFE(const Shelf* s);
void _Z5Shelf5printFE(const Shelf* s);

/*the code above is taken from encasulation directory in order to make the tests easy*/


/*   Materials     */

typedef struct Materials{}Materials;

typedef enum Types
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Types;

void _Z9MaterialsCE(Materials* _this);
void _Z9MaterialsDE(Materials* _this);


typedef struct Material_t
{
     Materials m_mat;
     Types material;
}Material_t;

void _Z11Material_tCE(Material_t* _this);
void _Z11Material_tDE(Material_t* _this);

Material_t* _Z10Material_t14assignOperator(Material_t* _this, const Material_t* other);


/*  PhysicalBox   */


typedef struct PhysicalBox{
    Box m_b;
    Material_t material;
}PhysicalBox;

void _Z11PhysicalBoxCEddd(PhysicalBox* _this, double l, double w, double h);
void _Z11PhysicalBoxCEdddTypes(PhysicalBox* _this, double l, double w, double h,  Types t);
void _Z11PhysicalBoxCETypes(PhysicalBox* _this,  Types t);
void _Z11PhysicalBoxCEPhysicalBox(PhysicalBox* _this, PhysicalBox* other);
PhysicalBox* _Z11PhysicalBox14assignOperatorFEPhysicalBox(PhysicalBox* _this, const PhysicalBox* other);
void _Z11PhysicalBoxDE(PhysicalBox* _this);

void _Z11PhysicalBox6printpFE(const PhysicalBox* _this);




/*  WeightBox  */


typedef struct WeightBox{
    Box m_b;
    double weight;
}WeightBox;

void _Z9WeightBoxCEdddd(WeightBox* _this, double l, double w, double h, double wgt);
void _Z9WeightBoxCEWeightBox(WeightBox* _this, const WeightBox* other);
void _Z9WeightBoxDE(WeightBox* _this);

WeightBox* _Z9WeightBox14operatorAssignFEWheightBox(WeightBox* _this, const WeightBox* other);

void _Z9WeightBox6printwFE(const WeightBox* _this);



#endif /* __CPP2C_INHERITANCE_DEFS_H__*/


