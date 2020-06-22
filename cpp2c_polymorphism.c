#include "cpp2c_polymorphism_defs.h"





void doPrePostFixer()
{
    printf("\n--- start doPrePostFixer() ---\n\n");


    PrePostFixer angleBrackets("<<< ", " >>>");
    _Z12PrePostFixer5printFEcp(&angleBrackets, "Hello World!");
    _Z12PrePostFixer5printFElc(&angleBrackets, -777, '\0');
    _Z12PrePostFixer5printFElc(&angleBrackets, 350, '#');
    _Z12PrePostFixer5printFElc(&angleBrackets, (long int)(3.14), '\0');

    printf("\n--- end doPrePostFixer() ---\n\n");
}

void doPrePostDollarFixer()
{
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer asterisks("***** ", " *****");
    _Z18PrePostDollarFixer5printFEic(&asterisks, -777, '$');
    _Z18PrePostDollarFixer5printFEic(&asterisks, 350, '#');
    _Z18PrePostDollarFixer5printFEdc(&asterisks, 3.14f, '$');

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
}

void doPrePostChecker()
{
    printf("\n--- start doPrePostChecker() ---\n\n");

    PrePostChecker check;
    _Z14PrePostChecker24printThisSymbolUsingFuncFE(&check);
    _Z14PrePostChecker23printThisSymbolDirectlyFE(&check);
    _Z14PrePostChecker32printDollarSymbolByCastUsingFuncFE(&check);
    _Z14PrePostChecker33printDollarSymbolByScopeUsingFuncFE(&check);
    _Z14PrePostChecker31printDollarSymbolByCastDirectlyFE(&check);
    _Z14PrePostChecker32printDollarSymbolByScopeDirectlyFE(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
}

void doPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixer hashes("### ", " ###");
    _Z23PrePostFloatDollar5printFEf(&hashes, -777);
    _Z23PrePostFloatDollar5printFEfc(&hashes, 350, '#');
    _Z23PrePostFloatDollar5printFEf(&hashes, 3.14f);
////
    PrePostDollarFixer hashes2(hashes);
    _Z23PrePostFloatDollar5printFEf(&hashes2, 7.5);
    _Z23PrePostFloatDollar5printFEf(&hashes2, 100);

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
}

void runAsPrePostFixerRef(const PrePostFixer* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    pp.print(123);

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    pp.print(123);

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    pp.print(123);

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(const PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    pp.print(123);

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier m1(3);
    Multiplier m2 = 5;
    Multiplier m3 = m1;
    Multiplier m4(m2);

    m1.print("abc ");
    m2.print("abc ");
    m3.print("abc ");
    m4.print("abc ");

    printf("\n--- start doMultiplier() ---\n\n");
}

void doFormatterArray()
{
    printf("\n--- start doFormatterArray() ---\n\n");

    DefaultTextFormatter formatters[] =
    {
        PrePostDollarFixer("!!! ", " !!!"),
        Multiplier(4),
        PrePostChecker()
    };

    for (int i = 0; i < 3; ++i)
        formatters[i].print("Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");
}

void doFormatterPtrs()
{
    printf("\n--- start doFormatterPtrs() ---\n\n");

    DefaultTextFormatter* pfmt[] =
    {
        new PrePostDollarFixer("!!! ", " !!!"),
        new Multiplier(4),
        new PrePostChecker()
    };

    for (int i = 0; i < 3; ++i)
        pfmt[i]->print("Hello World!");

    for (int i = 2; i >= 0; --i)
        delete pfmt[i];

    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatter* formatters = generateFormatterArray();
    
    for (int i = 0; i < 3; ++i)
        formatters[i].print("Hello World!");

    delete[] formatters;

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    PrePostHashFixer hfix;
    runAsPrePostFixerRef(hfix);
    runAsPrePostDollarFixerRef(hfix);
    runAsPrePostDollarFixerObj(hfix);
    runAsPrePostHashFixerRef(hfix);

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();

    printf("\n--- End main() ---\n\n");

    return 0;
}



