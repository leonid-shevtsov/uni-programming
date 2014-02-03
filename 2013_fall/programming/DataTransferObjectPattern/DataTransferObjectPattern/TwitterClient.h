#ifndef __DataTransferObjectPattern__TwitterClient__
#define __DataTransferObjectPattern__TwitterClient__

#include "Tweet.h"

class TwitterClient {
public:
    Tweet* getLatestTweet();
};

#endif /* defined(__DataTransferObjectPattern__TwitterClient__) */
