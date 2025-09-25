
// Function to generate binary numbers from 1 to N using a queue.
char** generate(int n) {
    // using a list to store the answer.
    char** ans = (char**)malloc(n * sizeof(char*));
    int ans_index = 0;

    // using a queue of strings which helps in generating binary numbers.
    char** queue = (char**)malloc(n * 2 * sizeof(char*));
    int front = 0, rear = 0;

    // pushing first binary number i.e. 1 in queue.
    queue[rear] = strdup("1");
    rear++;

    while (n--) {
        // storing the front element of queue and popping it.
        char* s1 = queue[front];
        front++;
        // adding the popped element in answer.
        ans[ans_index] = strdup(s1);
        ans_index++;

        // generating the next two binary numbers by adding "0" and "1" to
        // the existing strings s1 and pushing them into queue.
        char* s1_zero = (char*)malloc(strlen(s1) + 2);
        char* s1_one = (char*)malloc(strlen(s1) + 2);
        strcpy(s1_zero, s1);
        strcpy(s1_one, s1);
        strcat(s1_zero, "0");
        strcat(s1_one, "1");

        queue[rear] = s1_zero;
        rear++;
        queue[rear] = s1_one;
        rear++;

        free(s1);
    }

    free(queue);
    return ans;
}

