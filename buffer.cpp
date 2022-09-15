#include "protos.h"

char* buffer (const char* file_name, size_t* char_len, size_t* str_len) {

    FILE* input = fopen (file_name, "r");

    fseek (input, -1, SEEK_END);
    if (fgetc (input) != '\n') {

        fclose (input);

        input = fopen (file_name, "a");

        fputc ('\n', input);

        fclose (input);

        input = fopen (file_name, "r");
    }
    fseek (input, 0, SEEK_SET);

    *char_len = get_len (file_name);

<<<<<<< HEAD
    printf ("%d", *char_len);

    char* buff = (char*) calloc (*char_len + 2 + n_before_EOF, sizeof (char));
    assert (buff != NULL);
=======
    char* buff = (char*) calloc (*char_len + 2, sizeof (char));
>>>>>>> parent of f25ef8c (Added docs)
    buff++;

    get_out (fread (buff, sizeof (char), *char_len, input) == 0, NULL, MEM_ERR);

    buff[*char_len] = '\0';

    *str_len = *char_len - strlen (buff) + 1;

    fclose (input);
    return buff;
}