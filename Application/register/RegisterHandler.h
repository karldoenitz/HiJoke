//
// Created by 李志豪 on 10/3/15.
//

#ifndef HIJOKE_REGISTER_H
#define HIJOKE_REGISTER_H

#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/mount_point.h>
#include <cppcms/http_request.h>
#include <cppcms/json.h>
#include <iostream>
#include "../../DatabaseManager/DatabaseOperator.h"
#include "../../Utils/Utils.h"

using namespace std;

class Register {
public:
    bool user_register(std::string username, std::string password);
};

class RegisterHandler : public cppcms::application {
public:
    RegisterHandler(cppcms::service &srv) : cppcms::application(srv){};
    virtual void main(std::string url);
};


#endif //HIJOKE_REGISTER_H
