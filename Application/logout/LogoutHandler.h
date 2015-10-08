//
// Created by 李志豪 on 10/5/15.
//

#ifndef HIJOKE_LOGOUTHANDLER_H
#define HIJOKE_LOGOUTHANDLER_H

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

using namespace std;
using namespace cppcms::http;

class LogoutHandler : public cppcms::application {
public:
    LogoutHandler(cppcms::service &srv) : cppcms::application(srv){};
    virtual void main(std::string url);
};


#endif //HIJOKE_LOGOUTHANDLER_H
