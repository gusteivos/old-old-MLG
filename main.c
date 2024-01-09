#include "main.h"

char *read_file_as_string(const char *filename)
{

    char *data_buffer = NULL;


    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {

        fprintf(stderr, "Error opening file in path: %s.\n", filename);


        goto endoffunc;

    }


    fseek(file, 0, SEEK_END);

    long file_size = ftell(file);

    rewind(file);


    data_buffer = (char *)malloc((file_size + 1) * sizeof(char));

    if (data_buffer == NULL)
    {

        fprintf(stderr, "Memory allocation error while reading file: %s.\n", filename);


        fclose(file);


        goto endoffunc;

    }


    size_t read_elements = fread(data_buffer, sizeof(char), (size_t)file_size, file);

    if (read_elements == 0)
    {

        fprintf(stderr, "Error reading file: %s.\n", filename);


        free(data_buffer);

        data_buffer = NULL;

        fclose(file);


        goto endoffunc;

    }


    data_buffer[read_elements] = '\0';

    fclose(file);


endoffunc:

    return data_buffer;

}


int main(int argc, char *argv[])
{

    if (argc < 2)
    {

        printf("Use: %s file/patch/file.name\n", argv[0]);


        return EXIT_FAILURE;

    }

    char *source_file_data = read_file_as_string(argv[1]);

    if (source_file_data == NULL)
    {

        printf("todo: .\n");


        return EXIT_FAILURE;

    }


    printf("############source############\n");

    printf("%s", source_file_data);

    printf("#############code#############\n");



    mlg_lexer_t *lexer = create_mlg_lexer(source_file_data);


    bool can_exit = false;

    mlg_token_t *curent_token = NULL;

    mlg_lexer_skip_spaces(lexer);


    while(!can_exit)
    {

        curent_token = mlg_lexer_next_token(lexer);


        if (curent_token != NULL)
        {

            printf("token (type: %2d), (str type: %s), (value: %s).\n", curent_token->type, mlg_token_type_to_string(curent_token->type), curent_token->value);


            switch (curent_token->type)
            {

            case MLG_TOKEN_EOF:

                can_exit = true;


                continue;

            }

        }


        mlg_lexer_next_char(lexer);

    }


    return EXIT_SUCCESS;

}
