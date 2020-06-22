#ifndef __CPP2C_POLYMORPHISM_H__
#define __CPP2C_POLYMORPHISM_H__


#include <stdio.h>

typedef enum funcs{
    dtor,
    print_char,
    print_long,
    get_default_symbol
}funcs;

typedef void* (*func_ptr)(void*);

/*    TextFormatter     */

extern func_ptr TextFormatterVPTR[];

typedef struct TextFormatter{
    func_ptr* VPTR;
}TextFormatter;

void _Z13TextFormatterCE(TextFormatter* _this);
void _Z13TextFormatterDE(TextFormatter* _this);
void _ZTextFormatter5printFEcp(const TextFormatter* _this, const char* text);

/*   DefaultTextFormatter   */

extern func_ptr DefaultTextFormatterVPTR[];


typedef struct DefaultTextFormatter
{
    TextFormatter _tformatter;
    int id;
}DefaultTextFormatter;

extern int next_id;


void _Z20DefaultTextFormatterCE(DefaultTextFormatter* _this);
void _Z20DefaultTextFormatterCEDefaultTextFormatter(DefaultTextFormatter* _this, const DefaultTextFormatter* other);
DefaultTextFormatter* _Z20DefaultTextFormatter14assignOperatorFEDefaultTextFormatter(DefaultTextFormatter* _this, const DefaultTextFormatter* other);
void _Z20DefaultTextFormatterDE(DefaultTextFormatter* _this);

void _Z20DefaultTextFormatter5printFEcp(const DefaultTextFormatter* _this, const char* text);


DefaultTextFormatter* _Z22generateFormatterArrayFE();


/*    PrePostFixer    */

extern func_ptr PrePostFixerVPTR[];

typedef struct PrePostFixer
{
    DefaultTextFormatter _dtformatter;
    const char* pre;
    const char* post;
}PrePostFixer;

void _Z12PrePostFixerCEcpcp(PrePostFixer* _this, const char* prefix, const char* postfix);
void _Z12PrePostFixerDE(PrePostFixer* _this);
void _Z12PrePostFixerCEppfixer(PrePostFixer* _this, const PrePostFixer* other);

void _Z12PrePostFixer5printFEcp(const PrePostFixer* _this, const char* text);
void _Z12PrePostFixer5printFElc(const PrePostFixer* _this, long num, char symbol/* = '\0'*/) ;

char _Z12PrePostFixer16getDefaultSymbolFE(const PrePostFixer* _this);


/*   PrePostDollarFixer     */

extern func_ptr PrePostDollarFixerVPTR[];
inline extern const char _Z18PrePostDollarFixer14DEFAULT_SYMBOLVE;

typedef struct PrePostDollarFixer
{
    PrePostFixer _ppfixer;
}PrePostDollarFixer;

void _Z18PrePostDollarFixerCEcpcp(PrePostDollarFixer* _this, const char* prefix, const char* postfix);
void _Z18PrePostDollarFixerCEppdfixer(PrePostDollarFixer* _this, const PrePostDollarFixer* other);
void _Z18PrePostDollarFixerDE(PrePostDollarFixer* _this);

void _Z18PrePostDollarFixer5printFEic(const PrePostDollarFixer* _this, int num, char symbol/* = DEFAULT_SYMBOL*/);
void _Z18PrePostDollarFixer5printFElc(const PrePostDollarFixer* _this, long num, char symbol/* = DEFAULT_SYMBOL*/);
void _Z18PrePostDollarFixer5printFEdc(const PrePostDollarFixer* _this, double num, char symbol/* = DEFAULT_SYMBOL*/);
char _Z18PrePostDollarFixer16getDefaultSymbolFE(const PrePostDollarFixer* _this);


/*   PrePostHashFixer    */

extern func_ptr PrePostHashFixerVPTR[];
inline extern const char _Z16PrePostHashFixer14DEFAULT_SYMBOLVE;

typedef struct PrePostHashFixer{
    PrePostDollarFixer _ppdfixer;
    int precision;
}PrePostHashFixer;

void _Z16PrePostHashFixerCEi(PrePostHashFixer* _this, int prc/* = 4*/);
void _Z16PrePostHashFixerDE(PrePostHashFixer* _this);

void _Z16PrePostHashFixer5printFEic(const PrePostHashFixer* _this, int num, char symbol/* = DEFAULT_SYMBOL*/);
void _Z16PrePostHashFixer5printFElc(const PrePostHashFixer* _this, long num, char symbol/* = DEFAULT_SYMBOL*/);
char _Z16PrePostHashFixer16getDefaultSymbolFE(const PrePostHashFixer* _this);


/*    PrePostFloatDollarFixer     */

extern func_ptr PrePostFloatDollarFixerVPTR[];
inline extern const char _Z23PrePostFloatDollarFixer14DEFAULT_SYMBOLVE;

typedef struct PrePostFloatDollarFixer
{
    PrePostDollarFixer _ppdfixer;
}PrePostFloatDollarFixer;

void _Z23PrePostFloatDollarCEcpcp(PrePostFloatDollarFixer* _this, const char* prefix, const char* postfix);
void _Z23PrePostFloatDollarDE(PrePostFloatDollarFixer* _this);
void _Z23PrePostFloatDollar5printFEf(const PrePostFloatDollarFixer* _this, float num);
void _Z23PrePostFloatDollar5printFEfc(const PrePostFloatDollarFixer* _this, float num, char symbol);
char _Z23PrePostFloatDollar16getDefaultSymbolFE(const PrePostFloatDollarFixer* _this);

/*    PrePostChecker    */

extern func_ptr PrePostCheckerVPTR[];

typedef struct PrePostChecker {
    PrePostFloatDollarFixer _ppfdfixer;
}PrePostChecker;

void _Z14PrePostCheckerCE(PrePostChecker* _this);
void _Z14PrePostCheckerDE(PrePostChecker* _this);

void _Z14PrePostChecker24printThisSymbolUsingFuncFE(const PrePostChecker* _this);
void _Z14PrePostChecker23printThisSymbolDirectlyFE(const PrePostChecker* _this);
void _Z14PrePostChecker32printDollarSymbolByCastUsingFuncFE(const PrePostChecker* _this);
void _Z14PrePostChecker33printDollarSymbolByScopeUsingFuncFE(const PrePostChecker* _this);
void _Z14PrePostChecker31printDollarSymbolByCastDirectlyFE(const PrePostChecker* _this);
void _Z14PrePostChecker32printDollarSymbolByScopeDirectlyFE(const PrePostChecker* _this);



/*    Multiplier    */

extern func_ptr MultiplierVPTR[];

typedef struct Multiplier
{
    DefaultTextFormatter _dtformatter;
    int times;
}Multiplier;

void _Z10MultiplierDE(Multiplier* _this);

void _Z10Multiplier5printFEcp(const Multiplier* _this, const char* text);

/*   Multiplier Defs

inline Multiplier::Multiplier(int t=2)
{
    _this -> times = t;
    printf("--- Multiplier CTOR: times = %d\n", _this->times);
}
*/


#endif // __CPP2C_POLYMORPHISM_H__

