#include <iostream>

class Coffee{
public:
    Coffee(){}
    std::string& getType() {
        return type;
    }
protected:
    std::string type;
};

class Espresso: public Coffee {
public:
    Espresso(): Coffee() {
        type = "Espresso";
        std::cout << "Making an espresso" << std::endl;
    }
};

class Cappuccino: public Coffee {
public:
    Cappuccino(): Coffee() {
        type = "Cappuccino";
        std::cout << "Making a cappuccino" << std::endl;
    }
};

class CoffeeMakerFactory {
public:
    Coffee* getCoffee(){
        int choice;

        std::cout << "select type of coffee to make: " << std::endl
            << "1: Espresso" << std::endl
            << "2: Cappuccino" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
                return new Espresso;
        case 2:
                return new Cappuccino;
        default:
            std::cout << "Invalid selection";
            return NULL;    
        }
    }
private:
    Coffee* coffee;

};


int main(){
    CoffeeMakerFactory coffeeMachine;
    Coffee *cup;
    cup = coffeeMachine.getCoffee();

    std::cout << cup->getType();
    delete cup;
}