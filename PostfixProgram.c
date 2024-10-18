#include <stdio.h>
#include <string.h>
#include <ctype.h>

char infix[100], stack[100];
int top = -1;

void push(char a) 
{
    if (top == 99) 
    {
        printf("Overflow\n");
    } else 
    {
        top++;
        stack[top] = a;
    }
}

char pop() 
{
    if (top == -1) 
    {
        printf("Underflow\n");
        return '\0';
    }
    return stack[top--]; 
}

int priority(char b) {
    if (b == '(') return 0;
    if (b == '*' || b == '/') return 2;
    if (b == '^') return 3;
    if (b == '+' || b == '-') return 1;
    return -1; 
}

int main() {
    int i;
    printf("Enter your expression: ");
    scanf("%s", infix);
    
    int length = strlen(infix);
        infix[length] = ')'; 
        infix[length + 1] = '\0'; 
    push('('); 
    length = strlen(infix); 

    for (i = 0; i < length; i++) 
    {
        if (infix[i] == '(') 
        {
            push(infix[i]);
        } 
        else if (isalnum(infix[i])) 
        {
            printf("%c", infix[i]); // Print operands directly
        } 
        else if (infix[i] == '^' || infix[i] == '-' || infix[i] == '+' || infix[i] == '*' || infix[i] == '/') 
        {
            while (priority(stack[top]) >= priority(infix[i]))
            {
                printf("%c", pop()); 
            }
            push(infix[i]); 
        } 
        else if (infix[i] == ')') 
        {
            while (stack[top] != '(') 
            {
                printf("%c", pop()); 
            }
            pop(); 
        }
    }
    return 0;
}
