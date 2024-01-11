#include "mlg_parser.h"


mlg_parser_t *create_mlg_parser(mlg_token_t *token, size_t token_count)
{

    mlg_parser_t *new_parser = NULL;

    if (token == NULL || token_count == 0)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        goto endoffunc;

    }


    new_parser = (mlg_parser_t *)malloc(sizeof(mlg_parser_t));

    if (new_parser == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        goto endoffunc;

    }
    

    new_parser->token       = token;

    new_parser->token_count = token_count;


    new_parser->token_index = 0;


endoffunc:

    return new_parser;

}


bool mlg_parser_next_token(mlg_parser_t *parser)
{

    if (parser == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        return false;

    }


    if (parser->current_token->type != MLG_TOKEN_EOF && parser->token_index < parser->token_count)
    {

        parser->current_token = &(parser->token[parser->token_index++]);

    }


    return true;

}

mlg_token_t *mlg_parser_peek_token(mlg_parser_t *parser, long offset)
{

    if (parser == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        return '\0';

    }


    return &(parser->token[parser->token_index + offset]);

}

bool mlg_parser_eat_token (mlg_parser_t *parser, mlg_token_type_t type)
{

    if (mlg_parser_peek_token(parser, 1)->type == type)
    {

        mlg_parser_next_token(parser);


        return false;

    }


    return true;

}


bool mlg_parser_next_AST(mlg_parser_t *parser)
{

    if (parser == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        return false;

    }




    // while (parser->token[parser->token_index].)
    {
    
        

    }


    return true;

}


void free_mlg_parser(mlg_parser_t *parser)
{

    if (parser == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        return;

    }



    free(parser);

}
