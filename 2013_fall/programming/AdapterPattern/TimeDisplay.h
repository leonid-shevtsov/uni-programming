#ifndef __AdapterPattern__TimeDisplay__
#define __AdapterPattern__TimeDisplay__

#include "TimeSource.h"

class TimeDisplay {
public:
    TimeDisplay(TimeSource* timeSource);
    void displayTime();
    
private:
    TimeSource* timeSource;
};

#endif /* defined(__AdapterPattern__TimeDisplay__) */
