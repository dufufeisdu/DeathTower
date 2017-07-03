//
//  Character.hpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <string>
#include "Skill.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include <iostream>
using namespace std;
class Monsters;
class Character{
private:
    
    int HP;
    
    int MP;
    
    int attackStrenth;
    
    int defence;
    
    bool alive;
    
    string name;
    
    Skill* skill;
    
    Weapon* weapon;
    
    Armor* armor;
    
    
public:
    
    Character(){}
    
    Character(string name,int HP, int MP, int defence,Skill* skill, Weapon* weapon,Armor* armor){
    
        this->name = name;
       
        this->HP = HP;
        
        this->MP = MP;
        
        this->defence = defence;
        
        this->skill = skill;
        
        this->weapon = weapon;
        
        this->armor = armor;
        
        attackStrenth = weapon->getDamage();
        
        alive = true;
    }
    
    bool killMonster(Monsters* );
    
    bool expainOrder(char, Monsters* );
    
    bool normalAttack(Monsters* );
    
    bool douge(Monsters* );
    
    bool skillAttack(Monsters* );
    
    bool commitSuicide(Monsters* );
    
    string getName(){
        
        return name;
    }
    int getHP(){
        
        return HP;
    }
    int getMP(){
        
        return MP;
    }
    int getDefence(){
        
        return defence;
    }
    Skill* getSkill(){
        
        return skill;
    }
    Weapon* getWeapon(){
        
        return weapon;
    }
    Armor* getArmor(){
    
        return armor;
    }
    int getAttackStrength(){
    
        return attackStrenth;
    }
    void setAttackStrenth(){
        
        attackStrenth = weapon->getDamage();
    
    }
    bool getAliveState(){
    
        return alive;
    }
    void setLiveState(bool alive){
    
        this->alive = alive;
    }
    void setHP(int);
    void setMP();
    void changeEquipment(Equipment *);
};
#endif /* Character_hpp */
