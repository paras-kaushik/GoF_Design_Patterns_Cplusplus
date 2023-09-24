
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <sstream>
using namespace std;

struct Address{
    string street;
    string city;
    int suite;
    
    Address(const string& street, const string& city, const int suite)
    : street{street},city{city},suite{suite}{}
    
    Address(const Address& other)
       : street{other.street},
         city{other.city},
         suite{other.suite}{}

    friend ostream& operator<<(ostream& os, const Address& obj){
        return os
        << "street: " << obj.street
        << " city: " << obj.city
        << " suite: " << obj.suite;
    }
};

struct Contact{
    string name;
    Address* address;
    
    Contact& operator=(const Contact& other){
        if (this == &other)
            return *this;
        name = other.name;
        address = other.address;
        return *this;
    }//overloading copy assignment
    
    Contact(string name, Address* address)
    : name{name}, address{new Address(*address)}{}
    
    Contact(const Contact& other):
    name{other.name},
    address(new Address(*other.address))
    {}// oveloading copy constructor
    
    ~Contact(){
        delete address;
    }
    
    friend ostream& operator<<(ostream& os, const Contact& obj){
        return os
        << "name: " << obj.name
        << " works at " << *obj.address<<endl;
    }
};

Address* addr=new Address{ "Some common street", "London", 0};
Contact john{ "John Doe",  addr };// the prototypes

int main(){
    Contact john2{john};// new obj using
    john2.address->suite=5;
    
    Contact jane{ "Jane Doe", addr };// Using address prototype
    jane.address->street = "Differnt Steert";
    
    Contact jane2{ jane };
    jane2.address->city = "Delhi";
    
    cout <<john<<john2<<jane<< jane2 << std::endl;
    
    
    getchar();
    return 0;
    return 0;
}
