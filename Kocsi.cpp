#include "Kocsi.h"
#include <iostream>

using namespace std;


Kocsi& Kocsi::operator=(const Kocsi& k){

    if (this != &k) {
        id = k.id;
        maxhely = k.getmaxHely();
        if (maxhely > 0) {
            Szabad = new bool[maxhely];
            for (int i = 0; i < maxhely; i++) {
                Szabad[i] = k.Szabad[i];
            }
        }
    }
    return *this;


}

int Kocsi::getmaxHely()const {
return maxhely;
}
int Kocsi::findHelyFoglal(){
    for(int i= 0;i<maxhely;i++){
        if(Szabad[i]){
            Szabad[i]=false;
            return i;
        }
    }
    return -1;
}
std::ostream& Kocsi::toFile(std::ostream& os){
    os<<id<<";"<<maxhely<<";";
    return os;
}

