#ifndef FILEHANDLING_LOCALFETCHER_HPP
#define FILEHANDLING_LOCALFETCHER_HPP

#include "IFileFetcher.hpp"

#include <filesystem>
#include <iostream>

#include "../../Misc/Types.hpp"

class LocalFetcher : public IFileFetcher
{
public:
    std::string Fetch() override;
private:
    std::string GetFilePath();
};

#endif //FILEHANDLING_LOCALFETCHER_HPP