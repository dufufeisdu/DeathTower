//
//  Skill.hpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#ifndef Skill_hpp
#define Skill_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Skill{
private:
    
    string name;
    
    int damage;
    
    int MPperSkill;
    
public:
    Skill();
    Skill(string name,int damage, int MPperSkill){
    
        this->name = name;
        
        this->damage = damage;
        
        this->MPperSkill = MPperSkill;
    }

    int getDamage(){
    
        return damage;
    
    };
    string getName(){
    
        return name;
    }
    int getMPperSkill(){
    
        return MPperSkill;
    
    }
};

#endif /* Skill_hpp */
