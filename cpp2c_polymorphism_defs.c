#include "cpp2c_polymorphism_defs.h"
#include <string.h>


/* TextFormatter Defs */

func_ptr TextFormatterVPTR[2]  = {(func_ptr) &_Z13TextFormatterDE, (func_ptr) &_ZTextFormatter5printFEcp};
/*
inline void _Z13TextFormatterCE(TextFormatter* _this){
    _this->VPTR = TextFormatterVPTR;
}
*/
void _Z13TextFormatterDE(TextFormatter* _this){}

void _ZTextFormatter5printFEcp(const TextFormatter* _this, const char* text){}


/*    DefaultTextFormatter Defs     */

func_ptr DefaultTextFormatterVPTR[2] = {(func_ptr) &_Z20DefaultTextFormatterDE, (func_ptr) &_Z20DefaultTextFormatter5printFEcp};

int next_id = 0;

void _Z20DefaultTextFormatterCE(DefaultTextFormatter* _this){
    ((TextFormatter*)_this)->VPTR = DefaultTextFormatterVPTR;
    _this->id = next_id++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", _this->id);
}

void _Z20DefaultTextFormatterDE(DefaultTextFormatter* _this){
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", _this->id);
    _Z13TextFormatterDE((TextFormatter*)_this);
}

void _Z20DefaultTextFormatterCEDefaultTextFormatter(DefaultTextFormatter* _this, const DefaultTextFormatter* other){
    _Z13TextFormatterCE((TextFormatter*)_this);
    ((TextFormatter*)_this)->VPTR = DefaultTextFormatterVPTR;
    _this->id = next_id++;

    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, _this->id);
}

DefaultTextFormatter* _Z20DefaultTextFormatter14assignOperatorFEDefaultTextFormatter(DefaultTextFormatter* _this, const DefaultTextFormatter* other){
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, _this->id);
    return _this;
}

void _Z20DefaultTextFormatter5printFEcp(const DefaultTextFormatter* _this, const char* text){
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}

DefaultTextFormatter* _Z22generateFormatterArrayFE(){
    DefaultTextFormatter* temp = (DefaultTextFormatter*)malloc(sizeof(DefaultTextFormatter)*3);
    return temp;
}


/*  PrePostFixer Defs    */

func_ptr PrePostFixerVPTR[4] = {(func_ptr) &_Z12PrePostFixerDE, (func_ptr) &_Z12PrePostFixer5printFEcp, (func_ptr) &_Z12PrePostFixer5printFElc, (func_ptr) &_Z12PrePostFixer16getDefaultSymbolFE};

void _Z12PrePostFixerCEcpcp(PrePostFixer* _this, const char* prefix, const char* postfix){
    _Z20DefaultTextFormatterCE((DefaultTextFormatter*) _this);
    ((TextFormatter*)_this)->VPTR = PrePostFixerVPTR;
    _this->pre = prefix;
    _this->post = postfix;

    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", _this->pre, _this->post);
}

void _Z12PrePostFixerDE(PrePostFixer* _this){
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", _this->pre, _this->post);
    _Z20DefaultTextFormatterDE((DefaultTextFormatter*) _this);
}

void _Z12PrePostFixerCEppfixer(PrePostFixer* _this, const PrePostFixer* other){
    _Z20DefaultTextFormatterCE((DefaultTextFormatter*)_this);
    memcpy((void*)_this + sizeof(DefaultTextFormatter), (void*)other + sizeof(DefaultTextFormatter), sizeof(PrePostFixer) - sizeof(DefaultTextFormatter));
}

void _Z12PrePostFixer5printFEcp(const PrePostFixer* _this, const char* text){
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", _this->pre, text, _this->post);
}

char _Z12PrePostFixer16getDefaultSymbolFE(const PrePostFixer* _this){
    return '\0';
}

void _Z12PrePostFixer5printFElc(const PrePostFixer* _this, long num, char symbol/* = '\0'*/){

    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol)
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", _this->pre, symbol, num, _this->post);
    }
    else
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", _this->pre, num, _this->post);
    }
}


/*   PrePostDollarFixer Defs    */

func_ptr PrePostDollarFixerVPTR[4]  = {(func_ptr) &_Z18PrePostDollarFixerDE, (func_ptr) &_Z12PrePostFixer5printFEcp, (func_ptr) &_Z18PrePostDollarFixer5printFElc, (func_ptr) &_Z18PrePostDollarFixer16getDefaultSymbolFE};
inline const char _Z18PrePostDollarFixer14DEFAULT_SYMBOLVE = '$';

