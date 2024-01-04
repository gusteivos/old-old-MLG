
#ifndef MLG_LEXER_H_
#define MLG_LEXER_H_

    #include <ctype.h>
    #include <stdbool.h>
    #include "mlg_token.h"


    typedef struct mlg_lexer_s
    {

        char *source;

        long  source_size;

        long  source_index;
        

        char current_source_char;

    } mlg_lexer_t;


    extern bool is_id_char         (char c);

    extern bool is_word_char       (char c);
    
    extern bool is_number_char     (char c);
    
    extern bool is_word_number_char(char c);
    

    extern mlg_lexer_t *create_mlg_lexer(char *source);


    extern char         mlg_lexer_next_char     (mlg_lexer_t *lexer);

    extern char         mlg_lexer_peek_char     (mlg_lexer_t *lexer, long offset);

    extern void         mlg_lexer_skip_spaces   (mlg_lexer_t *lexer);

    extern void         mlg_lexer_skip_line     (mlg_lexer_t *lexer);


    extern mlg_token_t *mlg_lexer_parse_id_token    (mlg_lexer_t *lexer);

    extern mlg_token_t *mlg_lexer_parse_number_token(mlg_lexer_t *lexer);


    extern mlg_token_t *mlg_lexer_next_token(mlg_lexer_t *lexer);


    extern void free_mlg_lexer(mlg_lexer_t *lexer);
    
#endif
