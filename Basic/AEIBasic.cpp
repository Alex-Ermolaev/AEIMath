//
// Created by Andrey Ermolaev on 15.12.17.
//

#include "AEIBasic.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <limits>

ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}
ll lcm (ll a, ll b) {
    return a / gcd (a, b) * b;
}
ll binPow(ll a, ll b) {
    if (b == 0)
        return 1;
    else
        if (b & 1 == 0) {
            ll t = binPow(a,b >> 1);
            return t*t;
        } else {
            return a*binPow(a,b-1);
        }
}
ll binModPow(ll a, ll b, ll m) {
    if (b == 0) return 1;
    if ((b & 1) == 0) {
        ll temp = binModPow(a,b >> 1,m);
        return (temp * temp) % m;
    } else {
        return (a * binModPow(a,b-1,m)) % m;
    }
}

bool isPrimeBig(ll a) {
    if ((a == 0) || (a == 1)) return false;
    if ((a == 2) || (a == 3)) return true;
    srand((unsigned int)time(nullptr));
    const int RANDK = 100;
    ll rm = a - 2, r;
    if (rm > RAND_MAX) rm = RAND_MAX;

    for (int i = 0; i < RANDK; i++) {
        r = rand() % rm + 2;
        if (gcd(a,r) > 1) return false;
        if (binModPow(r,a-1,a) != 1) return false;
    }
    return true;
}
bool isPrime(ll a) {
    if ((a == 0) || (a == 1)) return false;
    for (int i = 2; i <= trunc(sqrt(a)); i++)
        if (a % i == 0) return false;
    return true;
}


void minmaxValue() {
    std::cout << "short:\t\t" << SHRT_MIN << " ... " << SHRT_MAX << " (" << sizeof(short) << " bytes)\n";
    std::cout << "int:\t\t" << INT_MIN << " ... " << INT_MAX << " (" << sizeof(int) << " bytes)\n";
    std::cout << "long:\t\t" << LONG_MIN << " ... " << LONG_MAX << " (" << sizeof(long) << " bytes)\n";
    std::cout << "long long:\t" << LONG_LONG_MIN << " ... " << LONG_LONG_MAX << " (" << sizeof(long long) << " bytes)\n";
    std::cout << std::endl;
    std::cout << "unsigned short:\t\t0 ... " << USHRT_MAX << " (" << sizeof(unsigned short) << " bytes)\n";
    std::cout << "unsigned int:\t\t0 ... " << UINT_MAX << " (" << sizeof(unsigned int) << " bytes)\n";
    std::cout << "unsigned long:\t\t0 ... " << ULONG_MAX << " (" << sizeof(unsigned long) << " bytes)\n";
    std::cout << "unsigned long long:\t0 ... " << ULONG_LONG_MAX << " (" << sizeof(unsigned long long) << " bytes)\n";
    std::cout << std::endl;
    std::cout << "float:\t\t\t" << std::numeric_limits<float>::min() << " ... " << std::numeric_limits<float>::max() << " (" << sizeof(float) << " bytes)\n";
    std::cout << "double:\t\t\t" << std::numeric_limits<double>::min() << " ... " << std::numeric_limits<double>::max() << " (" << sizeof(double) << " bytes)\n";
    std::cout << "long double:\t" << std::numeric_limits<long double>::min() << " ... " << std::numeric_limits<long double>::max() << " (" << sizeof(long double) << " bytes)\n";
}
