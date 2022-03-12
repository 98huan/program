#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int main(){
    int ia[6] = {27, 210, 12, 47, 109, 83};
    vector<int, allocator<int>> vi(ia, ia+6);

    cout << count_if(vi.begin(), vi.end(),      //算法：计算符合条件的个数
            not1(bind2nd(less<int>(),40)));
            
    return 0;
}