#ifndef __CPP2C_INHERITANCE_DEFS_H__
#define __CPP2C_INHERITANCE_DEFS_H__

#include <cstdio>
#include "cpp2c_encapsulation_defs.h"

//// Materials ////////////

enum Types
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
};


/*inline const char* _Z9Materials7getNameFETypes(enum Types type)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    return names[type];
}*/

struct Material_t
{
    enum Types material;
};

Material_t* _Z10Material_t14assignOperator(Material_t* _this, const Material_t* other);

/*inline void _Z10Material_tCETypes(Material_t* _this, enum Types mat){

    _this->material = mat;

    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[_this->material]);
    }
}

inline const char* _Z10Material_t4nameFE(const Material_t* _this){
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        return names[_this->material];
    }
}*/


//// PhysicalBox ////////////


struct PhysicalBox{
    Box m_b;
    Material_t material;
};

void _Z11PhysicalBoxCEddd(PhysicalBox* _this, double l, double w, double h);
void _Z11PhysicalBoxCEdddTypes(PhysicalBox* _this, double l, double w, double h, enum Types t);
void _Z11PhysicalBoxCETypes(PhysicalBox* _this, enum Types t);
void _Z11PhysicalBoxCEPhysicalBox(PhysicalBox* _this, PhysicalBox* other);
PhysicalBox* _Z11PhysicalBox14assignOperatorFEPhysicalBox(PhysicalBox* _this, const PhysicalBox* other);
void _Z11PhysicalBoxDE(PhysicalBox* _this);

//enum Types _Z11PhysicalBox11getMaterialFE(const PhythicalBox* _this);(inline)
void _Z11PhysicalBox6printpFE(const PhysicalBox* _this);


//bool operator==(const PhysicalBox&, const PhysicalBox&);(inline)
//bool operator!=(const PhysicalBox&, const PhysicalBox&);(inline)

//// PhysicalBox Defs ////////////

/*inline Materials::Types PhysicalBox::getMaterial() const
{
    return material.material;
}

inline bool operator==(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return (const Box*)lhs == (const Box*)rhs && lhs.material.material == rhs.material.material;
}

inline bool operator!=(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return !(lhs == rhs);
}*/

//////  WeightBox  /////


struct WeightBox{
    Box m_b;
    double weight;
};

void _Z9WeightBoxCEdddd(WeightBox* _this, double l, double w, double h, double wgt);
void _Z9WeightBoxCEWeightBox(WeightBox* _this, const WeightBox* other);
void _Z9WeightBoxDE(WeightBox* _this);

WeightBox* _Z9WeightBox14operatorAssignFEWheightBox(WeightBox* _this, const WeightBox* other);

//double getWeight() const;(inline)
void _Z9WeightBox6printwFE(const WeightBox* _this);


//bool operator==(const WeightBox&, const WeightBox&);(inline)
//bool operator!=(const WeightBox&, const WeightBox&);(inline)

//// WeightBox Defs ////////////

/*inline double WeightBox::getWeight() const
{
    return weight;
}

inline bool operator==(const WeightBox& lhs, const WeightBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getWeight() == rhs.getWeight();
}

inline bool operator!=(const WeightBox& lhs, const WeightBox& rhs)
{
    return !(lhs == rhs);
}*/









#endif // __CPP2C_INHERITANCE_DEFS_H__


