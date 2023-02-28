#include <iostream>
#include <string>
#include <map>

using namespace std;

void remove_author(multimap<string, string> &books, const string &author)
{
    auto pos = books.equal_range(author); // 要查找的作者
    if (pos.first == pos.second)
        cout << "没有" << author << "这个作者" << endl;
    else
        books.erase(pos.first, pos.second); // 删除该作者及其所有作品
}

void print_books(multimap<string, string> &books)
{
    cout << "当前书目包括：" << endl;
    for (auto &book : books) // 打印作者及其书目
        cout << book.first << "：《" << book.second << "》" << endl;
}

int main()
{
    multimap<string, string> books;
    books.insert({"Barth, John", "Sot-Weed Factor"});
    books.insert({"Barth, John", "Lost in the Funhouse"});
    books.insert({"金庸", "笑傲江湖"});
    books.insert({"金庸", "天龙八部"});
    books.insert({"金庸", "射雕英雄传"});

    print_books(books);
    remove_author(books, "张三");
    remove_author(books, "Barth, John");
    print_books(books);

    return 0;
}
