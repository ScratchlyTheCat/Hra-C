#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

string begingame;
int playerclass;
char presstocontinue;
int monsters = 16;
int miniboss = 2;
int boss = 1;
int village = 2;
int atk = 0;
int def = 0;
int gold = 0;
int maxhp = 20;
int hp = maxhp;
int maxmana = 20;
int mana = maxmana;
int worldprogress = 0;
int currentmap;
int maxmap;
int randomevent;
int LV = 0;

int emptyy;

void setstats(int selecting, int chosen){

if(selecting == 1){

    switch(chosen){
    case 1:{
    cout << endl << "You have picked: SWORDSMAN." << endl;
    atk = 5;
    def = 3;
    gold = 0;
    maxhp = 20;
    hp = maxhp;
    maxmana = 0;
    mana = maxmana;
    LV = 1;
    break;
    }
    case 2:{
    cout << endl << "You have picked: MECHATRON." << endl;
    atk = 2;
    def = 8;
    gold = 0;
    maxhp = 15;
    hp = maxhp;
    maxmana = 0;
    mana = maxmana;
    LV = 1;
    break;
    }
    case 3:{
    cout << endl << "You have picked: PEACEBRINGER." << endl;
    atk = 1;
    def = 1;
    gold = 0;
    maxhp = 50;
    hp = maxhp;
    maxmana = 150;
    mana = maxmana;
    LV = 1;
    break;
    }
    case 4:{
    cout << endl << "You have picked: DUSTSETTLER" << endl;
    atk = 3;
    def = 3;
    gold = 0;
    maxhp = 10;
    hp = maxhp;
    maxmana = 250;
    mana = maxmana;
    LV = 1;
    break;
    }
    default:
        playerclass = 0;
        cout << endl << "What you have entered is wrong. Please re-enter your class." << endl;
    system("pause");
    system("cls");
    cout << endl << "CLASSES: SWORDSMAN, MECHATRON, PEACEBRINGER, DUSTSETTLER";
    cout << endl << "1|SWORDSMAN:| ATK 5| DEF 3| HP 20| NO MAGIC| 'Classic and reliable. Wields a simple sword.'"; //relies on you leveling up
    cout << endl << "2|MECHATRON:| ATK 2| DEF 8| HP 15| NO MAGIC| 'Benefits heavily from his own inventions.'"; //relies heavily on shop
    cout << endl << "3|PEACEBRINGER:| ATK 1| DEF 1| HP 50| 150 MANA| 'Peace brings him control.'"; //will roll better chances on his attacks the less hp the enemies have
    cout << endl << "4|DUSTSETTLER:| ATK 3| DEF 3| HP 10| 250 MANA| 'As the dust settles... He moves on.'"; //will gain a dmg and hp boost that stacks if you go to the next encounter right away
    cout << endl << "Enter your desired class:";
    cin >> playerclass;
    setstats(1, playerclass);
        break;
}
}
}

void battle(){

}

void goldfound(int &goldies, int random){
    srand(time(0));
    random = rand() % 10 + 1;
    goldies = gold + random;
    cout << endl << "On your way, you found: " << random << " gold!" <<  endl;
}

void ingame(){
    cout << endl << "Before the story may begin, you must pick your class." << endl;
    cout << endl << "Please choose carefully as you will not be able to change it later." << endl;
    cout << endl << "Enter any number linked with the class you like." << endl;
    cout << endl << "CLASSES: SWORDSMAN, MECHATRON, PEACEBRINGER, DUSTSETTLER";
    cout << endl << "1|SWORDSMAN:| ATK 5| DEF 3| HP 20| NO MAGIC| 'Classic and reliable. Wields a simple sword.'"; //relies on you leveling up
    cout << endl << "2|MECHATRON:| ATK 2| DEF 8| HP 15| NO MAGIC| 'Benefits heavily from his own inventions.'"; //relies heavily on shop
    cout << endl << "3|PEACEBRINGER:| ATK 1| DEF 1| HP 50| 150 MANA| 'Peace brings him control.'"; //will roll better chances on his attacks the less hp the enemies have
    cout << endl << "4|DUSTSETTLER:| ATK 3| DEF 3| HP 10| 250 MANA| 'As the dust settles... He moves on.'"; //will gain a dmg and hp boost that stacks if you go to the next encounter right away
    cout << endl << "Enter your desired class:";
    cin >> playerclass;

    setstats(1, playerclass);

    int monsters = 4;
    int miniboss = 0;
    int boss = 0;
    system("pause"); //čeká na input klávesnice
    system("cls"); // smaže text z cmd
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
    system("cls");
    cout << endl;
    cout << endl << "ZONE 1 - RUINS";
    currentmap = 0;
    maxmap = 25;
    cout << endl;
    cout << endl << "You stand infront of a room with two staircases leading up to a large doorway." << endl;
    system("pause");
    cout << endl << "Walking through, you find yourself in a pink maze made of bricks with many halls that contain enemies." << endl;
    system("pause");
    cout << endl << "Your only way out is through here." << endl;
    system("pause");
    cout << endl << "And so... You march on." << endl;
    system("pause");
    system("cls");
    do{ // cykl chození
        cout << endl << "You continue walking through. Your current progress is: " << currentmap << "/" << maxmap << "." <<  endl;
        cout << endl << "Your current statistics are:" <<  endl;
        cout << endl << "ATK | " << atk <<  endl;
        cout << endl << "DEF | " << def <<  endl;
        cout << endl << "GOLD | " << gold <<  endl;
        cout << endl << "HP | " << hp << "/" << maxhp <<  endl;
        cout << endl << "MANA | " << mana << "/" << maxmana <<  endl;
        cout << endl << "LV | " << LV <<  endl;
        srand(time(0));  // inicializace generátoru náhodných čísel
        randomevent = rand() % 100 + 1;  // čísla od 0 až do 100
        system("pause");
        currentmap++;
        if(randomevent >= 0 && randomevent <= 20){
            battle();
            cout << endl << "BATTLE INITIATE!...Oh wait, theres no battle function yet." << endl;
            system("pause");
            system("cls");
        }
        if(randomevent > 20 && randomevent <= 80){
            battle();
            cout << endl << "Nothing interesting occured." << endl;
            system("pause");
            system("cls");
        }
        if(randomevent > 80 && randomevent <= 100){
            goldfound(gold, emptyy);
            system("pause");
            system("cls");
        }
    }while(currentmap != maxmap);
    worldprogress++;
    system("cls");
    cout << endl << "DEMO END" << endl;
}

int main(){
    cout << "Welcome to..." << endl;
    cout << "UNDERTALE: TEXTRPG EDITION" << endl;
    cout << "Begin game? [Y/N]" << endl;
    cin >> begingame;
    if(begingame == "Y"){
        ingame();
        }else{
        cout << endl << "Game exited!";
        }

}
