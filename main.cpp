#include "protos.h"

/*
create struct text - ok
func to read file
func to calculate length of file
func to sort
*/
error_codes errcod = OK;
int main () {
    
    text test_input = read_text ("Onegin");

<<<<<<< HEAD
    printf ("char_len : %d \n" "str_len : %d\n" "Input as string :\n" "%s\n" "---------------\n" "Input as separate lines :\n", test_input.char_len, test_input.str_len, test_input.txt);
=======
    qsort (onegin.lines, onegin.str_len, sizeof (line), &comp_str);
>>>>>>> parent of f25ef8c (Added docs)

    for (size_t i = 0; i < test_input.str_len; i++) {

<<<<<<< HEAD
        char* ptr = test_input.lines[i].lft;
        while (ptr != test_input.lines[i].rgt) printf ("%c", *ptr++);
    }
=======
    printf ("-----------------------------\n");
    
    qsort (onegin.lines, onegin.str_len, sizeof (line), &comp_arabic);

    for (size_t i = 0; i < onegin.str_len; i++)
        print_line (onegin.lines[i]);

    printf ("-----------------------------\n");

    printf ("%s", onegin.txt);
>>>>>>> parent of f25ef8c (Added docs)

    printf ("\n-------------");
}