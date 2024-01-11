
#ifndef MLG_PARSER_H_
#define MLG_PARSER_H_

    #include "mlg_lexer.h"
    #include "mlg_AST.h"
    #include "elist.h"


    typedef struct mlg_parser_s
    {

        mlg_token_t *token;

        size_t       token_count;

        size_t       token_index;

        mlg_token_t *current_token;

    }  mlg_parser_t;
    

    extern mlg_parser_t *create_mlg_parser(mlg_token_t *token, size_t token_count);


    extern bool mlg_parser_next_token(mlg_parser_t *parser);

    extern bool mlg_parser_eat_token (mlg_parser_t *parser, mlg_token_type_t type);


    extern void free_mlg_parser(mlg_parser_t *parser);

#endif
