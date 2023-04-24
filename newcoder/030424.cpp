#include <iostream>
class t_classA {
   public:
    t_classA(){};
    ~t_classA(){};
};
class t_classB {
   public:
    t_classB(){};
    virtual ~t_classB(){};
};
class t_classC : public t_classA, public t_classB {
   public:
    t_classC(){};
    virtual ~t_classC(){};
};
int main() {
    int nLenA = sizeof(t_classA);
    t_classA oA;
    int nLenAObject = sizeof(oA);

    int nLenB = sizeof(t_classB);
    t_classB oB;
    int nLenBObject = sizeof(oB);

    int nLenC = sizeof(t_classC);
    t_classC oC;
    int nLenCObject = sizeof(oC);
    std::cout << nLenA << std::endl;
    std::cout << nLenAObject << std::endl;
    std::cout << nLenB << std::endl;
    std::cout << nLenBObject << std::endl;
    std::cout << nLenC << std::endl;
    std::cout << nLenCObject << std::endl;
}