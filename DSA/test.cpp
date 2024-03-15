//#include <iostream>
//
//using namespace std;
//
//class T {
//public:
//    T(int i = 0) : x(i) {
//        c++;
//        show();
//    }
//
//    ~T() {
//        c--;
//        show();
//    }
//
//    static void show() { cout << c; }
//
//private:
//    static int c;
//    int x;
//};
//
//int T::c = 0;
//
//int main() {
//    T *i = new T[3];
//    T *j = new T(8);
//    delete[] i;
//    delete j;
//    return 0;
//}
#include <iostream>
using namespace std;
template <class T>
void fun(T temp){

    cout << temp << endl;cout << "A" << endl;
}

void fun(int temp){
    cout << temp << endl;cout << "B"<< endl;}
int main(){

    fun(30);
    return 0;
}
