//
// Created by 李志豪 on 10/3/15.
//

#include "Utils.h"

std::string Utils::uuid() {
    boost::uuids::uuid uuid_boost = boost::uuids::random_generator()();
    std::string uuid = boost::lexical_cast<std::string>(uuid_boost);
    return uuid;
}
