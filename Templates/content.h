//
// Created by 李志豪 on 10/15/15.
//

#ifndef HIJOKE_CONTENT_H
#define HIJOKE_CONTENT_H

#include <cppcms/view.h>
#include <string>

namespace content  {
    struct message : public cppcms::base_content {
        std::string static_host;
    };
    struct index : public cppcms::base_content {
        std::string static_host;
    };
}

#endif //HIJOKE_CONTENT_H
