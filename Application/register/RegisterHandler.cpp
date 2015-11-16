//
// Created by 李志豪 on 10/3/15.
//

#include "RegisterHandler.h"

bool Register::user_register(std::string username, std::string password) {
    std::shared_ptr<DatabaseOperator>databaseOperator(new DatabaseOperator());
    std::shared_ptr<User>user(new User());
    user->set_username(username);
    user = databaseOperator->userManager->get_user(user, 1);
    if (user->get_status()!=0){
        return false;
    }
    std::shared_ptr<Utils>utils(new Utils());
    std::string uuid = utils->uuid();
    user->set_username(username);
    user->set_password(cppcms::util::md5hex(password));
    user->set_usercode(uuid);
    user->set_status(1);
    bool result = databaseOperator->userManager->save_user(user);
    return result;
}

void RegisterHandler::main(std::string url) {
    std::string username = request().post("username");
    std::string password = request().post("password");
    cppcms::json::value json_result;
    if (username.length()<1||password.length()<1){
        json_result["result"] = false;
        json_result["reason"] = "注册失败，请输入用户名或密码";
        response_as_json(json_result);
        return;
    }
    Register *registerUser = new Register();
    bool result = registerUser->user_register(username, password);
    if (result){
        json_result["result"] = true;
        json_result["reason"] = "注册成功";
    } else{
        json_result["result"] = false;
        json_result["reason"] = "注册失败";
    }
    response_as_json(json_result);
    delete registerUser;
}
