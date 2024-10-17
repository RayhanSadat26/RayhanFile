#include <stdio.h>
#include <string.h>
char infix[20],postfix[20],stack[20],a;
char temp;
int length,postfixindex=0,pos;
int top=-1;
void infixtopostfix();
void push(char a);
char pop();
int priority(char a);
int priority(char a)
{
    int p;
    switch(a)
    {
        case '^':
        {
            p=3;
            break;
        }
        case '*':
        case'/':
        {
            p=2;
            break;
        }
        case '+':
        case '-':
        {
            p=1;
            break;
        }
        case '(':
        {
            p=0;
            break;
        }
    }
    return (p);
}
void push(char a)
{
    if (top==20)
    {
        printf("Stack is full");
    }
    else
    {
        top=top+1;
        stack[top]=a;
    }
}
char pop()
{
    char b;
    if (top==-1)
    {
        printf("Underflow");
    }
    else
    {
        return stack[top];
        top=top-1;
    }
}
void infixtopostfix()
{
    int index1=0;
    length=strlen(infix);
    push('#');
    while(index1<length)
    {
        a=infix[index1];
        switch(a)
        {
            case '(':
            {
                push(a);
            }
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            {
                while (priority(stack[pos])>=priority(a))
                {
                    temp=pop();
                    postfix[pos++]=a;

                }
                push(a);
                break;
            }
            case ')':
            {
                temp=pop();
                while (temp!='(')
                {
                    postfix[pos]=temp;
                    pos++;
                    temp=pop();
                }
                break;
            }
            default:
            {
                postfix[pos++]=a;
            }
            index1++;
        }
        while (top>0)
        {
            temp=pop();
            postfix[pos++]=temp;
        }
    }

}
void main()
{
    printf("Enter you infix");
    scanf("%s",&infix);
    infixtopostfix();
    printf("Postfix is %s",postfix);
}