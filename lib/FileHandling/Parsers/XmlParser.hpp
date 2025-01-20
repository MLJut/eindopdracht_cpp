#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <iostream>
#include <string>
#include "./IFileParser.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "../../Misc/Types.hpp"

class XmlParser : public IFileParser {
private:
    

public:
    XmlParser () {};
    virtual ~XmlParser() {};

    void readFile(const std::string& filePath) override;

};

#endif // XMLPARSER_H