//
// Created by Andrey Ermolaev on 14.12.17.
//

#ifndef AEIMATH_AEITIMER_H
#define AEIMATH_AEITIMER_H

#include <string>


class AEITimer {
private:
    int sec;
    int min;
    int hou;

public:
    AEITimer();
    explicit AEITimer(int s);
    AEITimer(int m, int s);
    AEITimer(int h, int m, int s);


    int getSeconds();
    int getMinutes();
    int getHours();

    void setSeconds(int s);
    void setMinutes(int m);
    void setHours(int h);

    void setTime(int s);
    void setTime(int m, int s);
    void setTime(int h, int m, int s);

    int getTime();
    std::string getStrTime();
    std::string getStrTimeWithSeparator(std::string sep, bool isZero);


    AEITimer& operator++();
    AEITimer operator++(int);
    AEITimer& operator--();
    AEITimer operator--(int);

    friend const AEITimer operator+(AEITimer left, AEITimer right);
    friend const AEITimer operator-(AEITimer left, AEITimer right);
    friend const AEITimer operator+(AEITimer timer, int s);
    friend const AEITimer operator-(AEITimer timer, int s);
    friend const AEITimer operator*(AEITimer timer, float k);
    friend const AEITimer operator/(AEITimer timer, float k);

    friend bool operator==(AEITimer& left, AEITimer& right);
    friend bool operator>(AEITimer& left, AEITimer& right);
    friend bool operator<(AEITimer& left, AEITimer& right);

    explicit operator int() const;
};


#endif //AEIMATH_AEITIMER_H
