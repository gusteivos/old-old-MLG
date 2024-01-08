#include "mlg_token.h"


char *mlg_token_type_to_string(mlg_token_type_t type)
{

    switch (type)
    {

        case MLG_TOKEN_NONE: return "MLG_TOKEN_NONE";

        case MLG_TOKEN_ID    : return "MLG_TOKEN_ID"    ;
        case MLG_TOKEN_NUMBER: return "MLG_TOKEN_NUMBER";

        case MLG_TOKEN_COMMA: return "MLG_TOKEN_COMMA";
        case MLG_TOKEN_DOT  : return "MLG_TOKEN_DOT"  ;

        case MLG_TOKEN_COLON    : return "MLG_TOKEN_COLON"    ;
        case MLG_TOKEN_SEMICOLON: return "MLG_TOKEN_SEMICOLON";

        case MLG_TOKEN_EQUALS  : return "MLG_TOKEN_EQUALS"  ;
        case MLG_TOKEN_LES_THAN: return "MLG_TOKEN_LES_THAN";
        case MLG_TOKEN_BIG_THAN: return "MLG_TOKEN_BIG_THAN";
        case MLG_TOKEN_LES_OR_EQUAL: return "MLG_TOKEN_LES_OR_EQUAL";
        case MLG_TOKEN_BIG_OR_EQUAL: return "MLG_TOKEN_BIG_OR_EQUAL";

        case MLG_TOKEN_L_PARENTHESIS: return "MLG_TOKEN_L_PARENTHESIS";
        case MLG_TOKEN_R_PARENTHESIS: return "MLG_TOKEN_R_PARENTHESIS";
        case MLG_TOKEN_L_BRACKET    : return "MLG_TOKEN_L_BRACKET"    ;
        case MLG_TOKEN_R_BRACKET    : return "MLG_TOKEN_R_BRACKET"    ;
        case MLG_TOKEN_L_BRACE      : return "MLG_TOKEN_L_BRACE"      ;
        case MLG_TOKEN_R_BRACE      : return "MLG_TOKEN_R_BRACE"      ;

        case MLG_TOKEN_SUM_OPERATOR: return "MLG_TOKEN_SUM_OPERATOR";
        case MLG_TOKEN_SUB_OPERATOR: return "MLG_TOKEN_SUB_OPERATOR";
        case MLG_TOKEN_MUL_OPERATOR: return "MLG_TOKEN_MUL_OPERATOR";
        case MLG_TOKEN_DIV_OPERATOR: return "MLG_TOKEN_DIV_OPERATOR";

        case MLG_TOKEN_TODO: return "MLG_TOKEN_TODO";

        case MLG_TOKEN_EOF : return "MLG_TOKEN_EOF";

    }


    return "token type to string not implemented.";

}


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
