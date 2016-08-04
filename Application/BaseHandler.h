//
// Created by 李志豪 on 10/25/15.
//

#ifndef HIJOKE_BASEHANDLER_H
#define HIJOKE_BASEHANDLER_H

#include <booster/log.h>
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/http_cookie.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>
#include <cppcms/mount_point.h>
#include <cppcms/service.h>
#include <cppcms/session_interface.h>
#include <cppcms/util.h>
#include <cppcms/url_dispatcher.h>
#include <iostream>
#include <fstream>
#include "../DatabaseManager/DatabaseOperator.h"
#include "../Utils/Utils.h"

using namespace std;
using namespace cppcms::http;

class BaseHandler : public cppcms::application {
public:
    BaseHandler(cppcms::service &srv) : cppcms::application(srv){};
    /**
     * response as json
     * @param json: response json
     */
    void response_as_json(cppcms::json::value &json);
    /**
     * response as static
     * @param f: static file stream
     */
    void response_as_static(std::ifstream &f);
    /**
     * response as 404
     */
    void response_as_404();
    /**
     * set cookie
     * @param key: cookie's key
     * @param value: cookie's value
     */
    void set_cookie(std::string key, std::string value);
    /**
     * get cookie
     * @param key: cookie's key
     * @return cookie's value
     */
    std::string get_cookie(std::string key);
    /**
     * set session
     * @param key: session's key
     * @param value: session's value
     */
    void set_session(std::string key, std::string value);
    /**
     * get session
     * @param key: session's key
     * @return session's value
     */
    std::string get_session(std::string key);
};

#endif //HIJOKE_BASEHANDLER_H
