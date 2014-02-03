#ifndef __DataTransferObjectPattern__Tweet__
#define __DataTransferObjectPattern__Tweet__

class Tweet {
public:
    Tweet(const char* message, const char* author);
    const char* getMessage();
    const char* getAuthor();
    ~Tweet();
private:
    char* message;
    char* author;
};

#endif /* defined(__DataTransferObjectPattern__Tweet__) */
