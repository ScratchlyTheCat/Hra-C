#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

string begingame;
int playerclass;
int monsters = 4;
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
int worldprogress = 1;
int currentmap = 1;
int maxmap = 0;
int randomevent = 0;
int LV = 0;
string inventory[6];
int invsize = 6;

int emptyy = 0;
//---------------------------------------------------------------------------------------------------------------------------------------------------------
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
    selecting = 0;
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
    selecting = 0;
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
    selecting = 0;
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
    selecting = 0;
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
}else{
cout << "test";
}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
void itemuse(int item){
    cout << endl << "Item test" << endl;
    system("pause");
    system("cls");
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
void battle(string monster = "", int monsternum = 0){

int monsteramount = 1;
srand(time(0));
monsteramount = rand() % 3 + 1;
int monsters_erased = monsteramount;
int monsteratk = 1;
int monsterhp = 1;
int monstercurrenthp = 1;
int monstermax = 1;
int g_reward = 1;
int mana_reward = 1;
int hp_reward = 1;
int battleon = 1;
int option = 1;

int randatk = 1;
int randesc = 1;
int itemselected = 1;
int randatkm = 1;

    system("cls");
    srand(time(0));
    monsternum = rand() % 3 + 1;
    monstermax = worldprogress;
    switch(monsternum){ //setting statistics of monster depending on world from weakest to strongest
case 1:
    srand(time(0));
    monsterhp = rand() % monstermax + 1;
    monsterhp = monsterhp*6;
    monsteratk = rand() % monstermax + 1;
    g_reward = rand() % monstermax + 1;
    g_reward = g_reward*20;
    mana_reward = rand() % monstermax + 1;
    mana_reward = mana_reward*10;
    hp_reward = rand() % monstermax + 1;
    hp_reward = hp_reward*10;
    monstercurrenthp = monsterhp;
    monster = "weak monster.";
    break;
case 2:
    srand(time(0));
    monsterhp = rand() % monstermax + 1;
    monsterhp = monsterhp*12;
    monsteratk = rand() % monstermax + 1;
    monsteratk = monsteratk*2;
    g_reward = rand() % monstermax + 1;
    g_reward = g_reward*30;
    mana_reward = rand() % monstermax + 1;
    mana_reward = mana_reward*20;
    hp_reward = rand() % monstermax + 1;
    hp_reward = hp_reward*20;
    monstercurrenthp = monsterhp;
    monster = "strong monster.";
    break;
case 3:
    srand(time(0));
    monsterhp = rand() % monstermax + 1;
    monsterhp = monsterhp*24;
    monsteratk = rand() % monstermax + 1;
    monsteratk = monsteratk*3;
    g_reward = rand() % monstermax + 1;
    g_reward = g_reward*40;
    mana_reward = rand() % monstermax + 1;
    mana_reward = mana_reward*30;
    hp_reward = rand() % monstermax + 1;
    hp_reward = hp_reward*30;
    monstercurrenthp = monsterhp;
    monster = "very strong monster.";
    break;
default:
    break;
    }
    cout << "You have encountered a " << monster << endl;
    while(battleon == 1){ //fighting loop
        cout << endl << "The monsters current statistics are:" << endl;
        cout << endl << monstercurrenthp << "/" << monsterhp << "|HP" << endl;
        cout << endl << monsteratk << "|ATK" << endl << endl;
        cout << endl << "What do you do?" << endl;
    cout << endl << "| 1=FIGHT | 2=ITEM | 3=ESCAPE |" << endl;
    cin >> option;
        switch(option){
    case 1:{
        randatk = rand() % atk + 1;
        cout << endl << "You dealt: " << randatk << " damage." << endl;
        monstercurrenthp = monstercurrenthp - randatk;
        cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
        system("pause");

        randatkm = rand() % monsteratk + 1;
        cout << endl << "It dealt: " << randatkm << " damage." << endl;
        hp = hp - randatkm;
        cout << endl << "You have: " << hp << "/" << maxhp << " HP" << endl;
        system("pause");
        system("cls");
    break;
    }
    case 2:{
        cout << endl << "Which item do you wish to use?" << endl;
        cout << endl << "Your current items are:" << endl;
        for(int i; i<=invsize; i++){
            cout << "Item " << i << ": " << inventory[i] << endl;
        }
        cin >> itemselected;
        itemuse(itemselected);
    break;
    }
    case 3:{
        randesc = rand() % monstermax*100 + 1;
        if(randesc <= 40){
            cout << endl << "You escaped and left empty handed!" << endl;
            battleon = 0;
            g_reward = 0;
            hp_reward = 0;
            mana_reward = 0;
        }else{
        cout << "You did not escape. The monster attacked you instead.";
        randatkm = rand() % monsteratk + 1;
        cout << endl << "It dealt: " << randatkm << " damage." << endl;
        hp = hp - randatkm;
        cout << endl << "You have: " << hp << "/" << maxhp << " HP" << endl;
        system("pause");
        system("cls");
        }
    break;
    }
    default:
        cout << endl << "What you have entered is wrong. Please re-enter your option." << endl;
    system("pause");
    system("cls");
        break;
}
if(monstercurrenthp <= 0){
    monsteramount--;
    if(monsteramount <= 0){
    battleon = 0;
    monsters = monsters - monsters_erased;
    cout << endl << "You won! Your rewards are:" << endl;
    cout << endl << g_reward << " Gold." << endl;
    cout << endl << hp_reward << " Health." << endl;
    if(playerclass >= 2){
    cout << endl << mana_reward << " Mana." << endl;
    }
    system("pause");
    system("cls");
}else{
cout << endl << "You have encountered another monster of the same type!" << endl;
monstercurrenthp = monsterhp;
}
}

if(hp <= 0){
    battleon = 0;
    cout << endl << "You lost." << endl;
}
}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
void store(string inventory[], int invsize, int gold, int worldprogress){
int inshop = 0;
system("cls");
cout << endl << "Welcome to the shop!" << endl;
cout << endl << "GOLD | " << gold <<  endl;
cout << endl << "ITEMS | VVV |" << endl;
        for(int i = 0; i+1<=invsize; i++){
            cout << "Item " << i +1 << ": " << inventory[i] << endl;
        }

cout << endl << "Do you wish to leave, or to buy? |1 (Buy) / 0 (Leave)|" << endl;
cin >> inshop;
while(inshop == 1){
switch(worldprogress){

case 1:{ //WORLD 1 ITEMS
int prices[9] = {5, 8, 12, 20, 15, 10, 25, 25, 15};
string shopitem[9] = {"|Healing Potion|", "|Mana Potion|", "|Weak Helmet|", "|Weak Chestplate|", "|Weak Leggings|", "|Weak Boots|", "|ATK Boost Ring|", "|DEF Boost Ring|", "|Weak Weapon|", };
int currentitem = 0;
cout << endl << "SHOP ITEMS | VVV |" << endl;
for(int i = 0; i+1<=prices[i]; i++){
            cout << "Price: " << prices[i] << " Gold =";
            cout << " Item " << i +1 << ": " << shopitem[i] << endl;
        }
    cout << endl << "Which item do you want to buy? (Insert from 1 to 9 to pick, insert anything else to cancel.)" << endl;
    cin >> currentitem;
    currentitem = currentitem-1;
    if(currentitem >= 0 && currentitem <= 9 && gold >= prices[currentitem]){
        int slot = 0;
        cout << endl << "Buying: " << shopitem[currentitem] << " for " << prices[currentitem];
        gold = gold - prices[currentitem];
        do{
        cout << endl << "Select which inventory slot to replace:" << endl;
        cin >> slot;
        }while(!(slot >= 1 && slot <= 6));
        slot--;
        inventory[slot] = shopitem[currentitem];
        setstats(0, playerclass);
        }else{
    cout << endl << "Buying cancelled!" << endl;
    system("pause");
    }
}
//WORLD 1 ITEMS

default:{
    break;
}
}
system("cls");
cout << endl << "GOLD | " << gold <<  endl;
cout << endl << "ITEMS | VVV |" << endl;
        for(int i = 0; i+1<=invsize; i++){
            cout << "Item " << i +1 << ": " << inventory[i] << endl;
        }
cout << endl << "Do you wish to leave, or to buy? |1 (Buy) / 0 (Leave)|" << endl;
cin >> inshop;
}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
void goldfound(int &goldies, int random){
    srand(time(0));
    random = rand() % worldprogress*10 + 1;
    goldies = gold + random;
    cout << endl << "On your way, you found: " << random << " gold!" <<  endl;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
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

    monsters = 4;
    miniboss = 0;
    boss = 0;
    system("pause"); //ceka na input klavesnice
    system("cls"); // smaze text z cmd
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
    do{ // cykl chozeni
        cout << endl << "You continue walking through. Your current progress is: " << currentmap << "/" << maxmap << "." <<  endl;
        cout << endl << "Your current statistics are:" <<  endl;
        cout << endl << "WORLD | " << worldprogress <<  endl;
        cout << endl << "ATK | " << atk <<  endl;
        cout << endl << "DEF | " << def <<  endl;
        cout << endl << "GOLD | " << gold <<  endl;
        cout << endl << "HP | " << hp << "/" << maxhp <<  endl;
        cout << endl << "MANA | " << mana << "/" << maxmana <<  endl;
        cout << endl << "LV | " << LV <<  endl;
        cout << endl << "ITEMS | VVV |" << endl;
        for(int i = 0; i+1<=invsize; i++){
            cout << "Item " << i +1 << ": " << inventory[i] << endl;
        }

        srand(time(0));  // inicializace generatoru nahodných cisel
        randomevent = rand() % 100 + 1;  // cisla od 0 až do 100
        system("pause");
        if(currentmap <= maxmap){
            currentmap++;
        }else{
        cout << endl << "You may have made it to the end, but there are still " << monsters << " monsters blocking your way." << endl;
        cout << endl << "You decide to run back to not get overwhelmed and beat them off one by one." << endl;
        currentmap = 0;
        system("pause");
        }

        if(randomevent >= 0 && randomevent <= 30){
            battle();
        }
        if(randomevent > 30 && randomevent <= 80){
            cout << endl << "Nothing interesting occured." << endl;
            system("pause");
            system("cls");
        }
        if(randomevent > 80 && randomevent <= 100){
            goldfound(gold, emptyy);
            system("pause");
            system("cls");
        }
    }while(!(currentmap == maxmap && hp >= 1 && monsters <= 0));
    system("cls");
    if(hp <= 0){
        cout << endl << "GAME OVER.";
    }
    worldprogress++;
    cout << endl << "In the distance, you see a small village." << endl;
    system("pause");
    cout << endl << "You think you might not make it out due to the number of monsters, but fortunately for you... These are friendly." << endl;
    system("pause");
    cout << endl << "You are unsure why, but you accept the warm embrace of this part of monsterkind nontheless." << endl;
    system("pause");
    cout << endl << "Walking through, you find yourself near a nice cozy shop and decide to check it out." << endl;
    system("pause");
    cout << endl << "You walk in the shop, and a familiar smile greets you." << endl;
    system("pause");
    cout << endl << "Michael: Ah! Good to see you pal. I see you've got yourself stuck down here too..." << endl;
    system("pause");
    cout << endl << "Michael: Dont worry buddy, i've got you covered, i already spoke to everyone around here." << endl;
    system("pause");
    cout << endl << "Michael: I've made a deal to fight against the evil part of their kind, and in return they let humans roam free here!" << endl;
    system("pause");
    cout << endl << "Michael: Honestly quite the miracle, i didn't believe it would work either but hey, im alive, so that's nice." << endl;
    system("pause");
    store(inventory, invsize, gold, worldprogress);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------


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
