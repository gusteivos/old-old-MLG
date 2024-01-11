
#ifndef ELIST_H_
#define ELIST_H_

    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>


    #ifndef ELIST_DEFAULT_CAPACITY
    #define ELIST_DEFAULT_CAPACITY 8
    #endif


    typedef struct elist_s
    {

        size_t capacity;

        void **item;

        size_t count;

    } elist_t;
    

    extern elist_t *create_elist         (void);

    extern elist_t *create_elist_capacity(size_t capacity);


    extern bool elist_realloc(elist_t *list, size_t new_capacity);


    extern bool elist_add   (elist_t *list, void *value);
    
    extern bool elist_remove(elist_t *list, void *value);


    /*
        
    todo:
    
        functions to traverse the list in index format, retrieve index based on value.
    
    */


    extern bool  elist_enqueue(elist_t *list, void *value);
    
    extern void *elist_dequeue(elist_t *list);


    /*
        
    todo:

        functions to manipulate the list as a stack.
    
    */


    extern void free_elist(elist_t *list);


    #define elist_rmv(list, value) elist_remove(list, value)

#endif
