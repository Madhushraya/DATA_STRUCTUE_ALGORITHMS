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
        void inorder(struct node*);
        void preorder(struct node*);
        void postorder(struct node*);
        int search(int,struct node*);
        int ins(int);
        void display(int);
        int s(int);

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

                    
                    b1.display(2);
                    break;

                case 3:

                    
                    b1.display(3);
                    break;

                case 4:

                    
                    b1.display(4);
                    break;

                case 5:

                    printf("Enter number to be searched:\n");
                    scanf("%d",&num);
                    if (b1.s(num))
                    {
                        printf("Number exists\n");
                    }

                    else
                    {
                        printf("Number does not exist\n");
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
    
        char choice;
        printf("LorY");
        scanf(" %c",&choice);

        switch(choice)
        {
            case 'L':
                
        
                if (root->left==nullptr)
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
                    return 1;
                }
                return 0;

            case 'R':
                
        
                if (root->right==nullptr)
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
                    return 1;
                }
                return 0;
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
        insert(num,root);
    }
}

// Method to do inorder traversal

void binary_tree::inorder(struct node* root)
{
    if(root!=nullptr)
    {

        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);

    }

}

// Method to do preorder traversal

void binary_tree::preorder(struct node* root)
{
    if(root!=nullptr)
    {
        
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}

// Method to do postorder traversal

void binary_tree::postorder(struct node* root)
{
    if(root!=nullptr)
    {
        
        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->data);
    
    }
}

// helper method

void binary_tree::display(int choice)
{
    switch(choice)
    {
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
    }
}

// method to search 
int binary_tree::search(int num, struct node* root) {
    if (root == nullptr) {
        return 0;
    } 
    if (root->data == num) {
        return 1;
    } 
    // Recursively search in the left and right subtrees
    return search(num, root->left) || search(num, root->right);
}

// helper method
int binary_tree::s(int num) {
    // Call the search method with the root of the binary tree
    return search(num, root);
}

