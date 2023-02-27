#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int main(){
    vector<int> ivec;
    int i = 1;
    while(i!=101){
        ivec.push_back(i);
        ++i;
    }
    int sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
    cout << sum << endl;
    return 0;
}