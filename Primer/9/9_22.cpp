#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> iv = {1, 1, 2, 1};
    int val = 1;
    vector<int>::iterator iter = iv.begin();
    int size = iv.size(), ele = 0;
    while(iter!=(iv.begin()+size/2+ele))
        if(*iter==val){
            iter = iv.insert(iter, 2 * val);
            ++ele;
            iter += 2;
        }else{
            ++iter;
        }
    for (iter = iv.begin(); iter != iv.end();++iter)
        cout << *iter << endl;
    return 0;
}