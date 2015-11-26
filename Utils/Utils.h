//
// Created by 李志豪 on 10/3/15.
//

#ifndef HIJOKE_UTILS_H
#define HIJOKE_UTILS_H

#include <string.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include "HttpClient.h"
#include "../settings.h"

class Utils {
public:
    std::string uuid();
    int send_message(std::string phone, std::string message);
};


#endif //HIJOKE_UTILS_H
