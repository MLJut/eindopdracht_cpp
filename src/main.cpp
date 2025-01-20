// memory leak detection
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include "../lib/FileHandling/FileHandler.hpp"
// #include "../lib/FileHandling/Parsers/XmlParser.hpp"

int main() {
    // Enable detailed memory leak reporting
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    FileHandler fileHandler;
    fileHandler.GetFile();
    // XmlParser xmlParser;
    // xmlParser.readFile("C:\\Users\\Matthijs\\School\\cpp\\eindopdracht_cpp\\resources\\kasteelruine.xml");

    // memory leak detection
    _CrtDumpMemoryLeaks();
    return 0;
}