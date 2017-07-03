//
//  Armor.cpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#include "Armor.hpp"
string Armor:: getData(string &str){
    
    string target;
    
    unsigned long dp = str.find(" ");
    
    target = str.substr(0,dp);
    
    str = str.substr(dp+1,str.length());
    
    return target;
}
