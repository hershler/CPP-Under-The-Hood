#include "cpp2c_polymorphism_defs.h"

/* TextFormatter  */

void* (*)(void*) TextFormatterVPTR[2] = {(void* (*)(void*))&_Z13TextFormatterDE, (void* (*)(void*))&_ZTextFormatter5printFEcp}

void _Z13TextFormatterDE(TextFormatterDE* _this){}

void _ZTextFormatter5printFEcp(const TextFormatterDE* _this, const char* text){}


/*    DefaultTextFormatter Defs     */

void* (*)(void*) DefaultTextFormatterVPTR[2] = {(void* (*)(void*))&_Z20DefaultTextFormatterDE, (void* (*)(void*))&_Z20DefaultTextFormatter5printFEcp}

int next_id = 0;

void _Z20DefaultTextFormatterCE(DefaultTextFormatter* _this){
    _this->id = next_id++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", _this->id);
}

void _Z20DefaultTextFormatterDE(DefaultTextFormatter* _this){
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", _this->id);
}

void _Z20DefaultTextFormatterCEDefaultTextFormatter(DefaultTextFormatter* _this, const DefaultTextFormatter* other){
    id = next_id++;

    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, _this->id);
}

DefaultTextFormatter* _Z20DefaultTextFormatter14assignOperatorFEDefaultTextFormatter(DefaultTextFormatter* _this, const DefaultTextFormatter* other){
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, _this->id);
    return this;
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

void* (*)(void*) PrePostFixerVPTR[4] = {(void* (*)(void*))&_Z12PrePostFixerDE, (void* (*)(void*))&_Z12PrePostFixer5printFEcp, (void* (*)(void*))&_Z12PrePostFixer5printFElc, (void* (*)(void*))&_Z12PrePostFixer16getDefaultSymbolFE};

void _Z12PrePostFixerCEcpcp(PrePostFixer* _this, const char* prefix, const char* postfix){
    _this->pre = prefix;
    _this->post = postfix;

    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", pre, post);
}

void _Z12PrePostFixerDE(PrePostFixer* _this){
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", _this->pre, _this->post);
}

void _Z12PrePostFixerCEppfixer(PrePostFixer* _this, const PrePostFixer* other){
    memcpy();
}

void _Z12PrePostFixer5printFEcp(const PrePostFixer* _this const char* text){
    printf("%-60s | ",fname); "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", _this->pre, text, _this->post);
}

void _Z12PrePostFixer5printFElc(const PrePostFixer* _this, long num, char symbol = '\0'){
    return '\0';
}

char _Z12PrePostFixer16getDefaultSymbolFE(const PrePostFixer* _this){
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

void* (*)(void*) PrePostDollarFixerVPTR[4]  = {(void* (*)(void*))&_Z18PrePostDollarFixerDE, (void* (*)(void*))&_Z12PrePostFixer5printFEcp, (void* (*)(void*))&_Z18PrePostDollarFixer5printFElc, (void* (*)(void*))&_Z18PrePostDollarFixer16getDefaultSymbolFE};
const char _Z18PrePostDollarFixer14DEFAULT_SYMBOLVE = '$';

void _Z18PrePostDollarFixerCEcpcp(PrePostDollarFixer* _this, const char* prefix, const char* postfix){
    _Z12PrePostFixerCEcpcp((PrePostFixer*)_this, prefix, postfix)

    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)_this)->pre, ((PrePostFixer*)_this)->post);
}

void _Z18PrePostDollarFixerCEppdfixer(PrePostDollarFixer* _this, const PrePostDollarFixer* other){
    _Z12PrePostFixerCEcpcp((PrePostFixer*)_this, other);

    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)_this)->pre, ((PrePostFixer*)_this)->post);
}

void _Z18PrePostDollarFixerDE(PrePostDollarFixer* _this){
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", _this->pre, _this->post);
}

void _Z18PrePostDollarFixer5printFEic(const PrePostDollarFixer* _this, int num, char symbol = DEFAULT_SYMBOL){
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    print(long(num), symbol);
}

void _Z18PrePostDollarFixer5printFElc(const PrePostDollarFixer* _this, long num, char symbol = DEFAULT_SYMBOL){
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    _Z12PrePostFixer5printFElc(num, symbol);
}

void _Z18PrePostDollarFixer5printFEdc(const PrePostDollarFixer* _this, double num, char symbol = DEFAULT_SYMBOL){
    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", ((PrePostFixer*)_this)->pre, symbol, num, ((PrePostFixer*)_this)->post);
}

char _Z18PrePostDollarFixer16getDefaultSymbolFE(const PrePostDollarFixer* _this){
    return _Z18PrePostDollarFixer14DEFAULT_SYMBOLVE;
}

/*  PrePostHashFixer Defs    */

void* (*)(void*) PrePostHashFixerVPTR[4] ={(void* (*)(void*))&_Z16PrePostHashFixerDE, (void* (*)(void*))&_Z12PrePostFixer5printFEcp, (void* (*)(void*))&_Z16PrePostHashFixer5printFElc, (void* (*)(void*))&_Z16PrePostHashFixer16getDefaultSymbolFE};

