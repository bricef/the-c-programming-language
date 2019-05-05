/*
 * Escercise 1-12: Write a program that prints its output one word per line.
 */

#include <stdio.h>
#define OUT 0
#define IN 1

int main(){
    int c, state = OUT, nw = 0;
    while((c = getchar())!=EOF){
        if(c == ' '||c == '\n'||c == '\t'){
            state = OUT;
            putchar('\n');
        }
        else if(state == OUT){
            putchar(c);
            ++nw;
            state = IN;
        }
        else{
            putchar(c);
        }
    }
}
