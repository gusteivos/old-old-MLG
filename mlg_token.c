#include "mlg_token.h"


mlg_keyword_token_t keywords[] = 
{

    {"function", "func", MLG_TOKEN_KW_FUNC},

/* modifiers: */

    {"constant", "const", MLG_TOKEN_KW_CONST},
    {"readonly", "rdnly", MLG_TOKEN_KW_RDNLY},
    {"thiscope", "thscp", MLG_TOKEN_KW_THSCP},
    {"external", "xtrnl", MLG_TOKEN_KW_XTRNL},
    
/* type modifiers: */

    {"signed", "", MLG_TOKEN_KW_SIGNED},
    {"ungned", "", MLG_TOKEN_KW_UNGNED},

/* types: */

    {"integer", "int", MLG_TOKEN_KW_INT},
    {"float"  , "flt", MLG_TOKEN_KW_FLT},

    {"none"  , "", MLG_TOKEN_KW_NONE},


    {NULL, NULL, MLG_TOKEN_EOF}

};


char *mlg_token_type_to_string(mlg_token_type_t type)
{

    switch (type)
    {

        case MLG_TOKEN_NONE: return "MLG_TOKEN_NONE";

        case MLG_TOKEN_ID    : return "MLG_TOKEN_ID";

        case MLG_TOKEN_LITERAL_NUMBER: return "MLG_TOKEN_LITERAL_NUMBER";

        case MLG_TOKEN_KW_FUNC: return "MLG_TOKEN_KW_FUNC";

        case MLG_TOKEN_KW_CONST: return "MLG_TOKEN_KW_CONST";
        case MLG_TOKEN_KW_RDNLY: return "MLG_TOKEN_KW_RDNLY";
        case MLG_TOKEN_KW_THSCP: return "MLG_TOKEN_KW_THSCP";
        case MLG_TOKEN_KW_XTRNL: return "MLG_TOKEN_KW_XTRNL";

        case MLG_TOKEN_KW_SIGNED: return "MLG_TOKEN_KW_SIGNED";
        case MLG_TOKEN_KW_UNGNED: return "MLG_TOKEN_KW_UNGNED";

        case MLG_TOKEN_KW_INT: return "MLG_TOKEN_KW_INT";
        case MLG_TOKEN_KW_FLT: return "MLG_TOKEN_KW_FLT";

        case MLG_TOKEN_KW_NONE: return "MLG_TOKEN_KW_NONE";

        case MLG_TOKEN_COMMA: return "MLG_TOKEN_COMMA";
        case MLG_TOKEN_DOT  : return "MLG_TOKEN_DOT"  ;

        case MLG_TOKEN_COLON    : return "MLG_TOKEN_COLON"    ;
        case MLG_TOKEN_SEMICOLON: return "MLG_TOKEN_SEMICOLON";

        case MLG_TOKEN_EQUALS      : return "MLG_TOKEN_EQUALS"  ;
        case MLG_TOKEN_LES_THAN    : return "MLG_TOKEN_LES_THAN";
        case MLG_TOKEN_BIG_THAN    : return "MLG_TOKEN_BIG_THAN";
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


bool mlg_token_id_to_keyword(mlg_token_t *token)
{

    if (token == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        return false;

    }


    int index = 0;

    mlg_keyword_token_t current = keywords[index];

    while ((current.name0 != NULL || current.name1 != NULL) && current.kw_token != MLG_TOKEN_EOF)
    {

        if (strcmp(current.name0, token->value) == 0 || strcmp(current.name1, token->value) == 0)
        {

            free(token->value);

            token->value = NULL;

            token->type = current.kw_token;


            break;

        }

       current = keywords[++index];

    }
    


    return true;

}



void free_mlg_token(mlg_token_t *token)
{

    if (token == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);

    }


    free(token);

}
