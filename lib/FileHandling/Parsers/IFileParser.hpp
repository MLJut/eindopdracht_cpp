#ifndef IFILEPARSER_H
#define IFILEPARSER_H

#include <string>

class IFileParser {
public:
    virtual ~IFileParser() = default;

    virtual void readFile(const std::string& filePath) = 0;
};

#endif // IFILEPARSER_H