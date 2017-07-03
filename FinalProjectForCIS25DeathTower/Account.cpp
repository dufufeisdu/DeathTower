//
//  Account.cpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#include "Account.hpp"

//Newly create a Hero;

void Account::setHero(int HeroCode){

    
    if(HeroCode == 1){
        
        Skill* skill = new Skill("Sword Dance", 100, 20);
        
        Weapon * weapon = new Weapon("Rusty Sword","sword", 10);
        
        Armor * armor = new Armor("Outdated Light Armer",50);
    
        hero = new Character("BladeMaster",500,100,500, skill, weapon, armor);
    
    }
    else if(HeroCode == 2){
        
        Skill* skill = new Skill("Summon Nen Dragon", 150, 30);
        
        Weapon * weapon = new Weapon("Rusty Knuckle","knuckle", 20);
        
        Armor * armor = new Armor("Outdated colth Armer",40);
        
        hero = new Character("NenMaster",400,200,400, skill, weapon, armor);
        
    }
    else if(HeroCode == 3){
        
        Skill* skill = new Skill("IceWall", 200, 40);
        
        Weapon * weapon = new Weapon("Rusty Staff","staff", 30);
        
        Armor * armor = new Armor("Outdated colth Armer",30);
        
        hero = new Character("Elementlist",300,300,300, skill, weapon, armor);
        
    }
    else if(HeroCode == 4){
        
        Skill* skill = new Skill("Summon Satellite Laser", 250, 50);
        
        Weapon * weapon = new Weapon("Rusty HandGun","autogun", 40);
        
        Armor * armor = new Armor("Outdated colth Armer",20);
        
        hero = new Character("Mechanic",200,400,200, skill, weapon, armor);
        
    }
    else{
        //This code should never be executed.
        cout<<"Unkown Mistake with HeroCode Equals "<<HeroCode<<endl;
    
    }

}

//read information from accountFile;
void Account::setHero(){
    
    accountFile.open(name,ios::in);
    
    string heroName;   //0
    
    string HP;         //1
    
    string MP;         //2
    
    string defence;    //3
    
    string skillName;  //4
    
    string skillPower;  //5
    
    string MPperSkill;  //add1
    
    string weaponName;  //6
    
    string weaponKind; //add2
    
    string weaponPower; //7
    
    string armorName;   //8
    
    string armorPower;  //9
    
    if(accountFile){
        
        string psWd;   //ignor
  
        getline(accountFile,psWd);
        
        getline(accountFile,heroName);  //0
        
        getline(accountFile,HP);        //1
        
        getline(accountFile,MP);        //2
        
        getline(accountFile,defence);   //3
        
        getline(accountFile,skillName); //4
        
        getline(accountFile,skillPower);//5
        
        getline(accountFile,MPperSkill);//add1
        
        getline(accountFile,weaponName);//6
        
        getline(accountFile,weaponKind);//add2
        
        getline(accountFile,weaponPower);//7
        
        getline(accountFile,armorName); //8
        
        getline(accountFile,armorPower);//9
        
        accountFile.close();
    }
    else{
        cout<<"In reading Exist Hero, fail to open file"<<endl;
    
    }
    
    Skill* skill = new Skill(skillName, stoi(skillPower),stoi(MPperSkill));
    
    Weapon * weapon = new Weapon(weaponName, weaponKind, stoi(weaponPower));
    
    Armor * armor = new Armor(armorName, stoi(armorPower));
    
    hero = new Character(heroName,stoi(HP),stoi(MP),stoi(defence),skill,weapon,armor);
}

void Account::save(){
    
//get information from Hero;
    
    string psWd;                                                    //null
    
    string heroName = hero->getName();                                  //0
    
    int HP = hero->getHP();                                             //1
    
    int MP = hero->getMP();                                             //2
    
    int defence = hero->getDefence();                                   //3
    
    string skillName = hero->getSkill()->getName();                     //4
    
    int skillPower = hero->getSkill()->getDamage()  ;                   //5
    
    int MPperSkill = hero->getSkill()->getMPperSkill();                 //add1
    
    string weaponName = hero->getWeapon()->getName();                   //6
    
    string weaponKind = hero->getWeapon()->getKind();                   //add2
    
    int weaponPower = hero->getWeapon()->getDamage();                   //7
    
    string armorName = hero->getArmor()->getName();                     //8
    
    int armorPower = hero->getArmor()->getDefence();                    //9
    
    accountFile.open(("/Users/fufeidu/Documents/workspace/FinalProjectForCIS25DeathTower/FinalProjectForCIS25DeathTower/"+name),ios::in);
    
    if (accountFile) {
        
        getline(accountFile,psWd);
        
        accountFile.close();
    }
    else{
        cout<<"Cannot open file at save funtion when reading password from "<<name<<endl;
    }
    accountFile.open(("/Users/fufeidu/Documents/workspace/FinalProjectForCIS25DeathTower/FinalProjectForCIS25DeathTower/"+name),ios::out);
    
    if (accountFile) {
        
        accountFile<<psWd<<endl;                      //null
        
        accountFile<<heroName<<endl;                //0
        
        accountFile<<HP<<endl;                      //1
        
        accountFile<<MP<<endl;                      //2
        
        accountFile<<defence<<endl;                 //3
        
        accountFile<<skillName<<endl;               //4
        
        accountFile<<skillPower<<endl;              //5
        
        accountFile<<MPperSkill<<endl;              //add1
        
        accountFile<<weaponName<<endl;              //6
        
        accountFile<<weaponKind<<endl;              //add2
        
        accountFile<<weaponPower<<endl;             //7
        
        accountFile<<armorName<<endl;               //8
        
        accountFile<<armorPower<<endl;              //9
        
        accountFile.close();
    }
    else{
        cout<<"Cannot open file at save funtion when writing to file "<<name<<endl;
    }
}

void Account:: showHeroInfo(){
    
    cout<<"Name:"<<hero->getName()<<endl;
    
    cout<<"HP:"<<hero->getHP()<<endl;
    
    cout<<"MP:"<<hero->getMP()<<endl;
    
    cout<<"Weapon:"<<hero->getWeapon()->getName()<<endl;
    
    cout<<"attackStrenth:"<<hero->getAttackStrength()<<endl;
    
    cout<<"Armor:"<<hero->getArmor()->getName()<<endl;
    
    cout<<"Skill:"<<hero->getSkill()->getName()<<endl;
    


}
Character* Account::getHero(){

    return hero;
}
