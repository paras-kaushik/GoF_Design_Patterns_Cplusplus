//
//  StaticListStratergy.h
//  LLD_PARKING_LOT
//
//  Created by Paras Kaushik on 01/08/23.
//

#ifndef StaticListStratergy_h
#define StaticListStratergy_h
#include "Headers.h"
#include "ListStratergy.h"

template <typename LS>
struct TextProcessor2 {
    void append_list(const vector<string>& items){
        list_stratergy.start(oss);
        for(auto& item:items){
            list_stratergy.add_list_item(oss,item);
        }
        list_stratergy.end(oss);
    }
    string str(){ return oss.str();}
    void clear (){
        oss.str("");// clear content
        oss.clear();// Clear the error state
    }
private:
    ostringstream oss;
    LS list_stratergy;
};


#endif /* StaticListStratergy_h */
