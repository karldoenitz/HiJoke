//
// Created by 李志豪 on 10/5/15.
//

#ifndef HIJOKE_LOGINHANDLER_H
#define HIJOKE_LOGINHANDLER_H

#include "../BaseHandler.h"
#include "../../Templates/content.h"

class Login {
public:
    /**
     * @brief user login
     * @param username: user's name
     * @param password: user's password
     * @param status: user's status
     * @return login result
     */
    std::string user_login(std::string username, std::string password, int status);
};

class LoginHandler : public BaseHandler {
public:
    LoginHandler(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};

class AdminLoginHandler : public BaseHandler {
public:
    AdminLoginHandler(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};

class AdminLoginView : public BaseHandler {
public:
    AdminLoginView(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};

class AdminView : public BaseHandler {
public:
    AdminView(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};

class GetUser {
public:
    /**
     * @brief get user with status
     * @param start: start index
     * @param length: end index
     * @param status: user's status
     * @return cppcms json
     */
    cppcms::json::value get_users(int start, int length, int status);
};

class GetUsersHandler : public BaseHandler {
public:
    GetUsersHandler(cppcms::service &srv) : BaseHandler(srv){}
    virtual void main(std::string url);
};

class SetUserStatusHandler : public BaseHandler {
public:
    SetUserStatusHandler(cppcms::service &srv) : BaseHandler(srv){}
    virtual void main(std::string url);
};

#endif //HIJOKE_LOGINHANDLER_H
