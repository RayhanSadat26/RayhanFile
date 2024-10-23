#include <stdio.h>
int Size=6;
int front=-1;
int rear=-1;
int Q[1000];
void reset()
{
    if (front==rear)
    {
        front=rear=-1;
    }
}
int insert(int a)
{
    if(front==-1 && rear==-1)
    {
        front+=1;
        rear+=1;
        Q[rear]=a;
        printf("Element instered is %d\n",a);
    }
    else if(rear==Size-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear+=1;
        Q[rear]=a;
        printf("Element inserted is %d\n",a);
    }
}
void delete()
{
    if(front==-1||front>=rear)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("The element deleted in the Queue is %d\n",Q[front]);
        front+=1;
        reset();
        
    }
}
void display()
{
    int i;
    if ((front==rear)&&(front!=0))
    {
        printf("No elements in Queue\n");
    }
    else
    {
        for (i=0;i<Size;i++)
        {
            printf("%d\n",Q[i]);
        }
    }
}
void main()
{
    int var,ins;
    for(int i=0;i<100;i++)
    {
        printf("Enter 1 to insert and 2 to delete and 3 to display,4 to exit\n");
        scanf("%d",&var);
        if (var==1)
        {
            printf("Enter element to insert");
            scanf("%d",&ins);
            insert(ins);
        }
        else if (var==2)
        {
             delete();
        }
        else if (var==3)
        {
            display();
        }
        else
        {
            printf("Invalid input\n");
        }
               
         
    }
}
