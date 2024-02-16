#include <iostream>
#include <string>

class Person {
private:
    std::string name;

public:

    void feedCat() {
        std::cout << name << "ιè" << std::endl;
    }

    explicit Person(const char string[7]) {
        name = string;
    }
};

int main() {
    Person xiaohong("С��");
    Person xiaolan("С��");
    Person xiaoming("С��");
    while (true) {
        std::string catAction;
        std::cout << "������è�Ķ���(jump��meow��roll)'exit'�˳���";
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
            std::cout << "��Ч��è�Ķ�������" << std::endl;
        }
    }
    return 0;
}