#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__

//// Box ////////////

struct Box
{
    double length;
    double width;
    double height;
};


void ctor(Box* b, double dim=1);
void ctor(Box* b, double l, double w, double h);
void dtor(Box* b);

double getWidth(const Box* b);
double getLength(const Box* b);
double getHeight(const Box* b);

double getVolume(const Box* b);

Box* operator*=(Box* b, double mult);


void print(const Box* b);
//
//Box operator*(const Box* box, double mult);
//Box operator*(double mult, const Box* box);
//bool operator==(const Box* lhs, const Box& rhs);
//bool operator!=(const Box* lhs, const Box& rhs);


//// Box Defs ////////////
/*
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
    return b->width * b->length * b->height;
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

*/
//// Shelf ////////////

struct Shelf
{
    static const unsigned int NUM_BOXES = 3;
    static const char* const DEF_MSG;
    static const char* message;

    Box boxes[NUM_BOXES];
};


void setBox(Shelf s*, int index, const Box* dims);
double getVolume(const Shelf* s);
Box* getBox(Shelf*, int index);
void print(const Shelf*);

static int getNumBoxes();
static void setMessage(const char* msg);


//// Shelf Defs ////////////
/*
inline Box* Shelf::getBox(int index)
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
*/
#endif // __CPP2C_ENCAPSULATION_DEFS_H__

