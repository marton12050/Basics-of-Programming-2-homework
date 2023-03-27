#ifndef VONAT_H
#define VONAT_H
#include "Kocsi.h"
#include "HelyJegy.h"
#include <string>

class Vonat{
    std::string id;
    int ferohely;
    size_t kocsikszama;
    std::string tipus;
    Kocsi *k; //A vonathoz kapcsolt kocsik
public:
    Vonat(const std::string &id = "",const std::string &tipus = ""):id(id),ferohely(0),kocsikszama(0),tipus(tipus){}
    Vonat(const Vonat& v);
    Vonat& operator=(const Vonat&);

    int getFeroHely()const;
    HelyJegy findHely();
    void addKocsi(const Kocsi& kocsi);

    std::ostream& print(std::ostream& os)const;
    std::ostream& toFile(std::ostream& os);
    ~Vonat(){if(kocsikszama>0)delete[] k;}
};
inline std::ostream& operator<<(std::ostream& os, const Vonat& v){
    return v.print(os);
}
#endif // VONAT_H
