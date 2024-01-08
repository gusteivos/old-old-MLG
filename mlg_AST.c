#include "mlg_AST.h"


mlg_AST_node_t *create_AST_node(mlg_AST_node_type_t type)
{

    mlg_AST_node_t *new_ast_node = (mlg_AST_node_t *)calloc(1, sizeof(mlg_AST_node_t));

    if (new_ast_node == NULL)
    {

        fprintf(stderr, "todo: .\n");


        goto endoffunc;

    }


    new_ast_node->type = type;

    switch (new_ast_node->type)
    {

    case MLG_AST_NODE_TYPE_VAR_DEC:
    case MLG_AST_NODE_TYPE_VAR_DEF:

        new_ast_node->other_value = (void *)create_mlg_type_value(MLG_TYPE_NONE);

        break;

    }


endoffunc:

    return new_ast_node;

}


void free_AST_node(mlg_AST_node_t *ast_node)
{

    if (ast_node == NULL)
    {

        fprintf(stderr, "todo: .\n");


        return;

    }


    /* TODO: */


    free(ast_node);

}
