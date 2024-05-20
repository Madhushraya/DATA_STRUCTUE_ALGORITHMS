#include <stdio.h>
#include <stdlib.h>
#include <time.h>


class DoublyLinkedList 
{
private:
    struct DoublyNode {
        int data;
        DoublyNode* next;
        DoublyNode* prev;
        DoublyNode* up;
        DoublyNode* down;
    };

    DoublyNode* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertBeginning(int);
    void insertEnd(int);
    void deleteBeginning();
    void deleteEnd();
    void display();
    bool search(int);
    void moveUp(int);
    void moveDown(int);
    void insertUp(int, int);
    void insertDown(int, int);
    void deleteUp(int);
    void deleteDown(int);
    bool searchUp(int);
    bool searchDown(int);

};

class MultiCircularLinkedList {
private:
    struct CircularNode {
        int data;
        CircularNode* next;
        CircularNode* prev;
        // Additional pointers for multi-linked list
        CircularNode* up;
        CircularNode* down;

        // Constructor
        CircularNode(int value) : data(value), next(nullptr), prev(nullptr), up(nullptr), down(nullptr) {}
    };

    CircularNode* head;

public:

    MultiCircularLinkedList() 
    {
        head = nullptr;
    }

    void insertEnd(int);
    void deleteBeginning();
    void display();
    bool search(int);
    void moveUp(int);
    void moveDown(int);
    void insertUp(int , int);
    void insertDown(int , int);
    void deleteUp(int);
    void deleteDown(int);

};

#include <iostream>
#include <cstdlib>
#include <ctime>

class SkipList {
private:
    struct Node {
        int data;
        Node** next;

        Node(int d, int level) : data(d) {
            next = new Node*[level + 1];
            for (int i = 0; i <= level; ++i) {
                next[i] = nullptr;
            }
        }

        ~Node() {
            delete[] next;
        }
    };

    Node* head;
    int maxLevel;
    float probability;

    int randomLevel() {
        int level = 0;
        while (static_cast<float>(rand()) / RAND_MAX < probability && level < maxLevel) {
            level++;
        }
        return level;
    }


public:
    SkipList(int maxLvl, float prob) : maxLevel(maxLvl), probability(prob) {
        head = new Node(-1, maxLevel);
        srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    }

    ~SkipList() {
        Node* current = head->next[0];
        while (current != nullptr) {
            Node* temp = current->next[0];
            delete current;
            current = temp;
        }
        delete head;
    }
    void insert(int);
    bool search(int);
    void remove(int);
    void display();
}


void DoublyLinkedList::insertBeginning(int num) 
{
    DoublyNode* newNode = new DoublyNode;
    newNode->data = num;
    newNode->next = head;
    newNode->prev = nullptr;
    newNode->up = nullptr;
    newNode->down = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void DoublyLinkedList::insertEnd(int num) {
   DoublyNode* newNode = new DoublyNode;
    newNode->data = num;
    newNode->next = nullptr;
    newNode->up = nullptr;
    newNode->down = nullptr;
    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }
    DoublyNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void DoublyLinkedList::deleteBeginning() {
   if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    DoublyNode* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::deleteEnd() {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    DoublyNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::display() {
    DoublyNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

void DoublyLinkedList::moveUp(int num) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    DoublyNode* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Node with value " << num << " does not exist" << std::endl;
        return;
    }
    if (current->up != nullptr) {
        head = current->up;
    } else {
        std::cout << "Node " << num << " has no up link" << std::endl;
        return; // Return early if no up link
    }
}


void DoublyLinkedList::moveDown(int num) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    DoublyNode* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Node with value " << num << " does not exist" << std::endl;
        return;
    }
    if (current->down != nullptr) {
        head = current->down;
    } else {
        std::cout << "Node " << num << " has no down link" << std::endl;
        return; // Return early if no down link
    }
}

bool DoublyLinkedList::searchUp(int num) {
    DoublyNode* temp = head;
    while (temp != nullptr) {
        if (temp->data == num) {
            return true;
        }
        temp = temp->up;
    }
    return false;
}

