#include <stdio.h>
#include <stdlib.h>

void enqueue(int size,int a[]);

void dequeue(int size , int a[]);

void Peek(int a[]);

int IsFull(int size_of_queue);

int IsEmpty();

void Display(int size_of_queue , int a[]);

int front = -1;

int rear = -1;

int main()
{
    int user_choice;

    int size_of_queue;

    int queue[size_of_queue];

    int to_continue = 0;

    printf("Enter the Size of the Queue : ");

    scanf("\n%d" , &size_of_queue);

    while(user_choice != 5)
    {
        printf("Choose operation : \n 1. Enqueue \n 2. Dequeue \n 3. Peek \n 4. Display \n 5. Stop\n");

        scanf("%d",&user_choice);

        switch(user_choice)
        {
            case 1:
                enqueue(size_of_queue,queue);
                break;

            case 2:
                dequeue(size_of_queue,queue);
                break;

            case 3:
                Peek(queue);
                break;

            case 4:
                Display(size_of_queue , queue);
                break;
        }
    }

    return 0;
}

int IsEmpty()
{
    if (front == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int IsFull(int size)
{
    if (( front == 0&& rear == size - 1) || (rear + 1 == front))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void enqueue(int size , int a[])
{
    if(IsFull(a) == 0)
    {
        printf("The Queue if Full \n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if ( rear == size - 1 )
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }

        int element;

        printf("Enter the element to add : ");

        scanf("%d" , &element);

        a[rear] = element;

        printf("\n%d is inserted\n",element);
    }
}

void dequeue(int size , int a[])
{

    if (IsEmpty() == 0)
    {
        printf("The Queue is empty\n");
    }
    else
    {
        int element;
        element = a[front];

        if (front == rear)
        {
            front = -1 ;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }

        printf("%d is deleted\n" , element);

    }
}

void Peek(int a[])
{
    printf("The front element of the queue is %d\n" , a[front]);
}

void Display(int size , int a[])
{
    if (IsEmpty() == 0)
    {
        printf("The Queue is Empty\n");
    }
    else
    {
        printf("The Elements of the Queue are : \n");

        if (rear > front)
        {
            for (int i = front ; i < rear ; i++)
            {
                printf("%d" , a[i]);
            }

        }
        else
        {
            for (int i = front ; i < size - 1 ; i++)
            {
                printf("%d",a[i]);
            }
        }
    }
}
