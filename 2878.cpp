#include <iostream>
#include <string>

using namespace std;

int ch_to_num(char ch)
{
    if (ch>='0' && ch<='9') return ch-'0';
    if (ch>='A' && ch<='Z') return ch-'A'+10;
    if (ch>='a' && ch<='z') return ch-'a'+10;
}

char num_to_ch(int num)
{
    if (num>=0 && num<=9) return '0'+num;
    if (num>=10 && num<=35) return 'A'+(num-10);
}

int main()
{
    string str1,str2;
    int l1,l2,B;
    cin>>l1>>l2>>B;
    cin>>str1>>str2;
    int len=max(l1,l2)-1;
    while (str1.length()<len) str1='0'+str1;
    while (str2.length()<len) str2='0'+str2;
    string res="";
    int carry=0;
    for(int j=len-1;j>=0;j--)
    {
        int num1=ch_to_num(str1[j]);
        int num2=ch_to_num(str2[j]);
        if (num1+num2+carry>=B)
        {
            res=num_to_ch(num1+num2-B+carry)+res;
            carry=1;
        }
        else
        {
            res=num_to_ch(num1+num2+carry)+res;
            carry=0;
        }
    }
    cout << res << endl;
    return 0;
}