//
// Created by 李志豪 on 10/5/15.
//

#ifndef HIJOKE_LOGOUTHANDLER_H
#define HIJOKE_LOGOUTHANDLER_H

#include "../BaseHandler.h"

class LogoutHandler : public BaseHandler {
public:
    LogoutHandler(cppcms::service &srv) : BaseHandler(srv){};
    virtual void main(std::string url);
};


#endif //HIJOKE_LOGOUTHANDLER_H