bool DoublyLinkedList::searchDown(int num) {
    DoublyNode* temp = head;
    while (temp != nullptr) {
        if (temp->data == num) {
            return true;
        }
        temp = temp->down;
    }
    return false;
}



bool DoublyLinkedList::search(int num) {
    DoublyNode* temp = head;
    while (temp != nullptr) {
        if (temp->data == num) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}    

void DoublyLinkedList::insertUp(int num, int value) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    DoublyNode* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Node with value " << num << " does not exist" << std::endl;
        return;
    }
    DoublyNode* newNode = new DoublyNode;
    newNode->data = value;
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != nullptr) {
        current->prev->next = newNode;
    } else {
        head = newNode;
    }
    current->prev = newNode;
}

void DoublyLinkedList::insertDown(int num, int value) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    DoublyNode* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Node with value " << num << " does not exist" << std::endl;
        return;
    }
    DoublyNode* newNode = new DoublyNode;
    newNode->data = value;
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void DoublyLinkedList::deleteUp(int num) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    DoublyNode* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Node with value " << num << " does not exist" << std::endl;
        return;
    }
    if (current->prev != nullptr) {
        DoublyNode* temp = current->prev;
        if (current->next != nullptr) {
            current->next->prev = temp;
        }
        temp->next = current->next;
        delete current;
    } else {
        std::cout << "Node " << num << " has no node above" << std::endl;
    }
}

void DoublyLinkedList::deleteDown(int num) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    DoublyNode* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Node with value " << num << " does not exist" << std::endl;
        return;
    }
    if (current->next != nullptr) {
        DoublyNode* temp = current->next;
        if (current->prev != nullptr) {
            current->prev->next = temp;
        }
        temp->prev = current->prev;
        delete current;
    } else {
        std::cout << "Node " << num << " has no node below" << std::endl;
    }
}


void SkipList::insert(int value) {
    Node* update[maxLevel + 1];
    Node* current = head;

    // Start from the highest level of the skip list
    for (int i = maxLevel; i >= 0; i--) {
        while (current->next[i] != nullptr && current->next[i]->data < value) {
            current = current->next[i];
        }
        update[i] = current;
    }

    int level = randomLevel();
    Node* newNode = new Node(value, level);

    for (int i = 0; i <= level; i++) {
        newNode->next[i] = update[i]->next[i];
        update[i]->next[i] = newNode;
    }
}

bool SkipList::search(int value) {
    Node* current = head;
    for (int i = maxLevel; i >= 0; i--) {
        while (current->next[i] != nullptr && current->next[i]->data < value) {
            current = current->next[i];
        }
    }
    current = current->next[0];
    return current != nullptr && current->data == value;
}

void SkipList::remove(int value) {
    Node* update[maxLevel + 1];
    Node* current = head;

    for (int i = maxLevel; i >= 0; i--) {
        while (current->next[i] != nullptr && current->next[i]->data < value) {
            current = current->next[i];
        }
        update[i] = current;
    }

    current = current->next[0];

    if (current != nullptr && current->data == value) {
        for (int i = 0; i <= maxLevel; i++) {
            if (update[i]->next[i] != current) {
                break;
            }
            update[i]->next[i] = current->next[i];
        }
        delete current;
    }
}

void SkipList::display() {
    for (int i = 0; i <= maxLevel; i++) {
        Node* node = head->next[i];
        std::cout << "Level " << i << ": ";
        while (node != nullptr) {
            std::cout << node->data << " ";
            node = node->next[i];
        }
        std::cout << std::endl;
    }
}

void MultiCircularLinkedList::insertEnd(int num) {
    CircularNode* newNode = new CircularNode(num);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
        head->up = nullptr;
        head->down = nullptr;
    } else {
        CircularNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
        // Set up and down pointers for multi-linked list
        newNode->up = nullptr;
        newNode->down = nullptr;
    }
}

void MultiCircularLinkedList::deleteBeginning() {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    CircularNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    if (temp == head) {
        head = nullptr;
    } else {
        temp->next = head->next;
        head->next->prev = temp;
        delete head;
        head = temp->next;
    }
}

