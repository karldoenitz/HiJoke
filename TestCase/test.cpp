//
// Created by 李志豪 on 9/27/15.
//

#include <iostream>
#include <memory>
#include "../DatabaseManager/DatabaseOperator.h"

using namespace std;

int main() {
    std::shared_ptr<User>user(new User());
    user->set_username("karl");
    user->set_password("doenitz");
    user->set_usercode("2315ufkzc69");
    user->set_status(1);
    std::shared_ptr<DatabaseOperator>databaseOperator(new DatabaseOperator());
    databaseOperator->userManager->save_user(user);
    return 0;
}
