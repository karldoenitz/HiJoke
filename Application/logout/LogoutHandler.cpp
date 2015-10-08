//
// Created by 李志豪 on 10/5/15.
//

#include "LogoutHandler.h"

void LogoutHandler::main(std::string url) {
    cppcms::json::value json_result;
    cookie logout_cookie = request().cookie_by_name("usercode");
    std::string usercode = logout_cookie.value();
    session().load();
    session()[usercode] = false;
    session().save();
    json_result["result"] = "logout success";
    response().out() << json_result;
}
