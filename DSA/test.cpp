#include <iostream>
#include <string>

class Person {
private:
    std::string name;

public:

    void feedCat() {
        std::cout << name << "喂猫" << std::endl;
    }

    explicit Person(const char string[7]) {
        name = string;
    }
};

int main() {
    Person xiaohong("小红");
    Person xiaolan("小兰");
    Person xiaoming("小明");
    while (true) {
        std::string catAction;
        std::cout << "请输入猫的动作(jump、meow、roll)'exit'退出：";
        std::cin >> catAction;
        if (catAction == "jump") {
            xiaohong.feedCat();
        } else if (catAction == "meow") {
            xiaolan.feedCat();
        } else if (catAction == "exit") {
            break;
        } else if (catAction == "roll") {
            xiaoming.feedCat();
        } else {
            std::cout << "无效的猫的动作输入" << std::endl;
        }
    }
    return 0;
}