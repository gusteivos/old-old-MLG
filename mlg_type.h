
#ifndef MLG_TYPE_H_
#define MLG_TYPE_H_    

    #include <stdio.h>
    #include <stdlib.h>


    /* TODO: CREATE TYPE FLAGS DEFINITION */


    typedef enum mlg_type_e
    {

        MLG_TYPE_NONE = 0,

        MLG_TYPE_BYT,
        MLG_TYPE_SHT,
        MLG_TYPE_INT,
        MLG_TYPE_LNG,

        MLG_TYPE_FLT,
        MLG_TYPE_DBL,

    } mlg_type_t;

    typedef struct mlg_type_value_s
    {
        
        mlg_type_t type;

        int flags;


        union
        {

            signed   char _singed_byte  ;
            unsigned char _byte         ;
            unsigned char _ungned_byte  ;
            signed   short _signed_short;
            short          _short       ;
            unsigned short _ungned_short;
            signed   int _signed_integer;
            int          _integer       ;
            unsigned int _ungned_integer;
            signed   long _signed_long  ;
            long          _long         ;
            unsigned long _ungned_long  ;

            float _float  ;
            double _double;

        };
        

    } mlg_type_value_t;


    extern mlg_type_value_t *create_mlg_type_value(mlg_type_t type);


    extern void free_mlg_type_value(mlg_type_value_t *type_value);

#endif
