#include <string>
#include "TwitterClient.h"

Tweet* TwitterClient::getLatestTweet() {
    // Here the Client makes a remote request to some API that returns the data in one package
    // such as this super simple encoding for demo purposes
    // Then the Client creates a data transfer object from the data.
    char remoteData[] = "Hello, World\n@leonid_shevtsov";
    char* author = strstr(remoteData, "\n");
    *author++ = 0;
    return new Tweet(remoteData, author);
}