#include "mlg_token.h"
#include <string.h>


void serialize_token(FILE *file, const mlg_token_t *token)
{

    if (file == NULL || token == NULL)
    {
    
        return;
    
    }

    
    fwrite(&(token->type), sizeof(mlg_token_type_t), 1, file);


    size_t value_length = strlen(token->value);

    fwrite(&value_length, sizeof(size_t), 1, file);


    fwrite(token->value, sizeof(char), value_length, file);

}

mlg_token_t *deserialize_token(FILE *file) {
    
    if (file == NULL)
    {
    
        return NULL;
    
    }


    mlg_token_t *deserialized_token = (mlg_token_t *)malloc(sizeof(mlg_token_t));

    if (deserialized_token == NULL)
    {
    
        return NULL;
   
    }


    fread(&(deserialized_token->type), sizeof(mlg_token_type_t), 1, file);


    size_t value_length;

    fread(&value_length, sizeof(size_t), 1, file);

    deserialized_token->value = (char *)malloc(value_length + 1);
    
    if (deserialized_token->value == NULL)
    {

        free(deserialized_token);

        return NULL;

    }
    

    fread(deserialized_token->value, sizeof(char), value_length, file);
    
    deserialized_token->value[value_length] = '\0';


    return deserialized_token;

}
