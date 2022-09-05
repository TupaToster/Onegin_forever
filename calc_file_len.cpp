#include "protos.h"

/*!
    \brief Calculates amount of lines in a file
    \param src - FILE* to calculate length of
*/
unsigned int calc_file_lines (FILE* src) {

    unsigned int line_cnt = 0;
    char* temp = (char*) malloc (200);
    assert (temp != NULL);
    
    while (fgets (temp, 199, src) != NULL) line_cnt++;

    fseek (src, SEEK_SET, 0);

    return line_cnt;
}