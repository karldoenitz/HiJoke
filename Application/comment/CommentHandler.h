//
// Created by 李志豪 on 10/11/15.
//

#ifndef HIJOKE_COMMENTHANDLER_H
#define HIJOKE_COMMENTHANDLER_H

#include "../BaseHandler.h"

class WriteComment {
public:
    bool write_comment(int joke_id, std::string usercode, std::string comment);
};

class WriteCommentHandler : public BaseHandler {
public:
    WriteCommentHandler(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};

class GetComment {
public:
    cppcms::json::value get_comment(int joke_id);
};

class CommentHandler : public BaseHandler {
public:
    CommentHandler(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};


#endif //HIJOKE_COMMENTHANDLER_H
