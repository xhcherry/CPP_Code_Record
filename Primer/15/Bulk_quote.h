#ifndef TEST_BULK_QUOTE_H
#define TEST_BULK_QUOTE_H

#include "Quote.h"
#include <string>

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);
    // 覆盖基类的函数版本以实现基于大量购买的折扣政策
    virtual double net_price(std::size_t) const override;

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string &book, double p,
                       std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {}

double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

#endif // TEST_BULK_QUOTE_H
