#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <regex>

int main() 
{

    std::regex pattern("《(.*?)》");
    std::smatch match_results;
    std::string extract_res = "";
    std::string doc_title = "学唱经典:《troubleisafriend》";
    bool ff = std::regex_search(doc_title, match_results, pattern);
    if (std::regex_search(doc_title, match_results, pattern)) {
        std::cout << "here" << std::endl;
        std::printf("size %ld", match_results.size());
        if (match_results.size() > 1) {
            if (extract_res.empty()) {
                extract_res = match_results[1].str();
                std::printf("res %s", extract_res.c_str());
            }
        }
    }
    return 0;
}