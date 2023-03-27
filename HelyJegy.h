#ifndef HELYJEGY_H
#define HELYJEGY_H
#include <iostream>

class HelyJegy
{
    int kocsiSzam;
    int hely;
    public:
        HelyJegy():kocsiSzam(0),hely(0){}
        HelyJegy(int kSz,int h):kocsiSzam(kSz),hely(h){}

        std::ostream& print(std::ostream& os)const;
};

inline std::ostream& operator<<(std::ostream& os, const HelyJegy& a) {
    return a.print(os);
}
#endif // HELYJEGY_H
