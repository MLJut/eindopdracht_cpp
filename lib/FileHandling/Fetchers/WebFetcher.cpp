#include "WebFetcher.hpp"

#include <iostream>
#include <regex>
#include <cpr/cpr.h>

#include "../../config.hpp"

std::string WebFetcher::Fetch()
{
    std::string usrInput;

    bool condition = true;
    do {
        std::cout << "Link:";
        std::cin >> usrInput;

        if (this->IsLink(usrInput) == true)
            condition = false;

    } while (condition);   

    std::cout << usrInput << std::endl;

    std::filesystem::path sysPath = this->DownloadFile(usrInput);

    if (sysPath.string() == "")
    {
        std::runtime_error("LocalFetcher::Fetch - Path was empty");
    }

    return sysPath.string();
}

bool WebFetcher::IsLink(std::string input)
{
    std::regex regex("(^(http|https|)://([\\w-]+\\.)+[\\w-]+(/[\\w\\- ./?%&=]*)?$)");
    if ( std::regex_match(input, regex) ) {
        std::cout << "WebFetcher::IsLink returned: true" << std::endl;
        return true;
    }
    std::cout << "WebFetcher::IsLink returned: false" << std::endl;
    return false;
}

std::filesystem::path WebFetcher::DownloadFile(std::filesystem::path path)
{
    std::string delimiter = "?alt=media";
    std::filesystem::path fileName = "";
    size_t pos = path.string().find(delimiter);
    if ( pos != std::string::npos ){
        fileName = path.string().substr(0, pos);
    }

    // ADD WEB TO THE PATH TO MAKE SURE IT DOESN'T OVERWRITE ALREADY EXISTING FILES
    std::filesystem::path dir = DOWNLOAD_DIR;
    std::filesystem::path filePath = dir / fileName.filename();

    std::string str_url = path.string();
    std::string str_path = filePath.string();

    LPCSTR URL = str_url.c_str();
    LPCSTR PATH = str_path.c_str();

    auto code = URLDownloadToFile(NULL, URL, PATH, 0, NULL);
    if (S_OK == code) {
        std::cout << "WebFetcher::DownloadFile returned: OK" << std::endl;
        return filePath;
    }

    std::cout << "WebFetcher::DownloadFile returned: NOK" << std::endl;
    return "";
}