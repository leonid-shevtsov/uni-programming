#ifndef __AdapterPattern__FancyThirdPartyNTPClient__
#define __AdapterPattern__FancyThirdPartyNTPClient__

#include <ctime>

class FancyThirdPartyNTPClient {
public:
    time_t getTimeFromServer();
};


#endif /* defined(__AdapterPattern__FancyThirdPartyNTPClient__) */
