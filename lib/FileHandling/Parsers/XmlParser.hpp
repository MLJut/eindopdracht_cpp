#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <iostream>
#include <string>
#include "./IFileParser.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "../../Misc/Types.hpp"
#include "../../Misc/Defines.hpp"

class XmlParser : public IFileParser {
private:
    Locatie* locaties[MAX_LOCATIES];
    int locationCount = 0;

public:
    XmlParser () {
        for (int i = 0; i < MAX_LOCATIES; i++) {
            locaties[i] = nullptr;
        }
    };
    virtual ~XmlParser() {
        for (int i = 0; i < MAX_LOCATIES; i++) {
            if(locaties[i] != nullptr){
                delete locaties[i];
            }
        }
    };

    void readFile(const std::string& filePath) override;
    // Locatie* getLocations();
};

#endif // XMLPARSER_H