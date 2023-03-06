#include <iostream>
#include <string>
#include <vector>

class GetInput {
public:
    GetInput(std::istream &i = std::cin) : is(i) { }
    std::string operator()() const {
        std::string str;
        std::getline(is, str);
        return is ? str : std::string();
    }

private:
    std::istream &is;
};

int main() {
    GetInput getInput;
    std::vector<std::string> svec;
    for (std::string tmp; !(tmp = getInput()).empty(); )
        svec.push_back(tmp);
    for (const auto &str : svec)
        std::cout << str << ",";
    std::cout << std::endl;
    return 0;
}
