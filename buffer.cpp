#include "protos.h"

char* buffer (const char* file_name, size_t* char_len, size_t* str_len) {

    FILE* input = fopen (file_name, "r");
    
    *char_len = get_len (file_name);

    char* buff = (char*) calloc (*char_len + 1, sizeof (char));

    get_out (fread (buff, sizeof (char), *char_len, input) == 0, NULL, MEM_ERR);

    buff[*char_len] = '\0';

    *str_len = *char_len - strlen (buff) + 1;

    fclose (input);
    return buff;
}