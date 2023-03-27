#ifndef JEGYAUTOMATA_H
#define JEGYAUTOMATA_H
#include "Jarat.h"

class JegyAutomata
{
    Jarat *J;
    size_t Jsz;
    Vonat *V;
    size_t Vsz;
    int penzosszeg;
    public:
        JegyAutomata():Jsz(0),Vsz(0), penzosszeg(0){}

        size_t getJaratokSz();
        bool listJaratok();
        bool listJaratKeres(Datum indulas,Datum erkezes,std::string iHely,std::string eHely);
        bool listVonatok();
        void buyTicket(size_t jaratszam);
        void addVonat(const Vonat&);
        void addKocsi(Vonat&,const Kocsi&);
        void addJarat(const Jarat& j);
        void toFile(std::ostream&);
        void listJaratokUI();
        void listJaratokKeresUI();
        void JaratHozzadasUI();
        void VonatHozzadasUI();
        void KocsiHozzadasUI();
        void VonatokLoad();
        void VonatokSave();
        ~JegyAutomata(){delete[] J;delete[] V;}

        void TEST();//Teszt
};

#endif // JEGYAUTOMATA_H
