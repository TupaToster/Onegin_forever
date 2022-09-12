#include "protos.h"


/*!
    \brief Returns len of file in chars
    \param file_name name of file that's length will be returned
    \return sizeof file in chars
*/
size_t get_len (const char* file_name) {

    struct stat info = {};

    get_out (stat (file_name, &info) != 0, 0, MEM_ERR);
    
    return info.st_size;
}