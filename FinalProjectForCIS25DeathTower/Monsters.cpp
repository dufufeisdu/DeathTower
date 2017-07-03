//
//  Monsters.cpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#include "Monsters.hpp"

void Monsters::showInfo(){

    cout<<"Monster Name:"<<name<<endl;
    cout<<"Monster HP:"<<HP<<endl;
    cout<<"Monster attack:"<<attackForce<<endl;
    cout<<"Monster Skill:"<<getSkill()->getName()<<endl;
}

bool Monsters::killHero(Character* ch,bool useSkill){

    if(this->getAlive()==false){
        
        cout<<"The monster is dying and bleeding on the floor"<<endl;
        
        cout<<"The Monster droped an Equipment"<<endl;
        
        return false;
    }
        if (useSkill) {
            ch->setHP(this->getSkill()->getDamage());
            
            cout<<this->getName()<<" used a skill "<<
            this->getSkill()->getName()<<endl;
           
            cout<<"You lost "<<this->getSkill()->getDamage()<<" points HP"<<endl;
            
            return ch->getAliveState();
        }
        else{
        
            ch->setHP(this->getAttackForce());
            
            cout<<this->getName()<<" attacks you, ";
            
            cout<<"You lost "<<this->getAttackForce()<<" points HP"<<endl;
        
            return ch->getAliveState();
        }

}
int Monsters:: getRandNumber(int max, int min){
    
    int randNumber = 0;
    
    srand(static_cast<unsigned>(time(0)) );
    
    randNumber = rand()%(max + 1 - min) + min;
    
    return randNumber;
    
    
}

void Monsters:: setHP(int damage){

    HP = HP - damage;
    
    if(HP<=0){
        
        HP = 0;
        
        alive = false;
    }



}
Equipment* Monsters:: dropEquipment(){
    
    //equipmentkind = 1 stand for Weapon
    //equipmentKind = 2 stand for Armor
    
    int equipmentKind = getRandNumber(2, 1);
    
    if(equipmentKind == 1){
        
        int weaponCode = getRandNumber(12, 1);
        
        return new Weapon(weaponCode);
    }
    else {
    
        int ArmorCode = getRandNumber(10, 1);
        
        return new Armor(ArmorCode);
    
    
    }
    

}
