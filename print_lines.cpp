#include "protos.h"

void print_lines (char** lines, unsigned int line_cnt, FILE* out) {

    for (unsigned int i = 0; i < line_cnt; i++) {

        fputs (lines[i], out);
    }
}