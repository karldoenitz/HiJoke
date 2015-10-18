//
// Created by 李志豪 on 10/11/15.
//

#include "CommentHandler.h"

cppcms::json::value GetComment::get_comment(int joke_id) {
    cppcms::json::value comment_result;
    std::shared_ptr<DatabaseOperator>databaseOperator(new DatabaseOperator());
    std::shared_ptr<std::vector<std::shared_ptr<Comment>>> comment_vector = databaseOperator->commentManager->get_comment_vector(joke_id);
    cppcms::json::value joke_json;
    joke_json["id"] = comment_vector->size()>0?comment_vector->at(0)->get_joke()->get_joke_id():0;
    joke_json["title"] = comment_vector->size()>0?comment_vector->at(0)->get_joke()->get_title():"";
    joke_json["content"] = comment_vector->size()>0?comment_vector->at(0)->get_joke()->get_content():"";
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
    response().content_type("application/json; charset=\"utf-8\"");
    response().out() << getComment->get_comment(id);
    delete getComment;
}

bool WriteComment::write_comment(int joke_id, std::string usercode, std::string comment) {
    std::shared_ptr<DatabaseOperator>databaseOperator(new DatabaseOperator());
    bool result = databaseOperator->commentManager->write_comment(joke_id, usercode, comment);
    return result;
}

void WriteCommentHandler::main(std::string url) {
    session().load();
    cookie logout_cookie = request().cookie_by_name("usercode");
    std::string usercode = logout_cookie.value();
    cppcms::json::value json_error;
    json_error["result"] = false;
    json_error["reason"] = "user not login";
    response().content_type("application/json; charset=\"utf-8\"");
    if (usercode.size() <= 0){
        response().out() << json_error;
        return;
    }
    std::string session_value = session()[usercode];
    if (session_value == "false"){
        response().out() << json_error;
        return;
    }
    std::string joke = request().post("joke_id");
    int joke_id = std::atoi(joke.c_str());
    std::string comment = request().post("comment");
    WriteComment *writeComment = new WriteComment();
    bool result = writeComment->write_comment(joke_id, usercode, comment);
    cppcms::json::value json_result;
    json_result["result"] = result;
    response().out() << json_result;
    delete writeComment;
}
