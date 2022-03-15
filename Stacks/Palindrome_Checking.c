// Logic : https://www.geeksforgeeks.org/check-whether-the-given-string-is-palindrome-using-stack/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char* stack;
int top = -1;
 
void push(char ele){
    stack[++top] = ele;
}
 
char pop(){
    return stack[top--];
}
 
int isPalindrome(char str[]){
    int length = strlen(str);
 
    stack = (char*)malloc(length * sizeof(char));
 
    int i, mid = length / 2;
 
    for (i = 0; i < mid; i++) {
        push(str[i]);
    }
 
    // Ignore the middle character if odd
    if (length % 2 != 0) {
        i++;
    }
 
    while (str[i] != '\0') {
        char element = pop();
 
        if (element != str[i])
            return 0;
        i++;
    }
 
    return 1;
}
 
// Driver code
int main(){
    char str[] = "madam";
 
    if (isPalindrome(str)) {
        printf("It is a Palindrom");
    } else {
        printf("It is not a Palindrome");
    }
 
    return 0;
}