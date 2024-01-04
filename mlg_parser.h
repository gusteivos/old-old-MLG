
#ifndef MLG_PARSER_H_
#define MLG_PARSER_H_

    #include "mlg_lexer.h"
    #include "mlg_AST.h"


    typedef struct mlg_parser_s
    {

        mlg_lexer_t *lexer;

    }  mlg_parser_t;
    

    extern mlg_parser_t *create_mlg_parser(mlg_lexer_t *lexer);


    extern void free_mlg_parser(mlg_parser_t *parser);

#endif
