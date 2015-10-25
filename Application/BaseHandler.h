//
// Created by 李志豪 on 10/25/15.
//

#ifndef HIJOKE_BASEHANDLER_H
#define HIJOKE_BASEHANDLER_H

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
#include "../DatabaseManager/DatabaseOperator.h"
#include "../Utils/Utils.h"

using namespace std;
using namespace cppcms::http;

class BaseHandler : public cppcms::application {
public:
    BaseHandler(cppcms::service &srv) : cppcms::application(srv){};
    void response_as_json(cppcms::json::value json);
    void set_cookie(std::string key, std::string value);
    std::string get_cookie(std::string key);
    void set_session(std::string key, std::string value);
    std::string get_session(std::string key);
};

#endif //HIJOKE_BASEHANDLER_H
