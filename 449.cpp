// Function to reverse the queue using a stack (array)
/*
    // Define the structure for Queue
    typedef struct Queue {
        int* arr;
        int front;
        int rear;
        int capacity;
    } Queue;

    // Function to initialize a new queue
    Queue* createQueue(int capacity) {
        Queue* queue = (Queue*)malloc(sizeof(Queue));
        queue->capacity = capacity;
        queue->front = 0;
        queue->rear = 0;
        queue->arr = (int*)malloc(queue->capacity * sizeof(int));
        return queue;
    }

    // Function to add an element to the queue
    void push(Queue* queue, int element) {
        if (queue->rear == queue->capacity) {
            // Resize the array if needed
            queue->capacity *= 2;
            queue->arr = (int*)realloc(queue->arr, queue->capacity * sizeof(int));
        }
        queue->arr[queue->rear++] = element;
    }

    // Function to remove and return the front element of the queue
    int pop(Queue* queue) {
        if (queue->front != queue->rear) {
            return queue->arr[queue->front++];
        }
        return -1; // Return -1 if the queue is empty
    }

    // Function to get the front element without removing it
    int front_ele(Queue* queue) {
        if (queue->front != queue->rear) {
            return queue->arr[queue->front];
        }
        return -1;
    }

    // Function to check if the queue is empty
    int empty(Queue* queue) {
        return queue->front == queue->rear;
    }
*/

Queue* reverseQueue(Queue* q) {
    // Use a temporary stack (array)
    int* stack = (int*)malloc(q->capacity * sizeof(int));
    int stack_top = 0;

    // Pop elements from the queue and push them into the stack
    while (!empty(q)) {
        stack[stack_top++] = front_ele(q);
        pop(q);
    }

    // Create a new queue to store the reversed elements
    Queue* reversed = createQueue(q->capacity);

    // Push elements back into the queue from the stack
    while (stack_top > 0) {
        push(reversed, stack[--stack_top]);
    }

    free(stack); // Free the allocated memory for the stack
    return reversed;
}
