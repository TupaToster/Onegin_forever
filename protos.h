#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef ERRCODES
enum error_codes {
    OK = 0, 
    BAD_ALLOC = -1, 
    MEM_ERR = 1
};

extern error_codes errcod;

#define get_out( cond, return_val, error_code ) \
    if (cond) {                                 \
        errcod = error_code;                    \
        return return_val;                      \
    }

#define ERRCODES
#endif

struct line {

    char* lft = NULL;
    char* rgt = NULL;
};

struct text {

    size_t char_len = 0;
    size_t str_len = 0;
    char* txt = NULL;
    line* lines = NULL;
};

size_t get_len (const char* file_name);

text read_text (const char* file_name);

char* buffer (const char* file_name, size_t* char_len, size_t* str_len);

bool is_txt (const char c);

int comp_str (const void* line1, const void* line2);

int comp_arabic (const void* line1, const void* line2);

int comp_core (line fst, line scd, int delta);

void print_line (line out);
