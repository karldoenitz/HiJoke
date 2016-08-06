//
// Created by 李志豪 on 10/3/15.
//

#ifndef HIJOKE_REGISTER_H
#define HIJOKE_REGISTER_H

#include "../BaseHandler.h"

class Register {
public:
    /**
     * @brief register
     * @param username: user's name
     * @param password: user's password
     * @return true or false
     */
    bool user_register(std::string username, std::string password);
};

class RegisterHandler : public BaseHandler {
public:
    RegisterHandler(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};


#endif //HIJOKE_REGISTER_H
