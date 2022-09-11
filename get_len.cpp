#include "protos.h"

size_t get_len (const char* file_name) {

    struct stat info = {};

    get_out (stat (file_name, &info) != 0, 0, MEM_ERR);
    
    return info.st_size;
}