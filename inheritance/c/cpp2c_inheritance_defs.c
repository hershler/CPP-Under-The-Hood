#include <stdio.h>
#include "cpp2c_inheritance_defs.h"
#include <string.h>


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
    memcpy((void*)_this + sizeof(Box), (void*)other + sizeof(Box), sizeof(PhysicalBox) - sizeof(Box));

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


/*// WeightBox Defs ///////////*/


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


