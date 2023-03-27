#include <iostream>
#include <locale>
#include <fstream>
#include <sstream>
#include <string>
#include "JegyAutomata.h"



using namespace std;

int main()
{

    setlocale(LC_ALL, "");
    JegyAutomata Automata;
    
    Automata.listJaratok();
    Automata.listVonatok();
    Automata.VonatokLoad();
    
    Automata.TEST();//Betölt elõre pár adatot hogy tudjunk egybõl keresni.

    int choose=-1;
    cout<<"Vonat jegy eladó sotftware by Kerekes Márton"<<endl;
    while(choose != 6){
    cout<<"----------------------------------------------------"<<endl;
    cout<<"Válaszon az alábbi opciók közül(Sorszám és Enter)"<<endl;
    cout<<"\n1. Járatok kilistázása"<<endl;
    cout<<"2. Járatok Keres"<<endl;
    cout<<"3. Járatok Hozzáadása"<<endl;
    cout<<"4. Vonat hozzáadása"<<endl;
    cout<<"5. Kocsi hozzáadása"<<endl;
    cout<<"6. Kilép"<<endl;
    cin>>choose;
    switch(choose){
    case 1: Automata.listJaratokUI(); break;
    case 2: Automata.listJaratokKeresUI(); break;
    case 3: Automata.JaratHozzadasUI(); break;
    case 4: Automata.VonatHozzadasUI(); break;
    case 5: Automata.KocsiHozzadasUI(); break;
    case 6: break;

    default: cout<<"Rosszul adta meg!"<<endl;
    }}

    //vonatok mentése
    Automata.VonatokSave();
    cout<<"Vonatok elmentve."<<endl;
    return 0;
}
