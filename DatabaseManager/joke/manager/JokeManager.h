//
// Created by 李志豪 on 9/28/15.
//

#ifndef HIJOKE_JOKEMANAGER_H
#define HIJOKE_JOKEMANAGER_H

#include <memory>
#include <vector>
#include <cppdb/frontend.h>
#include "../bean/Joke.h"

class JokeManager {
private:
    cppdb::session sql_session;
public:
    JokeManager();
    std::shared_ptr<std::vector<std::shared_ptr<Joke>>> get_jokes(int begin_id, int end_id);
};


#endif //HIJOKE_JOKEMANAGER_H
