//
// Created by 李志豪 on 11/25/15.
//

#include "HttpClient.h"


static size_t WriteMemoryCallback(char *contents, size_t size, size_t nmemb, struct MemoryStruct *userp)
{
    size_t realsize = size * nmemb;
    userp->memory = contents;
    if(userp->memory == NULL) {
        /* out of memory! */
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }
    return realsize;
}


char* HttpClient::get_http_response(char *url) {
    CURL *curl;
    CURLcode res;
    this->memoryStruct = new MemoryStruct();
    memoryStruct->memory = new char[200];
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, memoryStruct);
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return memoryStruct->memory;
}

