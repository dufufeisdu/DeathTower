//
//  Armor.hpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#ifndef Armor_hpp
#define Armor_hpp

#include <stdio.h>
#include "Equipment.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Armor: public Equipment{

private:
    
    string name;
    
    string kind;
    
    int defence;
    
public:
    
    Armor():Equipment(){}
    
    Armor(string name,int defence):Equipment(){
    
        this->name = name;
        
        this->defence = defence;
        
        kind = "Armor";
    
    }
    Armor(int code):Equipment(){
        
        fstream ap;
        
        ap.open("armorList.txt",ios::in);
        
        if(ap){
            string armorCode;
            
            string armorName;
            
            string armorDefence;
            
            string wholeLine;
            
            for(int line = 1;line <= code; ++line){
                
                getline(ap,wholeLine);
                
            }
            armorCode = getData(wholeLine);
            
            armorName = getData(wholeLine);
            
            armorDefence = getData(wholeLine);
            
            ap.close();
            
            name = armorName;
            
            defence = stoi(armorDefence);
            
            kind = "Armor";
    
        }
        else{
            
            cout<<"Can not open file WeaponList.txt when new a weapon "<<endl;
        }
        
    }

    virtual void getInfo(){
        
        cout<<"Name:"<<name<<endl;
        
        cout<<"Kind:"<<kind<<endl;
        
        cout<<"Defence power:"<<defence<<endl;
        
    
    
    }
    virtual string getName(){
    
        return name;
    }
    
    int getDefence(){
    
        return defence;
    }
    virtual string getKind(){
    
        return kind;
    }
    virtual int getValue(){
    
        return defence;
    }
    string getData(string &str);
};
#endif /* Armor_hpp */
