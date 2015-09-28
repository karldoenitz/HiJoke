//
// Created by 李志豪 on 9/26/15.
//

#include "User.h"

User::User() {
    this->username = "";
    this->password = "";
    this->usercode = "";
    this->status = 0;
}

void User::set_username(std::string username) {
    this->username = username;
}

void User::set_password(std::string password) {
    this->password = password;
}

void User::set_usercode(std::string usercode) {
    this->usercode = usercode;
}

void User::set_status(int status) {
    this->status = status;
}

std::string User::get_username() {
    return this->username;
}

std::string User::get_password() {
    return this->password;
}

std::string User::get_usercode() {
    return this->usercode;
}

int User::get_status() {
    return this->status;
}
