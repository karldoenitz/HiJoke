//
// Created by 李志豪 on 9/26/15.
//

#ifndef CPPDB_USER_H
#define CPPDB_USER_H

#include <iostream>
#include <string.h>


class User {
private:
    std::string username;
    std::string password;
    int status;
    std::string usercode;
public:
    User();
    void set_username(std::string username);
    void set_password(std::string password);
    void set_usercode(std::string usercode);
    void set_status(int status);
    std::string get_username();
    std::string get_password();
    std::string get_usercode();
    int get_status();
};


#endif //CPPDB_USER_H
