#include <stdio.h>
#include "cpp2c_inheritance_defs.h"


void doMaterials()
{
    Material_t mat1, mat2;
    Materials mat;
    typedef struct MatTest { Materials mat; Material_t mat_t; }MatTest;

    printf("\n--- Start doMaterials() ---\n\n");

    printf("Size of Materials: %lu\n", sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(Materials));
    printf("Size of Materials::Types: %lu\n", sizeof(enum Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));


    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest));

    (&mat1)->material = OTHER;

    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[(&mat1)->material]);
    }

    (&mat2)->material = METAL;

    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[(&mat2)->material]);
    }

    printf("\n--- End doMaterials() ---\n\n");
}

void doPhysicalBox()
{
    PhysicalBox pb1, pb2, pb3, pb4;

    printf("\n--- Start doPhysicalBox() ---\n\n");

    _Z11PhysicalBoxCEdddTypes(&pb1, 8, 6, 4, PLASTIC);
    _Z11PhysicalBoxCETypes(&pb2, WOOD);
    _Z11PhysicalBoxCEdddTypes(&pb3, 7, 7, 7, OTHER);
    
    printf("\npb4 is copy-constructed from pb1\n");
    _Z11PhysicalBoxCEPhysicalBox(&pb4, &pb1);
    _Z11PhysicalBox6printpFE(&pb4);
    _Z11PhysicalBox6printpFE(&pb1);
    printf("pb4 %s pb1\n", ((const Box*)(&pb4))->width == ((const Box*)(&pb1))->width &&
                           ((const Box*)(&pb4))->height == ((const Box*)(&pb1))->height && ((const Box*)(&pb4))->length == ((const Box*)(&pb1))->length &&
                           pb4.material.material == pb1.material.material ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    _Z11PhysicalBox14assignOperatorFEPhysicalBox(&pb4, &pb3);
    _Z11PhysicalBox6printpFE(&pb4);
    _Z11PhysicalBox6printpFE(&pb3);
    printf("pb4 %s pb3\n", ((const Box*)(&pb4))->width == ((const Box*)(&pb3))->width &&
            ((const Box*)(&pb4))->height == ((const Box*)(&pb3))->height && ((const Box*)(&pb4))->length == ((const Box*)(&pb3))->length &&
            pb4.material.material == pb3.material.material ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
    _Z11PhysicalBoxDE(&pb4);
    _Z11PhysicalBoxDE(&pb3);
    _Z11PhysicalBoxDE(&pb2);
    _Z11PhysicalBoxDE(&pb1);

}

void doWeightBox()
{
    WeightBox pw1, pw2, pw3, pw4;

    printf("\n--- Start doWeightBox() ---\n\n");

    _Z9WeightBoxCEdddd(&pw1, 8, 6, 4, 25);
    _Z9WeightBoxCEdddd(&pw2, 1, 2, 3, 0.0);
    _Z9WeightBoxCEdddd(&pw3, 10, 20, 30, 15);
    
    printf("\npw4 is copy-constructed from pw1\n");
    _Z9WeightBoxCEWeightBox(&pw4, &pw1);
    _Z9WeightBox6printwFE(&pw4);
    _Z9WeightBox6printwFE(&pw1);
    printf("pw4 %s pw1\n", ((const Box*)&pw4)->width == ((const Box*)(&pw1))->width &&
                            ((const Box*)(&pw4))->height == ((const Box*)(&pw1))->height &&
                            ((const Box*)(&pw4))->length == ((const Box*)(&pw1))->length &&
                            pw4.weight == pw1.weight ? "equals" : "does not equal");

     printf("\npw4 is copy-assigned from pw3\n");
    _Z9WeightBox14operatorAssignFEWheightBox(&pw4, &pw3);
    _Z9WeightBox6printwFE(&pw4);
    _Z9WeightBox6printwFE(&pw3);
    printf("pw4 %s pw3\n",  ((const Box*)&pw4)->width == ((const Box*)(&pw3))->width &&
                            ((const Box*)(&pw4))->height == ((const Box*)(&pw3))->height &&
                            ((const Box*)(&pw4))->length == ((const Box*)(&pw3))->length &&
                            pw4.weight == pw3.weight ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
    _Z9WeightBoxDE(&pw4);
    _Z9WeightBoxDE(&pw3);
    _Z9WeightBoxDE(&pw2);
    _Z9WeightBoxDE(&pw1);
}





int main()
{
    printf("\n--- Start main() ---\n\n");

    doMaterials();

    doPhysicalBox();

    doWeightBox();

    printf("\n--- End main() ---\n\n");

}
