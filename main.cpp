#include "holiday.h"
#include <array>

int main()
{
    const int size{2};
    using namespace HongKildong1234567;
    dayOfYear d1[size];
    std::cin >> d1[0];
    d1[1] = dayOfYear(1, 2);
    
    for (int i = 0; i < size; i++)
    {
        std::cout << d1[i];
    }
    
    std::cout << d1[0] - d1[1];
    std::cout << ++d1[0];
    std::cout << d1[0]++;
    std::cout << d1[0];
    d1[0]+=dayOfYear{2,2};
    std::cout << d1[0];

    std::array<holiday, size> arr;
    for(int i = 0; i<arr.size(); i++)
    {
        arr.at(i) = holiday{"someday", d1[i], false};
    }
    for (const auto& arri : arr)
        std::cout << arri;
}