//
// Created by 李志豪 on 9/28/15.
//

#ifndef HIJOKE_COMMENTMANAGER_H
#define HIJOKE_COMMENTMANAGER_H

#include <memory>
#include <vector>
#include <cppdb/frontend.h>
#include "../bean/Comment.h"
#include "../../joke/bean/Joke.h"
#include "../../user/bean/User.h"
#include "../../user/manager/UserManager.h"

class CommentManager {
private:
    cppdb::session sql_session;
public:
    CommentManager();
    bool write_comment(int joke_id, std::string usercode, std::string comment);
    std::shared_ptr<std::vector<std::shared_ptr<Comment>>> get_comment_vector(int joke_id);
};


#endif //HIJOKE_COMMENTMANAGER_H