#include "NTPClientToTimeSourceAdapter.h"

NTPClientToTimeSourceAdapter::NTPClientToTimeSourceAdapter(FancyThirdPartyNTPClient* ntpClient): ntpClient(ntpClient) {}

NTPClientToTimeSourceAdapter::~NTPClientToTimeSourceAdapter() {
    delete ntpClient;
}

std::tm* NTPClientToTimeSourceAdapter::getCurrentTime() {
    // Here we're taking the result of adapter class and converting it into a type that
    // the adapter's client will understand
    time_t time = ntpClient->getTimeFromServer();
    return localtime(&time);
}