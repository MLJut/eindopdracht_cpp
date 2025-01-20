#ifndef FILEHANDLING_IFILEFETCHER_HPP
#define FILEHANDLING_IFILEFETCHER_HPP

#include <iostream>

class IFileFetcher
{
public:
    virtual std::string Fetch() = 0;
};

#endif //FILEHANDLING_IFILEFETCHER_HPP