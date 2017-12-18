//
// Created by Andrey Ermolaev on 14.12.17.
//

#include "AEITimer.h"

AEITimer::AEITimer() {
    sec = min = hou = 0;
}
AEITimer::AEITimer(int s) {
    if (s < 0) {
        s = 0;
    }
    if (s > 86399) {
        s = s % 86400;
    }
    hou = s / 3600;
    min = (s - hou*3600) / 60;
    sec = s - 3600*hou - 60*min;
}
AEITimer::AEITimer(int m, int s) {
    *this = AEITimer(60*m + s);
}
AEITimer::AEITimer(int h, int m, int s) {
    *this = AEITimer(3600*h + 60*m + s);
}


int AEITimer::getSeconds() {
    return sec;
}
int AEITimer::getMinutes() {
    return min;
}
int AEITimer::getHours() {
    return hou;
}

void AEITimer::setSeconds(int s) {
    *this = AEITimer(3600*hou + 60*min + s);
}
void AEITimer::setMinutes(int m) {
    *this = AEITimer(3600*hou + 60*m + sec);
}
void AEITimer::setHours(int h) {
    *this = AEITimer(3600*h + 60*min + sec);
}

void AEITimer::setTime(int s) {
    *this = AEITimer(s);
}
void AEITimer::setTime(int m, int s) {
    *this = AEITimer(60*m + s);
}
void AEITimer::setTime(int h, int m, int s) {
    *this = AEITimer(3600*h + 60*m + s);
}

int AEITimer::getTime() {
    return 3600*hou + 60*min + sec;
}
std::string AEITimer::getStrTime() {
    return getStrTimeWithSeparator(":",true);
}
std::string AEITimer::getStrTimeWithSeparator(std::string sep, bool isZero) {
    std::string st;
    if ((hou < 10) && (isZero)) st += "0";
    st += std::to_string(hou) + sep;
    if ((min < 10) && (isZero)) st += "0";
    st += std::to_string(min) + sep;
    if ((sec < 10) && (isZero)) st += "0";
    st += std::to_string(sec);
    return st;
    //return std::string(std::to_string(hou) + sep + std::to_string(min) + sep + std::to_string(sec));
}


AEITimer& AEITimer::operator++() {
    *this = AEITimer(3600*hou + 60*min + sec + 1);
    return *this;
}
AEITimer AEITimer::operator++(int) {
    AEITimer temp = *this;
    ++*this;
    return temp;
}
AEITimer& AEITimer::operator--() {
    *this = AEITimer(3600*hou + 60*min + sec - 1);
    return *this;
}
AEITimer AEITimer::operator--(int) {
    AEITimer temp = *this;
    --*this;
    return temp;
}

const AEITimer operator+(AEITimer left, AEITimer right) {
    return AEITimer(left.getTime() + right.getTime());
}
const AEITimer operator-(AEITimer left, AEITimer right) {
    return AEITimer(left.getTime() - right.getTime());
}
const AEITimer operator+(AEITimer timer, int s) {
    return AEITimer(timer.getTime() + s);
}
const AEITimer operator-(AEITimer timer, int s) {
    return AEITimer(timer.getTime() - s);
}
const AEITimer operator*(AEITimer timer, float k) {
    return AEITimer(int(timer.getTime() * k));
}
const AEITimer operator/(AEITimer timer, float k) {
    return AEITimer(int(timer.getTime() / k));
}

bool operator==(AEITimer& left, AEITimer& right) {
    return left.getTime() == right.getTime();
}
bool operator>(AEITimer& left, AEITimer& right) {
    return left.getTime() > right.getTime();
}
bool operator<(AEITimer& left, AEITimer& right) {
    return left.getTime() < right.getTime();
}

AEITimer::operator int() const {
    return 3600*hou + 60*min + sec;
}
