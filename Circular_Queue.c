#include <stdio.h>
int front=-1;
int rear=-1;
int Size=4;
int CircularQ[4];
void reset()
{
    if (front==rear);
    front=rear=-1;
}
int enque(int a)
{
    if (front==-1 && rear==-1)
    {
        front+=1;
        rear+=1;
        CircularQ[rear]=a;
        printf("The number inserted is: %d\n",a);

    }
    else if (rear==Size-1 && front!=0)
    {
        rear=0;
        CircularQ[rear]=a;
        printf("The number inserted is: %d\n",a);
    }
    else if ((rear==Size-1 && front==0)||(rear+1%Size==front))
    {
        printf("Circular Queue is full\n");
    }
    else
    {
        rear+=1;
        CircularQ[rear]=a;
        printf("The element inserted is: %d\n",a);
    }

}
int deque()
{
    if ((rear==-1 && front==-1)||(front>=rear))
    {
        printf("Underflow\n");
    }
    else if (front==Size-1)
    {
        printf("The number deleted is %d\n",CircularQ[front]);
        front=0;
        void reset();
    }
    else
    {
        printf("The number deleted is %d\n",CircularQ[front]);
        front+=1;
        void reset();
    }

}
void display()
{
    if (front==-1)
    {
        printf("No elements in Circular Queue\n");
    }
    else if (front>rear)
    {
        for (int i=front;i<Size;i++)
        {
            printf("%d\n",CircularQ[i]);
        }
        for (int i=0;i=rear;i++)
        {
            printf("%d\n",CircularQ[i]);
        }
        
    }
    else if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d\n",CircularQ[i]);
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
            enque(ins);
        }
        else if (var==2)
        {
             deque();
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