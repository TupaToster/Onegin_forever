#include "protos.h"


error_codes errcod = OK; ///< variable to store errors


/*!
    \brief Contains body of prog

So it's basically what makes it not a set of funcs
*/
int main () {
    
    text test_input = read_text ("Onegin");

    printf ("char_len : %d \n" "str_len : %d\n" "Input as string :\n" "%s\n" "---------------\n" "Input as separate lines :\n", test_input.char_len, test_input.str_len, test_input.txt);

    for (size_t i = 0; i < test_input.str_len; i++) {

        char* ptr = test_input.lines[i].lft;
        while (ptr != test_input.lines[i].rgt) printf ("%c", *ptr++);
    }

    printf ("\n-------------");
}