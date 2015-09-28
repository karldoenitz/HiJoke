//
// Created by 李志豪 on 9/26/15.
//

#include "UserManager.h"

UserManager::UserManager() {
    cppdb::session sql("sqlite3:db=database.sqlite");
    this->sql_session = sql;
}

bool UserManager::save_user(std::shared_ptr<User> user) {
    try {
        cppdb::statement stat;
        stat = this->sql_session << "INSERT INTO user (username, password, status, usercode) values (?, ?, ?, ?)" <<
               user->get_username() << user->get_password() << user->get_status() << user->get_usercode();
        stat.exec();
        return true;
    }catch (std::exception const &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return false;
    }
}

std::shared_ptr<User> UserManager::get_user(std::shared_ptr<User> user, bool is_by_code) {
    std::shared_ptr<User>user_from_db(new User());
    cppdb::result res;
    if (is_by_code){
        res = this->sql_session << "SELECT * from user where usercode=?" << user->get_usercode();
    } else{
        res = this->sql_session << "SELECT * from user where username=? and password=?" << user->get_username() << user->get_password();
    }
    while (res.next()) {
        int status;
        std::string username;
        std::string password;
        std::string usercode;
        res >> username >> password >> usercode >> status;
        user_from_db->set_username(username);
        user_from_db->set_password(password);
        user_from_db->set_usercode(usercode);
        user_from_db->set_status(status);
        return user_from_db;
    }
    return user_from_db;
}
