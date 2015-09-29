//
// Created by 李志豪 on 9/28/15.
//

#include "JokeManager.h"


JokeManager::JokeManager() {
    cppdb::session sql("sqlite3:db=database.sqlite");
    this->sql_session = sql;
}

std::shared_ptr<std::vector<std::shared_ptr<Joke>>> JokeManager::get_jokes(int begin_id, int end_id) {
    std::shared_ptr<std::vector<std::shared_ptr<Joke>>>joke_vector(new std::vector<std::shared_ptr<Joke>>);
    cppdb::result res;
    res = this->sql_session << "SELECT * from joke where id >=? and id <= ?" << begin_id << end_id;
    while (res.next()) {
        std::shared_ptr<Joke>joke(new Joke());
        int id;
        std::string title;
        std::string content;
        res >> id >> title >> content;
        joke->set_joke_id(id);
        joke->set_title(title);
        joke->set_content(content);
        joke_vector->push_back(std::move(joke));
    }
    return joke_vector;
}
