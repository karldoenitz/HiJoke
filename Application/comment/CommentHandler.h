//
// Created by 李志豪 on 10/11/15.
//

#ifndef HIJOKE_COMMENTHANDLER_H
#define HIJOKE_COMMENTHANDLER_H

#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/mount_point.h>
#include <cppcms/http_request.h>
#include <cppcms/http_cookie.h>
#include <cppcms/session_interface.h>
#include <cppcms/json.h>
#include <iostream>
#include "../../DatabaseManager/DatabaseOperator.h"
#include "../../Utils/Utils.h"

class WriteComment {

};

class WriteCommentHandler : public cppcms::application {
public:
    WriteCommentHandler(cppcms::service &srv) : cppcms::application(srv){};
    virtual void main(std::string url);
};

class GetComment {
public:
    cppcms::json::value get_comment(int joke_id);
};

class CommentHandler : public cppcms::application {
public:
    CommentHandler(cppcms::service &srv) : cppcms::application(srv){};
    virtual void main(std::string url);
};


#endif //HIJOKE_COMMENTHANDLER_H
