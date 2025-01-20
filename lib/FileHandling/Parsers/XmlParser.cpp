#include "./XmlParser.hpp"

void XmlParser::readFile(const std::string& filePath) {
    using boost::property_tree::ptree;
    ptree tree;

    // Read the XML file
    try {
        boost::property_tree::read_xml(filePath, tree); // Creates memory leak --> 16 bytes
    } catch (const std::exception& e) {
        std::cerr << "Error reading XML file: " << e.what() << std::endl;
        return;
    }
    // Parse the locations
    for (const auto& locatieNode : tree.get_child("locaties")) {
        if (locatieNode.first == "locatie") {
            Locatie locatie;
            const auto& attributes = locatieNode.second;
            locatie.id = attributes.get<int>("<xmlattr>.id", -1);
            locatie.noord = attributes.get<int>("<xmlattr>.noord", -1);
            locatie.oost = attributes.get<int>("<xmlattr>.oost", -1);
            locatie.zuid = attributes.get<int>("<xmlattr>.zuid", -1);
            locatie.west = attributes.get<int>("<xmlattr>.west", -1);
            locatie.vijand = attributes.get<std::string>("<xmlattr>.vijand", "");
            locatie.objectenVerborgen = attributes.get<std::string>("<xmlattr>.objectenverborgen", "");
            locatie.objectenZichtbaar = attributes.get<std::string>("<xmlattr>.objectenzichtbaar", "");

            // The location name is the text content before the "beschrijving"
            locatie.naam = attributes.get<std::string>("", "");

            // The description is stored under the "beschrijving" tag
            locatie.beschrijving = attributes.get<std::string>("beschrijving", "");
            locatie.print();
            if (locationCount < MAX_LOCATIES) {
                locaties[locationCount++] = &locatie;
            }
            else {
                std::cerr << "Error: Maximum number of locations reached (" << MAX_LOCATIES << ")\n";
            }
        }
    }
    tree.clear();
}

Locatie* XmlParser::getLocations() {
    return locaties; // returns pointer to first element of array
}