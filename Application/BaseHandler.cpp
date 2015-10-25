//
// Created by 李志豪 on 10/25/15.
//

#include "BaseHandler.h"


void BaseHandler::response_as_json(cppcms::json::value json) {
    response().content_type("application/json; charset=\"utf-8\"");
    response().out() << json;
}

void BaseHandler::set_cookie(std::string key, std::string value) {
    cookie cookie_value(key, value, 84600, "/");
    response().set_cookie(cookie_value);
}

std::string BaseHandler::get_cookie(std::string key) {
    cookie cookie_value = request().cookie_by_name(key);
    return cookie_value.value();
}

void BaseHandler::set_session(std::string key, std::string value) {
    session().load();
    session()[key] = value;
    session().save();
}

std::string BaseHandler::get_session(std::string key) {
    session().load();
    return session()[key];
}
