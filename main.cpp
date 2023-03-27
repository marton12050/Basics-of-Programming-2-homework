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
    
    Automata.TEST();//Bet�lt el�re p�r adatot hogy tudjunk egyb�l keresni.

    int choose=-1;
    cout<<"Vonat jegy elad� sotftware by Kerekes M�rton"<<endl;
    while(choose != 6){
    cout<<"----------------------------------------------------"<<endl;
    cout<<"V�laszon az al�bbi opci�k k�z�l(Sorsz�m �s Enter)"<<endl;
    cout<<"\n1. J�ratok kilist�z�sa"<<endl;
    cout<<"2. J�ratok Keres"<<endl;
    cout<<"3. J�ratok Hozz�ad�sa"<<endl;
    cout<<"4. Vonat hozz�ad�sa"<<endl;
    cout<<"5. Kocsi hozz�ad�sa"<<endl;
    cout<<"6. Kil�p"<<endl;
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

    //vonatok ment�se
    Automata.VonatokSave();
    cout<<"Vonatok elmentve."<<endl;
    return 0;
}
