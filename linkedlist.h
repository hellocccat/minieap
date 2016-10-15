#ifndef _MINIEAP_LINKEDLIST_H
#define _MINIEAP_LINKEDLIST_H

typedef struct _element {
    struct _element* next;
    struct _element* prev;
    void* content;
} LIST_ELEMENT;

void insert_data(LIST_ELEMENT** start, void* data);

/*
 * elem_to_find is a pointer to the actual data
 * Prototype of cmpfunc: int cmpfunc(void* lvalue, void* rvalue);
 * cmpfunc returns 0 for equalvity, others for non-
 */
void* lookup_data(LIST_ELEMENT* start, void* elem_to_find, int(*cmpfunc)(void*, void*));

/*
 * user pointer is passed to func directly, for private use
 * Prototype of func: void func(void* current_data, void* user);
 */
void list_traverse(LIST_ELEMENT* start, void(*func)(void*, void*), void* user);

/*
 * Destroy a list, freeing all the memory all nodes take up
 */
void list_destroy(LIST_ELEMENT* start);

/*
 * Remove specific data using custom comprator
 */
void remove_data(LIST_ELEMENT* start, void* elem_to_remove, int(*cmpfunc)(void*, void*));
#endif