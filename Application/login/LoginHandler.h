//
// Created by 李志豪 on 10/5/15.
//

#ifndef HIJOKE_LOGINHANDLER_H
#define HIJOKE_LOGINHANDLER_H

#include <string.h>
#include <iostream>
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/json.h>
#include <cppcms/service.h>
#include <cppcms/mount_point.h>
#include <cppcms/session_interface.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/http_cookie.h>
#include "../../DatabaseManager/DatabaseOperator.h"
#include "../../Templates/content.h"

using namespace std;
using namespace cppcms::http;

class Login {
public:
    std::string user_login(std::string username, std::string password, int status);
};

class LoginHandler : public cppcms::application {
public:
    LoginHandler(cppcms::service &srv) : cppcms::application(srv){};
    virtual void main(std::string url);
};

class AdminLoginHandler : public cppcms::application {
public:
    AdminLoginHandler(cppcms::service &srv) : cppcms::application(srv){};
    virtual void main(std::string url);
};

class AdminLoginView : public cppcms::application {
public:
    AdminLoginView(cppcms::service &srv) : cppcms::application(srv){};
    virtual void main(std::string url);
};

class AdminView : public cppcms::application {
public:
    AdminView(cppcms::service &srv) : cppcms::application(srv){};
    virtual void main(std::string url);
};

#endif //HIJOKE_LOGINHANDLER_H
