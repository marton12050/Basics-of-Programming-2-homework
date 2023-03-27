#include "Vonat.h"
#include <iostream>

int Vonat::getFeroHely()const{
return ferohely;
}
Vonat& Vonat::operator=(const Vonat& v){
    if (this != &v) {
        id = v.id;
        ferohely = v.ferohely;
        if (kocsikszama > 0)
            delete[] k;
        kocsikszama = v.kocsikszama;
        tipus = v.tipus;
        if (kocsikszama > 0) {
            k = new Kocsi[kocsikszama];
            for (size_t i = 0; i < kocsikszama; i++) {
                k[i] = v.k[i];
            }

        }
    }
    return (*this);
}

Vonat::Vonat(const Vonat& v):kocsikszama(0){

    if (this != &v)
        *this = v;
}

void Vonat::addKocsi(const Kocsi& kocsi){
if(kocsikszama == 0){
    k = new Kocsi[1];
    k[0] = kocsi;
}
else{
    Kocsi *temp = new Kocsi[kocsikszama+1];
    for(size_t i = 0;i<kocsikszama;i++){
        temp[i] = k[i];
    }
    temp[kocsikszama] = kocsi;
    delete[] k;
    k = temp;

}

ferohely += kocsi.getmaxHely();
kocsikszama++;

}

HelyJegy Vonat::findHely(){
    for(size_t i = 0;i<kocsikszama;i++){
        int tmp = k[i].findHelyFoglal();
        if(tmp != -1){

            return HelyJegy(i+1,tmp+1);
        }
    }
    return HelyJegy(-1, -1);
}

std::ostream& Vonat::print(std::ostream& os)const{
            return os<<"Azonosito:"<<id<<"   Tipus:"<<tipus<<"   Kocsik Szama:"<<kocsikszama<<"  Ferohelyes:"<<ferohely<<std::endl;
        }

std::ostream& Vonat::toFile(std::ostream& os){
    os<<id<<";"<<tipus<<";";
    for(size_t i = 0;i<kocsikszama;i++){
        k[i].toFile(os);
    }
    return os;
}
