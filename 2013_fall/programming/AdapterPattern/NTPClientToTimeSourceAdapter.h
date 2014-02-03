#ifndef __AdapterPattern__NTPClientToTimeSourceAdapter__
#define __AdapterPattern__NTPClientToTimeSourceAdapter__

#include "TimeSource.h"
#include "FancyThirdPartyNTPClient.h"

class NTPClientToTimeSourceAdapter: public TimeSource {
public:
    NTPClientToTimeSourceAdapter(FancyThirdPartyNTPClient* ntpClient);
    virtual ~NTPClientToTimeSourceAdapter();

    virtual std::tm* getCurrentTime();
private:
    FancyThirdPartyNTPClient* ntpClient;
};

#endif /* defined(__AdapterPattern__NTPClientToTimeSourceAdapter__) */
