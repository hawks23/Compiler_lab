%{
    #include "y.tab.h"
    int yywrap();
%}

letter [a-zA-Z]
digit [0-9]

%%

"int"                   { return keyword; }
{letter}({letter}|{digit})* { return id; }
{digit}+                { return num; }
"="                     { return '='; }
";"                     { return ';'; }
[ \t\n]                 ; // Ignore whitespace

.                       { return yytext[0]; } // Return any other single character

%%

int yywrap()
{
    return 1;
}
