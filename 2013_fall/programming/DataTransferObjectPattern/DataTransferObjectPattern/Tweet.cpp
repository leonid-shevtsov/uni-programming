#include <cstdlib>
#include <string>
#include "Tweet.h"

Tweet::Tweet(const char* message, const char* author) {
    this->message = strdup(message);
    this->author = strdup(author);
}

const char* Tweet::getMessage() {
    return message;
}

const char* Tweet::getAuthor() {
    return author;
}

Tweet::~Tweet() {
    free(message);
    free(author);
}