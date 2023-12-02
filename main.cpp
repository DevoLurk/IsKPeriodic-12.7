#include<iostream>
#include <string>

using namespace std;

bool IsKPeriodic(string& pat, int& period)
{
    int j = 0;
    int i = 1;
    int part_len = 1;

    int* lps = new int[pat.length()];
    lps[0] = 0; 

    while (i < pat.size())
    {
        if (pat[i] == pat[j]) 
            lps[i++] = ++j;
        else
        {
            if (j != 0) 
            {
                j = lps[j - 1];
                return false;
            }
            else
            {
                lps[i++] = 0;
                part_len++;
            }
        }
    }

   /* cout << "pat len = " << pat_len << endl;
    cout << "str len = " << pat.length() << endl;
    cout << "lps end = " << lps[pat.length() - 1] << endl;
    cout << endl;*/


    period = lps[pat.length() - 1] / part_len;
    return true;
}


int main()
{
    int period;
    string test1 = "ABCABCD";
    string test2 = "AABAACAABAA";
    string test3 = "asdasdasdasd";
    string test4 = "asdfasdfasdfasdfd";

    if (IsKPeriodic(test4, period))
        cout << "period = " << period << endl;
    else
        cout << "str is not periodik" << endl;

    return 0;
}

