#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[10];
    printf("Give a string with much more than 10 chars here: ");
    fflush(stdout); // force stdout to print without \n
    fgets(buffer, sizeof(buffer), stdin);
    do { } while(getchar() != '\n');
    printf("The string stored was: %s\n\n", buffer);
    
    printf("I'm waiting for YOUR input, not stdin: ");
    fflush(stdout); // force stdout to print without \n
    fgets(buffer, sizeof(buffer), stdin);
    printf("The another string stored was: %s\n\n", buffer);
    
    return 0;
}
