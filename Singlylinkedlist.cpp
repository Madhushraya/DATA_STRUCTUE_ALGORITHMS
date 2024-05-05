// IMPLEMENTATION OF SINGLY LINKED LIST

// Importing Necessary Modules

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Class Definition 

class Singlylinkedlist
{

    private:

        struct node
        {

            int data;
            struct node* next;

        };

        struct node* head;

    public:

        Singlylinkedlist()
        {
            head = nullptr;
        }
        
        // Methods that are to be implemented
        
            int insbeg(int);
            int insend(int);
            int inspos(int,int);
            int delbeg();
            int delend();
            int delpos(int);
            int search(int);
            void display();
            void display_rev();
            void link_reversal();
            int count(); //helper method

};

// Main block 

int main()
{

    int num,choice,pos;
    Singlylinkedlist s1;

    while(1)
    {
            
            system("clear");
            printf("Your options are:\n1.Insert at Begining\n2.Insert at End\n3.Insert at Given Position\n4.Delete at Begining\n5.Delete at End\n6.Delete at given position\n7.Search the given key\n8.Display the content of the list\n9.Display the contents of the list in reverse\n10.Reverse the link\n11.Exit\n");
            printf("Enter your choice");
            scanf("%d",&choice);
            
            switch(choice)
            {
                case 1:

                    printf("Enter number to be inserted\n");
                    scanf("%d",&num);
                    if (s1.insbeg(num))
                    {
                        printf("Number inserted Successfully\n");
                    }
                    
                    else
                    {
                        printf("Insertion Unsuccessful\n");
                    }

                    break;

                case 2:

                    printf("Enter number to be inserted\n");
                    scanf("%d",&num);
                    if (s1.insend(num))
                    {
                        printf("Number inserted Successfully\n");
                    }
                    
                    else
                    {
                        printf("Insertion Unsuccessful\n");
                    }

                    break;

                case 3:

                    printf("Enter number to be inserted\n");
                    scanf("%d",&num);

                    printf("Enter the position to be inserted\n");
                    scanf("%d",&pos);

                    if (s1.inspos(num,pos))
                    {
                        printf("Number inserted Successfully\n");
                    }
                    
                    else
                    {
                        printf("Insertion Unsuccessful\n");
                    }

                    break;
                
                case 4:

                    if (s1.delbeg())
                    {
                        printf("Number deleted Successfully\n");
                    }
                    
                    else
                    {
                        printf("Deletion Unsuccessful\n");
                    }

                    break;
                
                case 8:

                    s1.display();
                    break;

                case 11:

                    exit(0);

                default:

                    printf("Invalid Choice\n");
                    break;

            }
            printf("Press Enter Again\n");
            getchar();
            getchar();
    }

}

// METHOD TO IMPLEMENT INSERTION AT BEGINING 

int Singlylinkedlist::insbeg(int num)
{

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;

    // Checking if the memory allocation is successful

    if (newnode==nullptr)
    {
        printf("Memory Allocation Insuccessful");
    }

    // Checking if the list is empty

    if (head==nullptr)
    {

        newnode -> next = nullptr;
        head = newnode;
        return 1;

    }

    else
    {

        newnode->next = head;
        head = newnode;
        return 1;

    }

    return 0;

}

// METHOD TO INSERT AN ELEMENT AT THE END 

int Singlylinkedlist::insend(int num)
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
        while (temp->next!=nullptr)
        {

            temp = temp->next;

        }

        temp->next = newnode;
        newnode->next = nullptr;
        return 1;

    }
    
    return 0;
}   

// METHOD TO INSERT AN ELEMENT IN THE GIVEN POSITION 

int Singlylinkedlist::inspos(int num,int pos)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
     
    if(head==nullptr)
    {

        newnode->next = nullptr;
        head = newnode;
    
    }

    else
    
    
    
    if (pos > count())
    {

        
        printf("Position exceeds lenght of list.\n");
        return 0;

    }
    
    else
    {

        struct node* temp = head;
        for (int i=0;i<pos;i++)
        {

            temp = temp->next;

        }
            
            newnode->next = temp->next;
            temp->next = newnode;
            return 1;

    }

}


//HELPER MOTHOD

int Singlylinkedlist::count()
{
    struct node* temp = head;
    int count = 0;
    while (temp->next!=nullptr)
    {

        temp = temp->next;
        count++;

    }
    
    return count;

}

// METHOD TO DELETE AN ELEMENT IN THE BEGINING 

int Singlylinkedlist::delbeg()
{

    if (head==nullptr)
    {

        printf("List is empty");
        return 0;

    }

    else
    {
    
        struct node *temp;
        temp = head;
        head = temp->next;
        free(temp);
        return 1;

    }
    return 0;
}

// METHOD TO DISPLAY THE ELEMENTS OF THE LIST

void Singlylinkedlist::display()
{

    struct node* temp = head;
    
    if (head==nullptr)
    {

        printf("List is Empty");

    }

    else
    {

        while(temp!=nullptr)
        {

            printf("%d",temp->data);
            temp = temp->next;

        }
    }
}