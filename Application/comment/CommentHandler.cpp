//
// Created by 李志豪 on 10/11/15.
//

#include "CommentHandler.h"

cppcms::json::value GetComment::get_comment(int joke_id) {
    cppcms::json::value comment_result;
    std::shared_ptr<DatabaseOperator>databaseOperator(new DatabaseOperator());
    std::shared_ptr<std::vector<std::shared_ptr<Comment>>> comment_vector = databaseOperator->commentManager->get_comment_vector(joke_id);
    cppcms::json::value joke_json;
    joke_json["id"] = comment_vector->at(0)->get_joke()->get_joke_id();
    joke_json["title"] = comment_vector->at(0)->get_joke()->get_title();
    joke_json["content"] = comment_vector->at(0)->get_joke()->get_content();
    comment_result["joke"] = joke_json;
    for (int i = 0; i < comment_vector->size(); ++i) {
        cppcms::json::value joke_comment;
        joke_comment["id"] = comment_vector->at(i)->get_comment_id();
        joke_comment["comment"] = comment_vector->at(i)->get_comment();
        joke_comment["username"] = comment_vector->at(i)->get_user()->get_username();
        joke_comment["usercode"] = comment_vector->at(i)->get_user()->get_usercode();
        comment_result["comments"][i] = joke_comment;
    }
    return comment_result;
}

void CommentHandler::main(std::string url) {
    std::string joke_id = request().get("joke_id");
    int id = std::atoi(joke_id.c_str());
    GetComment *getComment = new GetComment();
    response().out() << getComment->get_comment(id);
    delete getComment;
}

void WriteCommentHandler::main(std::string url) {

}
