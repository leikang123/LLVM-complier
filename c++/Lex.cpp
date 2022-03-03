  /*用 lex编写的词法生成器*/
%{
    #include <stdio.h>
    #include <stdlib.h>
    #define VOID 1 
    #define CHAR 2
    #define INT 3
    #define FLOAT 4
    #define DOUBLE 5
    #define SHORT 6
    #define LONG 7
    #define SINGED 8
    #define UNSINGED 9
    #define STRUCT 10
    #define UNION 11
    #define ENUM 12
    #define TYPEDF 13
    #define SIZEOF 14
    #define AUTO 15
    #define STATIC 16
    #define CONST 17
    #define GOTO 18
    #define IF 19
    #define ELSE 20
    #define CASE 21
    #define FALSE 22
    #define TRUE 23
    #define DO 24
    #define WHILE 25
    #define SCANF 26
    #define ID 27
    #define NUMBER 28
    #define COLON 29
    #define SHA 30
%}
white [\t\n\ ]
digit [0-9]
letter [A-Za-z]
id {(letter()|_} {{letter}|{digit}|_}*
number  [1-9](digit)*|0
%%
{white}+;