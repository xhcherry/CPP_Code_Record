#include <iostream>
#include <string>
using namespace std;
class Sales_data
{
    friend istream &read(istream &is, Sales_data &item);
    friend ostream &print(ostream &is, const Sales_data &item);

public:
    Sales_data(const string &book, unsigned num, double sellp, double salep)
        : bookNo(book), units_sold(num), sellingprice(sellp), saleprice(salep)
    {
        if (sellingprice)
            discount = saleprice / sellingprice;
        cout << "该构造函数接受书号、销售量、原价、实际售价四个信息" << endl;
    }

private:
    string bookNo;
    unsigned units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;
};