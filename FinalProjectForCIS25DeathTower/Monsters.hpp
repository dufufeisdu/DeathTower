//
//  Monsters.hpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#ifndef Monsters_hpp
#define Monsters_hpp

#include <stdio.h>
#include "Skill.hpp"
#include "Character.hpp"
#include <iostream>
#include "Armor.hpp"
#include "Weapon.hpp"
#include <string>
using namespace std;

class Monsters{
private:
    
    string name;
    
    int HP;
    
    int attackForce;
    
    Skill* skill;
    
    bool  alive;
    
    
public:
    Monsters(){};
    
    Monsters(string name, int HP, int attackForce, Skill *skill){
    
        this->name = name;
        
        this->HP = HP;
        
        this->attackForce = attackForce;
        
        this->skill = skill;
        
        alive = true;
    };
    
    void setAlive(bool alive){
    
        this->alive = alive;
    
    };
    
    bool getAlive(){
    
        return alive;
    }
    
    bool killHero(Character*, bool);
    
    Equipment* dropEquipment();

    Skill* getSkill(){
    
        return skill;
    }
    string getName(){
    
        return name;
    }
    int getAttackForce() const{
        
        return attackForce;
        
    }
    
    void setHP(int damage);
    
    int getRandNumber(int,int);
    void showInfo();
};
#endif /* Monsters_hpp */
