#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node *head, struct node *tail, int data);
int deleteq(struct node *head, struct node *tail);

int main() {
    int data;
    struct node *head, *tail;

    head = (struct node *) malloc(sizeof(struct node));
    tail = (struct node *) malloc(sizeof(struct node));

    head->next = NULL;
    tail->next = NULL;

    while(scanf("%d", &data) == 1) {
        addq(head, tail, data);
    }
    printf("Print Queue\n");

    while(1) {
        printf("%d\n", head->next->data);
        head = head->next;
        if(head->next == NULL) {
            break;
        }
    }


    return 0;
}

void addq(struct node *head, struct node *tail, int data) {
    struct node *p = (struct node *) malloc(sizeof(struct node));
    if(p == NULL) {
        perror("malloc");
        exit(1);
    }

    p->data = data;

    if(head->next == NULL) {
        head->next = p;
        tail->next = p;
    }
    else {
        tail->next->next = p;
        tail->next = p;
    }
    p->next = NULL;
}