#include<iostream>
using namespace std;
istream& func(istream& is){
    std::string buf;
    while(is>>buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}
int main(){
    system("pause");
    cout << "请输入一些整数,按crtl+z结束" << endl;
    func(cin);
    return 0;
}