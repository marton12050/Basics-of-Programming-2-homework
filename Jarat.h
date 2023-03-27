#ifndef JARAT_H
#define JARAT_H
#include "Datum.h"
#include "HelyJegy.h"
#include "Vonat.h"

class Jarat
{
    int utasokszama;
    Vonat V;
    std::string inHely;
    Datum inIdo;
    std::string erHely;
    Datum erIdo;
    public:
        Jarat():utasokszama(0),V(),inHely(),inIdo(),erHely(),erIdo(){}
        Jarat(const Vonat &v, const std::string &inHely, const Datum &inIdo, const std::string &erHely, const Datum &erIdo):utasokszama(0),V(v),inHely(inHely),inIdo(inIdo),erHely(erHely),erIdo(erIdo){}
        Jarat(const Jarat&);
        Jarat& operator=(const Jarat&);

        bool egyenlo(const Jarat&)const;//Vonaton kívül minden

        void addUtas();
        bool tele();

        std::ostream& print(std::ostream& os)const{
            return os<<" Indulas helye:"<<inHely<<" Idopontja:"<<inIdo<<" Uticel:"<<erHely<<" Varható erkezes:"<<erIdo<<" Szabad helyek szama:"<<V.getFeroHely()-utasokszama<<std::endl;
        }

};

inline std::ostream& operator<<(std::ostream& os, const Jarat& j){
    return j.print(os);
}
#endif // JARAT_H
