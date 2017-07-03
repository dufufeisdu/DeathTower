//
//  Weapon.hpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include <stdio.h>
#include "Equipment.hpp"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;



class Weapon:public Equipment{
private:
    
    
    string name;
    
    string kind;
    
    int damage;
    
public:
    Weapon(){};
    Weapon(string name, string kind, int damage){
    
        this->name = name;
        
        this->damage = damage;
        
        this->kind = kind;
    
    }
    
    Weapon(int code):Equipment(){
    
        fstream wp;
        
        wp.open("weaponList.txt",ios::in);
        
        if(wp){
            string Weaponcode;
            
            string weaponName;
            
            string weaponKind;
            
            string weaponDamage;
        
            string wholeLine;
            
            for(int line = 1;line <= code; ++line){
            
            getline(wp,wholeLine);
                
            }
            Weaponcode = getData(wholeLine);
            
            weaponName = getData(wholeLine);
            
            weaponKind = getData(wholeLine);
            
            weaponDamage = getData(wholeLine);
            
            wp.close();
            
            name = weaponName;
            
            kind = weaponKind;
            
            damage = stoi(weaponDamage);
            
            
        
        }
        else{
            
            cout<<"Can not open file WeaponList.txt when building weapon "<<endl;
        }
    
    }
    
    virtual void getInfo(){
    
        cout<<"Name:"<<name<<endl;
        
        cout<<"Kind:"<< kind<<endl;
        
        cout<<"Damage:"<<damage<<endl;
    
    }
    int getDamage(){
    
        return damage;
    
    }
    
    virtual string getKind(){
    
    
        return kind;
    }
    
    virtual string getName(){
    
        return name;
    }
    virtual int getValue(){
        
        return damage;
        
    }

    string getData(string &str);
};
#endif /* Weapon_hpp */
