#ifndef __CPP2C_INHERITANCE_DEFS_H__
#define __CPP2C_INHERITANCE_DEFS_H__

#include <cstdio>


/*Box */

class Box
{
public:
    Box(double dim = 1);
    Box(double l, double w, double h);
    ~Box();

    double getWidth() const;
    double getLength() const;
    double getHeight() const;

    double getVolume() const;
    
    Box& operator*=(double mult);

protected:
    void print() const;

private:    
    double length;
    double width;
    double height;
};

Box operator*(const Box& box, double mult);
Box operator*(double mult, const Box& box);
bool operator==(const Box& lhs, const Box& rhs);
bool operator!=(const Box& lhs, const Box& rhs);


/* Box Defs */

inline double Box::getWidth() const
{
    return width;
}

inline double Box::getLength() const
{
    return length;
}

inline double Box::getHeight() const
{
    return height;
}

inline double Box::getVolume() const
{
    return width * length * height;
}

inline Box operator*(const Box& box, double mult)
{
    Box ret = box;
    ret *= mult;
    return ret;
}

inline Box operator*(double mult, const Box& box)
{
    return box * mult;
}

inline bool operator==(const Box& lhs, const Box& rhs)
{
    return lhs.getWidth() == rhs.getWidth() && lhs.getHeight() == rhs.getHeight() && lhs.getLength() == rhs.getLength();
}

inline bool operator!=(const Box& lhs, const Box&rhs)
{
    return !(lhs == rhs);
}


/* Shelf */

class Shelf
{
public:
    void setBox(int index, const Box& dims);
    double getVolume() const;
    Box& getBox(int index);
    void print() const;
    
    static int getNumBoxes();
    static void setMessage(const char* msg);
    
private:
    static const unsigned int NUM_BOXES = 3;
    static const char* const DEF_MSG;
    static const char* message;

    Box boxes[NUM_BOXES];
};

/* Shelf Defs */

inline Box& Shelf::getBox(int index)
{
    return boxes[index];
}

inline int Shelf::getNumBoxes()
{
    return NUM_BOXES;
}

inline void Shelf::setMessage(const char* msg)
{
    message = msg;
}

/*the code above is taken from encasulation directory in order to make the tests easy*/

/* Materials */

struct Materials
{
    enum Types
    {
        PLASTIC,
        METAL,
        WOOD,
        PAPER,
        OTHER
    };

    static const char* getName(Types type)
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        return names[type];
    }
};

struct Material_t: public Materials
{
    Material_t(Types mat = OTHER): material(mat) { printf("Material created, set to %s\n", name()); }
    const char* name() const { return getName(material); }

    Types material;
};


/* PhysicalBox */

class PhysicalBox: public Box
{
public:
    PhysicalBox(double l, double w, double h);
    PhysicalBox(double l, double w, double h, Materials::Types t);
    PhysicalBox(Materials::Types t);
    ~PhysicalBox();

    Materials::Types getMaterial() const;
    void printp() const;

private:
    Material_t material;
};

bool operator==(const PhysicalBox&, const PhysicalBox&);
bool operator!=(const PhysicalBox&, const PhysicalBox&);

/* PhysicalBox Defs */

inline Materials::Types PhysicalBox::getMaterial() const
{
    return material.material;
}

inline bool operator==(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getMaterial() == rhs.getMaterial();
}

inline bool operator!=(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return !(lhs == rhs);
}

/* WeightBox */

class WeightBox: public Box
{
public:
    WeightBox(double l, double w, double h, double wgt = 0.0);
    WeightBox(const WeightBox& other);
    ~WeightBox();

    WeightBox& operator=(const WeightBox& other);

    double getWeight() const;
    void printw() const;

private:
    double weight;
};

bool operator==(const WeightBox&, const WeightBox&);
bool operator!=(const WeightBox&, const WeightBox&);

/* WeightBox Defs */

inline double WeightBox::getWeight() const
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
}



#endif // __CPP2C_INHERITANCE_DEFS_H__

