#include "rextester.h"
#include <iostream>
#include <fstream>

using namespace client;


size_t Client::write_response(void *ptr, size_t size, size_t count, void *stream) {
    ((std::string*)stream)->append((char*)ptr, 0, size*count);
    return size*count;
}

std::vector<std::string> Client::rexec(std::string lang, std::string code, std::string stdin_) {

    CURL* curl = curl_easy_init();
    langs_ = json::parse(languages_);
    args_ = json::parse(compiler_args_);

    CURLcode res;

    if (langs_.find(lang) == langs_.end()){
        throw std::logic_error("Unknown Language!"); //
    }

    to_compile = "LanguageChoice=" + langs_.find(lang)->get<std::string>()  + "&Program=" + code + "&Input=" + stdin_ + "&CompilerArgs=";
    if (args_.find(lang) != args_.end()){
        to_compile += args_.find(lang)->get<std::string>();
    }

    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &write_response);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS , to_compile.c_str());

        res = curl_easy_perform(curl);

        if (CURLE_OK == res){
            response_js = json::parse(response_);
            rextester_result.push_back(response_js.find("Result")->dump());
            rextester_result.push_back(response_js.find("Errors")->dump());
            rextester_result.push_back(response_js.find("Files")->dump());
            rextester_result.push_back(response_js.find("Stats")->dump());

        }
        else{
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }


    }
    curl_easy_cleanup(curl);
    return rextester_result;
    }

