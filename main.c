#include "main.h"


int main(int argc, char *argv[])
{

    if (argc < 2)
    {

        printf("Use: %s file/patch/file.name\n", argv[0]);


        return EXIT_FAILURE;

    }


    FILE *source_file = fopen(argv[1], "rb");

    if (source_file == NULL)
    {

        printf("Error opening source_file with patch: %s, errno: %d.\n", argv[1], errno);


        return EXIT_FAILURE;

    }


    fseek(source_file, 0, SEEK_END);
    
    long source_file_size = ftell(source_file);
    
    fseek(source_file, 0, SEEK_SET);


    char *source_file_data = (char *)malloc(source_file_size * sizeof(char));

    if (source_file_data == NULL)
    {
    
        printf("todo: .\n");

    
        fclose(source_file);
    

        return EXIT_FAILURE;
    
    }


    fread(source_file_data, sizeof(char), source_file_size, source_file);


    printf("############source############\n");

    printf(source_file_data);

    printf("#############code#############\n");



    mlg_lexer_t *lexer = create_mlg_lexer(source_file_data);


    bool can_exit = false;

    mlg_token_t *curent_token = NULL;

    mlg_lexer_skip_spaces(lexer);
    

    while(!can_exit)
    {

        curent_token = mlg_lexer_next_token(lexer);


        bool next_char = true;

        if (curent_token != NULL)
        {

            printf("token (type: %d), (value: %s).\n", curent_token->type, curent_token->value);


            switch (curent_token->type)
            {

            case MLG_TOKEN_EOF:

                can_exit = true;


                continue;
            
            }

        }

    
        if (next_char)
        {

            mlg_lexer_next_char  (lexer);

        }
        
        mlg_lexer_skip_spaces(lexer);

    }


    fclose(source_file);


    return EXIT_SUCCESS;

}
