#include "elist.h"


elist_t *create_elist         ()
{

    return create_elist_capacity(ELIST_DEFAULT_CAPACITY);

}

elist_t *create_elist_capacity(size_t capacity)
{

    elist_t *new_list = malloc(sizeof(elist_t));

    if (new_list == NULL)
    {

        fprintf(stderr, "Error allocating memory for a new elist.");


        goto endoffunc;

    }


    new_list->capacity = capacity;

    new_list->item     = (void **)calloc(new_list->capacity, sizeof(void *));

    if (new_list->item == NULL)
    {

        fprintf(stderr, "Error allocating memory for item on new elist.\n");


        free(new_list);

        new_list = NULL;


        goto endoffunc;

    }


    new_list->count    = 0;



endoffunc:

    return new_list;

}


bool elist_realloc(elist_t *list, size_t new_capacity)
{

    if (list == NULL)
    {

        fprintf(stderr, "todo: .\n");


        return false;

    }


    if (list->item == NULL)
    {

        list->item = (void **)calloc(new_capacity, sizeof(void *));

    }
    else
    {

        void **new_item = (void **)realloc(list->item, new_capacity * sizeof(void *));

        if (new_item == NULL)
        {

            new_item = calloc(new_capacity, sizeof(void *));

            if (new_item == NULL)
            {
                
                fprintf(stderr, "todo: .\n");


                return false;

            }


            memcpy(new_item, list->item, list->capacity * sizeof(void *));


            free(list->item);

        }


        list->item = new_item;

    }


    list->capacity = new_capacity;


    return true;

}


bool elist_add   (elist_t *list, void *value)
{

    if (list == NULL)
    {

        fprintf(stderr, "todo: .\n");


        return false;

    }


    if (list->count >= list->capacity)
    {

        size_t new_capacity = list->capacity + (list->count - list->capacity) + 1;

        elist_realloc(list, new_capacity);

    }


    for (size_t q = 0; q < list->capacity; q++)
    {

        if (list->item[q] == NULL)
        {

            list->item[q] = value;

            list->count++;


            break;

        }

    }


    return true;

}

bool elist_remove(elist_t *list, void *value)
{

    if (list == NULL)
    {

        fprintf(stderr, "todo: .\n");


        return false;

    }


    for (size_t q = 0; q < list->capacity; q++)
    {

        if (list->item[q] == value)
        {

            list->item[q] = NULL;

            list->count--;


            break;

        }

    }


    return true;

}


bool  elist_enqueue(elist_t *list, void *value)
{

    if (list == NULL || value == NULL)
    {

        fprintf(stderr, "todo: .\n");


        return false;

    }


    size_t item_index = 0;


    if (list->count >= list->capacity)
    {

        size_t new_capacity = list->capacity + (list->count - list->capacity) + 1;

        elist_realloc(list, new_capacity);

    }


    bool last_item_is_null = false;

    for (item_index = list->capacity - 1; item_index >= 0; item_index--)
    {

        if (list->item[item_index] == NULL)
        {

            last_item_is_null = true;

        }
        else if (last_item_is_null)
        {

            item_index++;

            break;

        }

    }


    list->item[item_index] = value;

    list->count++;


    return true;

}

void *elist_dequeue(elist_t *list)
{

    void *item = NULL;


    if (list == NULL)
    {

        fprintf(stderr, "todo: .\n");

    
        goto endoffunc;
    
    }


    for (int q = 0; q < list->capacity; q++)
    {

        item = list->item[q];

        if (item != NULL)
        {

            list->item[q] = NULL;

            list->count--;            


            break;

        }

    }


endoffunc:

    return item;

}


void free_elist(elist_t *list)
{

    if (list == NULL)
    {
        
        fprintf(stderr, "Error elist is NULL.\n");


        return;

    }


    if (list->item != NULL)
    {

        free(list->item);

    }


    free(list);

}