void MultiCircularLinkedList::display() {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    CircularNode* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << std::endl;
}

bool MultiCircularLinkedList::search(int num) {
    if (head == nullptr) {
        return false;
    }
    CircularNode* temp = head;
    do {
        if (temp->data == num) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    return false;
}

void MultiCircularLinkedList::moveUp(int num) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    CircularNode* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Node with value " << num << " does not exist" << std::endl;
        return;
    }
    if (current->up != nullptr) {
        head = current->up;
    } else {
        std::cout << "Node " << num << " has no up link" << std::endl;
    }
}

void MultiCircularLinkedList::moveDown(int num) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    CircularNode* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Node with value " << num << " does not exist" << std::endl;
        return;
    }
    if (current->down != nullptr) {
        head = current->down;
    } else {
        std::cout << "Node " << num << " has no down link" << std::endl;
    }
}

void MultiCircularLinkedList::insertUp(int num, int value) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    CircularNode* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Node with value " << num << " does not exist" << std::endl;
        return;
    }
    CircularNode* newNode = new CircularNode(value);
    newNode->up = current->up;
    newNode->down = current;
    if (current->up != nullptr) {
        current->up->down = newNode;
    }
    current->up = newNode;
}

void MultiCircularLinkedList::insertDown(int num, int value) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    CircularNode* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Node with value " << num << " does not exist" << std::endl;
        return;
    }
    CircularNode* newNode = new CircularNode(value);
    newNode->down = current->down;
    newNode->up = current;
    if (current->down != nullptr) {
        current->down->up = newNode;
    }
    current->down = newNode;
}

void MultiCircularLinkedList::deleteUp(int num) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    CircularNode* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Node with value " << num << " does not exist" << std::endl;
        return;
    }
    if (current->up != nullptr) {
        CircularNode* temp = current->up;
        current->up = current->up->up;
        if (current->up != nullptr) {
            current->up->down = current;
        }
        delete temp;
    } else {
        std::cout << "Node " << num << " has no up link" << std::endl;
    }
}

void MultiCircularLinkedList::deleteDown(int num) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    CircularNode* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Node with value " << num << " does not exist" << std::endl;
        return;
    }
    if (current->down != nullptr) {
        CircularNode* temp = current->down;
        current->down = current->down->down;
        if (current->down != nullptr) {
            current->down->up = current;
        }
        delete temp;
    } else {
        std::cout << "Node " << num << " has no down link" << std::endl;
    }
}

