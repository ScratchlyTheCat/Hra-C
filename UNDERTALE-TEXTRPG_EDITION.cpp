#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

string begingame;
string playerclass;
char presstocontinue;

void ingame(){
    cout << endl << "Before the story may begin, you must pick your class." << endl;
    system("pause");
    cout << endl << "Please choose wisely as you will not be able to change it later on:" << endl;
    cout << endl << "CLASSES: SWORDSMAN, MECHATRON, PEACEBRINGER, DUSTSETTLER";
    cout << endl << "SWORDSMAN:| ATK-5| DEF-3| HP-20| NO MAGIC| 'Classic and reliable. Wields a simple sword.'"; //relies on you leveling up
    cout << endl << "MECHATRON:| ATK-2| DEF-8| HP-15| NO MAGIC| 'Benefits heavily from his own inventions.'"; //relies heavily on shop
    cout << endl << "PEACEBRINGER:| ATK-1| DEF-1| HP-50| 150 MANA| 'Peace brings him control.'"; //will roll better chances on his attacks the less hp the enemies have
    cout << endl << "DUSTSETTLER:| ATK-3| DEF-3| HP-10| 250 MANA| 'As the dust settles... He moves on.'"; //will gain a dmg and hp boost that stacks if you go to the next encounter right away
    cout << endl << "Enter your desired class:";
    do{
    cin >> playerclass;
    }while(!(playerclass == "SWORDSMAN" ||playerclass == "MECHATRON" ||playerclass == "PEACEBRINGER" ||playerclass == "DUSTSETTLER" ));

    if(playerclass == "SWORDSMAN"){
    cout << endl << "You have picked: SWORDSMAN." << endl;
    int atk = 5;
    int def = 3;
    int gold = 0;
    int maxhp = 20;
    int maxmana = 0;
    int LV = 1;
    }else if(playerclass == "MECHATRON"){
    cout << endl << "You have picked: MECHATRON." << endl;
    int atk = 2;
    int def = 8;
    int gold = 0;
    int maxhp = 15;
    int maxmana = 0;
    int LV = 1;
    }else if(playerclass == "PEACEBRINGER"){
    cout << endl << "You have picked: PEACEBRINGER." << endl;
    int atk = 1;
    int def = 1;
    int gold = 0;
    int maxhp = 50;
    int maxmana = 150;
    int LV = 1;
    }else if(playerclass == "DUSTSETTLER"){
    cout << endl << "You have picked: DUSTSETTLER" << endl;
    int atk = 3;
    int def = 3;
    int gold = 0;
    int maxhp = 10;
    int maxmana = 250;
    int LV = 1;
    }

    system("pause");
    system("cls");
    cout << endl << "STORY:";
    cout << endl << "Long ago... Two races ruled over earth: HUMANS AND MONSTERS" << endl;
    system("pause");
    cout << endl << "One day, war broke out between the two races." << endl;
    system("pause");
    cout << endl << "After a long battle, the humans were victorious." << endl;
    system("pause");
    cout << endl << "They sealed the monsters underground with a magic spell..." << endl;
    system("pause");
    cout << endl << "Many years later..." << endl;
    system("pause");
    cout << endl << "You came along, on MT EBOTT during 201X." << endl;
    system("pause");
    cout << endl << "Legends say that those who climb the mountain never return." << endl;
    system("pause");
    cout << endl << "Even so, you climbed it anyway, but of course..." << endl;
    system("pause");
    cout << endl << "You deeply regretted your decision as you fell down into the underground by accident." << endl;
    system("pause");
    cout << endl << "You felt a large thud, moments before you passed out." << endl;
    system("pause");
    cout << endl << "..." << endl;
    system("pause");
    cout << endl << "Suddenly, you woke up." << endl;
    system("pause");
    cout << endl << "Before you, stands a large pink arch with pillars." << endl;
    system("pause");
    cout << endl << "Everywhere else, darkness surrounds you..." << endl;
    system("pause");
    cout << endl << "You cannot do anything, but stand up, walk through, most likely beginning your adventure in..." << endl;
    system("pause");
    cout << endl;
    cout << endl << "ZONE 1 - RUINS";
    cout << endl;
    cout << endl << "TEST END" << endl;
    system("pause");
}

int main(){
    int monsters = 16;
    int miniboss = 2;
    int boss = 1;
    int village = 2;
    int atk = 0;
    int def = 0;
    int gold = 0;
    int maxhp = 20;
    int maxmana = 20;
    int LV = 0;

    cout << "Welcome to..." << endl;
    cout << "UNDERTALE: TEXTRPG EDITION" << endl;
    cout << "Begin game? [Y/N]" << endl;
    cin >> begingame;
    if(begingame == "Y"){
        int monsters = 16;
        int miniboss = 2;
        int boss = 1;
        int village = 2;
        int gold = 0;
        int maxhp = 20;
        int maxmana = 20;
        int LV = 0;
        ingame();
        }else{
        cout << endl << "Game exited!";
        }

}


