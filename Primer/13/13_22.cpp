#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :
            ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &);                 // 拷贝构造函数
    HasPtr &operator=(const HasPtr &);      // 拷贝赋值运算符
    HasPtr &operator=(const string &);      // 赋予新 string
    string &operator*();                    // 解引用
    ~HasPtr();                              // 析构函数
private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &orig) :
        ps(new std::string(*orig.ps)), i(orig.i) { }

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    std::string *newps = new std::string(*rhs.ps);  // 拷贝指针指向的对象
    delete ps;                                      // 销毁原 string
    ps = newps;                                     // 指向新 string
    i = rhs.i;                                      // 使用内置的 int 赋值
    return *this;                                   // 返回一个此对象的引用
}

HasPtr& HasPtr::operator=(const string &rhs) {
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*() {
    return *ps;
}

HasPtr::~HasPtr() {
    delete ps;          // 释放 string 内存
}

int main() {
    HasPtr h("hi mom!");
    HasPtr h2(h);       // 行为类值，h2、h3 和 h 指向不同 string
    HasPtr h3 = h;
    h2 = "hi dad!";
    h3 = "hi son!";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    return 0;
}
