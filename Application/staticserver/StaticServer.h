//
// Created by 李志豪 on 10/27/15.
//

#ifndef HIJOKE_STATICSERVER_H
#define HIJOKE_STATICSERVER_H

#include "../BaseHandler.h"

class StaticServer : public BaseHandler {
public:
    StaticServer(cppcms::service &srv) : BaseHandler(srv){
        dispatcher().assign("/(.*)", &StaticServer::serve_file, this, 1);
    };
    /**
     * @brief serve file
     * @param file_name: file's name
     */
    void serve_file(std::string file_name);
};


#endif //HIJOKE_STATICSERVER_H
