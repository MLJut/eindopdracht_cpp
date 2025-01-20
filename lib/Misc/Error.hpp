#ifndef MISC_ERROR_HPP
#define MISC_ERROR_HPP

enum class Error
{
    OK = 0,
    FAIL = -1,
    INVALID_ARG = -100,
    ALREADY_SET = -101
};

#endif //MISC_ERROR_HPP