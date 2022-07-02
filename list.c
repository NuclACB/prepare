#include <stdlib.h>
#include "list.h"

#ifdef PREPARE_LIST_H

Node *create_node(void *data) {
    Node *new_node = (Node *) malloc(sizeof (Node));
    if(!new_node)
        return 1;

    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
}

int insert(List *list,void *data) {
    if(!list)
        return 1;
    if(!data)
        return 2;
    Node *new_node = create_node(data);
    if(list -> head == NULL) {
        list -> head = new_node;
        return 0;
    } else {
        new_node -> next = list -> head;
        list -> head = new_node;
    }
    return 0;
}


int delete(List *list,predicate ptr_foo) {

}

#endif //PREPARE_LIST_H