//
//  ListStratergy.h
//  LLD_PARKING_LOT
//
//  Created by Paras Kaushik on 01/08/23.
//

//System behaviour partially specified at runtime or even compile time in some cases
//Example printing strategy -markdown and html

#ifndef ListStratergy_h
#define ListStratergy_h
#include "Headers.h"
enum class OutPutFormat {
    markdown ,
    html
};

struct ListStratergy {// since markdown doesnt have start and end to its list we are not making them pure virtual so
    // as to not force markdownStratergy to override them - Interface segregation principle
    virtual void start(ostringstream& oss) { };// not pure virtual
    virtual void add_list_item(ostringstream& oss,const string& item)=0;
    virtual void end(ostringstream& oss) { };// not pure virtual
};

struct MarkdownListStratergy : public ListStratergy {
    
    virtual void add_list_item(ostringstream& oss,const string& item) override {
        oss<<"- "<<item<<endl;
    }
};

struct HtmlListStratergy : public ListStratergy {
    virtual void start(ostringstream& oss) override {
        oss<<"<ul>"<<endl;
    };
    
    virtual void add_list_item(ostringstream& oss,const string& item) override {
        oss<<"<li> "<<item<<" </li>"<<endl;
    }
    virtual void end(ostringstream& oss) override{
        oss<<"</ul>"<<endl;
    };
};

struct TextProcessor {
    void append_list(const vector<string>& items){
        list_stratergy->start(oss);
        for(auto& item:items){
            list_stratergy->add_list_item(oss,item);
        }
        list_stratergy->end(oss);
    }
    string str(){
        return oss.str();
    }
    void clear (){
        oss.str("");// clear content 
        oss.clear();// Clear the error state
    }
    void set_output_format(const OutPutFormat& format){// dynamic stratergy
        switch (format) {
            case OutPutFormat::markdown:
                list_stratergy= new MarkdownListStratergy();
                break;
            case OutPutFormat::html:
                list_stratergy= new HtmlListStratergy();
                break;
                
            default:
                break;
        }
    }
private:
    ostringstream oss;
    ListStratergy* list_stratergy;
};


#endif /* ListStratergy_h */
/*
 A note about ostringstream
- In C++, ostringstream is part of the Standard Template Library (STL) and is defined in the <sstream> header.
- It is a subclass of ostream and allows you to create and manipulate strings in the same way you would with cout
- it even has the same syntax use as cout << , oss << str -> means insert into output string stream
- but instead of outputting to the console, it outputs to a string.
- It provides a convenient way to build strings dynamically,
- especially when you need to concatenate different data types together.

- ostringstream, you can directly concatenate different data types without converting them to strings explicitly using std::to_string.
- The ostringstream stream automatically handles the conversion for you.
 USE CASES :
- Building dynamic strings: When you need to construct a string from different data types, like in the example above, ostringstream makes the process much cleaner and more readable.

- Generating log messages: When logging information, you might need to include various variables and data in the log message. ostringstream simplifies the process of building such log messages.

- Formatting data for output: If you need to prepare data for display or writing to a file in a particular format, ostringstream allows you to easily construct the formatted string.

- String manipulation: When you need to perform string manipulation, such as extracting values from a complex data structure and composing them into a string, ostringstream can be quite useful.

- Generating error messages: When reporting errors or exceptions, ostringstream helps you construct detailed error messages containing relevant information.

- Serialization: When serializing data for communication or storage, you can use ostringstream to construct the serialized string.
 
 
 **/
