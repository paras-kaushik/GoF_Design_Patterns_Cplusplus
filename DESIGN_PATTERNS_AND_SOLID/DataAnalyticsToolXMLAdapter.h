//
//  DataAnalyticsToolXMLAdapter.h
//  LLD_PARKING_LOT
//
//  Created by Paras Kaushik on 06/07/23.
//

#ifndef DataAnalyticsToolXMLAdapter_h
#define DataAnalyticsToolXMLAdapter_h
#include<iostream>
#include<string>
using namespace std;


class XMLData {
    string xmlData;
public:
    XMLData(string xmlData){
        this->xmlData=xmlData;
    }
    
    string getXMLData(){
        return xmlData;
    }
};

class DataAnalyticsTool {
    string jsonData;
protected:
    void setJsonData(string jsonData){
        this->jsonData=jsonData;
    }
public:
    string getJsonData(){
        return jsonData;
    }
    DataAnalyticsTool(string jsonData){
        this->jsonData=jsonData;
    }
    virtual void analyseData(){// if `virtual' keyword is removed, parent pointer pointing to child object would call parents function due to early binding
        cout<<"I analyse Only json data ->> "<<jsonData<<endl;
    }
};

//============================================> writing an adapter to extend tools support for XML data client has
class DataAnalyticsToolXMLAdapter:public DataAnalyticsTool {
    // This is object adapter pattern(done via object composition)- there is also one class adapter pattern with uses multiple inheritance
public:
    DataAnalyticsToolXMLAdapter(XMLData* xmlData): DataAnalyticsTool(xmlData->getXMLData()){
        
    }
     void analyseData() override{
         // I CONVERT THIS XML DATA TO JSON DATA BY IN-HOUSE LOGIC OR BY EXTERNAL API
         setJsonData(getJsonData()+" Converted to JSON");
         DataAnalyticsTool::analyseData(); 
    }
};
// this is also a decorator


class Client {// client code remains the same
public:
    void processData(DataAnalyticsTool* tool){
        tool->analyseData();
    }
};

#endif /* DataAnalyticsToolXMLAdapter_h */
