#include "cpp2c_polymorphism_defs.h"
#include <string.h>
#include <stdlib.h>


void doPrePostFixer()
{
    PrePostFixer angleBrackets;

    printf("\n--- start doPrePostFixer() ---\n\n");

    _Z12PrePostFixerCEcpcp(&angleBrackets, "<<< ", " >>>");
    _Z12PrePostFixer5printFEcp(&angleBrackets, "Hello World!");
    _Z12PrePostFixer5printFElc(&angleBrackets, -777, '\0');
    _Z12PrePostFixer5printFElc(&angleBrackets, 350, '#');
    _Z12PrePostFixer5printFElc(&angleBrackets, (long int)(3.14), '\0');

    printf("\n--- end doPrePostFixer() ---\n\n");
    _Z12PrePostFixerDE(&angleBrackets);
}

void doPrePostDollarFixer()
{
    PrePostDollarFixer asterisks;

    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    _Z18PrePostDollarFixerCEcpcp(&asterisks, "***** ", " *****");
    _Z18PrePostDollarFixer5printFEic(&asterisks, -777, '$');
    _Z18PrePostDollarFixer5printFEic(&asterisks, 350, '#');
    _Z18PrePostDollarFixer5printFEdc(&asterisks, 3.14f, '$');

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    _Z18PrePostDollarFixerDE(&asterisks);
}

