#include "protos.h"

void print_line (line out) {

    while (out.lft != out.rgt) fputc (*out.lft, stdout);
}