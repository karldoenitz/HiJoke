//
// Created by 李志豪 on 10/8/15.
//

#include "JokeHandler.h"

bool WriteJoke::write_joke(std::string title, std::string content) {
    std::shared_ptr<Joke>joke(new Joke());
    joke->set_title(title);
    joke->set_content(content);
    std::shared_ptr<DatabaseOperator>databaseOperator(new DatabaseOperator());
    bool result = databaseOperator->jokeManager->write_joke(joke);
    return result;
}

void WriteJokeHandler::main(std::string url) {
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
    std::string title = request().post("title");
    std::string content = request().post("content");
    WriteJoke *writeJoke = new WriteJoke();
    bool result = writeJoke->write_joke(title, content);
    cppcms::json::value json_result;
    json_result["result"] = result;
    response().out() << json_result;
    delete writeJoke;
}

void JokeHandler::main(std::string url) {
    std::string start_index = request().get("start_index");
    std::string length = request().get("length");
    std::string status = request().get("status");
    int joke_status = status!=""?std::atoi(status.c_str()):1;
    int start = std::atoi(start_index.c_str());
    int end = std::atoi(length.c_str());
    DatabaseOperator *databaseOperator = new DatabaseOperator();
    std::shared_ptr<std::vector<std::shared_ptr<Joke>>> jokes = databaseOperator->jokeManager->get_jokes(start, end);
    cppcms::json::value json_result;
    unsigned long current_page_joke_number = jokes->size();
    json_result["current_joke_counts"] = current_page_joke_number;
    json_result["joke_counts"] = databaseOperator->jokeManager->get_joke_count(joke_status);
    for (int i = 0; i < current_page_joke_number; ++i) {
        cppcms::json::value json_joke;
        json_joke["id"] = jokes->at(i)->get_joke_id();
        json_joke["title"] = jokes->at(i)->get_title();
        json_joke["content"] = jokes->at(i)->get_content();
        json_result["jokes"][i] = json_joke;
    }
    response().content_type("application/json; charset=\"utf-8\"");
    response().out() << json_result;
    delete databaseOperator;
}
