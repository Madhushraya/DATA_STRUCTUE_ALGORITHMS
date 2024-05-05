// IMPLEMENTATION OF CIRCULAR QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

class circular_queue
{
    private:

        int arr[SIZE];        
    
    public:
    
        circular_queue()
        {
            for (int i=0;i<SIZE;i++)
            {
                arr[i] = nullptr;
            }
        }
};

circular_queue::circular_queue(/* args */)
{
}

circular_queue::~circular_queue()
{
}
