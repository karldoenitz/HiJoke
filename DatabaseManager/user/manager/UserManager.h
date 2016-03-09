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
    bool save_user(std::shared_ptr<User> user);
    std::shared_ptr<User> get_user(std::shared_ptr<User> user, int condition);
    std::shared_ptr<std::vector<std::shared_ptr<User>>> get_user(std::shared_ptr<User> user, int start_index, int length);
    int get_user_count(int status);
    bool set_user_status(std::string usercode, int status);
};


#endif //TESTCPPDB_USERMANAGER_H
