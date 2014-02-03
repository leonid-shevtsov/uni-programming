#include <iostream>
#include "TwitterClient.h"

int main(int argc, const char * argv[])
{
    TwitterClient* twitterClient = new TwitterClient();
    Tweet* tweet = twitterClient->getLatestTweet();
    std::cout << "Latest tweet: \"" << tweet->getMessage() << "\" by " << tweet->getAuthor() << std::endl;
    return 0;
}

