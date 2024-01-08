
#ifndef MLG_AST_H_
#define MLG_AST_H_

    #include "mlg_lang_type.h"


    typedef enum mlg_AST_node_type_e
    {

        MLG_AST_NODE_NONE = 0,

        MLG_AST_NODE_TYPE_VAR_DEC,
        MLG_AST_NODE_TYPE_VAR_DEF,

    } mlg_AST_node_type_t;

    typedef struct mlg_AST_node_s
    {

        mlg_AST_node_type_t type;


        char *value;

        int   value_flags;


        void *other_value;


        struct mlg_AST_node_s *l_children;

        struct mlg_AST_node_s *r_children;

    } mlg_AST_node_t;
    

    extern mlg_AST_node_t *create_AST_node(mlg_AST_node_type_t type);


    extern void free_AST_node(mlg_AST_node_t *ast_node);

#endif
