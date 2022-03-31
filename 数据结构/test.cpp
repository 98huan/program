#include <iostream>
#include <vector>
using namespace std;
#include <string>

vector<int> BubbleSort(vector<int>& v)
{
    int N = v.size();
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
    return v;
}

int algorithm(int N) {
    if (N <= 1) return 1;
    return algorithm(N - 1) + 1;
}

int main()
{
    // vector<int> v{1, 6, 32, 86, 91, 2, 5, 10, 7};
    // BubbleSort(v);
    // for (int num: v)
    // {
        // cout << num << " ";
    // }
    // cout << endl;

    cout << "stoi(null) = " << stoi("null") << endl;
    for (int i = 1; i < 10; ++i)
    {
        cout << algorithm(i) << endl;;
    }
    
    return 0;
}

