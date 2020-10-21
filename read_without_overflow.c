#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[10];
    printf("Give a string with much more than %ld chars here: ", sizeof(buffer)-1);
    fflush(stdout); // force stdout to print without \n
    fgets(buffer, sizeof(buffer), stdin);
    // fgets aways read sizeof - 1 characters, in order to
    // reserve the last position to '\0'(the end of this string)
    
    // strlen counts every character until '\n', inclusive, or
    // '\0', not inclusive. This first statement verifies 
    // whether the string was partially filled (less than max),
    // OR entirelly filled, at it's maximum or overflown
    // (cases in which cannot be differentiated)
    if( !(strlen(buffer) < sizeof(buffer)-1) ) {
        // if the string was successfully filled, it's time
        // to verify if it has only characters until '/0'
        // or: characters+'\n'+'\0'
        
        // the first scenario means that '\n' is still in
        // stdin, so the memory must be cleaned by getting
        // every character exceeded
        
        // the last scenario doesn't deserve much attention, 
        // since every byte until '\n' has been stored in our
        // string
        if(buffer[sizeof(buffer)-2] != '\n') {
            // "clean" stdin, by getting any character
            // overflown
            do { } while(getchar() != '\n');
            // aways fill the last char as '\n' for
            // formatting purposes, and compatibility
            // with another string functions
            buffer[sizeof(buffer)-1] = '\n';
        }
    }
    printf("The string stored was: %s\n\n", buffer);
    
    printf("I'm waiting for YOUR input, not stdin: ");
    fflush(stdout); // force stdout to print without \n
    // code responsible for secure reading of stdin
    fgets(buffer, sizeof(buffer), stdin);
    if( !(strlen(buffer) < sizeof(buffer)-1) ) {
        if(buffer[sizeof(buffer)-2] != '\n') {
            do { } while(getchar() != '\n');
            buffer[sizeof(buffer)-1] = '\n';
        }
    } // end reading without overflow
    printf("The another string stored was: %s\n\n", buffer);
    
    return 0;
}
