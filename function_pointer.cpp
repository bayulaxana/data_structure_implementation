#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <functional>

using namespace std;
using ull = unsigned long long;
using ll  = long long;

template <typename T> void for_each_data_in_vector
(vector<T> &vec, function<T (T &data)> func)
{
    for (T &each_data : vec) {
        each_data = func(each_data);
    }
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5};
    
    for (int x : vec) cout << x << ' ';
    puts("");

    auto mulBy2 = [](int &data) -> int {
        return (data * 2);
    };

    for_each_data_in_vector<int>(vec, mulBy2);

    for (int x : vec) cout << x << ' ';
    puts("");
    return 0;
}