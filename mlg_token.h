
#ifndef MLG_TOKEN_H_
#define MLG_TOKEN_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>


    typedef enum mlg_token_type_e
    {

        MLG_TOKEN_NONE = 0,

        MLG_TOKEN_ID    ,
        MLG_TOKEN_NUMBER,

        MLG_TOKEN_COMMA,
        MLG_TOKEN_DOT  ,

        MLG_TOKEN_COLON    ,
        MLG_TOKEN_SEMICOLON,

        MLG_TOKEN_EQUALS      ,
        MLG_TOKEN_LES_THAN    ,
        MLG_TOKEN_BIG_THAN    ,
        MLG_TOKEN_LES_OR_EQUAL,
        MLG_TOKEN_BIG_OR_EQUAL,

        MLG_TOKEN_L_PARENTHESIS,
        MLG_TOKEN_R_PARENTHESIS,
        MLG_TOKEN_L_BRACKET    ,
        MLG_TOKEN_R_BRACKET    ,
        MLG_TOKEN_L_BRACE      ,
        MLG_TOKEN_R_BRACE      ,

        MLG_TOKEN_SUB_OPERATOR,
        MLG_TOKEN_SUM_OPERATOR,
        MLG_TOKEN_MUL_OPERATOR,
        MLG_TOKEN_DIV_OPERATOR,

        MLG_TOKEN_TODO,

        MLG_TOKEN_EOF = EOF

    } mlg_token_type_t;

    typedef struct mlg_token_s
    {

        mlg_token_type_t type;

        char *value;

    } mlg_token_t;


    extern char *mlg_token_type_to_string(mlg_token_type_t type);


    extern mlg_token_t *create_mlg_token(mlg_token_type_t type, char *value);


    extern void free_mlg_token(mlg_token_t *token);

#endif
