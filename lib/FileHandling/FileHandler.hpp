#ifndef FILEHANDLING_FILEHANDLER_HPP
#define FILEHANDLING_FILEHANDLER_HPP

#pragma comment (lib, "urlmon.lib")

#include "../Misc/Types.hpp"
#include "../Misc/Error.hpp"
#include "Fetchers/LocalFetcher.hpp"
#include "Parsers/XmlParser.hpp"


class FileHandler
{
public:
    FileHandler();
    virtual ~FileHandler();

    Error GetFile();

    Error SelectParser(std::string path);
    FileExtension getFileType(const std::string& fileType);
    void receiveLocations();
    void emptyData();

private:
    LocalFetcher _local;
    XmlParser _xmlParser;

    Locatie* locaties[MAX_LOCATIES];
    int locationCount = 0;
};

#endif //FILEHANDLING_FILEHANDLER_HPP