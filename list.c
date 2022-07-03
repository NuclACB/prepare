#include <stdlib.h>
#include "list.h"

#ifdef PREPARE_LIST_H

Node *create_node(void *data) {
    if(!data)
        return 1;
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
     if(!list)
         return 1;
     if(ptr_foo == NULL)
         return 2;
     if(list -> head == NULL)
         return 1;
     Node *trash = NULL;
     if(list -> head -> data == ptr_foo) {
         trash = list -> head;
         list -> head = list -> head -> next;
         free(trash);
         return 0;
     } else {
         Node *current = list -> head;
         while(current) {
             if(current -> next -> data == ptr_foo) {
                 trash = current -> next;
                 current -> next = trash -> next;
             } else
                 return 4;//не найдено
             current = current -> next;
         }
     }
    return 0;
}

#endif //PREPARE_LIST_H


#ifdef ARRAY_H

Node *create_node(void *data) {
    if(!data)
        return 1;
    Node *new_node = (Node *) malloc(sizeof (Node));
    if(!new_node)
        return 1;

    new_node -> data = data;
    return new_node;
}

int insert(List *list,void *data,size_t size) {
    if(!list)
        return 1;//память
    if(!data)
        return 2;//нет информации
    if(size == 0)
        return 3;
    list -> size = size;
    if(size == list -> filled) {
        printf("Overflow"); //переполнение
        free(list -> array[0].data);
        list -> filled --;
    }

    Node *new_node = create_node(data);
    if(list -> (array + 0) == NULL) {
        list -> (array + 0) = (Node *)malloc(sizeof(Node) * size);
        if(!(list -> array))
            return 1;

        list -> (array + 0) = new_node;
        list -> filled ++;
        return 0;
    }
    else {
        for(size_t i = 1;i < list -> size;i ++) {
            if(list -> array[i].data == NULL) {
                list -> (array + i) = new_node;
                list -> filled ++;
            }
        }
    }
    return 0;
}

int delete(List *list,predicate ptr_foo) {
    if(!list)
         return 1;
    if(ptr_foo == NULL)
         return 2;
    if(list -> array == NULL)
         return 1;
    if(list -> size == 0)
        return 3;
    for(size_t i = 0;i < list -> filled;i ++) {
        if(list -> array[i].data == ptr_foo) {
            free(list -> array[i].data);
            //сдвиг относительно i
            for(i;i < size -> filled - 1;i ++) {
                list -> (array + i) = list -> (array + i + 1);
            }
            list -> filled --;
        }
    }
    return 0;
}



#endif //ARRAY_H