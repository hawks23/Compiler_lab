%{
    #include<stdio.h>
    int valid = 1;
%}

%token id num keyword
%%

start : term ';'  
    {
        printf("It is valid\n");
    }
    ;
term : keyword id '=' num
    ;

%%

int yyerror()
{
    valid = 0;
    printf("Not valid\n");
    return 1;
}

int main()
{
    printf("Enter expression: ");
    yyparse();
    return 0;
}
