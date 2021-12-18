#include "sectionA.h"
#include <iostream>

WebUrl::WebUrl(std::string webUrl)
    :_webUrl{ webUrl } { }

std::string WebUrl::getwebUrl() const{
    return _webUrl;
}

std::string WebUrl::getScheme() const{
    int count = 0;
    int numInBetween = 0;
    int num = 0;


    for (int i = 0; i < _webUrl.size(); i++) {
        if (_webUrl[i] == '/') {
            count++;
        }

        else if (count < 3) {
            numInBetween++;

            if (count < 1) {
                num++;
            }
        }
    }

    std::string scheme = _webUrl.substr(0, _webUrl.find_first_of("/"));
    return scheme;
}

std::string WebUrl::getAuthority() const{
    int count = 0;
    int numInBetween = 0;
    int num = 0;


    for (int i = 0; i < _webUrl.size(); i++) {
        if (_webUrl[i] == '/') {
            count++;
        }

        else if (count < 3) {
            numInBetween++;

            if (count < 1) {
                num++;
            }
        }
    }

    int lastIndexOfAuthority = (numInBetween + 2) - num;
    std::string authority = _webUrl.substr(_webUrl.find_first_of("/"), lastIndexOfAuthority);
    return authority;

}

std::string WebUrl::getUrlpath() const{
    int count = 0;
    int numInBetween = 0;
    int num = 0;


    for (int i = 0; i < _webUrl.size(); i++) {
        if (_webUrl[i] == '/') {
            count++;
        }

        else if (count < 3) {
            numInBetween++;

            if (count < 1) {
                num++;
            }
        }
    }

    int lastIndexOfAuthority = (numInBetween + 2) - num;
    std::string scheme = _webUrl.substr(0, _webUrl.find_first_of("/"));
    std::string authority = _webUrl.substr(_webUrl.find_first_of("/"), lastIndexOfAuthority);
    std::string path = _webUrl.substr(authority.size() + scheme.size(), _webUrl.size());
    return path;

}

std::ostream& operator<<(std::ostream& out, const WebUrl& webUrl) {

    out << "URL: " << webUrl.getwebUrl() << "\n SCHEME: " << webUrl.getScheme() <<
        " \n AUTHORITY: " << webUrl.getAuthority() << "\n PATH: " << webUrl.getUrlpath() << "\n";

    return out;
}