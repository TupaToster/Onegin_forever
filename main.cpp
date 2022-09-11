#include "protos.h"

/*
create struct text - ok
func to read file
func to calculate length of file
func to sort
*/
error_codes errcod = OK;
int main () {
    
    text onegin = read_text ("Onegin");

    qsort (onegin.lines, onegin.str_len, sizeof (line), &comp_str);

    for (size_t i = 0; i < onegin.str_len; i++)
        print_line (onegin.lines[i]);

    printf ("-----------------------------\n");
    
    qsort (onegin.lines, onegin.str_len, sizeof (line), &comp_arabic);

    for (size_t i = 0; i < onegin.str_len; i++)
        print_line (onegin.lines[i]);

    printf ("-----------------------------\n");

    printf ("%s", onegin.txt);

}