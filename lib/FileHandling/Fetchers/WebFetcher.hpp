#ifndef FILEHANDLING_WEBFETCHER_HPP
#define FILEHANDLING_WEBFETCHER_HPP

#include "IFileFetcher.hpp"

#include <filesystem>

class WebFetcher : public IFileFetcher
{
public:
    std::string Fetch() override;
private:
    bool IsLink(std::string);
    std::filesystem::path DownloadFile(std::filesystem::path);
};

#endif //FILEHANDLING_WEBFETCHER_HPP