#ifndef KOCSI_H
#define KOCSI_H
#include <string>

class Kocsi
{
    std::string id;
    int maxhely;
    bool *Szabad;
    public:
        Kocsi(int H = 0, const std::string& id = "") :id(id), maxhely(H) {if (maxhely > 0) {Szabad = new bool[maxhely]; for (int i = 0; i < maxhely; i++) { Szabad[i] = true; } } }
        int findHelyFoglal();
        int getmaxHely()const ;
        std::ostream& toFile(std::ostream& os);
        Kocsi& operator=(const Kocsi&);
        bool getIdx(int idx);

        ~Kocsi(){if(maxhely>0)delete[] Szabad;}
};

#endif // KOCSI_H


