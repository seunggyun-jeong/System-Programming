#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data);
int pop(struct node *top);

int main() {
    int data;
    struct node *top = NULL;

    while(scanf("%d", &data) == 1) {
        push(&top, data);
    }

    printf("Print stack\n");

    while(pop(top) != -1);

    return 0;
}

void push(struct node **top, int data) {
    struct node *p = (struct node *) malloc(sizeof(struct node));

    if(p == NULL) {
        perror("malloc");
        exit(1);
    }

    p->data = data;
    p->next = top;
    *top = *p;
}

int pop(struct node *top) {
    printf("%d\n", top->data);
    if(top->next == NULL) {
        return -1;
    }
    *top = *top->next;

    return 1;
}
