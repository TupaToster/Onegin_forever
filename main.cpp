#include "protos.h"


error_codes errcod = OK; ///< variable to store errors


/*!
    \brief Contains body of prog

So it's basically what makes it not a set of funcs
*/
int main () {
    
    text onegin = read_text ("Onegin");

    qsort (onegin.lines, onegin.str_len, sizeof (line), &comp_str);///< Sorts strings pravoslavno

    for (size_t i = 0; i < onegin.str_len; i++)
        print_line (onegin.lines[i]);

    printf ("-----------------------------\n");
    
    qsort (onegin.lines, onegin.str_len, sizeof (line), &comp_arabic);///< Sorts strings arabsky

    for (size_t i = 0; i < onegin.str_len; i++)
        print_line (onegin.lines[i]);

    printf ("-----------------------------\n");

    printf ("%s", onegin.txt);

}