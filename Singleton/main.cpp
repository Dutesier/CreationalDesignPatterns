#include <iostream>

class BestCar {
public:
    static BestCar* getInstance(){
        if (instance == NULL) {
            std::cout << "New Instance" << std::endl;
            instance = new BestCar;
        }
        return instance;
    }

    void whoIsTheBest(){
        std::cout << "BMW is the best" << std::endl;
    }


private:
    BestCar(){
        std::cout << "New Best Car" << std::endl;
    }

    static BestCar* instance;

};

// Initializing instance to avoid linker errors
BestCar* BestCar::instance = NULL;

int main(){
    BestCar::getInstance()->whoIsTheBest();
    BestCar::getInstance()->whoIsTheBest();
    delete BestCar::getInstance();
}