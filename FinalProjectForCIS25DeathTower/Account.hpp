//
//  Account.hpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Character.hpp"
#include "Skill.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include <string>
using namespace std;
class Account{
private:
    
    string name;
    
    string password;
    
    fstream accountFile;
    
    Character* hero;
    
public:
    
    Account(){};
    
    Account(string name, string password){
        
        
        this->name = name;
        
        this->password = password;
        
        //create a txt file
        
        accountFile.open(name,ios::out);
        
        accountFile<<password<<endl;
        
        accountFile.close();
        
    };
    Account(string name, string password,string fileName){
        
        this->name = name;
        
        this->password = password;
        
    };
    void setHero(int);
    
    Character* getHero();
    
    void setHero();
    
    void showHeroInfo();
    
    void save();
    
    ~Account(){
    
        
    
    };
};
#endif /* Account_hpp */
