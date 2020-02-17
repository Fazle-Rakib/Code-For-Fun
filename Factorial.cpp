#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long int temp;
    cin >> n;
    temp = n;
    vector<int>Extra1,ExtraM[2],MUL1,MUL2,sum;
    while(temp > 0)
    {
        MUL1.push_back(temp%10);
        temp/=10;
    }
    for(int i = n-1; i > 0;i--)
    {
        MUL2.clear();ExtraM[0].clear();ExtraM[1].clear();
        temp = i;
        while(temp > 0)
        {
            MUL2.push_back(temp%10);
            temp/=10;
        }
        for(int j = 0; j < MUL2.size();j++)
        {
            int carry =0;
            sum.clear();
//            cout << MUL2[j] << " * ";
            if(j > 0)
            {
                for(int k =0; k < j;k++)
                {
                    ExtraM[j].push_back(0);
                }
            }
            for(int k = 0; k < MUL1.size();k++)
            {

                    temp = MUL2[j]*MUL1[k]+carry;
                    ExtraM[j].push_back(temp%10);
//                    cout << MUL1[k] << " = " << temp % 10 << endl;
                    temp/=10;
                    carry = temp%10;
            }
            if(carry > 0)
            {
                ExtraM[j].push_back(carry);
                carry = 0;
            }
//            cout << "Extra : ";
//            for(int l = 0; l < ExtraM[j].size();l++)
//            {
//                cout << ExtraM[j][l] ;
//            }
//            cout << endl;
//            cout << "SIZE : " << ExtraM[0].size() << " " << ExtraM[1].size() << endl;

            int k = 0,var = 0;
            for(;k < ExtraM[0].size() && k < ExtraM[1].size();k++)
            {
                var = ExtraM[0][k]+ExtraM[1][k]+carry;
                sum.push_back(var%10);
                var/=10;
                carry= var%10;
            }
//            for(int l = 0; l < sum.size();l++)
//            {
//                cout << sum[l];
//            }
//            cout << endl;
            if(k < ExtraM[0].size())
            {
                for(;k < ExtraM[0].size();k++)
                {
                    var = ExtraM[0][k]+carry;
                    sum.push_back(var%10);
                    var/=10;
                    carry= var%10;
                }
            }
            else if(k < ExtraM[1].size())
            {
                for(;k < ExtraM[1].size();k++)
                {
                    var = ExtraM[1][k]+carry;
                    sum.push_back(var%10);
                    var/=10;
                    carry= var%10;
                }
            }
//            for(int l = 0; l < sum.size();l++)
//            {
//                cout << sum[l];
//            }
//            cout << endl;
            if(carry > 0)
            {
                sum.push_back(carry);
            }
        }
        MUL1.clear();
        for(int l = 0; l < sum.size();l++)
        {
            MUL1.push_back(sum[l]);
        }
//        for(int l = MUL1.size()-1; l >=0 ;l--)
//        {
//            cout << MUL1[l] ;
//        }
//        cout << endl;
    }
    for(int l = MUL1.size()-1; l >=0 ;l--)
    {
        cout << MUL1[l] ;
    }
    cout << endl;
}
