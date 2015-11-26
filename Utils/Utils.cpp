//
// Created by 李志豪 on 10/3/15.
//

#include "Utils.h"

std::string Utils::uuid() {
    boost::uuids::uuid uuid_boost = boost::uuids::random_generator()();
    std::string uuid = boost::lexical_cast<std::string>(uuid_boost);
    return uuid;
}

int Utils::send_message(std::string phone, std::string message) {
    /**
     * use HttpClient class to operate the http response, get sms' result and use xml parser to parse it.
     * I have not written the codes.
     */
    std::string request_url = sms_server + "?userCode=" + sms_user + "&userPass=" + sms_password + "&DesNo=" + phone +"&Msg=" + message + "&Channel=1";
    const char *url = request_url.c_str();
    std::shared_ptr<HttpClient>httpClient(new HttpClient());
    char *response = httpClient->get_http_response(url);
    // use xml parse to parse the response and get the status code
    return 1;
}
