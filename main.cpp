#include "protos.h"

/*!
    \brief Holds a program that sorts Onegin_file
    \param argc - count of com line args
    \param argv - array of com line args
    \return 0 - if OK

first it  reads strings from file with name Onegin_file, second it sorts them and prints them
*/
int main (int argc, char* argv[]) {


    FILE* Onegin_file = fopen ("Onegin_file", "r");
    assert (Onegin_file != NULL);
    FILE* out_file    = fopen ("out_file", "w");
    assert (out_file    != NULL);

    unsigned int line_cnt = calc_file_lines (Onegin_file);

    char** lines = NULL;

    read_lines (&lines, Onegin_file, line_cnt);

    mergesort_str (lines, lines + line_cnt);

    print_lines (lines, line_cnt, out_file);

    for (int i = 0; i < line_cnt+1; i++) {

        free (lines[i]);
    }

    free (lines);
    
    fclose (Onegin_file);
    free (Onegin_file);
    
    fclose (out_file);
    free (out_file);
}