// METHOD TO IMPLEMENT QUEUE ADT USING SINGLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class queue 
{
    private:
        struct node
        {

            int data;
            struct node* next;

        };

        struct node* head;

    public:

        queue ()
        {
            head = nullptr;
        }

        int enqueue(int);
        int dequeue();
        void peek();

};

// Main block

int main()
{

    int num , choice;
    queue q1;

    while(1)
    {

    system("clear");
    printf("Your options are:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);

        switch(choice)
        {

            case 1:

                printf("Enter the number to be enqueued");
                scanf("%d",&num);
                if (q1.enqueue(num))
                {
                    printf("Insertion Successful\n");
                }

                else
                {
                    printf("Insertion Unsuccessful\n");
                }

                break;
        
            case 2:

                if (q1.dequeue())
                {
                    printf("Deletion Successful\n");
                }

                else
                {
                    printf("Deletion Unsuccessful\n");
                }

                break;

            case 3:
             
                q1.peek();
                break;

            case 4:

                exit(0);

            default:

                printf("Invalid choice\n");
                break;

        }

        printf("Press Enter Again");
        getchar();
        getchar();

    }
}

// METHOD TO ENQUEUE AN ELEMENT

int queue::enqueue(int num)
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
        newnode->next = temp;
        head = newnode;
        return 1;

    }
    return 0;

}

// METHOD TO DEQUEUE AN ELEMENT 

int queue::dequeue()
{
    if (head == nullptr)
    {
        printf("The queue is empty\n");
        return 0;
    }
    else if (head->next == nullptr)
    {
        // If there is only one node in the queue
        free(head);
        head = nullptr;
        return 1;
    }
    else
    {
        struct node* temp = head;
        struct node* prev = nullptr;

        // Traverse to the last node while keeping track of the previous node
        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }

            // Otherwise, set the next pointer of the previous node to nullptr
            prev->next = nullptr;

        // Free the memory of the last node
        free(temp);
        return 1;
    }
}


// Method to peek 

void queue::peek()
{
    if (head==nullptr)
    {

        printf("The list is empty\n");

    }

    else
    {

        struct node* temp = head;
        printf("%d",temp->data);

    }
}