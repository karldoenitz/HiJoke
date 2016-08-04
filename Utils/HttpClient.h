//
// Created by 李志豪 on 11/25/15.
//

#ifndef HIJOKE_HTTPCLIENT_H
#define HIJOKE_HTTPCLIENT_H


#include <curl/curl.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;


struct MemoryStruct {
    std::string memory;
    size_t size;
};


class HttpClient {
private:
    MemoryStruct *memoryStruct;
public:
    /**
     * @brief http client
     * @param url: http request url
     * @return http response, std::string type
     */
    std::string get_http_response(const char *url);
    ~HttpClient(){
        delete this->memoryStruct;
    }
};


#endif //HIJOKE_HTTPCLIENT_H
