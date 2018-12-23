
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

const unsigned long maxshort=65536L;
const unsigned long multiplier=1194211693L;
const unsigned long adder=12345L;


class RandomNumber
{
    private:
        //当前种子
        unsigned long randseed;
    public:
        //构造函数，缺省值0表示由系统自动产生种子
        RandomNumber(unsigned long s=0);
        //产生0-n-1之间的随机整数
        unsigned short Random(unsigned long n);
        //产生[0，1)之间的随机实数
        double fRandom(void);
};

RandomNumber::RandomNumber(unsigned long s)
{
    if(s==0)
        randseed=time(0);
    else
        randseed=s;
}

unsigned short RandomNumber::Random(unsigned long n)
{
    randseed=multiplier*randseed+adder;
    return (unsigned short)((randseed>>16)%n);
}

double RandomNumber::fRandom(void)
{
    return Random(maxshort)/double(maxshort);
}

double Darts(int n)
{
    static RandomNumber dart;
    int k=0;


    for(int i=1; i<=n; i++)
    {
        double x=dart.fRandom();
        double y=dart.fRandom();
        if((x*x+y*y)<1)
            k++;
    }
    return 4*k/double(n);
}

int main(void )
{
    int t ;
    cin>>t;
    cout<<Darts(t);

}
