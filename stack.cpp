// IMPLEMENTING STACK USING SINGLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class stack
{

    private:

        struct node
        {

            int data;
            struct node* next;

        };

        struct node* head;

    public:

        stack ()
        {
            head = nullptr;
        }

        int push(int);
        int pop();
        void peek();

};

// Main block 

int main()
{
    int num,choice;
    stack s1;
    
    while(1)
    {

    system("clear");
    printf("Your options are:\n1. Push\n2. Pop\n3. Peek\n4. Exit\n");
    printf("Enter your option");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:

            printf("Enter Number to be inserted");
            scanf("%d",&num);
            if (s1.push(num))
            {

                printf("Inserted successfully\n");

            }

            else
            {

                printf("Insertion Unsuccessful\n");
            }

            break;

        case 2:
            
            if (s1.pop())
            {

                printf("Deleted successfully\n");

            }

            else
            {

                printf("Deletion Unsuccessful\n");
            }

            break;

        case 3:

            s1.peek();

            break;

        case 4:

            exit(0);

        case 5:

            printf("Invalid choice\n");
            break;
    }

    printf("Press Enter Again");
    getchar();
    getchar();

    }
}

// METHOD TO PUSH AN ELEMENT INTO THE STACK 

int stack::push(int num)
{

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;

    if (head==nullptr)
    {
        
        newnode->next = nullptr;
        head = newnode;
        return 1;

    }

    else
    {

        struct node* temp = head;
        newnode -> next = head;
        head = temp;
        return 1;
    }

    return 0;
    
}

// METHOD TO POP AN ELEMENT OUT OF THE STACK 

int stack::pop()
{

    if (head==nullptr)
    {

        printf("The stack is empty.");
        return 0;

    }

    else
    {

    struct node* temp = head;
    head = temp->next;
    int d = temp->data;
    free(temp);
    return d;

    }
}

// METHOD TO PEEK AN ELEMENT 

void stack::peek()
{

    if (head==nullptr)
    {

        printf("The list is empty\n");

    }

    else
    {

        struct node* temp = head;
        printf("%d\n", temp->data);

    }
}
    
