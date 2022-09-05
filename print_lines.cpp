#include "protos.h"

/*!
    \brief Prints array of c-strings
    \param lines - char** type var, that points to the first elem of array
    \param line_cnt - amount of strings
    \param out - FILE* type var 

This function prints to "out" file an array of c-strings
*/
void print_lines (char** lines, unsigned int line_cnt, FILE* out) {

    for (unsigned int i = 0; i < line_cnt; i++) {

        fputs (lines[i], out);
    }
}