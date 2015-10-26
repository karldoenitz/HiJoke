//
// Created by 李志豪 on 10/5/15.
//

#include "LoginHandler.h"

std::string Login::user_login(std::string username, std::string password, int status) {
    std::shared_ptr<DatabaseOperator>databaseOperator(new DatabaseOperator());
    std::shared_ptr<User>user(new User());
    user->set_username(username);
    user->set_password(password);
    user = databaseOperator->userManager->get_user(user, 2);
    if (user->get_status() != status) {
        return "";
    }
    return user->get_usercode();
}

void LoginHandler::main(std::string url) {
    std::string username = request().post("username");
    std::string password = request().post("password");
    Login *login = new Login();
    std::string usercode = login->user_login(username, password, 1);
    cppcms::json::value json_result;
    if (usercode.size() > 0){
        json_result["result"] = "login success";
        set_cookie("usercode", usercode);
        set_session(usercode, "user");
    }
    else {
        json_result["result"] = "login failed";
    }
    response_as_json(json_result);
    delete login;
}

void AdminLoginHandler::main(std::string url) {
    std::string username = request().post("username");
    std::string password = request().post("password");
    Login *login = new Login();
    std::string usercode = login->user_login(username, password, 2);
    cppcms::json::value json_result;
    if (usercode.size() > 0){
        json_result["result"] = "login success";
        set_cookie("usercode", usercode);
        set_session(usercode, "admin");
    }
    else {
        json_result["result"] = "login failed";
    }
    response_as_json(json_result);
    delete login;
}

void AdminLoginView::main(std::string url) {
    content::message c;
    c.static_host = static_file_path;
    render("message",c);
}

void AdminView::main(std::string url) {
    std::string usercode = get_cookie("usercode");
    if (usercode.size() <= 0){
        content::message c;
        c.static_host = static_file_path;
        render("message",c);
        return;
    }
    std::string session_value = get_session(usercode);
    if (session_value != "admin"){
        content::message c;
        c.static_host = static_file_path;
        render("message",c);
        return;
    }
    content::index c;
    c.static_host = static_file_path;
    render("index",c);
}

cppcms::json::value GetUser::get_users(int start, int length, int status) {
    cppcms::json::value users_json;
    std::shared_ptr<DatabaseOperator>databaseOperator(new DatabaseOperator());
    std::shared_ptr<User>user(new User());
    user->set_status(status);
    std::shared_ptr<std::vector<std::shared_ptr<User>>>users = databaseOperator->userManager->get_user(user, start, length);
    users_json["status"] = status;
    users_json["current_page"] = start / length + 1;
    users_json["current_users_counts"] = users->size();
    users_json["users_counts"] = databaseOperator->userManager->get_user_count(status);
    for (int i = 0; i < users->size(); ++i) {
        cppcms::json::value user_json;
        user_json["username"] = users->at(i)->get_username();
        user_json["usercode"] = users->at(i)->get_usercode();
        users_json["users"][i] = user_json;
    }
    return users_json;
}

void GetUsersHandler::main(std::string url) {
    std::string start_index = request().get("start_index");
    std::string length = request().get("length");
    std::string status = request().get("status");
    int user_status = status!=""?std::atoi(status.c_str()):1;
    int start = std::atoi(start_index.c_str());
    int end = std::atoi(length.c_str());
    GetUser *getUser = new GetUser();
    cppcms::json::value user_json = getUser->get_users(start, end, user_status);
    response_as_json(user_json);
    delete getUser;
}

void SetUserStatusHandler::main(std::string url) {
    std::string usercode = get_cookie("usercode");
    cppcms::json::value json_error;
    json_error["result"] = false;
    json_error["reason"] = "user not login";
    if (usercode.size() <= 0){
        response_as_json(json_error);
        return;
    }
    std::string session_value = get_session(usercode);
    if (session_value != "admin"){
        response_as_json(json_error);
        return;
    }
    std::string targetusercode = request().get("usercode");
    std::string status = request().get("status");
    int userstatus = std::atoi(status.c_str());
    DatabaseOperator *databaseOperator = new DatabaseOperator();
    bool result = databaseOperator->userManager->set_user_status(targetusercode, userstatus);
    cppcms::json::value json;
    json["result"] = result;
    json["reason"] = "database operate result";
    response_as_json(json);
    delete databaseOperator;
}
