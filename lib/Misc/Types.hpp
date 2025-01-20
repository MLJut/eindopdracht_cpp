#ifndef MISC_TYPES_HPP
#define MISC_TYPES_HPP

#include <iostream>
#include <string>

// Struct om een locatie te representeren
struct Locatie {
    int id = -1;
    int noord = -1, oost = -1, zuid = -1, west = -1;
    std::string naam;
    std::string beschrijving;
    std::string vijand;
    std::string objectenVerborgen;
    std::string objectenZichtbaar;

    void print() const {
        std::cout << "Locatie ID: " << id << "\n"
                  << "Naam: " << naam << "\n"
                  << "Beschrijving: " << beschrijving << "\n"
                  << "Noord: " << noord << " Oost: " << oost
                  << " Zuid: " << zuid << " West: " << west << "\n"
                  << "Vijand: " << vijand << "\n"
                  << "Objecten Verborgen: " << objectenVerborgen << "\n"
                  << "Objecten Zichtbaar: " << objectenZichtbaar << "\n"
                  << "---\n";
    }
};

enum class FileExtension
{
    XML,
    TXT,
    CSV
};

#endif //MISC_TYPES_HPP