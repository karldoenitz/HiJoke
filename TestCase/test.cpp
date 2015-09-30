//
// Created by 李志豪 on 9/27/15.
//

#include <iostream>
#include <vector>
#include <memory>
#include "../DatabaseManager/DatabaseOperator.h"

using namespace std;

void test_user(){
    std::shared_ptr<User>user(new User());
    user->set_username("karl");
    user->set_password("doenitz");
    user->set_usercode("2315ufkzc69");
    user->set_status(1);
    std::shared_ptr<DatabaseOperator>databaseOperator(new DatabaseOperator());
    databaseOperator->userManager->save_user(user);
}

void test_joke(){
    std::shared_ptr<std::vector<std::shared_ptr<Joke>>> joke_vector;
    std::shared_ptr<DatabaseOperator>databaseOperator(new DatabaseOperator());
    joke_vector = databaseOperator->jokeManager->get_jokes(1, 5);
    for (int i=0; i<joke_vector->size(); i++){
        cout << "---------------------------------------------------------" << endl;
        cout << "id:" << joke_vector->at(i)->get_joke_id() << endl;
        cout << "title:" << joke_vector->at(i)->get_title() << endl;
        cout << "content:" << joke_vector->at(i)->get_content() << endl;
    }
    cout << "---------------------------------------------------------" << endl;
}

void test_comment(){

}

int main() {
//    test_user();
    test_joke();
    return 0;
}
