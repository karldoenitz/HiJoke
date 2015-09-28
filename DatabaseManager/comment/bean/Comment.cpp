//
// Created by 李志豪 on 9/28/15.
//

#include "Comment.h"

Comment::Comment() {
}

void Comment::set_comment_id(int id) {
    this->id = id;
}

void Comment::set_comment(std::string comment) {
    this->comment = comment;
}

void Comment::set_joke(std::shared_ptr<Joke> joke) {
    this->joke = joke;
}

void Comment::set_user(std::shared_ptr<User> user) {
    this->user = user;
}

int Comment::get_comment_id() {
    return this->id;
}

std::string Comment::get_comment() {
    return this->comment;
}

std::shared_ptr<Joke> Comment::get_joke() {
    return this->joke;
}

std::shared_ptr<User> Comment::get_user() {
    return this->user;
}
