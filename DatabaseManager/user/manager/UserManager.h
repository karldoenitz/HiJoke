//
// Created by 李志豪 on 9/26/15.
//

#ifndef TESTCPPDB_USERMANAGER_H
#define TESTCPPDB_USERMANAGER_H

#include <memory>
#include <vector>
#include <cppdb/frontend.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include "../bean/User.h"
#include "../../../settings.h"

class UserManager {
private:
    cppdb::session sql_session;
public:
    UserManager();
    /**
     * save user to database
     * @param user: an std::shared_ptr point to User's object
     * @return true or false
     */
    bool save_user(std::shared_ptr<User> user);
    /**
     * get user from database
     * @param user: an std::shared_ptr point to User's object
     * @param condition: int type, 0 usercode, 1 username, 2 username and password, 3 status
     * @return an user object
     */
    std::shared_ptr<User> get_user(std::shared_ptr<User> user, int condition);
    /**
     * get user vector
     * @param user: an std::shared_ptr point to User's object
     * @param start_index: start index
     * @param length: vector's length
     * @return: an std::shared_ptr point to a vector which contain some std::shared_ptr point to User's object
     */
    std::shared_ptr<std::vector<std::shared_ptr<User>>> get_user(std::shared_ptr<User> user, int start_index, int length);
    /**
     * get users count
     * @param status: user's status
     * @return users number
     */
    int get_user_count(int status);
    /**
     * set user's status
     * @param usercode: user's usercode
     * @param status: user's status
     * @return: true or false
     */
    bool set_user_status(std::string usercode, int status);
};


#endif //TESTCPPDB_USERMANAGER_H
