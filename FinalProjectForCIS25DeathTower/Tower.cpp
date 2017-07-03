//
//  Tower.cpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#include "Tower.hpp"

void Tower::showTowerInfo(){
    cout<<"Yes, as you can see, I'm the grim reaper. No need to fear; I don't take lives indiscriminately. I've gathered the world's most powerful monsters in one place at this tower. What do you say? Aren't your instincts telling you to take on this challenge? If you manage to fight through those warriors and arrive at the top of this tower, all the world will know your strength. Of course, I'll be there waiting in case you crash and burn..."<<endl;
}

void Tower:: showTowerInfo(int stair){

    cout<<"The "<<stair<<" floor"<<endl;

}
void Tower::resetHero(){

    hero->setLiveState(true);

}
string Tower::getData(string &str){
    
    string target;
    
    unsigned long dp = str.find(" ");

    target = str.substr(0,dp);
    
    str = str.substr(dp+1,str.length());

    return target;
}
void Tower:: setMonster(int floor){
    
    
 //Skill(string name,int damage, int MPperSkill)
//Monsters(string name, int HP, int attackForce, Skill *skill)
    
    floor = floor%10 + 1;
    
    fstream dataReading;
    
    Skill *sk;
    
    string skillName;
    
    int skillDamage = 0;
    
    int MPperSkill = 0;
    
    string monsterName;
    
    int monsterHP = 0;
    
    int monsterAttackForce = 0;
    
    int skillCode = 0;
    
    dataReading.open("monsterList.txt",ios::in);
    
    if (dataReading) {
        
        string dataLine;
        
        for (int monsterOrder = 1; monsterOrder<=floor; monsterOrder++) {
            
            getline(dataReading,dataLine);
        }
        string order = getData(dataLine);
        
        
        
        monsterName = getData(dataLine);
        
        monsterHP = stoi(getData(dataLine));
        
        monsterAttackForce = stoi(getData(dataLine));
        
        skillCode = stoi(getData(dataLine));
        
        
        dataReading.close();
            
        
    }
    else{
        cout<<"Cannot open file when reading data from monsterList"<<endl;
    }
    
    dataReading.open("skillList.txt",ios::in);
    
    if (dataReading) {
        
        string dataLine;
        
        for (int skillOrder = 1; skillOrder<=skillCode; ++skillOrder) {
            
            getline(dataReading,dataLine);
        }
        
        string order = getData(dataLine);
        
        if(stoi(order) == skillCode){
            
            skillName = getData(dataLine);
            
            skillDamage = stoi(getData(dataLine));
            
            MPperSkill = stoi(getData(dataLine));
            
        }
        else{
            cout<<"Error when reading from skillList"<<endl;
            cout<<"skillCode  = "<<skillCode<<endl;
            cout<<"skillOrder in file = "<<order<<endl;
        }
        
        dataReading.close();
        
        
    }
    else{
        cout<<"Cannot open file when reading data from monsterList"<<endl;
        
        
    }
    
    sk = new Skill(skillName,skillDamage,MPperSkill);
   
    monster = new Monsters(monsterName,monsterHP,monsterAttackForce,sk);

}
int Tower:: getRandNumber(int max, int min){
    
    int randNumber = 0;
    
    srand(static_cast<unsigned>(time(0)) );
    
    randNumber = rand()%(max + 1 - min) + min;
    
    return randNumber;
    
    
}

void Tower::fight(){
    
    while(monster->getAlive()&&hero->getAliveState()){
        
    bool useSkill;
    // the higher floor the higher chance Monster use skill.
    int testNumber = getRandNumber(totalStrey, 0);
    
    if(testNumber>storey){
        
        useSkill = false;
        
    }
    else{
        
        useSkill = true;
    
    }
    
    hero->killMonster(monster);
        
    monster->killHero(hero, useSkill);

    
        
    }

}
bool Tower:: defeat(){
    
    if(monster->getAlive()==false&&hero->getAliveState()==true){
        
        return true;
    }
    else{
        return false;
    }
}
void Tower:: generateEquipment(){

   equipment =  monster->dropEquipment();
}

void Tower:: showEquipmentInfo(){
    
    equipment->getInfo();

}

void Tower:: changeEquipment(){

    bool notChange = true;
    
    string order;
    
    while (notChange) {
        
        cin>>order;
        
        if(order == "Y"||order=="N"||order=="n"||order=="y"){
        
            notChange = false;
        }
        else{
            cout<<"Incorrect order"<<endl;
            
            cout<<"You got an equitpable equipment, do you want to change? Y/N"<<endl;
        }
    }
    if (order=="Y"||order=="y") {
        
        hero->changeEquipment(equipment);
    }
    else{
    
        cout<<"The hero choose not to change the Equipment, so he throw it back to the Monster "<<endl;
        
        delete equipment;
        
        equipment = nullptr;
    
    }

}

void Tower:: equipable(){
 
    bool canEquipt = ((equipment->getKind() == hero->getArmor()->getKind()) || (equipment->getKind() == hero->getWeapon()->getKind() ));
    
    if(canEquipt){
    
        cout<<"Currently, your equipments are:"<<endl;
        
        hero->getArmor()->getInfo();
        
        hero->getWeapon()->getInfo();
        
        cout<<"You got an equitpable equipment, do you want to change? Y/N"<<endl;
        
        changeEquipment();
        
    }
    else{
        cout<<"Our hero got an "<<equipment->getKind()<<endl;
        
        cout<<"What he need is "<<hero->getWeapon()->getKind()<<endl;
        
        cout<<"The equipment is not suitable for our Hero, so he throw it back to the monster"<<endl;
        
        delete equipment;
        
        equipment = nullptr;
    
    }

}