void doPrePostChecker()
{
    PrePostChecker check;
    printf("\n--- start doPrePostChecker() ---\n\n");
    _Z14PrePostCheckerCE(&check);

    _Z14PrePostChecker24printThisSymbolUsingFuncFE(&check);
    _Z14PrePostChecker23printThisSymbolDirectlyFE(&check);
    _Z14PrePostChecker31printDollarSymbolByCastDirectlyFE(&check);
    _Z14PrePostChecker32printDollarSymbolByScopeDirectlyFE(&check);
    _Z14PrePostChecker32printDollarSymbolByCastUsingFuncFE(&check);
    _Z14PrePostChecker33printDollarSymbolByScopeUsingFuncFE(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
    _Z14PrePostCheckerDE(&check);
}

void doPrePostFloatDollarFixer()
{
    PrePostFloatDollarFixer hashes;
    PrePostDollarFixer hashes2;

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    _Z23PrePostFloatDollarFixerCEcpcp(&hashes, "### ", " ###");
    _Z23PrePostFloatDollarFixer5printFEf(&hashes, -777);
    _Z23PrePostFloatDollarFixer5printFEfc(&hashes, 350, '#');
    _Z23PrePostFloatDollarFixer5printFEf(&hashes, 3.14f);
    _Z18PrePostDollarFixerCEppdfixer(&hashes2, (PrePostDollarFixer*)&hashes);
    _Z18PrePostDollarFixer5printFEdc(&hashes2, 7.5, '$');
    _Z18PrePostDollarFixer5printFEic(&hashes2, 100, '$');

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
    _Z18PrePostDollarFixerDE(&hashes2);
    _Z23PrePostFloatDollarFixerDE(&hashes);
}

void runAsPrePostFixerRef(const PrePostFixer* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    ((void(*)(const PrePostFixer*, long, char))((((TextFormatter*)pp)->VPTR)[print_long_char]))(pp, 123, '\0');

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    _Z18PrePostDollarFixer5printFEic(pp, 123, '$');

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    _Z18PrePostDollarFixer5printFEic(&pp, 123, '$');

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(const PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    _Z16PrePostHashFixer5printFEic(pp, 123, '#');

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    Multiplier m1, m2, m3, m4;
    printf("\n--- start doMultiplier() ---\n\n");
    {
        _Z20DefaultTextFormatterCE((DefaultTextFormatter*)&m1);
        ((TextFormatter*)&m1)->VPTR = MultiplierVPTR;
        m1.times = 3;
        printf("--- Multiplier CTOR: times = %d\n", m1.times);
    }
    {
        _Z20DefaultTextFormatterCE((DefaultTextFormatter*)&m2);
        ((TextFormatter*)&m2)->VPTR = MultiplierVPTR;
        m2.times = 5;
        printf("--- Multiplier CTOR: times = %d\n", m2.times);
    }
    {
        _Z20DefaultTextFormatterCEDefaultTextFormatter((DefaultTextFormatter*)&m3, (DefaultTextFormatter*)&m1);
        memcpy((char*)&m3 + sizeof(DefaultTextFormatter), (char*)&m1 + sizeof(DefaultTextFormatter), sizeof(Multiplier) - sizeof(DefaultTextFormatter));
    }
    {
        _Z20DefaultTextFormatterCEDefaultTextFormatter((DefaultTextFormatter*)&m4, (DefaultTextFormatter*)&m2);
        memcpy((char*)&m4 + sizeof(DefaultTextFormatter), (char*)&m2 + sizeof(DefaultTextFormatter), sizeof(Multiplier) - sizeof(DefaultTextFormatter));
    }

    _Z10Multiplier5printFEcp(&m1, "abc ");
    _Z10Multiplier5printFEcp(&m2, "abc ");
    _Z10Multiplier5printFEcp(&m3, "abc ");
    _Z10Multiplier5printFEcp(&m4, "abc ");

    printf("\n--- start doMultiplier() ---\n\n");
    _Z10MultiplierDE(&m4);
    _Z10MultiplierDE(&m3);
    _Z10MultiplierDE(&m2);
    _Z10MultiplierDE(&m1);
}

void doFormatterArray() {
    int i;
    DefaultTextFormatter formatters[3];
    printf("\n--- start doFormatterArray() ---\n\n");
    {
        PrePostDollarFixer temp;
        _Z18PrePostDollarFixerCEcpcp(&temp, "!!! ", " !!!");
        _Z20DefaultTextFormatterCEDefaultTextFormatter(formatters, (DefaultTextFormatter *) &temp);
        _Z18PrePostDollarFixerDE(&temp);
    }
    {
        Multiplier temp;
        _Z20DefaultTextFormatterCE((DefaultTextFormatter *) &temp);
        temp.times = 4;
        printf("--- Multiplier CTOR: times = %d\n", temp.times);
        _Z20DefaultTextFormatterCEDefaultTextFormatter(formatters + 1, (DefaultTextFormatter *) &temp);
        _Z10MultiplierDE(&temp);
    }
    {
        PrePostChecker temp;
        _Z14PrePostCheckerCE(&temp);
        _Z20DefaultTextFormatterCEDefaultTextFormatter(formatters + 2, (DefaultTextFormatter *) &temp);
        _Z14PrePostCheckerDE(&temp);
    }

    for (i = 0; i < 3; ++i) {
        ((void (*)(const DefaultTextFormatter *,
                   const char *)) ((((TextFormatter *) &(formatters[i]))->VPTR)[print_char]))(&(formatters[i]),
                                                                                              "Hello World!");
    }
    printf("\n--- end doFormatterArray() ---\n\n");
    for (i = 2; i >= 0; --i) {
        _Z20DefaultTextFormatterDE(formatters + i);
    }
}

void doFormatterPtrs()
{
    int i;
    DefaultTextFormatter* pfmt[3];

    printf("\n--- start doFormatterPtrs() ---\n\n");

    {
        pfmt[0] = (DefaultTextFormatter*)malloc(sizeof(PrePostDollarFixer));
        _Z18PrePostDollarFixerCEcpcp((PrePostDollarFixer*)pfmt, "!!! ", " !!!");
    }
    {
        pfmt[1] = (DefaultTextFormatter*)malloc(sizeof(Multiplier));
        _Z20DefaultTextFormatterCE((DefaultTextFormatter*)(pfmt[1]));
        ((Multiplier*)(pfmt[1]))->times = 4;
        printf("--- Multiplier CTOR: times = %d\n", ((Multiplier*)(pfmt[1]))->times);
    }
    {
        pfmt[2] = (DefaultTextFormatter*)malloc(sizeof(PrePostChecker));
        _Z14PrePostCheckerCE((PrePostChecker*)pfmt[2]);
    }


    for (i = 0; i < 3; ++i) {
        ((void (*)(const DefaultTextFormatter *,
                const char *)) ((((TextFormatter *)(pfmt[i]))->VPTR)[print_char]))((pfmt[i]), "Hello World!");
    }

    for (i = 2; i >= 0; --i) {

        ((void (*)(const DefaultTextFormatter *)) ((((TextFormatter *) &(pfmt[i]))->VPTR)[dtor]))(pfmt[i]);
        free(pfmt[i]);
    }
    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    int i;
    DefaultTextFormatter* formatters;;

    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    formatters = _Z22generateFormatterArrayFE();
    for (i = 0; i < 3; ++i)
        ((void(*)(const DefaultTextFormatter*, const char*))((((TextFormatter*)(formatters + i))->VPTR)[print_char]))(formatters + i, "Hello World!");

    for(i = 0; i < 3; i++){
        _Z20DefaultTextFormatterDE(formatters + i);
    }
    free(formatters);

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{
    PrePostHashFixer hfix;
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();
    _Z16PrePostHashFixerCEi(&hfix, 4);
    runAsPrePostFixerRef((PrePostFixer*)&hfix);
    runAsPrePostDollarFixerRef((PrePostDollarFixer*)&hfix);
    {
        PrePostDollarFixer temp;
        _Z18PrePostDollarFixerCEppdfixer(&temp, (PrePostDollarFixer*)&hfix);
        runAsPrePostDollarFixerObj(temp);
        _Z18PrePostDollarFixerDE(&temp);
    }
    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();

    printf("\n--- End main() ---\n\n");
    _Z16PrePostHashFixerDE(&hfix);

    return 0;
}



