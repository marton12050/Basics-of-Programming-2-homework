#include "HelyJegy.h"

std::ostream& HelyJegy::print(std::ostream& os)const{
    return os<<kocsiSzam<<". kocsiszám "<<hely<<". ülés ";

}
