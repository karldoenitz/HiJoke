//
// Created by 李志豪 on 9/26/15.
//

#include "DatabaseOperator.h"

DatabaseOperator::DatabaseOperator() {
    this->userManager = std::make_shared<UserManager>();
    this->jokeManager = std::make_shared<JokeManager>();
    this->commentManager = std::make_shared<CommentManager>();
}
