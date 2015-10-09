//
// Created by 李志豪 on 10/5/15.
//

#include "LoginHandler.h"

std::string Login::user_login(std::string username, std::string password) {
    std::shared_ptr<DatabaseOperator>databaseOperator(new DatabaseOperator());
    std::shared_ptr<User>user(new User());
    user->set_username(username);
    user->set_password(password);
    user = databaseOperator->userManager->get_user(user, 2);
    return user->get_usercode();
}

void LoginHandler::main(std::string url) {
    std::string username = request().post("username");
    std::string password = request().post("password");
    Login *login = new Login();
    std::string usercode = login->user_login(username, password);
    cppcms::json::value json_result;
    json_result["result"] = "login success";
    cookie login_cookie("usercode", usercode, 84600, "/");
    response().set_cookie(login_cookie);
    session().load();
    session()[usercode] = true;
    session().save();
    response().out() << json_result;
    delete login;
}
