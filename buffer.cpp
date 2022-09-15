#include "protos.h"

/*!
    \brief Bufferizes file input
    \param file_name name of file to buffer
    \param char_len ptr to where to put len of file in chars
    \param str_len ptr to where to put len of file in strings
    \return ptr to memory that contains file'c contents
    \warning str_len calculation works correctly only on crlf endings

Bufferizes file input and allocates memory for read content
Calculates and returns length of file in chars and lines
Allocated memory contains one '\0' in front of file contents and one after
Puts \n in front of '\0' in buff if there is none
*/
char* buffer (const char* file_name, size_t* char_len, size_t* str_len) {

    FILE* input = fopen (file_name, "r");
    int n_before_EOF = 0;

    fseek (input, -1, SEEK_END); ///< Checks for absence of '\n' right before EOF for prettyness
    if (fgetc (input) != '\n') {

        ++*char_len;
        n_before_EOF = 1;
    }
    fseek (input, 0, SEEK_SET); ///< If there is one, places '\n' at the end of buff

    *char_len = get_len (file_name);

    printf ("%d", *char_len);

    char* buff = (char*) calloc (*char_len + 2 + n_before_EOF, sizeof (char));
    assert (buff != NULL);
    buff++;

    get_out (fread (buff, sizeof (char), *char_len - n_before_EOF, input) == 0, NULL, MEM_ERR);

    buff[*char_len - n_before_EOF] = '\n';

    buff[*char_len] = '\0';

    *str_len = *char_len - strlen (buff) + 1;

    fclose (input);
    return buff;
}