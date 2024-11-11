%{
    #include<stdio.h>
    #include<stdlib.h>
    void yyerror(const char *);
%}

LETTER [a-zA-Z]
DIGIT [0-9]
NUMBER [0-9]+
ID {LETTER}({LETTER}|{DIGIT})*

%%

"if"|"else"|"while"|"void"|"int"|"float"|"main" {printf("\n%s is a KEYWORD",yytext);}
"+"|"-"|"*"|"/"   {printf("\n%s is an OPERATOR",yytext);}
{ID}  {printf("\n%s is an IDENTIFIER",yytext);}
{NUMBER} {printf("\n%s is a NUMBER",yytext);}
" " ;
"\n\t" ;
. {printf("\nInvalid lexeme %s",yytext);}

%%
int yywrap(){}
int main()
{
    FILE *file = fopen("hello.txt","r");
    if (!file)
    {
        printf("Error");
        return;
    }
    yyin = file;
    yylex();
    close(file);
    return 0;
}

void yyerror(const char *s)
{
    return;
}