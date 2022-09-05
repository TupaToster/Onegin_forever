#include "protos.h"

/*!
    \brief Interface to interact with mergesort_str_inside. Look for docs there
*/
void mergesort_str (char** l, char** r) {

    char** temp = (char**) calloc (r - l + 1, sizeof (char*));
    assert (temp != NULL);

    mergesort_str_inside (l, r, temp);
}

/*!
    \brief Sorts an array of strings in right order
    \param l - pointer to the beginning of an array
    \param r - pointer to the element right after an array end
    \param temp - temporary array used for merging

Mergesorts through a c-string array
tries not to eat memory but is bad at it
also fast somehow 
*/
void mergesort_str_inside (char** l, char** r, char** temp) {

    if (r == l + 1) return;

    unsigned int line_cnt = r - l;
    char** mid = l + (line_cnt) / 2;
    char** l_ptr = l;
    char** r_ptr = mid;

    mergesort_str_inside (l, mid, temp);
    mergesort_str_inside (mid, r, temp);

    for (unsigned int i = 0; i < line_cnt; i++) {

        if (l_ptr != mid) {

            if (r_ptr != r) {

                if (strcmp (*l_ptr, *r_ptr) < 0) {

                    temp[i] = *l_ptr;
                    l_ptr++;
                }
                else {

                    temp[i] = *r_ptr;
                    r_ptr++;
                }
            }
            else {

                temp[i] = *l_ptr;
                l_ptr++;
            }
        }
        else {

            temp[i] = *r_ptr;
            r_ptr++;
        }
    }

    for (unsigned int i = 0; i < line_cnt; i++) {

        *l = temp[i];
        l++;
    }
}