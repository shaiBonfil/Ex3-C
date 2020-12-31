#include <stdio.h>
#include <string.h>
#include "txtfind.h"

#define LINE 256
#define WORD 30

//The function gets a string and saves it.
//The function returns the amount of characters actually absorbed.
int get_line(char s[]){
    int count = 0;
    char c = getchar();
    s[0] = c;
    while(c != '\n' && c != EOF){
        count++;
        c = getchar();
        s[count] = c;
    }
    s[count] = '\0';
    if(c == EOF){
        return EOF;
    }
    return count;
}

//The function gets a string and saves it.
//The function returns the number of characters in the word.
int get_word(char w[]){
    int count = 0;
    char c = getchar();
    w[0] = c;
    while(c != '\n' && c != '\t' && c != ' ' && c != '\r' && c != EOF){
        count++;
        c = getchar();
        w[count] = c;
    }
    w[count] = '\0';
    if(c == EOF){
        return EOF;
    }
    return count;
}

//The function gets two strings and checks if the first string containes the second string.
int subString(char *str1, char *str2){
    int count = 0, i = 0, j = 0;
    while(str1[i] != '\0' && str2[j] != '\0'){
        if(str1[i] == str2[j]){
            j++;
            i++;
            count++;
        }
        else{
            i++;
            j = 0;
            count = 0;
        }
    }
    if(count == 0){
        return 0;
    }
    return 1;     
}

//The function gets two strings and a n number.
//The function will check if the second string is equals to the first string,
//by less the number n of characters.
int similar(char *s, char *t, int n){
    int i = 0, j = 0;
    while(s[i] != '\0' || t[j] != '\0'){
        if(s[i] == t[j]){
            j++;
            i++;
        }
        else{
            i++;
            n--;
        }
    }
    if(n == 0){
        return 1;
    }
    return 0;
}

//The function gets a string, absorbed the lines of text,
//and prints the lines in which the desired string appears.
void print_lines(char *str){
    char line [LINE];
    int len = 0;
    while(len != EOF){
        len = get_line(line);
        if(subString(line, str)){
            printf(" %s\n", line);
        }
    }
}

//The function gets a string for searching, absorbed the text words
//and prints the words similar to the search string, to the point of
//ommiting one letter from the word that appear in the text.
void print_similar_words(char *str){
    char word [WORD];
    int len = 0;
    while(len != EOF){
        len = get_word(word);
        if(similar(word, str, 0)){
            printf(" %s\n", word);
        }
        if(similar(word, str, 1)){
            printf(" %s\n", word);
        }
    }
}
