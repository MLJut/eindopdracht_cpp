#ifndef FILEHANDLING_FILEHANDLER_HPP
#define FILEHANDLING_FILEHANDLER_HPP

#pragma comment (lib, "urlmon.lib")

#include "../Misc/Types.hpp"
#include "../Misc/Error.hpp"
#include "Fetchers/LocalFetcher.hpp"
#include "Fetchers/WebFetcher.hpp"
#include "Parsers/XmlParser.hpp"


class FileHandler
{
public:
    FileHandler();
    virtual ~FileHandler();

    Error GetFile();

    std::string SelectLocation();
    Error SelectParser(std::string path);
    FileExtension getFileType(const std::string& fileType);
    void emptyData();

private:
    LocalFetcher _local;
    WebFetcher _web;
    XmlParser _xmlParser;
};

#endif //FILEHANDLING_FILEHANDLER_HPP