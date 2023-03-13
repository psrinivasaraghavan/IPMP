#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, swapped_num;
    num = 28;
    bitset<8> binary_num(num);
    string binary_str = binary_num.to_string();
    swap(binary_str[0], binary_str[4]);
    swap(binary_str[1], binary_str[5]);
    swap(binary_str[2], binary_str[6]);
    swap(binary_str[3], binary_str[7]);
    swapped_num = bitset<8>(binary_str).to_ulong();
    cout << "Original number: " << num << endl;
    cout << "Swapped number: " << swapped_num << endl;

    return 0;
}
