#include "mlg_token.h"


mlg_token_t *create_mlg_token(mlg_token_type_t type, char *value)
{

    mlg_token_t *new_token = (mlg_token_t *)malloc(sizeof(mlg_token_t));

    if (new_token == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        goto endoffunc;

    }


    new_token->type  = type ;

    new_token->value = value;


endoffunc:

    return new_token;

}


void free_mlg_token(mlg_token_t *token)
{

    if (token == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);

    }


    free(token);

}
