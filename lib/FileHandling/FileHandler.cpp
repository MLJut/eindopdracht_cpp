#include "FileHandler.hpp"

#include "../Misc/Types.hpp"


#include <iostream>
#include <filesystem>
#include <cpr/cpr.h>
#include <stdexcept>

FileHandler::FileHandler()
{

}

FileHandler::~FileHandler()
{

}

FileExtension FileHandler::getFileType(const std::string& fileType) {
    if (fileType == ".xml") return FileExtension::XML;
    if (fileType == ".txt") return FileExtension::TXT;
    if (fileType == ".csv") return FileExtension::CSV;
    throw std::invalid_argument("Unknown filetype");
}

Error FileHandler::GetFile()
{
    // ask for file from user using terminal (1->local, 2->web)
    // if (1) open explorer [localFetcher]
    // if (2) enter link through terminal -> [webFetcher]

    std::string path = SelectLocation();

    if ( path == "" )
        return Error::FAIL;

    this->SelectParser(path);

    return Error::OK;
}

std::string FileHandler::SelectLocation() {
    int usrInput;

    std::cout << "Please select one of the following options (1||2)" << std::endl;
    std::cout << "(1) - Local File" << std::endl;
    std::cout << "(2) - Web File" << std::endl;
    
    bool condition = true;

    std::string path;

    do {
        std::cout << "Ans:";
        std::cin >> usrInput;

        switch(usrInput) {
            case 1:
                condition = false;
                path = this->_local.Fetch();
                break;
            case 2:
                condition = false;
                path = this->_web.Fetch();
                break;
            default:
                return "";
        }

    } while (condition);

    return path;
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
        case FileExtension::TXT:
            break;
        case FileExtension::CSV:
            break;
        default:
            std::cout << "Invalid file type" << std::endl;
            return Error::FAIL;
    }

    return Error::OK;
}

void FileHandler::emptyData()
{
    // empty the data
}