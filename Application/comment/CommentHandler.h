//
// Created by 李志豪 on 10/11/15.
//

#ifndef HIJOKE_COMMENTHANDLER_H
#define HIJOKE_COMMENTHANDLER_H

#include "../BaseHandler.h"

class WriteComment {
public:
    /**
     * @brief write comment to database
     * @param joke_id: joke id
     * @param usercode: user's code
     * @param comment: comment
     * @return true or false
     */
    bool write_comment(int joke_id, std::string usercode, std::string comment);
};

class WriteCommentHandler : public BaseHandler {
public:
    WriteCommentHandler(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};

class GetComment {
public:
    /**
     * @brief get comment from database
     * @param joke_id: joke's id
     * @return cppcms json data
     */
    cppcms::json::value get_comment(int joke_id);
};

class CommentHandler : public BaseHandler {
public:
    CommentHandler(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};


#endif //HIJOKE_COMMENTHANDLER_H
