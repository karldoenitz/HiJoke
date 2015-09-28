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

    return joke_vector;
}
