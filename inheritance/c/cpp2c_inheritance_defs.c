#include <string.h>
#include "cpp2c_inheritance_defs.h"


/* Box  */

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

void _Z3BoxCEBox(Box* b, Box* other){
    *b = *other;
}

const Box* const _Z3Box14assignOperatorFEBox(Box* b, const Box* const other){
    *b = *other;
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


/* Shelf */


void _Z5ShelfCE(Shelf* s){}

void _Z5ShelfDE(Shelf* s)
{
    _Z3BoxDE(&s->_Z5Shelf5boxesVE[2]);
    _Z3BoxDE(&s->_Z5Shelf5boxesVE[1]);
    _Z3BoxDE(&s->_Z5Shelf5boxesVE[0]);
}

const char* _Z5Shelf7messageVE = "The total volume held on the shelf is";


void _Z5Shelf6setBoxFEikBox(Shelf* s, int index, const Box* dims)
{
    _Z3Box14assignOperatorFEBox(&(s->_Z5Shelf5boxesVE[index]), dims);
}

double _Z5Shelf9getVolumeFE(const Shelf* s)
{
    double vol = 0;
    size_t i;

    for (i = 0; i < 3; ++i)
        vol += s->_Z5Shelf5boxesVE[i].width * s->_Z5Shelf5boxesVE[i].length * s->_Z5Shelf5boxesVE[i].height;

    return vol;
}

void _Z5Shelf5printFE(const Shelf* s)
{
    printf("%s %f\n", _Z5Shelf7messageVE, _Z5Shelf9getVolumeFE(s));
}

/*the code above is taken from encasulation directory in order to make the tests easy*/


/*Materials*/

void _Z9MaterialsCE(Materials* _this){}
void _Z9MaterialsDE(Materials* _this){}


/*Material_t*/

Material_t* _Z10Material_t14assignOperator(Material_t* _this, const Material_t* other){
    _this->material = other->material;
    return _this;
}

void _Z11Material_tCE(Material_t* _this){
    _Z9MaterialsCE((Materials*)_this);
}

void _Z11Material_tDE(Material_t* _this){
    _Z9MaterialsDE((Materials*)_this);
}


/*   PhysicalBox Defs   */

void _Z11PhysicalBoxCEddd(PhysicalBox* _this, double l, double w, double h){
    _Z3BoxCEddd((Box*)_this, l, w, h);
    _this->material.material = OTHER;

    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[_this->material.material]);
    }
    _Z11PhysicalBox6printpFE(_this);
}

void _Z11PhysicalBoxCEdddTypes(PhysicalBox* _this, double l, double w, double h,  Types t){
    _Z3BoxCEddd((Box*)_this, l, w, h);
    _this->material.material = t;

    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[_this->material.material]);
    }

    _Z11PhysicalBox6printpFE(_this);
}

void _Z11PhysicalBoxCETypes(PhysicalBox* _this,  Types t)
{
    _Z3BoxCEd(((Box*)_this), 1);
    _this->material.material = t;

    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[_this->material.material]);
    }

    _Z11PhysicalBox6printpFE(_this);
}

void _Z11PhysicalBoxCEPhysicalBox(PhysicalBox* _this, PhysicalBox* other){
    _Z3BoxCEBox((Box*)_this, (Box*)other);
    memcpy((char*)_this + sizeof(Box), (char*)other + sizeof(Box), sizeof(PhysicalBox) - sizeof(Box));

}

PhysicalBox* _Z11PhysicalBox14assignOperatorFEPhysicalBox(PhysicalBox* _this, const PhysicalBox* other){
    _Z3Box14assignOperatorFEBox((Box*)_this, (Box*)other);
    _Z10Material_t14assignOperator(&(_this->material), &(other->material));
    return _this;
}

void _Z11PhysicalBoxDE(PhysicalBox* _this){
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("PhysicalBox dtor, %f x %f x %f, %s; ", _this->m_b.length, _this->m_b.width, _this->m_b.height, names[_this->material.material]);
    }
    _Z3BoxDE((Box*)_this);
}

void _Z11PhysicalBox6printpFE(const PhysicalBox* _this)
{
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("PhysicalBox, made of %s; ", names[_this->material.material]);
    }
    _Z3Box5printFE((Box*)_this);
}


/* WeightBox Defs */


void _Z9WeightBoxCEdddd(WeightBox* _this, double l, double w, double h, double wgt){

    _Z3BoxCEddd((Box*)_this, l, w, h);
    _this->weight = wgt;
    _Z9WeightBox6printwFE(_this);
}

void _Z9WeightBoxCEWeightBox(WeightBox* _this, const WeightBox* other)
{
    _Z3BoxCE((Box*)_this);
    _this->weight = other->weight;
    _Z9WeightBox6printwFE(_this);
}

void _Z9WeightBoxDE(WeightBox* _this)
{
    printf("Destructing WeightBox; ");
    _Z9WeightBox6printwFE(_this);
    _Z3BoxDE((Box*)_this);
}

WeightBox* _Z9WeightBox14operatorAssignFEWheightBox(WeightBox* _this, const WeightBox* other)
{
    _this->weight = other->weight;
    return _this;
}

void _Z9WeightBox6printwFE(const WeightBox* _this)
{
    printf("WeightBox, weight: %f; ", _this->weight);
    _Z3Box5printFE((Box*)_this);
}


