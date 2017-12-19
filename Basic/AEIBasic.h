//
// Created by Andrey Ermolaev on 15.12.17.
//

#ifndef AEIMATH_AEIBASIC_H
#define AEIMATH_AEIBASIC_H

//Types
using ll = long long int;

//Basic math functions
ll gcd(ll, ll);
ll lcm(ll, ll);
ll binPow(ll, ll);
ll binModPow(ll, ll, ll);

//Prime functions
bool isPrimeBig(ll);
bool isPrime(ll);
ll phi(ll);
ll phiphi(ll);

//Help
void minmaxValue();
void printASCII(int, int, int);


#endif //AEIMATH_AEIBASIC_H
