
#ifndef PREPARE_LIST_H
#define PREPARE_LIST_H

typedef struct Node {
    void *data;
    struct Node *next;
}Node;

typedef struct List {
    Node *head;
}List;

#endif //PREPARE_LIST_H

#ifdef ARRAY_H
#define ARRAY_H

typedef struct Node {
    void *data;
}Node;

typedef struct List {
    size_t size;
    size_t filled;
    Node *array;
}List;


#endif //ARRAY_H

typedef void (*predicate)(void *);

int insert(List *list,void *data);
int delete(List *list,predicate ptr_foo);