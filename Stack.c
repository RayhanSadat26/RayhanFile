#include <stdio.h>
int top=-1, stack[1000],size;
int push(int a,int b)
{
    if (top==b)
    {
        printf("Stack is full\n");
    }
    else
    {
        top=top+1;
        stack[top]=a;
        printf("%d pushed to stack\n",a);
    }

}
int pop()
{
    if (top==-1)
    {
        printf("Stack is empty : underflow\n");
    }
    else
    {
        printf("Element that is popped is %d\n",stack[top]);
        top=top-1;
    }
}
int display()
{
    if (top==-1)
    {
        printf("No elements in the stack\n");
    }
    else 
    {
        for (int i=top;i>=0;i--)
        {
            printf("%d element is %d\n",i,stack[i]);
        }
    }
}
void main()
{
    int value,a,b;
    for (int i=0;i<1000;i++)
    {
        printf("Enter if you want to push or pop and element or if  u want to display the elements in the stack: Press 1  to push , 2  to pop, 3  to display and 4 to exit\n");
        scanf("%d",&value);
        if (value==1)
        {
            printf("Enter value to push");
            scanf("%d",&a);
            printf("Stack limit\n");
            scanf("%d",&b);
            push(a,b);
        }
        else if (value==2)
        {
            pop();
        }
        else if (value==3)
        {
            display();
        }
        else if (value==4)
        {
            break;
        }
        else{
            printf("Invalid input");
        }

    }
}
