#include "mlg_lang_type.h"


mlg_type_value_t *create_mlg_type_value(mlg_type_t type)
{

    mlg_type_value_t *new_type_value = (mlg_type_value_t *)calloc(1, sizeof(mlg_type_value_t));

    if (new_type_value == NULL)
    {

        fprintf(stderr, "todo: .\n");


        goto endoffunc;

    }


    new_type_value->type = type;

    
    new_type_value->_ungned_long = 0;

    
endoffunc:

    return new_type_value;

}


void free_mlg_type_value(mlg_type_value_t *type_value)
{

    if (type_value == NULL)
    {

        fprintf(stderr, "todo: .\n");


        return;

    }


    /* TODO: */


    free(type_value);

}
