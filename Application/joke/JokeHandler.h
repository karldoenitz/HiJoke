//
// Created by 李志豪 on 10/8/15.
//

#ifndef HIJOKE_JOKEHANDLER_H
#define HIJOKE_JOKEHANDLER_H

#include "../BaseHandler.h"

class WriteJoke {
public:
    bool write_joke(std::string title, std::string content);
};

class WriteJokeHandler : public BaseHandler {
public:
    WriteJokeHandler(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};

class JokeHandler : public BaseHandler {
public:
    JokeHandler(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};

class SetJokeStatusHandler : public BaseHandler {
public:
    SetJokeStatusHandler(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};


#endif //HIJOKE_JOKEHANDLER_H
