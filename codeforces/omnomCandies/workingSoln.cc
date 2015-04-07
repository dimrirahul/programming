#include<iostream>
using namespace std;
long long s,t,c,h1,h2,w1,w2;
int main()
{
    cin>>c>>h1>>h2>>w1>>w2;
    if(h1*w2<h2*w1) swap(h1,h2), swap(w1,w2);
    t=c/w1;
    s=t*h1+int((c-t*w1)/w2)*h2;
    for (int i=0;i<10000000&&i<=c/w2;i++)
        s=max(i*h2+int(1.*(c-i*w2)/w1)*h1,s);
    cout<<s;
}
