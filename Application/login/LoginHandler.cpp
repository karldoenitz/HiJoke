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
        cookie login_cookie("usercode", usercode, 84600, "/");
        response().set_cookie(login_cookie);
        session().load();
        session()[usercode] = "true";
        session().save();
    }
    else {
        json_result["result"] = "login failed";
    }
    response().content_type("application/json; charset=\"utf-8\"");
    response().out() << json_result;
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
        cookie login_cookie("usercode", usercode, 84600, "/");
        response().set_cookie(login_cookie);
        session().load();
        session()[usercode] = "true";
        session().save();
    }
    else {
        json_result["result"] = "login failed";
    }
    response().content_type("application/json; charset=\"utf-8\"");
    response().out() << json_result;
    delete login;
}

void AdminLoginView::main(std::string url) {
    content::message c;
    c.static_host = static_file_path;
    render("message",c);
}

void AdminView::main(std::string url) {
    session().load();
    cookie logout_cookie = request().cookie_by_name("usercode");
    std::string usercode = logout_cookie.value();
    if (usercode.size() <= 0){
        content::message c;
        c.static_host = static_file_path;
        render("message",c);
        return;
    }
    std::string session_value = session()[usercode];
    if (session_value == "false"){
        content::message c;
        c.static_host = static_file_path;
        render("message",c);
        return;
    }
    content::index c;
    c.static_host = static_file_path;
    render("index",c);
}