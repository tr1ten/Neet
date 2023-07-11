#include <bits/stdc++.h>

using namespace std;

double ternary(double lo,double hi, function<double(double)> f){
    double ep = 1e-7;
    while (hi-lo>ep)
    {
        double m1 = lo + (hi-lo)/3;;
        double m2 = hi - (hi-lo)/3;
        double f1=f(m1),f2=f(m2);
        if(f1>f2) lo = m1;
        else hi = m2;
    }
    return lo;
}