//
//  Equipment.hpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/27/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#ifndef Equipment_hpp
#define Equipment_hpp

#include <stdio.h>
#include <string>
using namespace std;
class Equipment{
public:


    virtual void getInfo();
    
    virtual string getKind();
    
    virtual string getName();
    
    virtual int getValue();
    
};
#endif /* Equipment_hpp */
