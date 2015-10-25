//
// Created by 李志豪 on 10/5/15.
//

#include "LogoutHandler.h"

void LogoutHandler::main(std::string url) {
    cppcms::json::value json_result;
    std::string usercode = get_cookie("usercode");
    set_session(usercode, "false");
    json_result["result"] = "logout success";
    response_as_json(json_result);
}
