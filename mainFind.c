#include <stdio.h>
#include "txtfind.h"

#define WORD 30

int main(){

    char str[WORD];
    get_word(str);
    char c;
    scanf(" %c", &c);
    if(c == 'a') {
        print_lines(str);
    }
    if(c == 'b') {
        print_similar_words(str);
    }
}