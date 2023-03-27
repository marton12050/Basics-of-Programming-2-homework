#include "Jarat.h"


Jarat& Jarat::operator=(const Jarat& j) {
    if (this != &j) {
        utasokszama = j.utasokszama;
        V = j.V;
        inHely = j.inHely;
        inIdo = j.inIdo;
        erHely = j.erHely;
        erIdo = j.erIdo;
    }
    return *this;
}

bool Jarat::egyenlo(const Jarat& j) const {
    if ((inHely == j.inHely || j.inHely == "-1") && (inIdo.egyenlo(j.inIdo)) && (erHely == j.erHely || j.erHely == "-1") && (erIdo.egyenlo(j.erIdo)))
        return true;
    return false;
}
bool Jarat::tele() {
    return V.getFeroHely() - utasokszama == 0;

}

void Jarat::addUtas(){
if(V.getFeroHely()-utasokszama<=0){
    std::cout<<"Nincs szabad hely";

}
else {
    std::cout << V.findHely();

    utasokszama++;
}
}


