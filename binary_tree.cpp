// IMPLEMENTATION OF BINARY TREE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class binary_tree
{
    private:

        struct node
        {
        
            int data;
            struct node* right;
            struct node* left;

        };

        struct node* root;

    public:
     
        binary_tree()
        {
            root = nullptr;
        }

        int insert(int,struct node*);
        void inorder();
        void preorder();
        void postorder();
        int search(int);
        int ins(int);

};

// MAIN BLOCK 

int main()
{
    int num,choice;
    binary_tree b1;

    while(1)
    {
        system("clear");
        printf("Your options are:\n1. Insertion\n2. Inorder traversal\n3. Preorder traversal\n4. Postorder traversal\n5. Search\n6. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            
            case 1:

                printf("Enter number to be inserted:\n");
                scanf("%d",&num);
                if (b1.ins(num))
                {

                    printf("Number inserted Successfully\n");
    
                }

                else 
                {

                    printf("Insertion unsuccessful\n");

                }

                break;

                case 2:
                 
                    b1.inorder();
                    break;

                case 3:

                    b1.preorder();
                    break;

                case 4:

                    b1.postorder();
                    break;

                case 5:

                    printf("Enter number to be searched:\n");
                    scanf("%d",&num);
                    if (b1.search(num))
                    {
                        printf("Number exists");
                    }

                    else
                    {
                        printf("Number does not exist");
                    }

                    break;

                    case 6:

                        exit(0);

                    default:

                        printf("Invalid choice");
                        break;

        }
        printf("Press Enter Again");
        getchar();
        getchar();
    }
}

// Method to implement insertion

int binary_tree::insert(int num,struct node* root)
{
    
        int choice;
        printf("%dLeft or right??",&choice);

        switch(choice)
        {
            case 'L':
                
        
                if (root==nullptr)
                {

                    struct node* newnode = (struct node*)malloc(sizeof(struct node));
                    newnode->data = num;
                    newnode->right = nullptr;
                    newnode->left = nullptr;
                    root->left = newnode;
                    return 1;
                
                }

                else
                {
                    root = root->left;
                    insert(num,root);
                }

            case 'R':
                
        
                if (root==nullptr)
                {

                    struct node* newnode = (struct node*)malloc(sizeof(struct node));
                    newnode->data = num;
                    newnode->right = nullptr;
                    newnode->left = nullptr;
                    root->right = newnode;
                    return 1;
                
                }

                else
                {
                    root = root->right;
                    insert(num,root);
                }
        }
    }

// helper method

int binary_tree::ins(int num)
{

    if (root==nullptr)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->right = nullptr;
        newnode->left = nullptr;
        root = newnode;
        return 1;
    }

    else
    {
        return insert(num,root);
    }
}