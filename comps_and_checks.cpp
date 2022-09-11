#include "protos.h"

bool is_txt (const char c) {

    return ((c >= 'A' and c <= 'Z')
         or (c >= 'a' and c <= 'z')
         or (c >= '0' and c <= '9'));
}

int comp_str (const void* line1, const void* line2) {

    line fst = *( (const line*) line1);
    line scd = *( (const line*) line2);
    
    return comp_core (fst, scd, 1);
}

int comp_arabic (const void* line1, const void* line2) {
    
    line fst = *( (const line*) line1);
    line scd = *( (const line*) line2);
    
    fst.lft--;
    scd.lft--;
    fst.rgt--;
    scd.rgt--;

    char* temp = fst.lft;
    fst.lft = fst.rgt;
    fst.rgt = temp;

    temp = scd.lft;
    scd.lft = scd.rgt;
    scd.rgt = temp;

    return comp_core (fst, scd, -1);
}

int comp_core (line fst, line scd, int delta) {

    while (!is_txt (*fst.lft) and fst.lft != fst.rgt) fst.lft += delta;
    while (!is_txt (*scd.lft) and scd.lft != scd.rgt) scd.lft += delta;

    while (*fst.lft == *scd.lft and fst.lft != fst.rgt and scd.lft != scd.rgt) {

        fst.lft += delta;
        scd.lft += delta;
    }

    if (fst.lft == fst.rgt and scd.lft != scd.rgt) return -1;
    if (fst.lft != fst.rgt and scd.lft == scd.rgt) return 1;
    if (fst.lft == fst.rgt and scd.lft == scd.rgt) return 0;

    if (*fst.lft <= *scd.lft) return -1;
    if (*fst.lft > *scd.lft) return 1;

    return 0;
}