//
// Created by 李志豪 on 9/28/15.
//

#ifndef HIJOKE_COMMENT_H
#define HIJOKE_COMMENT_H

#include <iostream>
#include <memory>
#include <string.h>
#include "../../user/bean/User.h"
#include "../../joke/bean/Joke.h"

class Comment {
private:
    int id;
    std::string comment;
    std::shared_ptr<User> user;
    std::shared_ptr<Joke> joke;
public:
    Comment();
    void set_comment_id(int id);
    void set_comment(std::string comment);
    void set_user(std::shared_ptr<User> user);
    void set_joke(std::shared_ptr<Joke> joke);
    int get_comment_id();
    std::string get_comment();
    std::shared_ptr<User> get_user();
    std::shared_ptr<Joke> get_joke();
};


#endif //HIJOKE_COMMENT_H