void _Z18PrePostDollarFixerCEcpcp(PrePostDollarFixer* _this, const char* prefix, const char* postfix){
    _Z12PrePostFixerCEcpcp((PrePostFixer*)_this, prefix, postfix);
    ((TextFormatter*)_this)->VPTR = PrePostDollarFixerVPTR;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)_this)->pre, ((PrePostFixer*)_this)->post);
}

void _Z18PrePostDollarFixerCEppdfixer(PrePostDollarFixer* _this, const PrePostDollarFixer* other){
    _Z12PrePostFixerCEppfixer((PrePostFixer*)_this, other);
    ((TextFormatter*)_this)->VPTR = PrePostDollarFixerVPTR;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)_this)->pre, ((PrePostFixer*)_this)->post);
}

void _Z18PrePostDollarFixerDE(PrePostDollarFixer* _this){
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)_this)->pre, ((PrePostFixer*)_this)->post);
    _Z12PrePostFixerDE((PrePostFixer*)_this);
}

void _Z18PrePostDollarFixer5printFEic(const PrePostDollarFixer* _this, int num, char symbol/* = DEFAULT_SYMBOL*/){
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    _Z18PrePostDollarFixer5printFElc((PrePostDollarFixer*)_this, (long)num, symbol);
}

void _Z18PrePostDollarFixer5printFElc(const PrePostDollarFixer* _this, long num, char symbol/* = DEFAULT_SYMBOL*/){
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    _Z12PrePostFixer5printFElc((PrePostFixer*)_this, num, symbol);
}

void _Z18PrePostDollarFixer5printFEdc(const PrePostDollarFixer* _this, double num, char symbol/* = DEFAULT_SYMBOL*/){
    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", ((PrePostFixer*)_this)->pre, symbol, num, ((PrePostFixer*)_this)->post);
}

char _Z18PrePostDollarFixer16getDefaultSymbolFE(const PrePostDollarFixer* _this){
    return _Z18PrePostDollarFixer14DEFAULT_SYMBOLVE;
}

/*  PrePostHashFixer Defs    */

func_ptr PrePostHashFixerVPTR[4] ={(func_ptr) &_Z16PrePostHashFixerDE, (func_ptr) &_Z12PrePostFixer5printFEcp, (func_ptr) &_Z16PrePostHashFixer5printFElc, (func_ptr) &_Z16PrePostHashFixer16getDefaultSymbolFE};

const char _Z16PrePostHashFixer14DEFAULT_SYMBOLVE = '#';

void _Z16PrePostHashFixerCEi(PrePostHashFixer* _this, int prc){
    _Z18PrePostDollarFixerCEcpcp((PrePostDollarFixer*)_this, "===> ", " <===");
    ((TextFormatter*)_this)->VPTR = PrePostHashFixerVPTR;
    _this->precision = prc;

    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", ((PrePostFixer*)_this)->pre, ((PrePostFixer*)_this)->post, _this->precision);

    {
        printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

        printf("%s[%c%.*f]%s\n", ((PrePostFixer*)_this)->pre, _Z16PrePostHashFixer14DEFAULT_SYMBOLVE, _this->precision, 9999.9999, ((PrePostFixer*)_this)->post);
    }
}

void _Z16PrePostHashFixerDE(PrePostHashFixer* _this)
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)_this)->pre, ((PrePostFixer*)_this)->post);
    _Z18PrePostDollarFixerDE((PrePostDollarFixer*)_this);
}

void _Z16PrePostHashFixer5printFEic(const PrePostHashFixer* _this, int num, char symbol/* = DEFAULT_SYMBOL*/)
{
    printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");
    {
        printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

        printf("%s[%c%.*f]%s\n", ((PrePostFixer*)_this)->pre, symbol, _this->precision, (double)num, ((PrePostFixer*)_this)->post);
    }
}

void _Z16PrePostHashFixer5printFElc(const PrePostHashFixer* _this, long num, char symbol/* = DEFAULT_SYMBOL*/)
{
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    {
        printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

        printf("%s[%c%.*f]%s\n", ((PrePostFixer*)_this)->pre, symbol, _this->precision, (double)num, ((PrePostFixer*)_this)->post);
    }
}

char _Z16PrePostHashFixer16getDefaultSymbolFE(const PrePostHashFixer* _this)
{
    return _Z16PrePostHashFixer14DEFAULT_SYMBOLVE;
}

/*   PrePostFloatDollarFixer Defs    */

func_ptr PrePostFloatDollarFixerVPTR[4] = {(func_ptr) &_Z23PrePostFloatDollarDE, (func_ptr) &_Z12PrePostFixer5printFEcp, (func_ptr) &_Z18PrePostDollarFixer5printFElc, (func_ptr) &_Z23PrePostFloatDollar16getDefaultSymbolFE};

