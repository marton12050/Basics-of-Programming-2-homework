#ifndef DATUM_H
#define DATUM_H
#include <string>
#include <iostream>

class Datum{
    int ev;
    int ho;
    int nap;
    int ora;
    int perc;
    public:
        Datum(int ev=0,int ho=0,int nap=0,int ora=0,int perc=0):ev(ev),ho(ho),nap(nap),ora(ora),perc(perc){}
        Datum(const Datum&);
        Datum& operator=(const Datum&);
        bool egyenlo(const Datum&)const;//ahol nem -1 ott ellenõrzi
        std::ostream& print(std::ostream& os)const;
};

inline std::ostream& operator<<(std::ostream& os, const Datum& a) {
    return a.print(os);
}

#endif // DATUM_H
