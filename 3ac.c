#include <stdio.h>
#include <ctype.h>
#include <string.h>

void generate_three_address_code(char expr[]) {
    int tempVarCount = 1;
    char temp[3];
    int i = 0;
    
    printf("Three Address Code:\n");

    // Continue until the end of the string
    
    while (i<strlen(expr)) {
        int j = 0;

        // Find the next operation to process (assuming left to right)
        while (expr[j] != '\0' && !(isalnum(expr[j]) && 
              (expr[j + 1] == '+' || expr[j + 1] == '-' || expr[j + 1] == '*' || expr[j + 1] == '/') &&
              isalnum(expr[j + 2]))) {
            j++;
        }

        // If a valid operation is found
        if (expr[j] != '\0') {
            char op1 = expr[j];
            char oper = expr[j + 1];
            char op2 = expr[j + 2];
            
            // Generate a temporary variable
            char temp = 'A' + tempVarCount; 
            tempVarCount++;
            // Print the three-address code for the current operation
            printf("\n%c = %c %c %c", temp, op1, oper, op2);
            
            // Replace the processed part of the expression with the temporary variable
            expr[j]=temp;
            
            // Shift the remaining part of the expression
            int k = j + 2;
            while (expr[k] != '\0') {
                expr[j + 1] = expr[k + 1];
                j++;
                k++;
            }
            expr[j + 1] = '\0'; // Null-terminate the string
            printf("\nModified string : %s",expr);
        }
        i++;
    
    }
}

int main() {
    char expression[20];
    
    printf("Enter a simple arithmetic expression (e.g., a+b-c): ");
    scanf("%s", expression);
    
    generate_three_address_code(expression);
    
    return 0;
}