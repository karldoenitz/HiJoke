//
// Created by 李志豪 on 10/27/15.
//

#include "StaticServer.h"


void StaticServer::serve_file(std::string file_name) {
    std::ifstream f((static_file_path + file_name).c_str());
    if(!f) {
        response_as_404();
    }
    else {
        response_as_static(f);
    }
}
