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
"/**{^]\n}***/"   /* 删除注释 */
"//"{^}\n]*       /*删除注释 */
{id} {fprint(yyout,"(%d,%s) \n",ID,yytext);}
{unmber} {printf(yyout,"(%d,%s) \n",NUMBER,yytext);}
{void} {printf(yyout,"(%d,%s) \n",VOID,yytetx);}
{char} {printf(yyout,"(%d,%s)\n",CHAR,yytext);}
{int} {printf(yyout,"(%d,%s) \n",INT,yytext);}
{float} {printf(yyout,"(%d,%s) \n",FLOAT,yytext);}
{double} {printf(yyout,"(%d,%s) \n",DOUBLE,yytext);}
{short} {printf(yyout,"(%d,%s) \n",SHORT,yytext);}
{long} {printf(yyout,"(%d,%s) \n",LONG,yytext);}
{signed} {printf(yyout,"(%d,%s) \n",SINGED,yytext);}
{unsigned} {printf(yyout,"(%d,%s) \n",UNSINGED,yytext);}
{struct} {printf(yyout,"(%d,%s) \n",STRUCT,yytext);}
{enum} {printf(yyout,"(%d,%s) \n",ENUM,yytext);}
{union} {printf(yyout,"(%d,%s) \n",UNION,yytext);}
{typedef} {printf(yyout,"(%d,%s) \n",TYPEDF,yytext);}
{sizeof} {printf(yyout,"(%d,%s) \n",SIZEOF,yytext);}
{long} {printf(yyout,"(%d,%s) \n",LONG,yytext);}
{auto} {printf(yyout,"(%d,%s) \n",AUTO,yytext);}
{register} {printf(yyout,"(%d,%s) \n",REGISTER,yytext);}
{extern} {printf(yyout,"(%d,%s) \n",EXTERN,yytext);}
{const} {printf(yyout,"(%d,%s) \n",CONST,yytext);}
{volatile} {printf(yyout,"(%d,%s) \n",VOLATILE,yytext);}
{return} {printf(yyout,"(%d,%s) \n",RETURN,yytext);}
{continue} {printf(yyout,"(%d,%s) \n",CONTIUNE,yytext);}
{break} {printf(yyout,"(%d,%s) \n",BREAK,yytext);}
{goto} {printf(yyout,"(%d,%s) \n",GOTO,yytext);}
{if} {printf(yyout,"(%d,%s) \n",IF,yytext);}
{else} {printf(yyout,"(%d,%s) \n",ELSE,yytext);}
{switch} {printf(yyout,"(%d,%s) \n",SIGWINCH,yytext);}
{case} {printf(yyout,"(%d,%s) \n",CASE,yytext);}
{for} {printf(yyout,"(%d,%s) \n",FOR,yytext);}
{do} {printf(yyout,"(%d,%s) \n",DO,yytext);}
{while} {printf(yyout,"(%d,%s) \n",WHILE,yytext);}
{scanf} {printf(yyout,"(%d,%s) \n",SCANF,yytext);}
{printf} {printf(yyout,"(%d,%s) \n",PRINTF,yytext);}
"{" {printf(yyout,"(%d,%s) \n",LC,yytext);}
"}" {printf(yyout,"(%d,%s) \n",RC,yytext);}
"[" {printf(yyout,"(%d,%s)\n",LB,yytext);}
"]" {printf(yyout,"(%d,%s) \n",RB,yytext);}
"(" {printf(yyout,"(%d,%s) \n",LP,yytext);}
")" {printf(yyout,"(%d,%s) \n",RP,yytext);}
...
%%
main()     /*ZHUHANSHU*/
{
  yyin = fopen("test.txt","r");
  yyout = fopen("result.txt","w");
  if(yyin !=NULL) return yylex();
}