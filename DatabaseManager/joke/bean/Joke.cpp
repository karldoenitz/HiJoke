//
// Created by 李志豪 on 9/28/15.
//

#include "Joke.h"

Joke::Joke() {
    this->id = 0;
    this->title = "";
    this->content = "";
}

void Joke::set_content(std::string content) {
    this->content = content;
}

void Joke::set_joke_id(int id) {
    this->id = id;
}

void Joke::set_title(std::string title) {
    this->title = title;
}

int Joke::get_joke_id() {
    return this->id;
}

std::string Joke::get_title() {
    return this->title;
}

std::string Joke::get_content() {
    return this->content;
}
