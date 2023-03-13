#ifndef TEST_LIMITED_QUOTE_H
#define TEST_LIMITED_QUOTE_H

#include "Quote.h"

class Limited_quote : public Quote
{
public:
    Limited_quote() = default;
    Limited_quote(const std::string &, double, std::size_t, double);
    // 覆盖基类的函数版本以实现基于大量购买的折扣政策
    virtual double net_price(std::size_t) const override;

private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};

Limited_quote::Limited_quote(const std::string &book, double p,
                             std::size_t qty, double disc) : Quote(book, p), max_qty(qty), discount(disc) {}

double Limited_quote::net_price(std::size_t cnt) const
{
    if (cnt <= max_qty)
        return cnt * (1 - discount) * price;
    else
        return (max_qty * (1 - discount) + (cnt - max_qty)) * price;
}

#endif // TEST_LIMITED_QUOTE_H
