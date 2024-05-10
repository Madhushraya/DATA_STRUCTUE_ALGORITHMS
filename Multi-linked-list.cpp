#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class GraphNode {
public:
    int data;
    GraphNode* next;
    GraphNode* adj;

    GraphNode(int d) : data(d), next(nullptr), adj(nullptr) {}

    void addEdge(GraphNode* v) {
        if (adj == nullptr) {
            adj = v;
        } else {
            GraphNode* temp = adj;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = v;
        }
    }
};

class DoublyLinkedList {
private:
    struct DoublyNode {
        int data;
        DoublyNode* next;
        DoublyNode* prev;
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
};

class CircularLinkedList {
private:
    struct CircularNode {
        int data;
        CircularNode* next;
    };

    CircularNode* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertEnd(int);
    void deleteBeginning();
    void display();
    bool search(int);
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
        while (rand() / static_cast<float>(RAND_MAX) < probability && level < maxLevel) {
            level++;
        }
        return level;
    }

public:
    SkipList(int maxLvl, float prob) : maxLevel(maxLvl), probability(prob) {
        head = new Node(-1, maxLevel);
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
};

struct Graph_Node {
    int data;
    GraphNode* next;
    // You might need additional members depending on your implementation
    Graph_Node(int d) : data(d), next(nullptr) {}
};


class Graph {
public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int source, int destination);
    void display();

private:
    int V;
    GraphNode* head;
};

class GraphLinkedList {
public:
    GraphLinkedList();
    ~GraphLinkedList();
    void insert(int data);
    bool search(int data);
    void remove(int data);
    void display();

private:
    GraphNode* head;
    int size;
};

