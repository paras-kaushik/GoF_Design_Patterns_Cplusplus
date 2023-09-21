#include "Headers.h"
#include "Logger.h"// Thread safe singleton
#include "DataAnalyticsToolXMLAdapter.h"// XML to JSON adapter
#include "VehicleFactory.h"//An Abstract factory that builds a Concrete factory for brandType
#include "ComputerBuilder.h"// Building a complex object Computer
#include "Observable.h"// Observer design pattern demo
#include "ListStratergy.h"// Dynamic stratergy pattern demo
#include "StaticListStratergy.h"// static strategy pattern demo
#include "GameTemplate.h"// templete design pattern demo
#include "ShapeDecorator.h"
#include "RenderorBridge.h"


int main(){

    return 0;
}

/*
 // Demonstrating bridge design pattern
 PixelRenderer pixelRenderer;
 VectorRenderer vectorRenderer;

 MyNewCircle circle1(pixelRenderer, 5.0);
 circle1.draw();
 circle1.render();

 MyNewCircle circle2(vectorRenderer, 10.0);
 circle2.draw();
 circle2.render();

 MyNewSquare square1(pixelRenderer, 8.0);
 square1.draw();
 square1.render();

 MyNewSquare square2(vectorRenderer, 12.0);
 square2.draw();
 square2.render();

 MyNewTriangle triangle1(pixelRenderer, 3.0, 4.0, 5.0);
 triangle1.draw();
 triangle1.render();

 MyNewTriangle triangle2(vectorRenderer, 6.0, 8.0, 10.0);
 triangle2.draw();
 triangle2.render();
 
 
 **/

/*
Demonstrating template design patten
 Chess chess;
 chess.run();// calling the skeleton algorithm, whose details are defined by inheritace
 // here we inherit and provide implemetations to the base class itslef
*/

/*
 Demonstrating dynamic/static stratergy design pattern
 
 vector<string> items{"foo","bar","baz"};
 TextProcessor tp;
 tp.set_output_format(OutPutFormat::markdown);
 tp.append_list(items);
 cout<<tp.str()<<endl;
 
 tp.clear();
 
 tp.set_output_format(OutPutFormat::html); // dynamic stratergy
 tp.append_list(items);
 cout<<tp.str()<<endl;
 
 TextProcessor2<MarkdownListStratergy> tpm;// static stratergy -fixed at compile time
 tpm.append_list(items);
 cout<<tpm.str()<<endl;
 
 tpm.clear();
 
 TextProcessor2<HtmlListStratergy> tph;
 tph.append_list(items);
 cout<<tph.str()<<endl;
 
 **/

/**
 Demonstrating observer design pattern
 
 // Create the weather station (Obvervable/Subject)
 WeatherStation*  weatherStation= new WeatherStation();

 // Create displays (observers)
 Display* display0= new Display();
 Display* display1 = new Display();

 
 weatherStation->registerObserver(display0);
 weatherStation->registerObserver(display1);
 
 // Simulate weather changes
 weatherStation->setMeasurements(25.0f, 60.0f, 1013.0f);
 
 weatherStation->removeObserver(display1);
 
 weatherStation->setMeasurements(30.0f, 55.0f, 1010.0f);
 
 */


/*
 Demonstrating Builder Design Pattern
 // Builder deisngn pattern is used whenever we build a very complex object with a lot of configs
 
  // Create the gaming computer builder
      GamingComputerBuilder* gamingComputerBuilder = new GamingComputerBuilder();
      // Create the computer director with the gaming computer builder
      ComputerDirector* gamingComputerDirector = new ComputerDirector(gamingComputerBuilder);

      // Build the gaming computer
      Computer* gamingComputer = gamingComputerDirector->buildComputer();

      // Display the details of the gaming computer
      std::cout << "Gaming Computer Details:\n";
      gamingComputer->displayDetails();
      std::cout << "\n";

      // Cleanup - delete allocated objects
      delete gamingComputerDirector;
      delete gamingComputerBuilder;
      delete gamingComputer;

      // Create the professional computer builder
      ProfessionalComputerBuilder* professionalComputerBuilder = new ProfessionalComputerBuilder();

      // Create the computer director with the professional computer builder
      ComputerDirector* professionalComputerDirector = new ComputerDirector(professionalComputerBuilder);

      // Build the professional computer
      Computer* professionalComputer = professionalComputerDirector->buildComputer();

      // Display the details of the professional computer
      std::cout << "Professional Computer Details:\n";
      professionalComputer->displayDetails();
      std::cout << "\n";

      // Cleanup - delete allocated objects
      delete professionalComputerDirector;
      delete professionalComputerBuilder;
      delete professionalComputer;
 
 **/


/*
 Demonstrating Abstract Factory Design Pattern
 -> Client used the Abstract Factory to create Factory and then object without worrying about internals
 -> Another example can be a GUIFactory which creates a mac/windows factory which in turn creates mac buttons/windows buttons
 
 string vehicleBrand;
 cout << "Enter vehicle brand (Audi/BMW): ";
 cin >> vehicleBrand;
// Please notice how the function is static so we are not creating an object of VehicleFactory
 Vehicle* vehicle = VehicleFactory::createVehicleBrandFactory(vehicleBrand)->createCar();// creates 'vehicleBrand' car
 if (vehicle) {
     vehicle->drive();
     delete vehicle;
     vehicle=nullptr;
 } else {
     std::cout << "Invalid vehicle type." << std::endl;
 }

 **/

/*
 Demonstrating Factory Design Pattern
 -> Client used the Factory to create Object without worrying about internals
 
 string vehicleType;
 cout << "Enter vehicle type (Car, Bike, Truck): ";
 cin >> vehicleType;
// Please notice how the function is static so we are not creating an object of VehicleFactory
 Vehicle* vehicle = VehicleFactory::createVehicle(vehicleType);

 if (vehicle) {
     vehicle->drive();
     delete vehicle;
 } else {
     std::cout << "Invalid vehicle type." << std::endl;
 }
 **/

/* Demonstrating Singleton Design Pattern
    Logger* logger=Logger::getLoggerInstance();
    Logger* logger2=Logger::getLoggerInstance();
    //Logger Logger3=*logger; copy assignment wont work
    //Logger Logger4(*logger); copy constructor wont work

    logger->log("Hello, World!\n");
    logger2->log("yello, World!\n");
    
    thread t1(user1logs);
    thread t2(user2logs);
    
    t1.join();
    t2.join();
*/
/* Demonstrating Adapter design pattern
    XMLData * xmlData=new XMLData("Sample XML");
   // DataAnalyticsTool* datTool=new DataAnalyticsTool(xmlData);//cannot be done
   //  DataAnalyticsTool* datTool=new DataAnalyticsTool("JSON CONVERTED FROM XML");//needs to be done
    DataAnalyticsTool* datTool=new DataAnalyticsToolXMLAdapter(xmlData);
    Client * myClient=new Client();// client code unchanged
    myClient->processData(datTool);
*/

/*
 SINGLETON RELATED CODE DEMONSTRATING TWO THREADS
void user1logs(){
    Logger * logger=Logger::getLoggerInstance();
    logger->log("Logs by user 1");
}

void user2logs(){
    Logger * logger=Logger::getLoggerInstance();
    logger->log("Logs by user 2");
}
 */
