#include <string>

class WebUrl {
public:
    WebUrl(std::string webUrl);

    std::string getwebUrl() const;
    std::string getScheme() const;
    std::string getAuthority() const;
    std::string getUrlpath() const;

private:
    std::string _webUrl;
    

};

std::ostream& operator<< (std::ostream& out, const WebUrl& webUrl);