const char _Z23PrePostFloatDollarFixer16DEFAULT_SYMBOLVE = '@';

void _Z23PrePostFloatDollarCEcpcp(PrePostFloatDollarFixer* _this, const char* prefix, const char* postfix){
    _Z18PrePostDollarFixerCEcpcp((PrePostDollarFixer*)_this, prefix, postfix);
    ((TextFormatter*)_this)->VPTR = PrePostFloatDollarFixerVPTR;

    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)_this)->pre, ((PrePostFixer*)_this)->post);
}

void _Z23PrePostFloatDollarDE(PrePostFloatDollarFixer* _this)
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)_this)->pre, ((PrePostFixer*)_this)->post);
    _Z16PrePostHashFixerDE((PrePostHashFixer*) _this);
}

void _Z23PrePostFloatDollar5printFEf(const PrePostFloatDollarFixer* _this, float num)
{
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    print(num, _Z23PrePostFloatDollarFixer16DEFAULT_SYMBOLVE);
}

void _Z23PrePostFloatDollar5printFEfc(const PrePostFloatDollarFixer* _this, float num, char symbol)
{
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]");

    printf("%s%c%.2f%s\n", ((PrePostFixer*) _this)->pre, symbol, num, ((PrePostFixer*) _this)->post);
}

char _Z23PrePostFloatDollar16getDefaultSymbolFE(const PrePostFloatDollarFixer* _this)
{
    return _Z23PrePostFloatDollarFixer16DEFAULT_SYMBOLVE;
}


/*  PrePostChecker Defs    */

func_ptr PrePostCheckerVPTR[4] = {(func_ptr) &_Z14PrePostCheckerDE, (func_ptr) &_Z12PrePostFixer5printFEcp, (func_ptr) &_Z16PrePostHashFixer5printFElc, (func_ptr) &_Z23PrePostFloatDollar16getDefaultSymbolFE};


void _Z14PrePostCheckerCE(PrePostChecker* _this){
    _Z23PrePostFloatDollarCEcpcp((PrePostFloatDollarFixer*)_this, "[[[[ ", " ]]]]");
    ((TextFormatter*)_this)->VPTR = PrePostCheckerVPTR;

    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)_this)->pre, ((PrePostFixer*)_this)->post);
}

void _Z14PrePostCheckerDE(PrePostChecker* _this)
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)_this)->pre, ((PrePostFixer*)_this)->post);
    _Z23PrePostFloatDollarFixerDE((PrePostFloatDollarFixer*)_this);
}

void _Z14PrePostChecker24printThisSymbolUsingFuncFE(const PrePostChecker* _this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n", _Z23PrePostFloatDollarFixer16getDefaultSymbolFE((PrePostFloatDollarFixer*)_this));
}

void _Z14PrePostChecker23printThisSymbolDirectlyFE(const PrePostChecker* _this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", _Z23PrePostFloatDollarFixer14DEFAULT_SYMBOLVE);
}

void _Z14PrePostChecker32printDollarSymbolByCastUsingFuncFE(const PrePostChecker* _this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", (char(*)(PrePostChecker))((TextFormatter*)(_this))->VPTR[get_default_symbol]);
}

void _Z14PrePostChecker33printDollarSymbolByScopeUsingFuncFE(const PrePostChecker* _this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n", _Z18PrePostDollarFixer16getDefaultSymbolFE((PrePostDollarFixer*)_this));
}

void _Z14PrePostChecker31printDollarSymbolByCastDirectlyFE(const PrePostChecker* _this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", (_Z18PrePostDollarFixer14DEFAULT_SYMBOLVE));
}

void _Z14PrePostChecker32printDollarSymbolByScopeDirectlyFE(const PrePostChecker* _this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", _Z18PrePostDollarFixer14DEFAULT_SYMBOLVE);
}


/*   Multiplier Defs   */

func_ptr MultiplierVPTR[] = {(func_ptr) &_Z10MultiplierDE, (func_ptr) &_Z10Multiplier5printFEcp};

void _Z10MultiplierDE(Multiplier* _this)
{
    printf("--- Multiplier DTOR: times = %d\n", _this->times);
    _Z13TextFormatterDE((TextFormatter*)_this);
}

void _Z10Multiplier5printFEcp(const Multiplier* _this, const char* text)
{
    int i;
    printf("%-60s | ", "[Multiplier::print(const char*)]");
    
    for (i = 0; i < _this->times; ++i)
        printf("%s", text);
    printf("\n");
}


