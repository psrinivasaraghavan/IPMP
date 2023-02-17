#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input = "a1b2c3d4";
    string output = "";
    for (int i = 0; i < input.length(); i++) if (isalpha(input[i])) output += input[i];
    for (int i = 0; i < input.length(); i++) if (isdigit(input[i])) output += input[i];
    cout << "The output string is " << output << endl;
    return 0;
}
