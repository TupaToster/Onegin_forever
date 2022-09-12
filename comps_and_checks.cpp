#include "protos.h"

/*!
    \brief Checks if c is a letter/number
    \param c char to check
    \return true if is a letter/number
    \return false - in any other case
*/
bool is_txt (const char c) {

    return ((c >= 'A' and c <= 'Z')
         or (c >= 'a' and c <= 'z')
         or (c >= '0' and c <= '9'));
}


/*!
    \brief Compares two strings, straight
    \param line1 first line
    \param line2 second line
    \return -1 if line1 < line2
    \return 0 if line1 = line2
    \return 1 if line1 > line2

Compares two strings the straight way
prepares strings for comp_core with delta = 1
*/
int comp_str (const void* line1, const void* line2) {

    line fst = *( (const line*) line1);
    line scd = *( (const line*) line2);
    
    return comp_core (fst, scd, 1);
}


/*!
    \brief Compares two strings, reverse
    \param line1 first line
    \param line2 second line
    \return -1 if line1 < line2 in reverse
    \return 0 if line1 = line2
    \return 1 if line1 > line2 in reverse

Compares two strings in reverse
Prepares strings for comp_core with delta = -1
*/
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


/*!
    \brief Core of comparison
    \param line1 first line
    \param line2 second line
    \param delta number that is added to lft of each string on each turn
    \return -1 - line1 < line2 with current delta
    \return 0 - line1 = line2
    \return 1 - line1 > line2 with current delta

Compares two strings, where lft points to the beginning of string, rgt - to element
next after end of string
Uses delta to move ptrs that lets sort strings in reverse
*/
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