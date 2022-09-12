#include "protos.h"

/*!
    \brief Reads from file_name to text struct
    \param file_name name of file to read from
    \return struct text variable

In process uses funcs buffer, get_len
*/
text read_text (const char* file_name) {

    text input = {};

    input.txt = buffer (file_name, &input.char_len, &input.str_len);
    
    input.lines = (line*) calloc (input.str_len + 1, sizeof (line));
    get_out (input.lines == NULL, {}, BAD_ALLOC);
    
    int lines_iter = 0;
    for (size_t i = 0; i < input.char_len; i++) {

        if (input.lines[lines_iter].lft == NULL) input.lines[lines_iter].lft = input.txt + i;
        
        if (input.txt[i] == '\n') {
 
            input.lines[lines_iter].rgt = input.txt + i + 1;
            lines_iter++;
        }
    }

    input.lines[lines_iter].rgt = input.txt + input.char_len;
    input.txt[input.char_len] = '\0';

    return input;
}