//
//  main.cpp
//  FinalProjectForCIS25DeathTower
//
//  Created by FUFEI DU on 11/26/16.
//  Copyright © 2016 FUFEI DU. All rights reserved.
//

#include <iostream>
#include "Armor.hpp"
#include "Weapon.hpp"
#include "Skill.hpp"
#include "Monsters.hpp"
#include "Account.hpp"
#include "Tower.hpp"
#include "Character.hpp"
#include "Equipment.hpp"
#include <string>

//change this path to where you store this files.
using namespace std;


    //***************************************************************************************************************
    //*Declear funcutions here
    //*
    //***************************************************************************************************************

void showLoadingMenu();

string loadGame();

bool checkAccount(string);

bool checkPassword(string,string);

string selectHero();

void showTowerOption();

int getRandNumber(int, int);

bool checkExistAccount(string,string);



int main(int argc, const char * argv[]) {
    
    //***************************************************************************************************************
    //*Some const varible
    //*
    //***************************************************************************************************************
    
    const int totalEquipmentKind = 2;
    
    const int totalArmerNumber = 10;
    
    const int totalWeaponNumber = 12;
    
    const int totalTowerFloors = 100;
    
    const string location = "/Users/fufeidu/Documents/workspace/FinalProjectForCIS25DeathTower/FinalProjectForCIS25DeathTower/";
    
    //creat a accout point
    Account *account = nullptr;
    
    
    //store the order from the user
    string order;
    
    //store bool value for checking the order from customer
    bool incorrectOrder = true;
    
    //check the loadGame function Input
    while (incorrectOrder) {
        
        try {
            order = loadGame();
            
            incorrectOrder = false;
            
        } catch (string ex) {
            
            cout<<ex<<" is not a valid command!"<<endl;
        }
    }
    
    //If user select "1", it will newly creat an account
    
    if(order == "1"){
        
        bool IncorrectAccount = true;
        
        string accountName ;
        
        string passWord ;
        
        while (IncorrectAccount) {
            
            cout<<"Account:";
            
            getline(cin,accountName);
            
            accountName+=".txt";
            
            cout<<"Password:";
            
            getline(cin,passWord);
            
            //To aovid user select the same name
            
            IncorrectAccount = checkAccount(accountName);
            
            if (IncorrectAccount) {
                
                cout<<"Already Existed Account Name, Choose Another One"<<endl;
            }
            else{
            
                IncorrectAccount = false;
            }
        }
        
        account = new Account(accountName,passWord);
        
        //***************************************************************************************************************
        //*An account must contains a character
        //*setup the character for new palyer
        //***************************************************************************************************************

        incorrectOrder = true;
        
        while (incorrectOrder) {
            
            try {
                order = selectHero();
                
                incorrectOrder = false;
                
            } catch (string ex) {
                
                cout<<ex<<" is not a valid command!"<<endl;
            }
        }
        
        // There are four heros can be selcted
        // heroCode will store the code of different hero.
        
        int heroCode = stoi(order);
        
        account->setHero(heroCode);
        
        account->save();
        
        account->showHeroInfo();
  
    }
    //If user select "2", it will check the existing account
    
    else if(order == "2"){
        
        bool IncorrectAccount = true;
        
        bool IncorrectPassword = true;
        
        string accountName ;
        
        string passWord ;
        
        while (IncorrectAccount) {
            
            cout<<"Account:";
            
            getline(cin,accountName);
            
            //account stored at a .txt file.
            accountName+=".txt";
            
            cout<<"Password:";
            
            getline(cin,passWord);
            
            //checkAccoutn() will return false if file exist, true if not.
            
            IncorrectAccount = checkExistAccount(accountName,passWord);
            
            
        
        }
        
        account = new Account(accountName,passWord,accountName);
        
        account->setHero();
        
        account->showHeroInfo();
        
        
        
    }
    //If user selct 3 the game will over.
    
    else if(order == "3"){
        
        cout<<"GOODBYE!!"<<endl;
        
        delete account;
        
        return 0;
    }
    
    // For developer test, in case unknown bug.
    else{
        cout<<"unknown error about this order:"<<order<<endl;
        
        
        return 0;
    }
    
    
    //game start here
    

    incorrectOrder = true;
    
    while (incorrectOrder) {
        
        showTowerOption();
        
        getline(cin,order);
        
        if(order == "1"||order=="2"){
            
            incorrectOrder = false;
            
        }
        else{
            cout<<"Incorrect order, try again"<<endl;
        }
    
    }
    
    
        
if(order == "1"){
        
    Tower deathTower(account->getHero(),totalTowerFloors);
    
    deathTower.resetHero();
    
    deathTower.showTowerInfo();
    
    for (int stair = 1; stair<=totalTowerFloors; ++stair) {
        
        deathTower.setStorey(stair);
        
        deathTower.showTowerInfo(stair);
        
        deathTower.setMonster(stair);
        
        deathTower.getMonster()->showInfo();
        
        deathTower.fight();
        
        if (deathTower.defeat()) {
            
            deathTower.generateEquipment();
            
            deathTower.showEquipmentInfo();
            
            deathTower.equipable();
            
        }
        else{
            cout<<"You are killed by the Monster"<<endl;
            
            cout<<"You soul is so weak that "<<endl;
            
            cout<<"the grim reaper kicks you out of the tower";
            
            break;
          
        }
        account->save();
        
        
    }
    delete account;
}
else if(order == "2"){
    
    cout<<"GoodBye!"<<endl;
    
    delete account;
    
    return 0;
}
else{
    
    cout<<"Unknown Error with the order:"<<order<<endl;

}
    
    return 0;
}


