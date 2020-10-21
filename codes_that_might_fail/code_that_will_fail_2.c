#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[10];
    printf("Give a string with much more than 10 chars here: ");
    fflush(stdout); // force stdout to print
    fgets(buffer, sizeof(buffer), stdin);
    printf("The string stored was: %s\n\n", buffer);
    
    printf("This code will be executed automatically: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    printf("The remaining chars are still in memory, and are: %s\n\n", buffer);
     
    return 0;
}
