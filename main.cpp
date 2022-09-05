#include "protos.h"

/*!
    \brief Holds a program that sorts onegin
    \param argc - count of com line args
    \param argv - array of com line args
    \return 0 - if OK

first it  reads strings from file with name onegin
second it sorts them
and prints them
*/
int main (int argc, char* argv[]) {


    FILE* onegin = fopen ("onegin", "r");
    assert (onegin != NULL);
    FILE* out    = fopen ("out", "w");
    assert (out    != NULL);

    unsigned int line_cnt = calc_file_lines (onegin);

    char** lines = NULL;

    read_lines (&lines, onegin, line_cnt);

    mergesort_str (lines, lines + line_cnt);

    print_lines (lines, line_cnt, out);
}