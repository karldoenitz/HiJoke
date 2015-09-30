//
// Created by 李志豪 on 9/28/15.
//

#include "CommentManager.h"

CommentManager::CommentManager() {
    cppdb::session sql("sqlite3:db=database.sqlite");
    this->sql_session = sql;
}

bool CommentManager::write_comment(int joke_id, std::string usercode, std::string comment) {
    try {
        cppdb::statement stat;
        stat = this->sql_session << "INSERT INTO comment (job_id, usercode, comment) values (?, ?, ?)" << joke_id << usercode << comment;
        stat.exec();
        return true;
    }catch (std::exception const &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return false;
    }
}

std::shared_ptr<std::vector<std::shared_ptr<Comment>>> CommentManager::get_comment_vector(int joke_id) {
    std::shared_ptr<std::vector<std::shared_ptr<Comment>>> comment_vector;
    cppdb::result comment_res;
    cppdb::result joke_res;
    comment_res = this->sql_session << "SELECT * FROM comment WHERE joke_id=?" << joke_id;
    joke_res = this->sql_session << "select * from joke where id=?" << joke_id;
    std::shared_ptr<Joke>joke(new Joke());
    while (joke_res.next()){
        int id;
        std::string title;
        std::string content;
        joke_res >> id >> title >> content;
        joke->set_joke_id(id);
        joke->set_title(title);
        joke->set_content(content);
    }
    while (comment_res.next()) {
        int comment_id;
        std::shared_ptr<Comment>comment(new Comment());
        std::string usercode;
        std::string joke_comment;
        std::shared_ptr<UserManager>userManager(new UserManager());
        comment_res >> comment_id >> usercode >> joke_comment;
        comment->set_joke(joke);
        std::shared_ptr<User>user(new User());
        user->set_usercode(usercode);
        user = userManager->get_user(user, true);
        comment->set_user(user);
        comment->set_comment(joke_comment);
        comment_vector->push_back(std::move(comment));
    }
    return comment_vector;
}
