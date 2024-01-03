
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

        MLG_TOKEN_LEFT_PARENTHESIS ,

        MLG_TOKEN_RIGHT_PARENTHESIS,

        MLG_TOKEN_COMMA,

        MLG_TOKEN_COLON    ,

        MLG_TOKEN_SEMICOLON,

        MLG_TOKEN_LESS_THAN   ,

        MLG_TOKEN_EQUALS      ,

        MLG_TOKEN_GREATER_THAN,

        MLG_TOKEN_LEFT_ARROW ,
        
        MLG_TOKEN_ARROW      ,

        MLG_TOKEN_RIGHT_ARROW,

        MLG_TOKEN_LEFT_BRACE ,

        MLG_TOKEN_RIGHT_BRACE,

        MLG_TOKEN_SUB_OPERATOR,

        MLG_TOKEN_SUM_OPERATOR,

        MLG_TOKEN_EOF ,

        MLG_TOKEN_TODO,

    } mlg_token_type_t;

    typedef struct mlg_token_s
    {

        mlg_token_type_t type;

        char *value;

    } mlg_token_t;


    extern mlg_token_t *create_mlg_token(mlg_token_type_t type, char *value);


    extern void free_mlg_token(mlg_token_t *token);

#endif
