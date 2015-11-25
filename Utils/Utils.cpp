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
    return 1;
}
