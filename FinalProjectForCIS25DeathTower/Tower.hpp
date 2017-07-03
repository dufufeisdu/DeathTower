//
//  Tower.hpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#ifndef Tower_hpp
#define Tower_hpp

#include <stdio.h>
#include <iostream>
#include "Monsters.hpp"
#include "Character.hpp"
#include "Equipment.hpp"
#include "Account.hpp"
#include <string>
using namespace std;
class Tower{
private:
    int totalStrey;
    
    int storey;
    
    Monsters* monster;
    
    Character* hero;
    
    Equipment* equipment;
    
public:
    Tower(){
    
    
    }
    
    Tower(Character* hero,int stage){
        
        totalStrey = stage;
        
        this->hero = hero;
        
    }
    
    void setStorey(int stair){
    
        storey = stair;
    
    }
    
    int getRandNumber(int,int);
    
    void showTowerInfo();
    
    void showTowerInfo(int);
    
    void resetHero();
    
    void setMonster(int);
    
    void fight();
    
    bool defeat();
    
    void showDeathResult();
    
    void generateEquipment();
    
    void showEquipmentInfo();
   
    void equipable();
    
    void changeEquipment();
    
    string getData(string&);
    
    Monsters* getMonster(){
        
        return monster;
    }

};

#endif /* Tower_hpp */
