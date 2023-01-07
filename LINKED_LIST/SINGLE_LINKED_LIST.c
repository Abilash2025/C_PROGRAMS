#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert_at_front(int element);

void insert_at_end(int element);

void insert_after_node(int element , int user_node);

void delete_at_front();

void delete_at_end();

void delete_node(int usernode);

void display(struct node *n);

void reverse();


struct node *head;

int main()
{
    int flag =  1;

    while (flag == 1)
    {

        int choice , element;
        
        printf("Choose : \n 1.Insert\n 2.Delete\n 3.Display\n 4.Stop\n");
        scanf("%d",&choice);

        if (choice == 1)
        {
            printf("Enter element to insert : ");
            scanf("%d" , &element);
        
            if (head == NULL)
            {
                insert_at_front(element);
            }
            else
            {
                int insert_choice;
                printf("Where do you want to insert :\n 1.Insert at front \n 2.Insert at end \n 3.Insert after a node\n");
                scanf("%d",&insert_choice);

                if (insert_choice == 1)
                {
                    insert_at_front(element);
                }
                else if (insert_choice == 2)
                {
                    insert_at_end(element);
                }
                else
                {
                    int user_node;
                    printf("Enter the node : ");
                    scanf("%d",&user_node);
                    insert_after_node(element,user_node);
                }
            }
        }

        else if (choice == 2)
        {
            if (head == NULL)
            {
                printf("The list is empty");
            }
            else
            {
                int delete_choice;
                printf("Where do you want to delete :\n 1.Delete from front \n 2.Delete from end \n 3.Delete a node\n");
                scanf("%d",&delete_choice);

                if (delete_choice== 1)
                {
                    delete_at_front(element);
                }
                else if (delete_choice== 2)
                {
                    delete_at_end(element);
                }
                else
                {
                    int user_node;
                    printf("Enter the node : ");
                    scanf("%d",&user_node);
                    delete_node(user_node);
                }
            }
        }
        
        else if (choice == 3)
        {
            display(head);
        }
        
        else if (choice == 4)
        {
            flag = 0;
        }
    }

    if (head != NULL)
    {
        printf("The linked list is : ");
        display(head);
      
        printf("Do you want to reverse the linked List (1- yes / 0 - No ) : ");

        scanf("%d",&flag);

        if (flag == 1)
        {
            reverse();
        }

    }

}

void insert_at_front(int element)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode ->data = element;
    newnode ->next = head;
    head = newnode;
    printf("%d is inserted at front\n",head->data);

}

void insert_at_end(int element)
{
    struct node *newnode,*temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode ->data = element;
    newnode ->next = NULL;

    temp = head;
    
    while (temp ->next != NULL)
    {
        temp = temp->next;
    }
    temp ->next = newnode;
    printf("%d is inserted at the end\n",element);
}

void insert_after_node(int element , int user_node)
{
    struct node *newnode,*temp;
    int i = 1;

    temp = head;
    while ( i < user_node)
    {
        temp = temp ->next;
        i++;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = temp->next;
    temp->next = newnode;
    printf("%d is inserted after %d th node\n",element,user_node);
}

void delete_at_front()
{
    struct node *temp;
    temp = head;
    printf("%d is deleted from front\n",head->data);
    head = head->next;
    free(temp);
}

void delete_at_end()
{
    struct node *temp,*prevnode;
    temp = head;
    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp ->next;
    }
    prevnode->next = NULL;
    printf("%d is deleted from end\n",temp->data);
    free(temp);

}
void delete_node(int usernode)
{
    struct node *temp, *prevnode;

    prevnode = head;
    int i = 1;
    while (i < usernode - 1)
    {
        prevnode = prevnode->next;
        i++;
    }
    temp = prevnode->next;
    prevnode->next = temp->next;
    printf("%d is deleted (%d node)\n",temp->data,usernode);
    free(temp);
}

void display(struct node *n)
{
    while (n != NULL)
    {
        printf("%d ",n->data);
        n = n->next;
    }
    printf("\n");
}

void reverse()
{
    struct node *prevnode,*currentnode,*nextnode;

    prevnode = NULL;
    currentnode = head;
    nextnode = head;

    while(nextnode != NULL)
    {
        nextnode = nextnode->next;
        currentnode ->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    
    head = prevnode;

    display(head);
}
