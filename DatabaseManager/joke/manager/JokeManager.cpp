//
// Created by 李志豪 on 9/28/15.
//

#include "JokeManager.h"


JokeManager::JokeManager() {
    cppdb::session sql(db_connection);
    this->sql_session = sql;
}

std::shared_ptr<std::vector<std::shared_ptr<Joke>>> JokeManager::get_jokes(int begin_id, int end_id, int joke_status) {
    std::shared_ptr<std::vector<std::shared_ptr<Joke>>>joke_vector(new std::vector<std::shared_ptr<Joke>>);
    cppdb::result res;
    res = this->sql_session << "SELECT * FROM (select * from joke where status=?) order by id desc limit ?, ?" << joke_status << begin_id << end_id;
    while (res.next()) {
        std::shared_ptr<Joke>joke(new Joke());
        int id;
        std::string title;
        std::string content;
        int status;
        res >> id >> title >> content >> status;
        joke->set_joke_id(id);
        joke->set_title(title);
        joke->set_content(content);
        joke->set_status(status);
        joke_vector->push_back(std::move(joke));
    }
    return joke_vector;
}

std::shared_ptr<Joke> JokeManager::get_joke(int id) {
    cppdb::result res;
    res = this->sql_session << "SELECT * from joke where id =?" << id;
    std::shared_ptr<Joke> joke(new Joke());
    while (res.next()) {
        std::string title;
        std::string content;
        int status;
        res >> id >> title >> content >> status;
        joke->set_joke_id(id);
        joke->set_title(title);
        joke->set_content(content);
        joke->set_status(status);
        return joke;
    }
    joke->set_joke_id(0);
    joke->set_title("");
    joke->set_content("");
    return joke;
}

bool JokeManager::write_joke(std::shared_ptr<Joke> joke) {
    try {
        cppdb::statement stat;
        stat = this->sql_session << "INSERT INTO joke (title, content, status) values (?, ?, 2)" << joke->get_title() << joke->get_content();
        stat.exec();
        return true;
    }catch (std::exception const &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return false;
    }
}

int JokeManager::get_joke_count(int status) {
    cppdb::result res;
    res = this->sql_session << "SELECT count(*) number from joke where status =?" << status;
    while (res.next()) {
        int number;
        res >> number;
        return number;
    }
    return 0;
}

bool JokeManager::set_joke_status(int joke_id, int status) {
    try {
        cppdb::statement stat;
        stat = this->sql_session << "update joke set status=? and id=?" << status << joke_id;
        stat.exec();
        return true;
    }catch (std::exception const &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return false;
    }
}
