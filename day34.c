
/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
*/


#include <stdio.h>
#include <ctype.h>

int calculate(char* s){
    int stack[1000];
    int top=-1;
    int num=0;
    char op='+';
    for(int i=0;s[i]!='\0';i++){
        if(isdigit(s[i])){
            num=num*10+(s[i]-'0');
        }
        if((!isdigit(s[i]) && s[i]!=' ') || s[i+1]=='\0'){
            if(op=='+') stack[++top]=num;
            else if(op=='-') stack[++top]=-num;
            else if(op=='*'){
                int a=stack[top--];
                stack[++top]=a*num;
            }else if(op=='/'){
                int a=stack[top--];
                stack[++top]=a/num;
            }
            op=s[i];
            num=0;
        }
    }
    int res=0;
    for(int i=0;i<=top;i++) res+=stack[i];
    return res;
}

int main(){
    char s[]="3+2*2";
    printf("%d",calculate(s));
    return 0;
}
