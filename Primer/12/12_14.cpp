#include <iostream>
#include <memory>

using namespace std;

struct destination
{
};
struct connection
{
};

connection connect(destination *pd)
{
    cout << "打开连接" << endl;
    return connection();
}

void disconnect(connection c)
{
    cout << "关闭连接";
}

// 未使用 shared_ptr 的版本
void f(destination &d)
{
    cout << "直接管理 connect" << endl;
    connection c = connect(&d);
    // 忘记调用 disconnect 关闭连接

    cout << "f 结束" << endl;
}

void end_connection(connection *p) { disconnect(*p); }

// 使用 shared_ptr 的版本
void f1(destination &d)
{
    cout << "用 shared_ptr 管理 connect" << endl;
    connection c = connect(&d);

    shared_ptr<connection> p(&c, end_connection);
    cout << "f1 结束" << endl;
}

int main()
{
    destination d;
    f(d);
    f1(d);
    return 0;
}
