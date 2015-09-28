//
// Created by 李志豪 on 9/28/15.
//

#ifndef HIJOKE_JOKE_H
#define HIJOKE_JOKE_H

#include <iostream>
#include <string.h>

class Joke {
private:
    int id;
    std::string title;
    std::string content;
public:
    Joke();
    void set_joke_id(int id);
    void set_title(std::string title);
    void set_content(std::string content);
    int get_joke_id();
    std::string get_title();
    std::string get_content();
};


#endif //HIJOKE_JOKE_H
