#include <iostream>
#include <string>

using namespace std;

template <typename T>

T MySum(T Num1, T Num2)
{
    return Num1 + Num2;
}

int main()
{

    cout << MySum<int>(1,80) << endl;
    cout << MySum<double>(1.85,8.7852) << endl;
    cout << MySum<string>("hallo","zoher") << endl;

    return 0;
}