#include <iostream>

// Chassis
class Chassis {
public:
    const std::string getChassis(){
        return chassis_type;
    }
protected:
    std::string chassis_type;
};

class Sedan: public Chassis {
public:
    Sedan(){
        std::cout << "Building a Sedan" << std::endl;
        chassis_type = "Sedan";
    }
};

class Roadster: public Chassis {
public:
    Roadster(){
        std::cout << "Building a Roadster" << std::endl;
        chassis_type = "Roadster";
    }
};


// Engines
class Engine {
public:
    const std::string getEngine(){
        return engine_type;
    }
protected:
    std::string engine_type;
};

class Electric: public Engine {
public:
    Electric(){
        std::cout << "Making an Electric engine" << std::endl;
        engine_type = "Electric";
    }
};

class Diesel: public Engine {
public:
    Diesel(){
        std::cout << "Making an Diesel engine" << std::endl;
        engine_type = "Diesel";
    }
};

// Wheels
class Wheels {
public:
    Wheels(){
        wheel_type = "Wheels";
    }
    const std::string getWheels(){
        return wheel_type;
    }
protected:
    std::string wheel_type;
};

// The main Class: has a pointer to a chassis, an engine and some wheels
class Car {
public:
    Car(std::string m){
        model = m;
    }

    ~Car(){
        delete chassis;
        delete engine;
        delete wheels;
    }

    void setChassis(Chassis* c) { chassis = c; }
    void setEngine(Engine* e) { engine = e; }
    void setWheels(Wheels* w) { wheels = w; }

    std::string checkFullModel(){
        std::string fullModel;

        fullModel = model + ": " + chassis->getChassis() + " "
            + engine->getEngine() + " "
            + wheels->getWheels() + "\n";
        
        return fullModel;
    }

private:
    Chassis*    chassis;
    Engine*     engine;
    Wheels*     wheels;
    std::string model;
};

// Builders
class CarBuilder {
public:
    virtual ~CarBuilder(){}
    virtual void makeChassis() {}
    virtual void makeEngine() {}
    virtual void makeWheels() {}

    Car*    getCar(){
        return car;
    }
protected:
    Car*    car;
};

// This is an easy way to add new complex classes
class iXBuilder: public CarBuilder {
public:
    iXBuilder(){
        car = new Car("iX");
    }

    void makeChassis() override {
        car->setChassis(new Sedan);
    }

    void makeEngine() override {
        car->setEngine(new Electric);
    }

    void makeWheels() override {
        car->setWheels(new Wheels);
    }
};

// If I want to replicate a Z4
class zFourBuilder: public CarBuilder {
public:
    zFourBuilder(){
        car = new Car("Z4");
    }

    void makeChassis() override {
        car->setChassis(new Roadster);
    }

    void makeEngine() override {
        car->setEngine(new Diesel);
    }

    void makeWheels() override {
        car->setWheels(new Wheels);
    }
};

// or the new i8
class iEightBuilder: public CarBuilder {
public:
    iEightBuilder(){
        car = new Car("i8");
    }

    void makeChassis() override {
        car->setChassis(new Roadster);
    }

    void makeEngine() override {
        car->setEngine(new Electric);
    }

    void makeWheels() override {
        car->setWheels(new Wheels);
    }
};

int main(){
    CarBuilder* builder;
    Car* myCar;
    int choice;

    std::cout << "Pick a car: " << std::endl
                << "1: iX" << std::endl
                << "2: Z4" << std::endl
                << "3: i8" << std::endl;
    std::cin >> choice;

    switch (choice) {
        case 1:
            builder = new iXBuilder;
            break;
        case 2:
            builder = new zFourBuilder;
            break;
        case 3:
            builder = new iEightBuilder;
            break;
        default:
            builder = NULL;
            return 1;
    }

    builder->makeChassis();
    builder->makeEngine();
    builder->makeWheels();

    myCar = builder->getCar();    
    std::cout << myCar->checkFullModel();

    delete builder;
    delete myCar;
}
