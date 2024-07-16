#include <iostream>
using namespace std;

bool Alphabetic(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        char a = str[i];
        int asciiValue = int(a);

        if ((asciiValue >= 65 && asciiValue <= 90) || (asciiValue >= 97 && asciiValue <= 122))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}


int main()
{
    string input1 = "HelloWorld";
    string input2 = "Hello123";

    cout << boolalpha;
    cout << "For String input1: " << Alphabetic(input1) << endl;
    cout << "For String input2: " << Alphabetic(input2) << endl;

}
