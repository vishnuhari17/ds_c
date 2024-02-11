#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int i, vertices, op, top = -1, front = -1, rear = -1, vertex, adjnmbr, item, ch, a[MAX],v;
bool visited[MAX];
struct node {
    int data;
    struct node* link;
};
struct node* head[MAX];
struct node* new;
struct node* ptr;

void creategraph();
void bfstraversal(int v);
void dfstraversal(int v);
void push(int t);
int pop();
bool search(int v);
void insert(int v);
int dequeue();
void enqueue(int v);

void main() {
    for (int i = 0; i < MAX; i++) {
        head[i] = NULL;
        visited[i] = false;
    }

    do {
        printf("1: create graph\n2: bfs traversal\n3: dfs traversal\n4: exiting\n");
        printf("enter the operation you need to perform: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            creategraph();
            break;
        case 2:
            printf("enter the vertex you need to start the bfs traversal: ");
            scanf("%d", &v);
            bfstraversal(v);
            break;
        case 3:
            printf("enter the vertex you need to start the dfs traversal: ");
            scanf("%d", &v);
            dfstraversal(v);
            break;
        case 4:
            break;
        }
        printf("Do you want to continue? (1 for yes, 0 for no): ");
        scanf("%d", &ch);
    } while (ch == 1);

}

void bfstraversal(int v) {
    if (head[v] == NULL) {
        printf("graph is empty\n");
    }
    else {
        enqueue(v);
        while (front!=-1) {
            v = dequeue();
            if (!search(v)) {
                printf("%d\t", v);
                insert(v);
                ptr = head[v];
                while (ptr != NULL) {
                    enqueue(ptr->data);
                    ptr = ptr->link;
                }
            }
        }
    }
}

void dfstraversal(int v) {
    if (head[v] == NULL) {
        printf("graph is empty\n");
    }
    else {
        push(v);
        while (top != -1) {
            v = pop();
            if (!search(v)) {
                printf("%d\t", v);
                insert(v);
                ptr = head[v];
                while (ptr != NULL) {
                    push(ptr->data);
                    ptr = ptr->link;
                }
            }
        }
    }
    printf("\n");
}

void push(int t) {
    if (top != MAX - 1) {
        a[++top] = t;
    }
}

int pop() {
    if (top != -1) {
        return a[top--];
    }
    else {
        return -1;
    }
}

int dequeue() {
    if (front == -1 && rear == -1) {
        printf("queue is empty\n");
        return -1;
    }
    else {
        int temp = a[front++];
        if (front > rear) {
            front = rear = -1;
        }
        return temp;
    }
}

void enqueue(int v) {
    if (rear == MAX - 1) {
        printf("queue is full\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        a[rear] = v;
    }
}

void insert(int v) {
    visited[v] = true;
}

bool search(int v) {
    return visited[v];
}

void creategraph() {
    printf("enter the number of vertices: ");
    scanf("%d", &vertices);
    for (i = 1; i <= vertices; i++) {
        struct node* ptr = NULL;
        printf("enter the vertex: ");
        scanf("%d", &vertex);
        printf("enter the number of adjacent vertices of %d: ", vertex);
        scanf("%d", &adjnmbr);
        for (int j = 1; j <= adjnmbr; j++) {
            new = (struct node*)malloc(sizeof(struct node));
            printf("enter the data to be inserted: ");
            scanf("%d", &item);
            new->data = item;
            new->link = NULL;
            if (head[vertex] == NULL) {
                head[vertex] = new;
                ptr = new;
            }
            else {
                ptr->link = new;
                ptr = ptr->link;
            }
        }
    }
}
