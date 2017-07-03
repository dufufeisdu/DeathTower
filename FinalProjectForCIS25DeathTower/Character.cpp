//
//  Character.cpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#include "Character.hpp"
#include "Monsters.hpp"
void Character:: setHP(int damage){
    
    HP = HP - damage;
    
    if(HP<=0){
        HP = 0;
        alive = false;
    }
   
}

void Character:: setMP(){

    
    
    MP = MP - this->getSkill()->getMPperSkill();
    
    

}

void Character:: changeEquipment(Equipment *eq){
    
    string EqKind = eq->getKind();
    
    string newEquipmentName;
    
    string newEquipmentKind;
    
    int newEquipmentValue;
    
    if (EqKind == this->getWeapon()->getKind()) {
        
        delete weapon;
        
        newEquipmentName = eq->getName();
        
        newEquipmentKind = eq->getKind();
        
        newEquipmentValue = eq->getValue();
        
        weapon = new Weapon(newEquipmentName, newEquipmentKind, newEquipmentValue);
        
        setAttackStrenth();
        
        cout<<"Sucess changed the Weapon"<<endl;
    }
    else if(EqKind == this->getArmor()->getKind()){
    
        delete armor;
        
        newEquipmentName = eq->getName();
        
        newEquipmentKind = eq->getKind();
        
        newEquipmentValue = eq->getValue();
        
        armor = new Armor(newEquipmentName,newEquipmentValue);
        
        cout<<"Sucess changed the Armor"<<endl;
    
    }
    else{
        cout<<"Unkonwn Error when changing equipment: "<<EqKind<<endl;
    
    }


};
bool Character:: killMonster(Monsters* ms){
    
    if(!this->getAliveState()){
        
        cout<<"You have been killed by the Monster"<<endl;
        
        return true;
    }
    
    else{
        
    bool monsterDead;
    
    string order;
    
    char od = '\0';
    
    bool incorrectOrder = true;
    
    while (incorrectOrder) {
    
    cout<<"A. attack ";
    
    cout<<"D. dodge ";
    
    cout<<"S. skill ";
    
    cout<<"C. suicide "<<endl;
    
    
    getline(cin,order);
    
     od = order[0];
    
        if(od=='A'||od=='D'||od=='S'||od=='C'||
           od=='a'||od=='d'||od=='s'||od=='c'){
    
           incorrectOrder = false;
        }
        else{
            cout<<"Incorrect order, try again"<<endl;
        }
    }
    
    monsterDead = expainOrder(od, ms);
    
    return monsterDead;
    }
}
bool Character:: expainOrder(char ch, Monsters* ms){
    
    if(ch == 'A'||ch == 'a'){
    
        return normalAttack(ms);
    
    }
    
    if(ch == 'D'||ch=='d'){
        
        return douge(ms);
        
    }
    if(ch == 'S'||ch == 's'){
        
        return skillAttack(ms);
    
    }
    if(ch == 'C'||ch=='c'){
        
        return commitSuicide(ms);
    
    }

    return nullptr;
}
bool Character:: normalAttack(Monsters* ms){
    
    ms->setHP(this->getAttackStrength());
    
    cout<<"You use "<<this->getWeapon()->getName()
    
        <<" attack "<<ms->getName()
    
    <<", and give it "<<this->getAttackStrength()<<" damage"<<endl;

    return ms->getAlive();

}
bool Character:: skillAttack(Monsters* ms){
    
    if((MP - this->getSkill()->getMPperSkill())>0){
        
        setMP();
    
    ms->setHP(this->getSkill()->getDamage());
        
        cout<<"You use the skill"<<this->getSkill()->getName()
        
            <<" attacks "<<ms->getName()
        
        <<" and give it "<<this->getSkill()->getDamage()<<" damage"<<endl;
        
        
    }
    else{
        cout<<"When you are trying to use the skill, you feel dazzle, you are lacking of mana"<<endl;
    
        cout<<"You missed this attack chance"<<endl;
    }
    return ms->getAlive();
}

bool Character:: douge(Monsters* ms){

    cout<<"You are trying to douge the monster's coming attack. "<<endl;
    
    cout<<"But the monster seems smarter than you."<<endl;
    
    cout<<"Next time you still under attack"<<endl;
    
    //Ok, I confess I don't know how to write this funtion...
    
    return ms->getAlive();

}

bool Character:: commitSuicide(Monsters* ms){

    this->setLiveState(false);
    
    cout<<"You killed youself to feed the monster"<<endl;

    return ms->getAlive();
}

