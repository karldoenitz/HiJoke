//
// Created by 李志豪 on 9/28/15.
//

#ifndef HIJOKE_JOKEMANAGER_H
#define HIJOKE_JOKEMANAGER_H

#include <memory>
#include <vector>
#include <cppdb/frontend.h>
#include "../bean/Joke.h"
#include "../../../settings.h"

class JokeManager {
private:
    cppdb::session sql_session;
public:
    JokeManager();
    /**
     * get joke vector
     * @param begin_id: begin id
     * @param end_id: end id
     * @param joke_status: joke status
     * @return an std::shared_ptr point to a vector contain some std::shared_ptr which point to Joke object
     */
    std::shared_ptr<std::vector<std::shared_ptr<Joke>>> get_jokes(int begin_id, int end_id, int joke_status);
    /**
     * get joke by id
     * @param id: joke's id
     * @return: an std::shared_ptr point to Joke object
     */
    std::shared_ptr<Joke> get_joke(int id);
    /**
     * get jokes count
     * @param status: joke's status
     * @return jokes count
     */
    int get_joke_count(int status);
    /**
     * write joke to database
     * @param joke: an std::shared_ptr point to Joke object
     * @return true or false
     */
    bool write_joke(std::shared_ptr<Joke> joke);
    /**
     * set joke status
     * @param joke_id: joke id
     * @param status: joke status
     * @return true or false
     */
    bool set_joke_status(int joke_id, int status);
};


#endif //HIJOKE_JOKEMANAGER_H
