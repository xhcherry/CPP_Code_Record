#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    // 构造函数分配新的 string 和新的计数器，将计数器置为 1
    HasPtr(const std::string &s = std::string()) :
            ps(new std::string(s)), i(0), use(new size_t(1)) { }
    // 拷贝构造函数拷贝所有三个数据成员，并递增计数器
    HasPtr(const HasPtr &);                 // 拷贝构造函数
    HasPtr &operator=(const HasPtr &);      // 拷贝赋值运算符
    HasPtr &operator=(const string &);      // 赋予新 string
    string &operator*();                    // 解引用
    ~HasPtr();                              // 析构函数
private:
    std::string *ps;
    int i;
    size_t *use;                            // 用来记录有多少个对象共享 *ps 的成员
};

HasPtr::HasPtr(const HasPtr &orig) :
        ps(orig.ps), i(orig.i), use(orig.use) { ++*use; }

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    ++*rhs.use;                 // 递增右侧运算对象的引用
    if (--*use == 0) {          // 然后递减本对象的引用计数
        delete ps;              // 如果没有其他用户
        delete use;             // 释放本对象分配的成员
    }
    ps = rhs.ps;                // 将数据从 rhs 拷贝到本对象
    i = rhs.i;
    use = rhs.use;
    return *this;               // 返回本对象
}

HasPtr& HasPtr::operator=(const string &rhs) {
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*() {
    return *ps;
}

HasPtr::~HasPtr() {
    if (--*use == 0) {  // 如果引用计数变为 0
        delete ps;      // 释放 string 内存
        delete use;     // 释放计数器内存
    }
}

int main() {
    HasPtr h("hi mom!");
    HasPtr h2 = h;      // 未分配新 string，h2 和 h 指向相同的 string
    h = "hi dad!";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    return 0;
}
