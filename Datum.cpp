#include "Datum.h"

Datum& Datum::operator=(const Datum& d) {

    ev = d.ev;
    ho = d.ho;
    nap = d.nap;
    perc = d.perc;
    ora = d.ora;
    return *this;

}

Datum::Datum(const Datum& d) {
    if(this != &d)
        *this = d;
}

bool Datum::egyenlo(const Datum& d) const {
    if ((ev == d.ev || d.ev == -1) && (ho == d.ho || d.ho == -1) && (nap == d.nap || d.nap == -1) && (ora == d.ora || d.ora == -1) && (perc == d.perc || d.perc == -1))
        return true;
    return false;
}

std::ostream& Datum::print(std::ostream& os)const{
    return os<<ev<<" év "<<ho<<" hónap "<<nap<<" nap "<<ora<<" óra "<<perc<<" perc";

}