/*------------------------------Defination of funtions---------------------------------------------------------*/



//***************************************************************************************************************
//Show the game information to let user select                                                                   *
//Three optinons as shown below                                                                                 *
//***************************************************************************************************************
string loadGame(){
    
    string order;
    
        cout<<"Welcome to the Death Tower"<<endl;
        cout<<"1. Create a New Hero"<<endl
        <<"2. Load an Exist Hero"<<endl
        <<"3. Quit Game"<<endl;
        
        getline(cin,order);
        
    
    if(order=="1"||order=="2"||order=="3"){
        
        return  order;
    }
    else{
        throw  order;
    }
}

//***************************************************************************************************************
//Show the heros for users                                                                                      *
//Four options as shown below                                                                                   *
//***************************************************************************************************************
string selectHero(){
    
    string order;
    
    cout<<"Please select a Hero:"<<endl;
    cout<<"1.BladeMaster"<<endl;
    cout<<"2.NenMaster"<<endl;
    cout<<"3.Elementlist"<<endl;
    cout<<"4.Mechanic"<<endl;
    
    getline(cin,order);
    
    if(order=="1"||order=="2"||order=="3"||order=="4"){
        
        return order;
    }
    else{
        throw  order;
    }
}

//***************************************************************************************************************
//Check whether the accounts file exist                                                                         *
//Return false if exist                                                                                          *
//Return true if not exist
//***************************************************************************************************************
bool checkAccount(string accountName){
    
    fstream FileName;
    
    FileName.open("/Users/fufeidu/Documents/workspace/FinalProjectForCIS25DeathTower/FinalProjectForCIS25DeathTower/"+accountName,ios::in);
    
    if (FileName) {
        
        FileName.close();
        
        return true;
    }
    
    else {
     
        return false;
    }

}

//***************************************************************************************************************
//* Check whether the password are correct
//* Password is stored at the first line of the file
//* Retrun FALSE if it is CORRECT(becuase the bool variable is incorrectpasswrd)
//***************************************************************************************************************

bool checkPassword(string accountName,string password){

    fstream FileName;
    
    string pw;
    
    FileName.open("/Users/fufeidu/Documents/workspace/FinalProjectForCIS25DeathTower/FinalProjectForCIS25DeathTower/"+accountName,ios::in);
    
    getline(FileName,pw);
    
    FileName.close();
    
    if (pw == password) {
        
        return false;
    }
    else{
    
        return true;
    }
    
}

//***************************************************************************************************************
//* A simple show funtion
//* Two options
//***************************************************************************************************************
void showTowerOption(){
    
    cout<<"Choose an option:"<<endl;
    
    cout<<"1.Enter the Death Tower "<<endl;
    
    cout<<"2.Quit the Game"<<endl;
}

//***************************************************************************************************************
//* A random number generater
//* input max value and min value
//* Output a random value between max and min
//***************************************************************************************************************

int getRandNumber(int max, int min){
    
    int randNumber = 0;
    
    srand(static_cast<unsigned>(time(0)) );
    
    randNumber = rand()%(max - min + 1) + min;
    
    return randNumber;

    
}

//***************************************************************************************************************
//* Check the exist Account
//* If Account does not exist, return true(For bool incorrectAccount)
//* If Account PassWord not right return true
//* If Account match return false;
//***************************************************************************************************************

bool checkExistAccount(string accountName,string password){
    
    fstream FileName;
    
    FileName.open("/Users/fufeidu/Documents/workspace/FinalProjectForCIS25DeathTower/FinalProjectForCIS25DeathTower/"+accountName,ios::in);
    
    if (FileName) {
        
        string ps;
        getline(FileName,ps);
        
        if(ps == password){
            
            cout<<"Load Success!"<<endl;
            
            FileName.close();
            
            return false;
        }
        else{
            
            cout<<"Incorrect Password"<<endl;
            
            
            FileName.close();
            
        return true;
        }
        
    }
    
    else {
        
        cout<<"Incorrect Account"<<endl;
        
        return true;
    }

    
}






