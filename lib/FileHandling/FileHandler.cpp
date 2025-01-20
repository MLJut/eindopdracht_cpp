#include "FileHandler.hpp"

// #include "../Misc/Types.hpp"

#include <iostream>
#include <filesystem>
// #include <cpr/cpr.h> --> just the include causes memory leaks
#include <stdexcept>

FileHandler::FileHandler()
{
    for (int i = 0; i < MAX_LOCATIES; i++) {
        locaties[i] = nullptr;
    }
}

FileHandler::~FileHandler()
{
    for (int i = 0; i < MAX_LOCATIES; i++) {
        if(locaties[i] != nullptr){
            delete locaties[i];
        }
    }
}

FileExtension FileHandler::getFileType(const std::string& fileType) {
    if (fileType == ".xml") return FileExtension::XML;
    throw std::invalid_argument("Unknown filetype");
}

Error FileHandler::GetFile()
{
    std::string path = this->_local.Fetch();

    if ( path == "" )
        return Error::FAIL;

    this->SelectParser(path);

    return Error::OK;
}

Error FileHandler::SelectParser(std::string path)
{
    // parser selection
    std::filesystem::path filePath = path;
    FileExtension fileExtension = getFileType(filePath.extension().string());
    switch(fileExtension) {
        case FileExtension::XML:
            this->_xmlParser.readFile(path);
            break;
        default:
            std::cout << "Invalid file type" << std::endl;
            return Error::FAIL;
    }

    return Error::OK;
}

void FileHandler::receiveLocations() {
    // get the locations from the parser
    Locatie* receivedLocations = this->_xmlParser.getLocations();
    for (int i = 0; i < MAX_LOCATIES; i++) {
        locaties[i] = receivedLocations[i]; // copy the pointers
    }
    delete locations;
}

void FileHandler::emptyData()
{
    // empty the data
    for (int i = 0; i < MAX_LOCATIES; i++) {
        locaties[i] = nullptr;
    }
}