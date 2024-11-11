%{
int length = 0;
int var = 0;
%}

%%

[a-zA-Z]    { 
    
    length++;
}

[a-zA-Z][a-zA-Z_0-9]* {var++;}

[ \n] {}


%%

int main(int argc, char **argv) {
    FILE *file = fopen("input.txt", "r");  
    if (!file) {
        printf("Could not open the file\n");
        return 1;
    }
    yyin = file;
    yylex();  
    printf("\nWord length = %d\n",length);
    printf("\nVariable length = %d\n",var);
    fclose(file);
    return 0;
}

int yywrap() {
    return 1;
}