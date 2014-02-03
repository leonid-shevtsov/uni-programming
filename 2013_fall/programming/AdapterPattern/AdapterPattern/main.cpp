#include <iostream>

#include "TimeDisplay.h"
#include "NTPClientToTimeSourceAdapter.h"

int main(int argc, const char * argv[])
{
    TimeSource* timeSource = new NTPClientToTimeSourceAdapter(new FancyThirdPartyNTPClient());
    TimeDisplay* timeDisplay = new TimeDisplay(timeSource);
    
    std::cout << "Displaying time from FancyNTPClient: " << std::endl;
    timeDisplay->displayTime();
    
    delete timeSource;
    delete timeDisplay;
    
    return 0;
}

