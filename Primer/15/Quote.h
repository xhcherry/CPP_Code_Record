#ifndef TEST_QUOTE_H
#define TEST_QUOTE_H

#include <string>
#include <iostream>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price)
        : bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    // 返回给定数量的书籍的销售总额
    // 派生类负责改写并使用不同的折扣计算算法
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default; // 对析构函数进行动态绑定

private:
    std::string bookNo; // 书籍的 ISBN 编号

protected:
    double price = 0.0; // 代表普通状态下不打折的价格
};

// 计算并打印销售给定数量的某种书籍所得的费用
double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    // 根据传入 item 形参的对象类型调用 Quote::net_price
    // 或者 Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}
#endif // TEST_QUOTE_H