const char _Z16PrePostHashFixer14DEFAULT_SYMBOLVE = '#';

void _Z16PrePostHashFixerCEi(PrePostHashFixer* _this, int prc){
    ((PrePostDollarFixer*)_this, "===> ", " <===");
    _this->precision = prc;

    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", ((PrePostDollarFixer*)_this)->pre, ((PrePostDollarFixer*)_this)->post, _this->precision);

    {
        printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

        printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->pre, _Z16PrePostHashFixer14DEFAULT_SYMBOLVE, _this->precision, 9999.9999, ((PrePostFixer*)this)->post);
    }
}

void _Z16PrePostHashFixerDE(PrePostHashFixer* _this)
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", _this->pre, _this->post);
}

void _Z16PrePostHashFixer5printFEic(const PrePostHashFixer* _this, int num, char symbol = DEFAULT_SYMBOL)
{
    printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");
    {
        printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

        printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->pre, symbol, _this->precision, double(num), ((PrePostFixer*)this)->post);
    }
}

void _Z16PrePostHashFixer5printFElc(const PrePostHashFixer* _this, long num, char symbol = DEFAULT_SYMBOL)
{
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    {
        printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

        printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->pre, symbol, _this->precision, double(num), ((PrePostFixer*)this)->post);
    }
}

char _Z16PrePostHashFixer16getDefaultSymbolFE(const PrePostHashFixer* _this)
{
    return _Z16PrePostHashFixer14DEFAULT_SYMBOLVE;
}

/*   PrePostFloatDollarFixer Defs    */

void* (*)(void*) PrePostFloatDollarFixerVPTR[4] = {(void* (*)(void*))&_Z23PrePostFloatDollarDE, (void* (*)(void*))&_Z12PrePostFixer5printFEcp, (void* (*)(void*))&_Z16PrePostHashFixer5printFElc, (void* (*)(void*))&_Z23PrePostFloatDollar16getDefaultSymbolFE};

const char _Z23PrePostFloatDollarFixer16DEFAULT_SYMBOLVE = '@';

void _Z23PrePostFloatDollarCEcpcp(PrePostFloatDollarFixer* _this, const char* prefix, const char* postfix){
    PrePostDollarFixer(prefix, postfix);

    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", _this->pre, _this->post);
}

void _Z23PrePostFloatDollarDE(PrePostFloatDollarFixer* _this)
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", _this->pre, _this->post);
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

    printf("%s%c%.2f%s\n", _this->pre, symbol, num, _this->post);
}

char _Z23PrePostFloatDollar16getDefaultSymbolFE(const PrePostFloatDollarFixer* _this)
{
    return _Z23PrePostFloatDollarFixer16DEFAULT_SYMBOLVE;
}


/*  PrePostChecker Defs    */

void* (*)(void*) PrePostCheckerVPTR[4] = {(void* (*)(void*))&_Z14PrePostCheckerDE, (void* (*)(void*))&_Z12PrePostFixer5printFEcp, (void* (*)(void*))&_Z16PrePostHashFixer5printFElc, (void* (*)(void*))&_Z23PrePostFloatDollar16getDefaultSymbolFE};


void _Z14PrePostCheckerCE(PrePostChecker* _this){
    PrePostFloatDollarFixer("[[[[ ", " ]]]]")

    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", _this->pre, _this->post);
}

void _Z14PrePostCheckerDE(PrePostChecker* _this)
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", _this->pre, _this->post);
}

void _Z14PrePostChecker24printThisSymbolUsingFuncFE(const PrePostChecker* _this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n", this->getDefaultSymbol());
}

void _Z14PrePostChecker23printThisSymbolDirectlyFE(const PrePostChecker* _this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", this->_Z23PrePostFloatDollarFixer16DEFAULT_SYMBOLVE);
}

void _Z14PrePostChecker32printDollarSymbolByCastUsingFuncFE(const PrePostChecker* _this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", ((PrePostDollarFixer*)(this))->getDefaultSymbol());
}

void _Z14PrePostChecker33printDollarSymbolByScopeUsingFuncFE(const PrePostChecker* _this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n", this->PrePostDollarFixer::getDefaultSymbol());
}

void _Z14PrePostChecker31printDollarSymbolByCastDirectlyFE(const PrePostChecker* _this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", ((PrePostDollarFixer*)(this))->DEFAULT_SYMBOL);
}

void _Z14PrePostChecker32printDollarSymbolByScopeDirectlyFE(const PrePostChecker* _this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", this->PrePostDollarFixer::DEFAULT_SYMBOL);
}


/*   Multiplier Defs   */

void* (*)(void*) MultiplierVPTR[] = {(void* (*)(void*))&_Z10MultiplierDE, (void* (*)(void*))&_Z10Multiplier5printFEcp};

void _Z10MultiplierDE(Multiplier* _this)
{
    printf("--- Multiplier DTOR: times = %d\n", _this->times);
}

void _Z10Multiplier5printFEcp(const Multiplier* _this, const char* text);
{
    int i;
    printf("%-60s | ", "[Multiplier::print(const char*)]");
    
    for (i = 0; i < _this->times; ++i)
        printf("%s", text);
    printf("\n");
}