void DoublyLinkedList::insertBeginning(int num) {
    DoublyNode* newNode = new DoublyNode;
    newNode->data = num;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void DoublyLinkedList::insertEnd(int num) {
    DoublyNode* newNode = new DoublyNode;
    newNode->data = num;
    newNode->next = nullptr;
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
        printf("List is empty");
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
        printf("List is empty");
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
        printf("%d ", temp->data);
        temp = temp->next;
    }
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

void CircularLinkedList::insertEnd(int num) {
    CircularNode* newNode = new CircularNode;
    newNode->data = num;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        CircularNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void CircularLinkedList::deleteBeginning() {
    if (head == nullptr) {
        printf("List is empty");
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
        delete head;
        head = temp->next;
    }
}

void CircularLinkedList::display() {
    if (head == nullptr) {
        printf("List is empty");
        return;
    }
    CircularNode* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

bool CircularLinkedList::search(int num) {
    if (head == NULL) {
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
void SkipList::insert(int data) {
        int level = randomLevel();
        Node* newNode = new Node(data, level);
        Node* update[maxLevel + 1];
        Node* current = head;

        for (int i = maxLevel; i >= 0; --i) {
            while (current->next[i] != nullptr && current->next[i]->data < data) {
                current = current->next[i];
            }
            update[i] = current;
        }

        for (int i = 0; i <= level; ++i) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }

bool SkipList::search(int target) {
        Node* current = head;
        for (int i = maxLevel; i >= 0; --i) {
            while (current->next[i] != nullptr && current->next[i]->data < target) {
                current = current->next[i];
            }
        }
        current = current->next[0];
        return current != nullptr && current->data == target;
    }

void SkipList::remove(int target) {
        Node* update[maxLevel + 1];
        Node* current = head;

        for (int i = maxLevel; i >= 0; --i) {
            while (current->next[i] != nullptr && current->next[i]->data < target) {
                current = current->next[i];
            }
            update[i] = current;
        }

        current = current->next[0];
        if (current != nullptr && current->data == target) {
            for (int i = 0; i <= maxLevel; ++i) {
                if (update[i]->next[i] != current)
                    break;
                update[i]->next[i] = current->next[i];
            }
            delete current;
        }
    }

void SkipList::display() {
        std::cout << "Skip List: " << std::endl;
        for (int i = maxLevel; i >= 0; --i) {
            Node* current = head->next[i];
            std::cout << "Level " << i << ": ";
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next[i];
            }
            std::cout << std::endl;
        }
    }


Graph::Graph(int vertices) {
    V = vertices;
    head = nullptr;
}

Graph::~Graph() {
    GraphNode* current = head;
    while (current != nullptr) {
        GraphNode* next = current->next;
        delete current;
        current = next;
    }
}

void Graph::addEdge(int source, int destination) {
    if (head == nullptr) {
        head = new GraphNode(source);
        head->addEdge(new GraphNode(destination));
    } else {
        GraphNode* current = head;
        while (current != nullptr) {
            if (current->data == source) {
                current->addEdge(new GraphNode(destination));
                break;
            }
            current = current->next;
        }

        if (current == nullptr) { // Source vertex not found
            head = new GraphNode(source);
            head->addEdge(new GraphNode(destination));
        }
    }
}

void Graph::display() {
    GraphNode* current = head;
    while (current != nullptr) {
        printf("%d -> ", current->data);
        GraphNode* temp = current->adj;
        while (temp != nullptr) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
        current = current->next;
    }
}

GraphLinkedList::GraphLinkedList() : head(nullptr), size(0) {}

GraphLinkedList::~GraphLinkedList() {
    GraphNode* current = head;
    while (current != nullptr) {
        GraphNode* next = current->next;
        delete current;
        current = next;
    }
}

void GraphLinkedList::insert(int data) {
    GraphNode* newNode = new GraphNode(data);
    newNode->next = head;
    head = newNode;
    size++;
}

bool GraphLinkedList::search(int data) {
    GraphNode* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void GraphLinkedList::remove(int data) {
    GraphNode* prev = nullptr;
    GraphNode* current = head;

    while (current != nullptr) {
        if (current->data == data) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            size--;
            return;
        }
        prev = current;
        current = current->next;
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
        printf("4. Graph-Based Linked List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                DoublyLinkedList dll;
                int dllChoice;
                do {
                    printf("\nDoubly Linked List Operations:\n");
                    printf("1. Insert at beginning\n");
                    printf("2. Insert at end\n");
                    printf("3. Delete from beginning\n");
                    printf("4. Delete from end\n");
                    printf("5. Display\n");
                    printf("6. Search\n");
                    printf("7. Back to main menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &dllChoice);

                    switch (dllChoice) {
                        case 1: {
                            int num;
                            printf("Enter number to insert: ");
                            scanf("%d", &num);
                            dll.insertBeginning(num);
                            break;
                        }
                        case 2: {
                            int num;
                            printf("Enter number to insert: ");
                            scanf("%d", &num);
                            dll.insertEnd(num);
                            break;
                        }
                        case 3:
                            dll.deleteBeginning();
                            break;
                        case 4:
                            dll.deleteEnd();
                            break;
                        case 5:
                            printf("Doubly Linked List: ");
                            dll.display();
                            break;
                        case 6: {
                            int num;
                            printf("Enter number to search: ");
                            scanf("%d", &num);
                            if (dll.search(num)) {
                                printf("Number found in the list\n");
                            } else {
                                printf("Number not found in the list\n");
                            }
                            break;
                        }
                        case 7:
                            break;
                        default:
                            printf("Invalid choice\n");
                    }
                } while (dllChoice != 7);
                break;
            }
            case 2: {
                CircularLinkedList cll;
                int cllChoice;
                do {
                    printf("\nCircular Linked List Operations:\n");
                    printf("1. Insert at end\n");
                    printf("2. Delete from beginning\n");
                    printf("3. Display\n");
                    printf("4. Search\n");
                    printf("5. Back to main menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &cllChoice);

                    switch (cllChoice) {
                        case 1: {
                            int num;
                            printf("Enter number to insert: ");
                            scanf("%d", &num);
                            cll.insertEnd(num);
                            break;
                        }
                        case 2:
                            cll.deleteBeginning();
                            break;
                        case 3:
                            printf("Circular Linked List: ");
                            cll.display();
                            break;
                        case 4: {
                            int num;
                            printf("Enter number to search: ");
                            scanf("%d", &num);
                            if (cll.search(num)) {
                                printf("Number found in the list\n");
                            } else {
                                printf("Number not found in the list\n");
                            }
                            break;
                        }
                        case 5:
                            break;
                        default:
                            printf("Invalid choice\n");
                    }
                } while (cllChoice != 5);
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
                        case 1: {
                            int num;
                            printf("Enter number to insert: ");
                            scanf("%d", &num);
                            sl.insert(num);
                            break;
                        }
                        case 2: {
                            int num;
                            printf("Enter number to remove: ");
                            scanf("%d", &num);
                            sl.remove(num);
                            break;
                        }
                        case 3: {
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
            case 4: {
                int numVertices;
                printf("Enter number of vertices: ");
                scanf("%d", &numVertices);
                Graph g(numVertices);
                int gChoice;
                do {
                    printf("\nGraph-Based Linked List Operations:\n");
                    printf("1. Add Edge\n");
                    printf("2. Display\n");
                    printf("3. Back to main menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &gChoice);

                    switch (gChoice) {
                        case 1: {
                            int source, destination;
                            printf("Enter source vertex: ");
                            scanf("%d", &source);
                            printf("Enter destination vertex: ");
                            scanf("%d", &destination);
                            g.addEdge(source, destination);
                            break;
                        }
                        case 2:
                            g.display();
                            break;
                        case 3:
                            break;
                        default:
                            printf("Invalid choice\n");
                    }
                } while (gChoice != 3);
                break;
            }
            case 5:
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
