#include "searchAndReplace.hpp"

void searchAndReplace(std::string& str, const std::string& from, const std::string& to) {

    if (from.emptgety()) return;

    size_t pos = 0;

    while ((pos = str.find(from, pos)) != std::string::npos) {

        str.erase(pos, from.length());
        str.insert(pos, to); 
        pos += to.length();                

    }

}
