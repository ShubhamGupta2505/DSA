#include <stdio.h>
#include <stdlib.h>
int Queue[5];
int front = -1;
int rear = -1;
void enqueue(int x)
{
    if(rear == 4)
    {
        printf("Overflow");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear =0;
        Queue[rear] = x;
    }
    else
    {
        rear++;
        Queue[rear] = x;
    }
}
void dequeue()
{
    int y = front;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty.");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("%d ",Queue[front]);
        printf("\n");
        //free(Queue[front]);

        front++;
        //free(Queue[front]);
    }
}
void display()
{
    int i;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        for(i = front;i<rear+1;i++)
        {
            printf("%d ",Queue[i]);

        }
    }
    printf("\n");
}
void peak()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty ");
    }
    else
    {
        printf("%d ",Queue[front]);
    }
}
int main()
{
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    dequeue();
    dequeue();
    dequeue();
    //dequeue();
    display();
    return 0;
}
