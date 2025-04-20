#include <stdio.h>
#include <conio.h>
#include <string.h>

void main() {
    char text[100], pattern[100];
    int i, j, n, m, flag=0;

    clrscr();  

    printf("Enter the text: ");
    gets(text); 
    printf("Enter the pattern: ");
    gets(pattern);

    n = strlen(text);
    m = strlen(pattern);

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            printf("Pattern found at position: %d\n", i);
            flag=1;
        }
    }

    if(flag==0)
        printf("Pattern not found.\n");

    getch();
}
