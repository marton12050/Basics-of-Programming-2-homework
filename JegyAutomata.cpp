#include "JegyAutomata.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool JegyAutomata::listJaratok(){
    if(Jsz == 0){
        cout<<"Nincsenek elerheto j�ratok"<<endl;
        return false;
    }
    cout << "0. Vissza" << endl;
    for(size_t i = 0;i<Jsz;i++){
        cout<<i+1<<". "<<J[i]<<endl;
    }
    return true;
}
bool JegyAutomata::listJaratKeres(Datum indulas, Datum erkezes, std::string iHely, std::string eHely) {
    bool van=false;
        for (size_t i = 0; i < Jsz; i++) {
            if (J[i].egyenlo(Jarat(Vonat("",""), iHely, indulas, eHely, erkezes))) {
                van = true;
                cout << i + 1 << ". " << J[i] << endl;
            }
        }
        return van;
}
bool JegyAutomata::listVonatok(){
    if(Vsz == 0){
        cout<<"Nincsenek elerhet� vonatok, adjon hozza el�szor"<<endl;
        return false;
    }
    cout<<"0. Vissza"<<endl;
    for(size_t i = 0;i<Vsz;i++){
        cout<<i+1<<".  "<<V[i]<<endl;
    }
    return true;
}
size_t JegyAutomata::getJaratokSz(){
    return Jsz;
}
void JegyAutomata::buyTicket(size_t jaratszam){
    if (!J[jaratszam].tele()) {
        int bem = 0;
        cout << "Milyen kedvezm�nye van?" << endl;
        cout << "1. Norm�l jegy" << endl;
        cout << "2. Di�k jegy" << endl;
        cout << "3. Nyugd�jas" << endl;
        cin >> bem;
        switch (bem) {
        case 1: cout << "1500 forint lesz." << endl; penzosszeg += 1500; break;
        case 2: cout << "750 forint lesz." << endl; penzosszeg += 750; break;
        case 3: cout << "500 forint lesz." << endl; penzosszeg += 500; break;
        default: cout << "V�s�rl�s t�r�lve lett." << endl; return;
        }
        cout << "\n*Automata Jegy Kiad�sa*" << endl;
        J[jaratszam].addUtas();
        cout << "\n\nEnnyi p�nz van �sszesen az automat�ban: " << penzosszeg<<endl;
    }
    else
        cout << "Tele van" << endl;
}
void JegyAutomata::addVonat(const Vonat& v){
    if(Vsz == 0){
        V = new Vonat[1];
        V[0] = v;
    }
    else{
        Vonat* tmp = new Vonat[Vsz+1];
        for(size_t i=0;i<Vsz;i++){
            tmp[i] = V[i];
        }
        tmp[Vsz] = v;
        delete[] V;
        V = tmp;
    }
    Vsz++;
}
void JegyAutomata::addJarat(const Jarat& j){
    if(Jsz == 0){
        J = new Jarat[1];
        J[0] = j;
    }else{
        Jarat *tmp = new Jarat[Jsz+1];
        for(size_t i=0;i<Jsz;i++){
            tmp[i] = J[i];
        }
        tmp[Jsz] = j;
        delete[] J;
        J = tmp;

    }
    Jsz++;
}
void JegyAutomata::addKocsi(Vonat& v,const Kocsi& k){
    v.addKocsi(k);
}

void JegyAutomata::listJaratokUI(){

    if(this->listJaratok()){
    size_t bem;
    cin>>bem;
    if(bem>this->getJaratokSz() || bem==0)
        return;
    bem -=1;
    this->buyTicket(bem);
    }

}

