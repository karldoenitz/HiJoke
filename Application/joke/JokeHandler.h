//
// Created by 李志豪 on 10/8/15.
//

#ifndef HIJOKE_JOKEHANDLER_H
#define HIJOKE_JOKEHANDLER_H

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

using namespace std;
using namespace cppcms::http;

class WriteJoke {
public:
    bool write_joke(std::string title, std::string content);
};

class WriteJokeHandler : public cppcms::application {
public:
    WriteJokeHandler(cppcms::service &srv) : cppcms::application(srv){};
    virtual void main(std::string url);
};

class JokeHandler : public cppcms::application {
public:
    JokeHandler(cppcms::service &srv) : cppcms::application(srv){};
    virtual void main(std::string url);
};


#endif //HIJOKE_JOKEHANDLER_H
