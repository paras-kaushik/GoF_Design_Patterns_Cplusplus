//
//  ComputerBuilder.h
//  LLD_PARKING_LOT
//
//  Created by Paras Kaushik on 16/07/23.
//

#ifndef ComputerBuilder_h
#define ComputerBuilder_h

#include <iostream>
#include <string>

class Computer {// the actual complex object we are trying to build peicewise
private:
    std::string cpu;
    std::string gpu;
    int ram;
    int storage;

public:
    void setCPU(const std::string& cpu) {
        this->cpu = cpu;
    }

    void setGPU(const std::string& gpu) {
        this->gpu = gpu;
    }

    void setRAM(int ram) {
        this->ram = ram;
    }

    void setStorage(int storage) {
        this->storage = storage;
    }

    // Other methods relevant to the computer...

    // Example method to display computer information.
    void displayDetails() const {
        std::cout << "Computer Specifications:\n";
        std::cout << "CPU: " << cpu << '\n';
        std::cout << "GPU: " << gpu << '\n';
        std::cout << "RAM: " << ram << " GB\n";
        std::cout << "Storage: " << storage << " GB\n";
    }
};

//BUILDER(abstract)
class ComputerBuilder {
protected:
    Computer * computer;// notice that this is protected as only conctete builders access this
public:
    ComputerBuilder(){
        this->computer=new Computer();
    }
    virtual void buildCPU() = 0;
    virtual void buildGPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;

    virtual Computer* getComputer(){
        return computer;
    };
};
// CONCRETE BUILDERS
// Concrete Builder 1: GamingComputerBuilder
class GamingComputerBuilder : public ComputerBuilder {
public:
    void buildCPU() override {
        computer->setCPU("High-performance CPU");
    }

    void buildGPU() override {
        computer->setGPU("Powerful GPU");
    }

    void buildRAM() override {
        computer->setRAM(16);
    }

    void buildStorage() override {
        computer->setStorage(512);
    }
};

// Concrete Builder 2: ProfessionalComputerBuilder
class ProfessionalComputerBuilder : public ComputerBuilder {
public:
    void buildCPU() override {
        computer->setCPU("Professional-grade CPU");
    }

    void buildGPU() override {
        computer->setGPU("Workstation GPU");
    }

    void buildRAM() override {
        computer->setRAM(32);
    }

    void buildStorage() override {
        computer->setStorage(1024);
    }
};


//DIRECTOR - directs the process of building
class ComputerDirector {// Director uses builder to build
    ComputerBuilder * computerBuilder;// THIS CAN ALSO BE UNDERSTOOD AS BUILDING "STRATERGY" withe specifics defined by inheritacne
public:
    ComputerDirector(ComputerBuilder* computerBuilder){
        this->computerBuilder=computerBuilder;
    }
    Computer* getComputer(){
        return computerBuilder->getComputer();
    }
    Computer* buildComputer(){
        computerBuilder->buildCPU();
        computerBuilder->buildGPU();
        computerBuilder->buildRAM();
        computerBuilder->buildStorage();
        return computerBuilder->getComputer();
    }
};
#endif /* ComputerBuilder_h */
