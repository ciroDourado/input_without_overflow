#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;
    printf("Give a string here: ");
    fflush(stdout);
    scanf("%c", &c);
    printf("The first character of the string was stored in the char variable: %c\n\n", c);
    
    printf("This code will be executed automatically: ");
    fflush(stdout);
    scanf("%c", &c);
    printf("The second character of the string is still in memory, and is: %c\n\n", c);
     
    return 0;
}
