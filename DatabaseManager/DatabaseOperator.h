//
// Created by 李志豪 on 9/26/15.
//

#ifndef TESTCPPDB_DATABASEOPERATOR_H
#define TESTCPPDB_DATABASEOPERATOR_H

#include "user/manager/UserManager.h"
#include "joke/manager/JokeManager.h"

class DatabaseOperator {
public:
    DatabaseOperator();
    std::shared_ptr<UserManager> userManager;
    std::shared_ptr<JokeManager> jokeManager;
};


#endif //TESTCPPDB_DATABASEOPERATOR_H
