#include "mlg_lexer.h"


bool is_id_char         (char c)
{

    return isalpha(c) || c == '_';

}

bool is_word_char       (char c)
{

    return is_id_char(c) || isdigit(c);

}

bool is_number_char     (char c)
{

    return isdigit(c);

}
    
bool is_word_number_char(char c)
{

    return is_number_char(c) || c == '.';

}


mlg_lexer_t *create_mlg_lexer(char *source)
{

    mlg_lexer_t *new_lexer = (mlg_lexer_t *)malloc(sizeof(mlg_lexer_t));

    if (new_lexer == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        goto endoffunc;

    }


    new_lexer->source       = source;

    new_lexer->source_size  = strlen(source);

    new_lexer->source_index = 0;


    new_lexer->current_source_char = new_lexer->source[new_lexer->source_index];


endoffunc:

    return new_lexer;

}


char mlg_lexer_next_char(mlg_lexer_t *lexer)
{

    if (lexer == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        return '\0';

    }


    if (lexer->current_source_char != '\0' && lexer->source_index < lexer->source_size)
    {

        lexer->source_index++;

    }


    return lexer->current_source_char = lexer->source[lexer->source_index];

}

char mlg_lexer_peek_char(mlg_lexer_t *lexer, long offset)
{

    if (lexer == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        return '\0';

    }


    return lexer->source[lexer->source_index + offset];

}

bool mlg_lexer_eat_char(mlg_lexer_t *lexer, char c)
{

    bool return_value = false;

    if (mlg_lexer_peek_char(lexer, 1) == c)
    {

        return_value = true;

        mlg_lexer_next_char(lexer);

    }


    return return_value;

}


void mlg_lexer_skip_spaces(mlg_lexer_t *lexer)
{

    if (lexer == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        return;

    }


    while (lexer->current_source_char == ' ' || lexer->current_source_char == '\n' || lexer->current_source_char == '\t' || lexer->current_source_char == '\r')
    {

        mlg_lexer_next_char(lexer);

    }

}

void mlg_lexer_skip_line(mlg_lexer_t *lexer)
{

    if (lexer == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        return;

    }


    while (lexer->current_source_char != '\0' && lexer->current_source_char != '\n')
    {

        mlg_lexer_skip_spaces(lexer);

        mlg_lexer_next_char  (lexer);

    }
    
}

mlg_token_t *mlg_lexer_parse_id_token(mlg_lexer_t *lexer)
{

    if (lexer == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        return NULL;

    }


    size_t value_size = 2;

    char  *value = malloc(value_size);

    value[0] = lexer->current_source_char;

    while (is_word_char(mlg_lexer_peek_char(lexer, 1)))
    {

        mlg_lexer_next_char(lexer);

        size_t previous_value_size = value_size++;

        value = realloc(value, value_size);

        value[previous_value_size - 1] = lexer->current_source_char;

    }
    

    value[value_size - 1] = '\0';


    return create_mlg_token(MLG_TOKEN_ID, value);

}

mlg_token_t *mlg_lexer_parse_number_token(mlg_lexer_t *lexer)
{

    if (lexer == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        return NULL;

    }


    size_t value_size = 2;

    char  *value = malloc(value_size);

    value[0] = lexer->current_source_char;

    while (is_word_number_char(mlg_lexer_peek_char(lexer, 1)))
    {

        mlg_lexer_next_char(lexer);

        size_t previous_value_size = value_size++;

        value = realloc(value, value_size);

        value[previous_value_size - 1] = lexer->current_source_char;

    }
    

    value[value_size - 1] = '\0';


    return create_mlg_token(MLG_TOKEN_LITERAL_NUMBER, value);

}

