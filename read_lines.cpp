#include "protos.h"

/*!
    \brief Reads an array of c-strings
    \param lines - ptr to a char** that will point to an array of strings
    \param src - FILE* to read from
    \param line_cnt - max amount of lines read

Reads lines to an array of c-strings
reads not more than line_cnt lines
may read less and say nothing
*/
void read_lines (char*** lines, FILE* src, unsigned int line_cnt) {

    char* temp = (char*) malloc (200);
    *lines = (char**) calloc (line_cnt + 1, sizeof (char*));
    assert (lines != NULL);
    assert (*lines != NULL);
    (*lines)[line_cnt] = (char*) malloc (20);
    strcpy ((*lines)[line_cnt], "end of lol man");

    for (unsigned int i = 0; i < line_cnt; i    ++) {

        temp = fgets (temp, 199, src);
        if (temp == NULL) break;
        (*lines)[i] = (char*) malloc (strlen (temp) + 1);
        strcpy ((*lines)[i], temp);
    }
}