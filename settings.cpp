//
// Created by 李志豪 on 10/17/15.
//

#include "settings.h"

bool is_debug = true;
std::string db_connection = "sqlite3:db=database.sqlite";
std::string static_file_host = "http://localhost:8888/";
std::string static_file_path = "./";  //when is_debug, this is your lighttp or nginx or apache's static files' path, else this is relative path.
std::string sms_server = "http://h.1069106.com:1210/services/msgsend.asmx/SendMsg";  //Your sms server url
std::string sms_user = "xxx";  //Your sms account
std::string sms_password = "xxx";  //Your sms password