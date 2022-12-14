#include <iostream>

namespace making_cars {
    class ADoor {
    public:
        ADoor(){}
        virtual ~ADoor(){};
        virtual void Open() = 0;
    };

    class iXDoor: public ADoor {
    public:
        iXDoor(){
            std::cout << "Building an electric car door (iX)" << std::endl;
        }
        void Open() override {
            std::cout << "Opening an electric car door (iX)" << std::endl;
        }
    };

    class XFiveDoor: public ADoor {
    public:
        XFiveDoor(){
            std::cout << "Building a diesel car door (X5)" << std::endl;
        }
        void Open() override {
            std::cout << "Opening an diesel car door (X5)" << std::endl;
        }

    };

    class AEngine{
    public:
        AEngine(){}
        virtual ~AEngine(){}
        virtual void Run() = 0;
    };

    class iXEngine: public AEngine {
    public:
        iXEngine(){
            std::cout << "Making an eletrical engine" << std::endl;
        }
        void Run() override {
            std::cout << "shhhhh" << std::endl;
        }
    };

    class XFiveEngine: public AEngine {
    public:
        XFiveEngine(){
            std::cout << "Making a diesel engine" << std::endl;
        }
        void Run() override {
            std::cout << "VRMMMMM" << std::endl;
        }
    };
    
    class ICarFactory{
    public:
        virtual ~ICarFactory(){}
        virtual ADoor* BuildDoor() = 0;
        virtual AEngine* BuildEngine() = 0;
    };

    class iXFactory: public ICarFactory{
    public:
        virtual ~iXFactory(){}

        ADoor* BuildDoor(){
            return new iXDoor();
        }

        AEngine* BuildEngine(){
            return new iXEngine();
        }
    };

    class XFiveFactory: public ICarFactory{
    public:
        virtual ~XFiveFactory(){}

        ADoor* BuildDoor(){
            return new XFiveDoor();
        }

        AEngine* BuildEngine(){
            return new XFiveEngine();
        }
    };

    void run_demo(){
        ICarFactory* CarPlant;
        int choice;

        std::cout << "Select car type: " << std::endl
        << "1: iX" << std::endl
        << "2: X5" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            CarPlant = new iXFactory;
            break;
        case 2:
            CarPlant = new XFiveFactory;
            break;
        default:
            std::cout << "Invalid selection";
            CarPlant = NULL;
            break;
        }

        if (CarPlant != NULL) {
            ADoor *myDoor = CarPlant->BuildDoor();
            AEngine *myEngine = CarPlant->BuildEngine();

            myDoor->Open();
            myEngine->Run();

            delete myDoor;
            delete myEngine;
            delete CarPlant;
        }
    }
}

int main() {
    making_cars::run_demo();
}