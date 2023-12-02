#include<iostream>
#include <string>

using namespace std;

bool IsKPeriodic(string& str, int period)
{
    if (!period)
        return false;
    if ((str.length() % period) != 0)
        return false;

    for (int i = period; i < str.length(); i += period)
        for (int j = 0; j < period; j++)
            if (str[j] != str[period + j])
                return false;
    return true;
}

void print(string& str)
{
    for (auto i{ 0 }; i < (str.length() / 2) + 1; i++)
        if (IsKPeriodic(str, i))
            printf(" %s k = %3d \033[032mtrue\033[0m\n", str.c_str(), i);
        else
            printf(" %s k = %3d \033[031mfalse\033[0m\n", str.c_str(), i);
}


int main()
{
    int period;
    string test1 = "ABCABCD";
    string test2 = "AABAACAABAA";
    string test3 = "asdasdasdasd";
    string test4 = "abcabcabcabcabcabcabcabc";


    print(test3);

    return 0;
}

