#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

char input[100][100];
char table[100][100];

void main()
{
    int n;
    printf("\nEnter number of lines :");
    scanf("%d",&n);
    printf("\nEnter the lines :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s",input[i]);
    }
    for(int i=0;i<n;i++)
    {
        table[i][0]=input[i][3];
        table[i][1]=input[i][2];
        table[i][2]=input[i][4];
        table[i][3]=input[i][0];
    }
    printf("\nOP\t\t\tOP1\t\t\tOP2\t\t\tRESULT\n");
    for(int i=0;i<n;i++)
    {
        printf("%c\t\t\t",table[i][0]);
        printf("%c\t\t\t",table[i][1]);
        printf("%c\t\t\t",table[i][2]);
        printf("%c\n",table[i][3]);
    }
}