

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false
*/



#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isValid(char* s){
    char stack[1000];
    int top=-1;
    for(int i=0;s[i]!='\0';i++){
        char c=s[i];
        if(c=='(' || c=='{' || c=='['){
            stack[++top]=c;
        }else{
            if(top==-1) return false;
            if(c==')' && stack[top]!='(') return false;
            if(c=='}' && stack[top]!='{') return false;
            if(c==']' && stack[top]!='[') return false;
            top--;
        }
    }
    if(top==-1) return true;
    return false;
}

int main(){
    char s[]="([])";
    if(isValid(s)) printf("true");
    else printf("false");
    return 0;
}