int main() {
    int choice;
    while(1) {
        system("clear");
        printf("Menu:\n");
        printf("1. Doubly Linked List\n");
        printf("2. Circular Linked List\n");
        printf("3. Skip List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
    DoublyLinkedList mdll;
    int dllChoice;
    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Display\n");
        printf("6. Search\n");
        printf("7. Insert above\n");
        printf("8. Insert below\n");
        printf("9. Delete node above\n");
        printf("10. Delete node below\n");
        printf("11. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &dllChoice);

        switch (dllChoice) {
            case 1: {
                int num;
                printf("Enter number to insert: ");
                scanf("%d", &num);
                mdll.insertBeginning(num);
                break;
            }
            case 2: {
                int num;
                printf("Enter number to insert: ");
                scanf("%d", &num);
                mdll.insertEnd(num);
                break;
            }
            case 3:
                mdll.deleteBeginning();
                break;
            case 4:
                mdll.deleteEnd();
                break;
            case 5:
                printf("Doubly Linked List: ");
                mdll.display();
                break;
            case 6: {
                int num;
                printf("Enter number to search: ");
                scanf("%d", &num);
                if (mdll.search(num)) {
                    printf("Number found in the list\n");
                } else {
                    printf("Number not found in the list\n");
                }
                break;
            }
            case 7: {
                int num, value;
                printf("Enter number to insert above: ");
                scanf("%d", &num);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                mdll.insertUp(num, value);
                break;
            }
            case 8: {
                int num, value;
                printf("Enter number to insert below: ");
                scanf("%d", &num);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                mdll.insertDown(num, value);
                break;
            }
            case 9: {
                int num;
                printf("Enter number to delete node above: ");
                scanf("%d", &num);
                mdll.deleteUp(num);
                break;
            }
            case 10: {
                int num;
                printf("Enter number to delete node below: ");
                scanf("%d", &num);
                mdll.deleteDown(num);
                break;
            }
            case 11:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (dllChoice != 11);
    break;
}

            case 2:
            {
                MultiCircularLinkedList mcll;
                int mcllChoice;
                do 
                {
                    printf("\nMulti Circular Linked List Operations:\n");
                    printf("1. Insert at end\n");
                    printf("2. Insert above\n");
                    printf("3. Insert below\n");
                    printf("4. Delete node\n");
                    printf("5. Delete node above\n");
                    printf("6. Delete node below\n");
                    printf("7. Display\n");
                    printf("8. Search\n");
                    printf("9. Back to main menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &mcllChoice);

                switch (mcllChoice) {
                    
                    case 1: 
                    {
                        int num;
                        printf("Enter number to insert: ");
                        scanf("%d", &num);
                        mcll.insertEnd(num);
                        break;
                    }
            
                    case 2: 
                    {

                        int num, value;
                        printf("Enter number to insert above: ");
                        scanf("%d", &num);
                        printf("Enter value to insert: ");
                        scanf("%d", &value);
                        mcll.insertUp(num, value);
                        break;
                    }
                    
                    case 3: 
                    {
                        int num, value;
                        printf("Enter number to insert below: ");
                        scanf("%d", &num);
                        printf("Enter value to insert: ");
                        scanf("%d", &value);
                        mcll.insertDown(num, value);
                        break;
                    }
                    
                    case 4:
                    {
                        
                        int num;
                        printf("Enter number to delete: ");
                        scanf("%d", &num);
                        mcll.deleteBeginning();
                        break;
                    }
                    
                    case 5: 
                    {
                        int num;
                        printf("Enter number to delete node above: ");
                        scanf("%d", &num);
                        mcll.deleteUp(num);
                        break;
                    }
                    
                    case 6:
                    
                    {
                        int num;
                        printf("Enter number to delete node below: ");
                        scanf("%d", &num);
                        mcll.deleteDown(num);
                        break;
                    }

                    case 7:
                        printf("Multi Circular Linked List: ");
                        mcll.display();
                        break;
                    
                    case 8: 
                    {
                        int num;
                        printf("Enter number to search: ");
                        scanf("%d", &num);
                        if (mcll.search(num)) {
                            printf("Number found in the list\n");
                        } else {
                            printf("Number not found in the list\n");
                        }
                        break;
                    }
                    
                    case 9:
                        
                        break;
                    default:
                        
                        printf("Invalid choice\n");
                }
            
            } while (mcllChoice != 9);
            break;
}

            case 3: {
                int maxLevel = 3; // Adjust as needed
                float probability = 0.5; // Adjust as needed

                SkipList sl(maxLevel, probability);
                int slChoice;
                do {
                    printf("\nSkip List Operations:\n");
                    printf("1. Insert\n");
                    printf("2. Remove\n");
                    printf("3. Search\n");
                    printf("4. Display\n");
                    printf("5. Back to main menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &slChoice);

                    switch (slChoice) {
                        case 1: 

                        {
                            int num;
                            printf("Enter number to insert: ");
                            scanf("%d", &num);
                            sl.insert(num);
                            break;
                        }

                        case 2: 

                        {
                            int num;
                            printf("Enter number to remove: ");
                            scanf("%d", &num);
                            sl.remove(num);
                            break;
                        }

                        case 3: 

                        {
                            int num;
                            printf("Enter number to search: ");
                            scanf("%d", &num);
                            if (sl.search(num)) {
                                printf("Number found in the list\n");
                            } else {
                                printf("Number not found in the list\n");
                            }
                            break;
                        }

                        case 4:

                            sl.display();
                            break;

                        case 5:

                            break;
                        
                        default:
                            printf("Invalid choice\n");

                    }
                } while (slChoice != 5);
                break;
            }
            case 4:
                printf("Exiting program\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("Press Enter Again");
        getchar();
        getchar();
    } 

    return 0;
}
