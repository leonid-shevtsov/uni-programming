#ifndef __AdapterPattern__TimeSource__
#define __AdapterPattern__TimeSource__

#include <ctime>

class TimeSource {
public:
    virtual std::tm* getCurrentTime() = 0;
    virtual ~TimeSource() {};
};

#endif /* defined(__AdapterPattern__TimeSource__) */
