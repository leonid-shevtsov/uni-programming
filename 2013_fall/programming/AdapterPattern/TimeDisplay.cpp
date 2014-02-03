#include <iostream>
#include "TimeDisplay.h"

TimeDisplay::TimeDisplay(TimeSource* timeSource): timeSource(timeSource) {}

void TimeDisplay::displayTime() {
    char buffer[100];
    strftime(buffer, 100, "%c", timeSource->getCurrentTime());
    std::cout << "Current time: " << buffer << std::endl;
}