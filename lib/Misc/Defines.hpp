#ifndef MISC_DEFINES_HPP
#define MISC_DEFINES_HPP

// Defines for application settings, allowed values: ["ALGA","DPA"]
#define APP_SUBJECT "DPA"

// Defines for application window dimensions
#define WINDOW_TITLE "Boogiewoogie"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

// Defines for simulation update loop
#define TICKS_PER_SECOND 20     // Update simulation 20x per second

// Defines for memento
#define MAX_MEMENTOS 15
#define SECONDS_PER_MEMENTO 5 // Every 5 seconds 1 memento (TICKS_PER_SECOND x 5)

#endif //MISC_DEFINES_HPP