mlg_token_t *mlg_lexer_next_token(mlg_lexer_t *lexer)
{

    if (lexer == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);


        return NULL;

    }


    mlg_lexer_skip_spaces(lexer);


    if (lexer->current_source_char != '\0')
    {

        mlg_token_t *new_token = NULL;

        if (is_id_char(lexer->current_source_char))
        {

            new_token = mlg_lexer_parse_id_token(lexer);


            if (mlg_token_id_to_keyword(new_token) == false)
            {

                fprintf(stderr, "todo: .\n");

            }


            goto return_new_token;

        }
        else if (is_number_char(lexer->current_source_char))
        {

            new_token = mlg_lexer_parse_number_token(lexer);


            goto return_new_token;

        }


        switch (lexer->current_source_char)
        {

        case '"':
            
            new_token = create_mlg_token(MLG_TOKEN_TODO, "identify and parse string.");


            break;
        
        case '#':

            new_token = create_mlg_token(MLG_TOKEN_TODO, "a hash tag, possibly a compiler directive.");

            /* temp: */
                
                mlg_lexer_skip_line(lexer);

            break;

        case ',':

            new_token = create_mlg_token(MLG_TOKEN_COMMA, NULL);

            break;

        case '.':

            new_token = create_mlg_token(MLG_TOKEN_DOT, NULL);

            break;


        case ':':
        
            new_token = create_mlg_token(MLG_TOKEN_COLON, NULL);
        
            break;

        case ';':

            if (mlg_lexer_eat_char(lexer, '#'))
            {

                printf("line comment, skipping this line.\n");

                mlg_lexer_skip_line(lexer);

            }
            else
            {


                new_token = create_mlg_token(MLG_TOKEN_SEMICOLON, NULL);

            }

            break;


        case '=':

            switch (mlg_lexer_peek_char(lexer, 1))
            {

            case '<':
                
                new_token = create_mlg_token(MLG_TOKEN_LES_OR_EQUAL, NULL);

                mlg_lexer_next_char(lexer);

                break;
            

            case '>':

                new_token = create_mlg_token(MLG_TOKEN_BIG_OR_EQUAL, NULL);
                
                mlg_lexer_next_char(lexer);

                break;


            default:

                new_token = create_mlg_token(MLG_TOKEN_EQUALS, NULL);


                break;
            
            }

            break;
        
        case '<':

            new_token = create_mlg_token(MLG_TOKEN_LES_THAN, NULL);

            break;

        case '>':

            new_token = create_mlg_token(MLG_TOKEN_BIG_THAN, NULL);

            break;


        case '(':

            new_token = create_mlg_token(MLG_TOKEN_L_PARENTHESIS, NULL);

            break;

        case ')':

            new_token = create_mlg_token(MLG_TOKEN_R_PARENTHESIS, NULL);

            break;

        case '[':

            new_token = create_mlg_token(MLG_TOKEN_L_BRACKET, NULL);

            break;

        case ']':

            new_token = create_mlg_token(MLG_TOKEN_R_BRACKET, NULL);

            break;

        case '{':

            new_token = create_mlg_token(MLG_TOKEN_L_BRACE, NULL);

            break;

        case '}':

            new_token = create_mlg_token(MLG_TOKEN_R_BRACE, NULL);

            break;


        case '-':

            new_token = create_mlg_token(MLG_TOKEN_SUB_OPERATOR, NULL);

            break;

        case '+':

            new_token = create_mlg_token(MLG_TOKEN_SUM_OPERATOR, NULL);
            
            break;

        case '*':

            new_token = create_mlg_token(MLG_TOKEN_MUL_OPERATOR, NULL);

            break;

        case '/':

            switch (mlg_lexer_peek_char(lexer, 1))
            {

            case '/':
                
                mlg_lexer_next_char(lexer);

                mlg_lexer_skip_line(lexer);


                break;


            case '*':
            
                mlg_lexer_next_char(lexer);
                
                mlg_lexer_next_char(lexer);


                while (lexer->current_source_char != '\0')
                {

                    if (lexer->current_source_char == '*')
                    {
                        
                        if (mlg_lexer_eat_char(lexer, '/'))
                        {

                            break;

                        }

                    }


                    mlg_lexer_next_char(lexer);                

                }
                
                break;    


            default:
        
                new_token = create_mlg_token(MLG_TOKEN_DIV_OPERATOR, NULL);


                break;
            
            }
            
            break;


        default:

            new_token = create_mlg_token(MLG_TOKEN_TODO, "default todo msg.");

            break;
        
        }


        if (new_token == NULL && lexer->current_source_char == '\0')
        {

            new_token = create_mlg_token(MLG_TOKEN_EOF, NULL);

        }


return_new_token:

        return new_token;

    }


    return create_mlg_token(MLG_TOKEN_EOF, NULL);    

}

void free_mlg_lexer(mlg_lexer_t *lexer)
{

    if (lexer == NULL)
    {

        fprintf(stderr, "todo: in %s.", __func__);

    }


    free(lexer);

}
