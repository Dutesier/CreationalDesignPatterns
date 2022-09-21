#include <iostream>

class ACar {
public:
    virtual ACar* Clone() = 0;
    virtual ~ACar(){}

    void    setChassisWidth(int cWidth) {
        chassisWidth = cWidth;
    }

    void    setChassisLenght(int cLength) {
        chassisLength = cLength;
    }

    void    setChassisHeight(int cHeight) {
        chassisHeight = cHeight;
    }

    void print(){
        std::cout << chassisWidth << std::endl << chassisLength << std::endl << chassisHeight << std::endl << engineType << std::endl << tractionType << std::endl << std::endl;
    }

protected:
    int chassisWidth, chassisLength, chassisHeight;
    int engineType, tractionType;
};

class iX: public ACar {
public:
    iX(){
        engineType = 1;
        tractionType = 4;
    }
    
    iX* Clone(){
        return new iX(*this);
    }

    void splitCar() {
        // we can only make two-wheel drive out of a four-wheel drive
        tractionType -= 2;
    }

};

class iThree: public ACar {
public:
    iThree(){
        engineType = 1;
        tractionType = 4;
    }
    
    iThree* Clone(){
        return new iThree(*this);
    }

};

int main() {
    iX* ix0 = new iX;
    ix0->setChassisHeight(10);
    ix0->setChassisLenght(20);
    ix0->setChassisWidth(10);

    iThree* i30 = new iThree;
    i30->setChassisHeight(10);
    i30->setChassisLenght(30);
    i30->setChassisWidth(50);

    // This can get realy unmanagable; lets use cloning
    ACar* fleet[3];

    fleet[0] = ix0->Clone();
    fleet[1] = i30->Clone();

    fleet[1]->setChassisLenght(100);

    ix0->splitCar();
    fleet[2] = ix0->Clone();

    delete i30;
    delete ix0;
    for (int i = 0; i < 3; ++i) {
        fleet[i]->print();
        delete fleet[i];
    }

    return 0;
}