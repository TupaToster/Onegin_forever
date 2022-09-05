#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void mergesort_str (char** l, char** r);

void mergesort_str_inside (char** l, char** r, char** temp);

unsigned int calc_file_lines (FILE* src);

void read_lines (char*** lines, FILE* src, unsigned int line_cnt);

void print_lines (char** lines, unsigned int line_cnt, FILE* out);