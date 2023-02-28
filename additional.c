#include <stdio.h>

char Choice()
{
    char input;
    char symb = '9';
    char garb[50];

beginning:
    printf("\nEnter your choice: ");
    scanf("%c", &input);
    fgets(garb, sizeof(garb), stdin);
    printf("\n");

    if (input < '1' || input > '9') {
        printf("Only numbers 1 to 8 can be chosen.\n");
        printf("If you want to try again type 'Y', if no, type 'N':\n");
        scanf("%c", &symb);
        fgets(garb, sizeof(garb), stdin);
        if (symb == 'Y') {
            goto beginning;
        }else {
            return '9';
        }
    }

    return input;
}