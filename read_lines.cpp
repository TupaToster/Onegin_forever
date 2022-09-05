#include "protos.h"

void read_lines (char*** lines, FILE* src, unsigned int line_cnt) {

    char* temp = (char*) malloc (200);
    *lines = (char**) calloc (line_cnt + 1, sizeof (char*));
    assert (lines != NULL);
    assert (*lines != NULL);
    (*lines)[line_cnt] = (char*) malloc (20);
    strcpy ((*lines)[line_cnt], "end of lol man");

    for (unsigned int i = 0; i < line_cnt; i    ++) {

        temp = fgets (temp, 199, src);
        assert (temp != NULL);
        (*lines)[i] = (char*) malloc (strlen (temp) + 1);
        strcpy ((*lines)[i], temp);
    }
}