void JegyAutomata::JaratHozzadasUI(){
    if(this->listVonatok()){
        size_t bem;
        cin>>bem;
        if(bem>this->Vsz || bem==0)
            return;
        bem -=1;

        string inHely,erHely;

        int ev,ho,nap,ora,perc;
        cout<<"Indul�s helye: ";
        cin>>inHely;
        cout<<"\nIndul�s ideje: \n";
        cout<<"�v: ";
        cin>>ev;
        cout<<"H�: ";
        cin>>ho;
        cout<<"nap: ";
        cin>>nap;
        cout<<"\n�ra: ";
        cin>>ora;
        cout<<"Perc: ";
        cin>>perc;
        Datum inIdo(ev,ho,nap,ora,perc);
        cout<<"�rkez�s helye: ";
        cin>>erHely;
        cout<<"\n�rkez�s ideje: \n";
        cout<<"�v: ";
        cin>>ev;
        cout<<"H�: ";
        cin>>ho;
        cout<<"nap: ";
        cin>>nap;
        cout<<"\n�ra: ";
        cin>>ora;
        cout<<"Perc: ";
        cin>>perc;
        Datum erIdo(ev,ho,nap,ora,perc);

        this->addJarat(Jarat(V[bem],inHely,inIdo,erHely,erIdo));

}}
void JegyAutomata::listJaratokKeresUI() {
    if (Jsz == 0) {
        cout << "Nincsenek elerhet� j�ratok" << endl;
    }
    else {
        string inHely, erHely;

        int ev, ho, nap, ora, perc;
        cout << "Ha azt szeretn� hogy ne keressen az alapj�n oda �rjon '-1'-et"<<endl;
        cout << "Indul�s helye: ";
        cin >> inHely;
        cout << "\nIndul�s ideje: \n";
        cout << "�v: ";
        cin >> ev;
        cout << "H�: ";
        cin >> ho;
        cout << "nap: ";
        cin >> nap;
        cout << "\n�ra: ";
        cin >> ora;
        cout << "Perc: ";
        cin >> perc;
        Datum inIdo(ev, ho, nap, ora, perc);
        cout << "�rkez�s helye: ";
        cin >> erHely;
        cout << "\n�rkez�s ideje: \n";
        cout << "�v: ";
        cin >> ev;
        cout << "H�: ";
        cin >> ho;
        cout << "nap: ";
        cin >> nap;
        cout << "\n�ra: ";
        cin >> ora;
        cout << "Perc: ";
        cin >> perc;
        Datum erIdo(ev, ho, nap, ora, perc);
        if (this->listJaratKeres(inIdo, erIdo, inHely, erHely)) {
            size_t bem;
            cin >> bem;
            if (bem > this->getJaratokSz() || bem == 0)
                return;
            bem -= 1;
            this->buyTicket(bem);
        }
        else {
            cout << "Nincs ilyen J�rat"<<endl;
        }
    }
}
void JegyAutomata::VonatHozzadasUI(){

string id,tipus;
cout<<"Add meg a vonat azonosit�j�t: ";
cin>>id;
cout<<"Add meg a vonat tipus�t: ";
cin>>tipus;
this->addVonat(Vonat(id,tipus));

}
void JegyAutomata::KocsiHozzadasUI(){

    if(this->listVonatok()){
    size_t bem;
    cin>>bem;
    if(bem>this->Vsz || bem == 0)
        return;
    bem -=1;
    int h;
    string id;
    cout<<"Adja meg a kocsi azonosiojat!: ";
    cin>>id;
    cout<<"Adja meg a kocsinak a kapacitasat: ";
    cin>>h;
    V[bem].addKocsi(Kocsi(h,id));

    }

}


void JegyAutomata::VonatokLoad(){
    string h;
    string id;
    string tipus;
    string vonat;
    ifstream Vonatok("Vonatok.txt");
    while(getline(Vonatok,vonat)){
        stringstream line(vonat);
        getline(line,id,';');
        getline(line,tipus,';');
        Vonat v = Vonat(id,tipus);
        while(getline(line,id,';')){
            getline(line,h,';');
            stringstream hely(h);
            int x = 0;
            hely >> x;
            
            v.addKocsi(Kocsi(x ,id));
        }
        
        this->addVonat(v);

    }


    Vonatok.close();
}
void JegyAutomata::VonatokSave(){
    ofstream file;
    file.open("Vonatok.txt");
        for(size_t i = 0;i<Vsz;i++){
        V[i].toFile(file);
        file<<"\n";
    }
    file.close();
}


void JegyAutomata::TEST() {

    this->addJarat(Jarat(V[2], "Budapest", Datum(2020, 5, 13, 10, 10), "Debrecen", Datum(2020, 5, 13, 11, 10)));
    this->addJarat(Jarat(V[1], "Budapest", Datum(2020, 5, 13, 10, 10), "Varsow", Datum(2020, 5, 13, 12, 10)));
    this->addJarat(Jarat(V[2], "Dunakeszi", Datum(2020, 5, 13, 14, 10), "Debrecen", Datum(2020, 5, 13, 15, 30)));
    this->addJarat(Jarat(V[3], "Varsow", Datum(2020, 5, 13, 10, 10), "Debrecen", Datum(2020, 5, 13, 11, 10)));
    this->addJarat(Jarat(V[4], "Budapest", Datum(2020, 5, 14, 10, 10), "Debrecen", Datum(2020, 5, 14, 11, 20)));
    for(int i = 0;i<49;i++)
        J[1].addUtas();
}
