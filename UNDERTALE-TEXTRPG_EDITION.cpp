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
int manaBOOST = 3;
int worldprogress = 1;
int areaprogress = 1;
int currentmap = 1;
int maxmap = 0;
int randomevent = 0;
int expcurrent = 0;
int expneed = 4;
int LV = 0;

int atkboost = 0;
string inventory[6][7]= {
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""}
};
int invsize = 6;

//7 statistics
//1 = NAME/ 2=+ATK/ 3=+DEF/ 4=ISHEAL>0 THEN +HEAL/ 5=ISMANA>0 THEN +MANA/ 6=SLOT/ 7=TYPE (0=LISTS +MANA OR +HEAL OR BOTH USING IF ELSE, 1=LISTS ATK AND DEF)

int emptyy = 0;
//---------------------------------------------------------------------------------------------------------------------------------------------------------
void setstats(int selecting, int chosen, int slot, int atk2 = 0, int def2 = 0){

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
    def = 4;
    gold = 20;
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
    def = 5;
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
    cout << endl << "1|SWORDSMAN:| ATK 5| DEF 3| HP 20| NO MAGIC| 'Classic and reliable. Wields a simple sword.'"; //relies on you leveling up (+1 lv = +atk +def)
    cout << endl << "2|MECHATRON:| ATK 2| DEF 4| HP 15| NO MAGIC| 'Benefits heavily from inventions.'"; //relies heavily on shop (you defend and eat coins up till you can afford op items)
    cout << endl << "3|PEACEBRINGER:| ATK 1| DEF 5| HP 50| 150 MANA| 'Violence brings it control.'"; //will roll better chances on his attacks the less hp the enemies have
    //(you ramp up atk overtime, for every hit you do you gain more atk, example: 5 atk hit gives you +5 to your attack, this stacks.)
    //(HOWEVER, after 15+ atk you get a debuff of (INSERT VARIABLE HERE)*2 per turn, till your atk is lower than 10 again, effectively making a sine wave of atk dmg)
    cout << endl << "4|DUSTSETTLER:| ATK 3| DEF 3| HP 10| 250 MANA| 'As the dust settles... It moves on.'"; //will gain a dmg and hp boost that stacks if you go to the next encounter right away
    //you CANNOT buy anything from the shop, however you gain +2 atk and +2 def after EVERY fight, and 2x rewards. this means you farm small battles to bassicaly heal yourself
    cout << endl << "Enter your desired class:";
    cin >> playerclass;
    setstats(1, playerclass, 0, 0, 0);
        break;
}
}else if(selecting == 0){ //set stats of armor
atk = atk + atk2;
def = def + def2;
}else{ //set stats of armor
atk = atk - atk2;
def = def - def2;
}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
void itemuse(int item){
    int choice = 0;
    do{
    cout << endl << "Your current items are:" << endl;
    for(int i = 0; i+1<=invsize; i++){
            cout << "Item " << i +1 << ": " << inventory[i][0] << endl;
        }
    cout << endl << "Which item would you like to use? Enter 1-6." << endl;
    cin >> choice;
    }while(!(choice >= 1 && choice <= 6));
    choice--;
    if(inventory[choice][0] != ""){
    int HEALAMOUNT = stoi(inventory[choice][3]);
    int MANAAMOUNT = stoi(inventory[choice][4]);
    int TYPE = stoi(inventory[choice][6]);
    if(TYPE == 0){
        cout << "Using item: " << choice + 1 << endl;
    for(int j = 0; j<=6; j++){
        inventory[choice][j] = "";
        }
        if(HEALAMOUNT > 0){
            hp = hp + HEALAMOUNT;
            if(hp > maxhp){
                hp = maxhp;
            }
        }else{
            mana = mana + MANAAMOUNT;
            if(mana > maxmana){
                mana = maxmana;
            }
        }
    }else{
    cout << endl << "Cannot use this item." << endl;
    }
    }else{
    cout << endl << "Item slot is empty." << endl;
    }
    system("pause");
    system("cls");
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
void bossbattle(int bosstype = 0, string monster = "", int monsternum = 0){
int monsteramount = 1;
srand(time(0));
monsteramount = 1;
int monsters_erased = monsteramount;
int monsteratk = 1;
int monsterhp = 1;
int monstercurrenthp = 1;
int monstermax = 1;
int g_reward = 1;
int mana_reward = 1;
int hp_reward = 1;
int exp_reward = 1;
int battleon = 1;
int option = 1;

int randatk = 1;
int randesc = 1;
int itemselected = 1;
int randatkm = 1;

int violencemeter = 1;
int antiviolence = 1;

int roll = 1;
int chancetohit = 50;
int chancetocrit = 20;
int chancetorevive = 1;

    system("cls");
    srand(time(0));
    monsternum = rand() % 3 + 1;
    monstermax = worldprogress;
    switch(bosstype){ //setting statistics of monster depending on world from weakest to strongest
case 1:
    srand(time(0));
    monsterhp = 120;
    monsteratk = 15;
    g_reward = 50;
    mana_reward = 1000;
    hp_reward = 1000;
    exp_reward = 150;
    monstercurrenthp = monsterhp;
    monster = "Toriel.";
    break;
case 2:
    srand(time(0));
    monsterhp = 350;
    monsteratk = 35;
    g_reward = 300;
    mana_reward = 1000;
    hp_reward = 1000;
    exp_reward = 1500;
    monstercurrenthp = monsterhp;
    monster = "Papyrus and Undyne!";
    break;
case 3:
    srand(time(0));
    monsterhp = 500;
    monsteratk = 60;
    g_reward = 1;
    mana_reward = 1;
    hp_reward = 1;
    exp_reward = 1;
    monstercurrenthp = monsterhp;
    monster = "Shuffler!";
    break;
default:
    break;
    }
    cout << "You have encountered " << monster << " A boss monster." << endl;
    while(battleon == 1){ //fighting loop
        mana = mana + 10;
        if(mana > maxmana){
            mana = maxmana;
        }
        if(bosstype == 3){
            cout << endl << "The shuffler loves to roll his dice and mess with your chances, be careful..." << endl;
        }
        cout << endl << "The monsters current statistics are:" << endl;
        cout << endl << monstercurrenthp << "/" << monsterhp << "|HP" << endl;
        cout << endl << monsteratk << "|ATK" << endl;
        cout << endl << "''-|-|-|-|-|-|-|-|-|-|-''" << endl;
        cout << endl << "ROLL | " << roll <<  endl;
        cout << endl << "HP | " << hp << "/" << maxhp <<  endl;
        cout << endl << "MANA | " << mana << "/" << maxmana <<  endl;
        if(playerclass == 2){
            cout << endl << "GOLD | " << gold <<  endl;
        }
        cout << endl << "What do you do?" << endl;
        if(playerclass == 3){
            cout << endl << "VIOLENCE METER | " << violencemeter << endl;
        }
    cout << endl << "| 1=FIGHT | 2=ITEM | 3=MANA | 4=XXXXXX |" << endl;
    cin >> option;

    if(bosstype == 3){
roll = rand() % 100 + 1;
if(monstercurrenthp < 50){
    chancetorevive = 50;
}else{
chancetorevive = 99;
}
if(roll >= chancetorevive){
    cout << endl << "Suddenly... The shuffler hit a triple 6 in a row!" << endl;
    cout << endl << "Unfortunately for you, that refills his health back to max." << endl;
    monstercurrenthp = monsterhp;
}
}

    //TORIEL ABILITY
    if(bosstype == 1){
        cout << endl << "Toriel attempts to summon a big fireball..." << endl;
        cout << endl << "Reflect it before it hits you!" << endl;
        cout << endl << "As soon as you press a key, a number will be shown, memorize it..." << endl;
        system("pause");
    system("cls");
    int randomnum = 0;
    int correct = 0;
    randomnum = rand() % 9 + 1;
    cout << randomnum;
    _sleep(300);
    system("cls");
    cout << "What was it?" << endl;
    cin >> correct;
    if(correct != randomnum){
        randatkm = rand() % monsteratk + 1;
        randatkm = randatkm + 4;
        randatkm * monsteratk;
        hp = hp - randatkm;
        cout << endl << "Incorrect. You got hit for: " << randatkm;
        cout << endl << "You have: " << hp << "/" << maxhp << " HP" << endl;
        system("pause");
    }else{
    cout << endl << "Correct! You reflected it's fireball flawlessly." << endl;
    system("pause");
    }
    }
    //UNDYNE + PAPYRUS ABILITY
    if(bosstype == 2){
    cout << endl << "Papyrus attempts to throw a bone, and undyne reflects it to throw you off." << endl;
        cout << endl << "Reflect it before it hits you!" << endl;
        cout << endl << "As soon as you press a key, a 2 numbers will be shown, memorize them and add them up!" << endl;
        system("pause");
    system("cls");
    int randomnum = 0;
    int answer = 0;
    int correct = 0;
    randomnum = rand() % 9 + 1;
    answer = answer + randomnum;
    cout << randomnum << endl;
    _sleep(300);
    randomnum = rand() % 9 + 1;
    answer = answer + randomnum;
    cout << randomnum;
    _sleep(300);
    system("cls");
    cout << "What was it?" << endl;
    cin >> correct;
    if(correct != answer){
        randatkm = rand() % monsteratk + 1;
        randatkm = randatkm + 4;
        randatkm * monsteratk;
        hp = hp - randatkm;
        cout << endl << "Incorrect. You got hit for: " << randatkm;
        cout << endl << "You have: " << hp << "/" << maxhp << " HP" << endl;
        system("pause");
    }else{
    cout << endl << "Correct! You reflected it's bone flawlessly." << endl;
    system("pause");
    }
    }
    if(bosstype == 3){
        roll = rand() % 100 + 1;
        if(roll >= 60){
            int dice = 0;
            bool wrong = false;
            int input = 0;
            cout << endl << "You have been trapped!" << endl;
            cout << endl << "Type the numbers you see till the Shuffler rolls 6 with one of his dice." << endl;
            system("pause");
            system("cls");
            dice = rand() % 6 + 1;
            do{
            cout << endl << dice << endl;
            cin >> input;
            if(input == dice){
                cout << endl << "Correct. Next up:";
                dice = rand() % 6 + 1;
            }else{
            dice = 6;
            wrong = true;
            }
            }while(dice != 6);
            if(wrong == true){
                system("cls");
                cout << "You entered a wrong number. The shuffler gets a free hit on you!";

                randatkm = rand() % monsteratk + 1;
        randatkm = randatkm + 4;
        randatkm * monsteratk;
        int randatkm2 = 0;
        randatkm2 = randatkm - def;
        if(randatkm2 < 0){
            randatkm2 = 0;
        }

        if(bosstype == 3){
            roll = rand() % 100 + 1;
            if(roll <= chancetocrit){
                cout << endl << "Before hitting you, he manages to roll a six with one of his dice!" << endl;
                cout << endl << "His damage multiplied by 2." << endl;
                randatkm2 = randatkm2 * 2;
                chancetocrit = chancetocrit - 5;
            }
        }
        chancetocrit = chancetocrit + 15;
        cout << endl << "It dealt: " << randatkm2 << " damage." << endl;
        hp = hp - randatkm2;
        cout << endl << "You have: " << hp << "/" << maxhp << " HP" << endl;

            }else{
                cout << endl << "You escaped!" << endl;
            }
        }
    }

        switch(option){
    case 1:{
        if(playerclass == 1 || playerclass == 2 || playerclass == 4){
        if(bosstype == 3){
        roll = rand() % 100 + 1;
        if(roll >= chancetohit){
        chancetohit = chancetohit + 10;
        randatk = rand() % atk + 1;
        cout << endl << "You dealt: " << randatk << " damage." << endl;
        monstercurrenthp = monstercurrenthp - randatk;
        cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
        system("pause");
        }else{
        cout << endl << "You tried to hit it, but unfortunately for you, it rolled a six with one if his dice!" << endl;
        cout << endl << "You have missed instead, better luck next time!" << endl;
        chancetohit = chancetohit - 10;
        }
        }else{
        randatk = rand() % atk + 1;
        cout << endl << "You dealt: " << randatk << " damage." << endl;
        monstercurrenthp = monstercurrenthp - randatk;
        cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
        system("pause");
        }

        randatkm = rand() % monsteratk + 1;
        randatkm = randatkm + 4;
        randatkm * monsteratk;
        int randatkm2 = 0;
        randatkm2 = randatkm - def;
        if(randatkm2 < 0){
            randatkm2 = 0;
        }

        if(bosstype == 3){
            roll = rand() % 100 + 1;
            if(roll <= chancetocrit){
                cout << endl << "Before hitting you, he manages to roll a six with one of his dice!" << endl;
                cout << endl << "His damage multiplied by 2." << endl;
                randatkm2 = randatkm2 * 2;
                chancetocrit = chancetocrit - 5;
            }
        }
        chancetocrit = chancetocrit + 15;
        cout << endl << "It dealt: " << randatkm2 << " damage." << endl;
        hp = hp - randatkm2;
        cout << endl << "You have: " << hp << "/" << maxhp << " HP" << endl;
        // MECHATRON ONLY
        if(playerclass == 2){
                int goldinsert = 0;
            if(gold >= 1){
                cout << endl << "Use your gold to your advantage! Load up your gun with it." << endl;
                cout << endl << "The more gold you put in, the bigger the damage output might be!" << endl;
                do{
                cin >> goldinsert;
                }while(goldinsert > gold || goldinsert <= 0);
                randatk = rand() % goldinsert + 1;
                cout << endl << "You dealt: " << randatk << " damage." << endl;
                monstercurrenthp = monstercurrenthp - randatk;
                cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
            }
            for(int j = 0; j<=6; j++){
                if(inventory[j][6] == "3"){
                    system("pause");
                    cout << endl << "Your robot " << inventory[j][0] << " then suddenly strikes!" << endl;
                    int randdmg = stoi(inventory[j][1]);
                    randatk = rand() % randdmg + 1;
                    cout << endl << "It dealt: " << randatk << " damage." << endl;
                    monstercurrenthp = monstercurrenthp - randatk;
                    cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
                }
            }
        }
        // MECHATRON ONLY
        }else{ //PEACEBRINGER ONLY

        if(bosstype == 3){
        roll = rand() % 100 + 1;
        if(roll >= chancetohit){
        randatk = rand() % violencemeter + 1;
        violencemeter = violencemeter + randatk;
        if(violencemeter > 15){
            antiviolence = antiviolence*2;
            violencemeter = violencemeter - antiviolence;
        }
        if(violencemeter <= 0){
            violencemeter = 0;
        }
        violencemeter++;
        chancetohit = chancetohit + 10;
        cout << endl << "You dealt: " << randatk << " damage." << endl;
        monstercurrenthp = monstercurrenthp - randatk;
        cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
        system("pause");
        }else{
        chancetohit = chancetohit - 10;
        cout << endl << "You tried to hit it, but unfortunately for you, it rolled a six with one if his dice!" << endl;
        cout << endl << "You have missed instead, better luck next time!" << endl;
        }
        }else{
        randatk = rand() % violencemeter + 1;
        violencemeter = violencemeter + randatk;
        if(violencemeter > 15){
            antiviolence = antiviolence*2;
            violencemeter = violencemeter - antiviolence;
        }
        if(violencemeter <= 0){
            violencemeter = 0;
        }
        violencemeter++;
        cout << endl << "You dealt: " << randatk << " damage." << endl;
        monstercurrenthp = monstercurrenthp - randatk;
        cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
        system("pause");
        }

        randatkm = rand() % monsteratk + 1;
        randatkm = randatkm + 4;
        randatkm * monsteratk;
        int randatkm2 = 0;
        randatkm2 = randatkm - def;
        if(randatkm2 < 0){
            randatkm2 = 0;
        }
        if(bosstype == 3){
            roll = rand() % 100 + 1;
            if(roll <= chancetocrit){
                cout << endl << "Before hitting you, he manages to roll a six with one of his dice!" << endl;
                cout << endl << "His damage multiplied by 2." << endl;
                randatkm2 = randatkm2 * 2;
                chancetocrit = chancetocrit - 5;
            }
        }
        chancetocrit = chancetocrit + 15;
        cout << endl << "It dealt: " << randatkm2 << " damage." << endl;
        hp = hp - randatkm2;
        cout << endl << "You have: " << hp << "/" << maxhp << " HP" << endl;
        } // PEACEBRINGER ONLY

        system("pause");
        system("cls");
    break;
    }
    case 2:{
        itemuse(itemselected);
    break;
    }
    case 3:{
        if(mana >= 1){
        cout << endl << "State how much mana you want to use from 10 to 99." << endl;
        cout << endl << "The closer to 99 you are, the less of a chance you have to fail your spell." << endl;
        int manachance = 0;
        cin >> manachance;
        mana = mana - manachance;
        int manachancehit = 0;
        manachancehit = rand() % manachance + 1;

        if(manachancehit >= 10){
        randatk = rand() % 10 + 1;
        if(randatk <= 5){
            randatk = 5;
        }
        if(mana <= 0){
            mana = 0;
        }

        if(playerclass == 3){
        violencemeter = violencemeter+randatk;
        if(violencemeter > 15){
            antiviolence = antiviolence*2;
            violencemeter = violencemeter - antiviolence;
        }
        if(violencemeter <= 0){
            violencemeter = 0;
        }
        violencemeter++;
        }

        randatk * manaBOOST;
        cout << endl << "You dealt: " << randatk << " damage." << endl;
        monstercurrenthp = monstercurrenthp - randatk;
        cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
        }else{
        cout << endl << "The spell failed." << endl;

        randatk = 1;
        if(mana <= 0){
            mana = 0;
        }

        if(playerclass == 3){
        violencemeter = violencemeter+randatk;
        if(violencemeter > 15){
            antiviolence = antiviolence*2;
            violencemeter = violencemeter - antiviolence;
        }
        if(violencemeter <= 0){
            violencemeter = 0;
        }
        violencemeter++;
        }

        randatk * manaBOOST;
        cout << endl << "You dealt: " << randatk << " damage." << endl;
        monstercurrenthp = monstercurrenthp - randatk;
        cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;

        }
        system("pause");

        randatkm = rand() % monsteratk + 1;
        cout << endl << "It dealt: " << randatkm << " damage." << endl;
        hp = hp - randatkm;
        cout << endl << "You have: " << hp << "/" << maxhp << " HP" << endl;
        }else{
        cout << endl << "You dont have enough mana to use spells." << endl;
        }
        system("pause");
        system("cls");
    break;
    }
    case 4:{
        cout << "You cannot escape. The monster attacked you instead.";
        randatkm = rand() % monsteratk + 1;
        cout << endl << "It dealt: " << randatkm << " damage." << endl;
        hp = hp - randatkm;
        cout << endl << "You have: " << hp << "/" << maxhp << " HP" << endl;
        system("pause");
        system("cls");
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
    if(playerclass == 4){
        atk = atk + 3;
        def++;
        maxhp = maxhp +10;
    }
    if(monsteramount <= 0){
    battleon = 0;
    monsters = monsters - monsters_erased;
    if(playerclass == 4){
        hp_reward = hp_reward*2;
        mana_reward = mana_reward*2;
    }
    cout << endl << "You won! Your rewards are:" << endl;
    cout << endl << g_reward << " Gold." << endl;
    cout << endl << hp_reward << " Health." << endl;
    cout << endl << exp_reward << " EXP." << endl;
    gold = gold + g_reward;
    hp = hp + hp_reward;
    expcurrent = expcurrent + exp_reward;
    if(playerclass >= 2){
    cout << endl << mana_reward << " Mana." << endl;
    mana = mana + mana_reward;
    }
    if(hp > maxhp){
        hp = maxhp;
    }
    if(mana > maxmana){
        mana = maxmana;
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
int exp_reward = 1;
int battleon = 1;
int option = 1;

int randatk = 1;
int randesc = 1;
int itemselected = 1;
int randatkm = 1;

int violencemeter = 1;
int antiviolence = 1;

    system("cls");
    srand(time(0));
    monsternum = rand() % 3 + 1;
    monstermax = worldprogress;
    switch(monsternum){ //setting statistics of monster depending on world from weakest to strongest
case 1:
    srand(time(0));
    monsterhp = monstermax*6;
    monsteratk = monstermax;
    g_reward = monstermax*20;
    mana_reward = monstermax*10;
    hp_reward = monstermax*10;
    exp_reward = monstermax*10;
    monstercurrenthp = monsterhp;
    monster = "weak monster.";
    break;
case 2:
    srand(time(0));
    monsterhp = monstermax*12;
    monsteratk = monstermax*2;
    g_reward = monstermax*30;
    mana_reward = monstermax*20;
    hp_reward = monstermax*20;
    exp_reward = monstermax*20;
    monstercurrenthp = monsterhp;
    monster = "strong monster.";
    break;
case 3:
    srand(time(0));
    monsterhp = monstermax*24;
    monsteratk = monstermax*3;
    g_reward = monstermax*40;
    mana_reward = monstermax*30;
    hp_reward = monstermax*30;
    exp_reward = monstermax*30;
    monstercurrenthp = monsterhp;
    monster = "very strong monster.";
    break;
default:
    break;
    }
    cout << "You have encountered a " << monster << endl;
    while(battleon == 1){ //fighting loop
        mana = mana + 10;
        if(mana > maxmana){
            mana = maxmana;
        }
        cout << endl << "The monsters current statistics are:" << endl;
        cout << endl << monstercurrenthp << "/" << monsterhp << "|HP" << endl;
        cout << endl << monsteratk << "|ATK" << endl;
        cout << endl << "''-|-|-|-|-|-|-|-|-|-|-''" << endl;
        cout << endl << "HP | " << hp << "/" << maxhp <<  endl;
        cout << endl << "MANA | " << mana << "/" << maxmana <<  endl;
        if(playerclass == 2){
            cout << endl << "GOLD | " << gold <<  endl;
        }
        if(playerclass == 3){
            cout << endl << "VIOLENCE METER | " << violencemeter << endl;
        }
        cout << endl << "What do you do?" << endl;
    cout << endl << "| 1=FIGHT | 2=ITEM | 3=MANA | 4=ESCAPE |" << endl;
    cin >> option;
        switch(option){
    case 1:{
        if(playerclass == 1 || playerclass == 2 || playerclass == 4){
        randatk = rand() % atk + 1;
        cout << endl << "You dealt: " << randatk << " damage." << endl;
        monstercurrenthp = monstercurrenthp - randatk;
        cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
        system("pause");

        randatkm = rand() % monsteratk + 1;
        randatkm = randatkm + 4;
        randatkm * monsteratk;
        int randatkm2 = 0;
        randatkm2 = randatkm - def;
        if(randatkm2 < 0){
            randatkm2 = 0;
        }
        cout << endl << "It dealt: " << randatkm2 << " damage." << endl;
        hp = hp - randatkm2;
        cout << endl << "You have: " << hp << "/" << maxhp << " HP" << endl;
        // MECHATRON ONLY
        if(playerclass == 2){
            int goldinsert = 0;
            if(gold >= 1){
                cout << endl << "Use your gold to your advantage! Load up your gun with it." << endl;
                cout << endl << "The more gold you put in, the bigger the damage output might be!" << endl;
                do{
                cin >> goldinsert;
                }while(goldinsert > gold || goldinsert <= 0);
                randatk = rand() % goldinsert + 1;
                cout << endl << "You dealt: " << randatk << " damage." << endl;
                monstercurrenthp = monstercurrenthp - randatk;
                cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
            }
            gold = gold - goldinsert;
            for(int j = 0; j<=6; j++){
                if(inventory[j][6] == "3"){
                    system("pause");
                    cout << endl << "Your robot " << inventory[j][0] << " then suddenly strikes!" << endl;
                    int randdmg = stoi(inventory[j][1]);
                    randatk = rand() % randdmg + 1;
                    cout << endl << "It dealt: " << randatk << " damage." << endl;
                    monstercurrenthp = monstercurrenthp - randatk;
                    cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
                }
            }
        }
        // MECHATRON ONLY
        }else{ //PEACEBRINGER ONLY
        randatk = rand() % violencemeter + 1;
        violencemeter = violencemeter + randatk;
        if(violencemeter > 15){
            antiviolence = antiviolence*2;
            violencemeter = violencemeter - antiviolence;
        }
        if(violencemeter <= 0){
            violencemeter = 0;
        }
        violencemeter++;
        cout << endl << "You dealt: " << randatk << " damage." << endl;
        monstercurrenthp = monstercurrenthp - randatk;
        cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
        system("pause");

        randatkm = rand() % monsteratk + 1;
        randatkm = randatkm + 4;
        randatkm * monsteratk;
        int randatkm2 = 0;
        randatkm2 = randatkm - def;
        if(randatkm2 < 0){
            randatkm2 = 0;
        }
        cout << endl << "It dealt: " << randatkm2 << " damage." << endl;
        hp = hp - randatkm2;
        cout << endl << "You have: " << hp << "/" << maxhp << " HP" << endl;
        } // PEACEBRINGER ONLY

        system("pause");
        system("cls");
    break;
    }
    case 2:{
        itemuse(itemselected);
    break;
    }
    case 3:{
        if(mana >= 1){
        cout << endl << "State how much mana you want to use from 10 to 99." << endl;
        cout << endl << "The closer to 99 you are, the less of a chance you have to fail your spell." << endl;
        int manachance = 0;
        do{
        cin >> manachance;
        }while(manachance > mana || manachance <= 0);
        mana = mana - manachance;
        int manachancehit = 0;
        manachancehit = rand() % manachance + 1;

        if(manachancehit >= 10){
        randatk = rand() % 10 + 1;
        if(randatk <= 5){
            randatk = 5;
        }
        if(mana <= 0){
            mana = 0;
        }

        if(playerclass == 3){
        violencemeter = violencemeter+randatk;
        if(violencemeter > 15){
            antiviolence = antiviolence*2;
            violencemeter = violencemeter - antiviolence;
        }
        if(violencemeter <= 0){
            violencemeter = 0;
        }
        violencemeter++;
        }

        randatk * manaBOOST;
        cout << endl << "You dealt: " << randatk << " damage." << endl;
        monstercurrenthp = monstercurrenthp - randatk;
        cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;
        }else{
        cout << endl << "The spell failed." << endl;

        randatk = 1;
        if(mana <= 0){
            mana = 0;
        }

        if(playerclass == 3){
        violencemeter = violencemeter+randatk;
        if(violencemeter > 15){
            antiviolence = antiviolence*2;
            violencemeter = violencemeter - antiviolence;
        }
        if(violencemeter <= 0){
            violencemeter = 0;
        }
        violencemeter++;
        }

        randatk * manaBOOST;
        cout << endl << "You dealt: " << randatk << " damage." << endl;
        monstercurrenthp = monstercurrenthp - randatk;
        cout << endl << "The monster has: " << monstercurrenthp << "/" << monsterhp << " HP" << endl;

        }
        system("pause");

        randatkm = rand() % monsteratk + 1;
        cout << endl << "It dealt: " << randatkm << " damage." << endl;
        hp = hp - randatkm;
        cout << endl << "You have: " << hp << "/" << maxhp << " HP" << endl;
        }else{
        cout << endl << "You dont have enough mana to use spells." << endl;
        }
        system("pause");
        system("cls");
    break;
    }
    case 4:{
        randesc = rand() % monstermax + 1;
        int randesc2 = randesc*100;
        randesc = rand() % randesc2 + 1;
        if(randesc <= 60){
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
    if(playerclass == 4){
        atk = atk + 3;
        def++;
        maxhp = maxhp +10;
    }
    if(monsteramount <= 0){
    battleon = 0;
    monsters = monsters - monsters_erased;
    if(playerclass == 4){
        hp_reward = hp_reward*2;
        mana_reward = mana_reward*2;
    }
    cout << endl << "You won! Your rewards are:" << endl;
    cout << endl << g_reward << " Gold." << endl;
    cout << endl << hp_reward << " Health." << endl;
    cout << endl << exp_reward << " EXP." << endl;
    gold = gold + g_reward;
    hp = hp + hp_reward;
    expcurrent = expcurrent + exp_reward;
    if(playerclass >= 2){
    cout << endl << mana_reward << " Mana." << endl;
    mana = mana + mana_reward;
    }
    if(hp > maxhp){
        hp = maxhp;
    }
    if(mana > maxmana){
        mana = maxmana;
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
void store(string inventory[6][7], int invsize, int gold, int worldprogress, int areaprogress){
int inshop = 0;
system("cls");
if(playerclass == 4){
        atk = 3;
        atk = atk*worldprogress;
        cout << endl << "You have came to a spot nearby the shop to rest." << endl;
        cout << endl << "You regained all your energy and health back at the cost of your power..." << endl;
        hp = maxhp;
        mana = maxmana;
        maxhp = 10*worldprogress;
        def = 3;
        def = def*worldprogress;
        system("pause");
    }else{
system("cls");
cout << endl << "Welcome to the zone " << worldprogress << " shop!" << endl;
cout << endl << "GOLD | " << gold <<  endl;
cout << endl << "ITEMS | VVV |" << endl;
        for(int i = 0; i+1<=invsize; i++){
            cout << "Item " << i +1 << ": " << inventory[i][0];
            if(inventory[i][0] != ""){
            int TYPE = stoi(inventory[i][6]);
            int HEALAMOUNT = stoi(inventory[i][3]);
            int MANAAMOUNT = stoi(inventory[i][4]);
            if(TYPE == 0 && HEALAMOUNT >= 1){
                cout << " Heals: " << inventory[i][3] << " HP";
            }else if(TYPE == 0 && MANAAMOUNT >= 1){
                cout << " Refills: " << inventory[i][4] << " MANA";
            }else if(TYPE == 1){
                cout << " ATK: " << inventory[i][1] << " DEF: " << inventory[i][2];
            }else if(TYPE == 2){
                cout << " ADDED TO MAX: " << inventory[i][2];
            }
            }
            cout << endl;
        }

cout << endl << "Do you wish to leave, or to buy? |2 (Remove) / 1 (Buy) / 0 (Leave)|" << endl;
cout << endl << "!;-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=;!" << endl;
cin >> inshop;
}
while(inshop == 1 || inshop == 2){

    if(inshop == 1){
switch(worldprogress){

case 2:{ //WORLD 2 ITEMS
//7 statistics
//1 = NAME/ 2=+ATK/ 3=+DEF/ 4=ISHEAL>0 THEN +HEAL/ 5=ISMANA>0 THEN +MANA/ 6=SLOT/ 7=TYPE (0=LISTS +MANA OR +HEAL OR BOTH USING IF ELSE, 1=LISTS ATK AND DEF, 2=+MAXHP(adds 20+maxhp upon use), 3=only mechatron can buy it, 4=+MAXMANA+MANABOOST )
int prices[11] = {15, 18, 40, 70, 80, 100, 60, 60, 60, 250};
string shopitem[10][7] = {
        {"|Healing Potion|", "0", "0", "40", "0", "", "0"},
        {"|Mana Potion|", "0", "0", "0", "60", "", "0"},
        {"|Weak Armor Piece 1|", "0", "2", "0", "0", "", "1"},
        {"|Weak Armor Piece 2|", "0", "3", "0", "0", "", "1"},
        {"|Weak Armor Piece 3|", "0", "5", "0", "0", "", "1"},
        {"|Weak Armor Piece 4|", "0", "7", "0", "0", "", "1"},
        {"|Weak Weapon|", "8", "0", "0", "0", "", "1"},
        {"|Health Crystal|", "0", "20", "0", "0", "", "2"},
        {"|Mana Crystal|", "0", "3", "0", "0", "", "2"},
        {"|MODITRON - MECHATRON ONLY|", "40", "0", "0", "0", "", "3"}
    };
int currentitem = 0;
cout << endl << "SHOP ITEMS | VVV |" << endl;
for(int i = 0; i+1<=prices[i]; i++){
            cout << "Price: " << prices[i] << " Gold =";
            cout << " Item " << i +1 << ": " << shopitem[i][0];
            int TYPE = stoi(shopitem[i][6]);
            int HEALAMOUNT = stoi(shopitem[i][3]);
            int MANAAMOUNT = stoi(shopitem[i][4]);
            if(TYPE == 0 && HEALAMOUNT >= 1){
                cout << " Heals: " << shopitem[i][3] << " HP";
            }else if(TYPE == 0 && MANAAMOUNT >= 1){
                cout << " Refills: " << shopitem[i][4] << " MANA";
            }else if(TYPE == 1){
                cout << " ATK: " << shopitem[i][1] << " DEF: " << shopitem[i][2];
            }else if(TYPE == 2){
                cout << " ADDED TO MAX: " << shopitem[i][2];
            }
            cout << endl;
        }
    cout << endl << "Which item do you want to buy? (Insert from 1 to 10 to pick, insert anything else to cancel.)" << endl;
    cin >> currentitem;
    currentitem = currentitem-1;
    if(currentitem >= 0 && currentitem <= 8 && gold >= prices[currentitem]){
        int slot = 0;
        cout << endl << "Buying: " << shopitem[currentitem][0] << " for " << prices[currentitem];
            if(currentitem != 7 && currentitem != 8 && currentitem != 9){
        do{
        cout << endl << "Select which inventory slot to replace:" << endl;
        cin >> slot;
        }while(!(slot >= 1 && slot <= 6));
        slot--;
        gold = gold - prices[currentitem];
        for(int j = 0; j<=6; j++){
        inventory[slot][j] = shopitem[currentitem][j];
        }
        int ATTACK = stoi(shopitem[currentitem][1]);
        int DEFENSE = stoi(shopitem[currentitem][2]);
        setstats(0, playerclass, slot, ATTACK, DEFENSE);
                }else if(currentitem == 8){
            int DEFENSE = stoi(shopitem[currentitem][2]);
            manaBOOST = manaBOOST + DEFENSE;
            gold = gold - prices[currentitem];
            cout << endl << "Mana DMG boosted by  " << DEFENSE << "!" << endl;
            system("pause");
            }else if (currentitem ==7) {
            int DEFENSE = stoi(shopitem[currentitem][2]);
            gold = gold - prices[currentitem];
            maxhp = maxhp + DEFENSE;
            cout << endl << "Max HP increased by " << DEFENSE << "!" << endl;
            system("pause");
            }
        }else if(currentitem == 9 && gold >= prices[currentitem] && playerclass == 2){ //MECHATRON--------------------------
            int hasrobot;
            for(int j = 0; j<=6; j++){
                if(inventory[j][6] == "3"){
                    cout << endl << "You already have a robot. Discard it to add a new one." << endl;
                    hasrobot = 1;
                    system("pause");
                }else{
                    if(hasrobot != 1){
                    hasrobot = 0;
                    }
                }
                }
                if(hasrobot == 0){
                int slot = 0;
                cout << endl << "Buying: " << shopitem[currentitem][0] << " for " << prices[currentitem];
                gold = gold - prices[currentitem];
                do{
                cout << endl << "Select which inventory slot to replace:" << endl;
                cin >> slot;
                }while(!(slot >= 1 && slot <= 6));
                slot--;
                for(int j = 0; j<=6; j++){
                inventory[slot][j] = shopitem[currentitem][j];
                hasrobot = 0;
                }
                }
            }else{
    cout << endl << "Buying cancelled!" << endl;
    system("pause");
    }
    break;
}
//WORLD 2 ITEMS

case 3:{ //WORLD 3 ITEMS
    //7 statistics
//1 = NAME/ 2=+ATK/ 3=+DEF/ 4=ISHEAL>0 THEN +HEAL/ 5=ISMANA>0 THEN +MANA/ 6=SLOT/ 7=TYPE (0=LISTS +MANA OR +HEAL OR BOTH USING IF ELSE, 1=LISTS ATK AND DEF, 2=+MAXHP(adds 20+maxhp upon use), 3=only mechatron can buy it, 4=+MAXMANA+MANABOOST )
int prices[11] = {40, 40, 100, 130, 150, 220, 180, 80, 80, 1000};
string shopitem[10][7] = {
        {"|Strong Healing Potion|", "0", "0", "100", "0", "", "0"},
        {"|Strong Mana Potion|", "0", "0", "0", "150", "", "0"},
        {"|Strong Armor Piece 1|", "0", "4", "0", "0", "", "1"},
        {"|Strong Armor Piece 2|", "0", "5", "0", "0", "", "1"},
        {"|Strong Armor Piece 3|", "0", "7", "0", "0", "", "1"},
        {"|Strong Armor Piece 4|", "0", "10", "0", "0", "", "1"},
        {"|Strong Weapon|", "18", "0", "0", "0", "", "1"},
        {"|Health Crystal|", "0", "20", "0", "0", "", "2"},
        {"|Mana Crystal|", "0", "3", "0", "0", "", "2"},
        {"|RAFATOTRON - MECHATRON ONLY|", "80", "0", "0", "0", "", "3"}
    };
int currentitem = 0;
cout << endl << "SHOP ITEMS | VVV |" << endl;
for(int i = 0; i+1<=prices[i]; i++){
            cout << "Price: " << prices[i] << " Gold =";
            cout << " Item " << i +1 << ": " << shopitem[i][0];
            int TYPE = stoi(shopitem[i][6]);
            int HEALAMOUNT = stoi(shopitem[i][3]);
            int MANAAMOUNT = stoi(shopitem[i][4]);
            if(TYPE == 0 && HEALAMOUNT >= 1){
                cout << " Heals: " << shopitem[i][3] << " HP";
            }else if(TYPE == 0 && MANAAMOUNT >= 1){
                cout << " Refills: " << shopitem[i][4] << " MANA";
            }else if(TYPE == 1){
                cout << " ATK: " << shopitem[i][1] << " DEF: " << shopitem[i][2];
            }else if(TYPE == 2){
                cout << " ADDED TO MAX: " << shopitem[i][2];
            }
            cout << endl;
        }
    cout << endl << "Which item do you want to buy? (Insert from 1 to 10 to pick, insert anything else to cancel.)" << endl;
    cin >> currentitem;
    currentitem = currentitem-1;
    if(currentitem >= 0 && currentitem <= 8 && gold >= prices[currentitem]){
        int slot = 0;
        cout << endl << "Buying: " << shopitem[currentitem][0] << " for " << prices[currentitem];
            if(currentitem != 7 && currentitem != 8 && currentitem != 9){
        do{
        cout << endl << "Select which inventory slot to replace:" << endl;
        cin >> slot;
        }while(!(slot >= 1 && slot <= 6));
        slot--;
        gold = gold - prices[currentitem];
        for(int j = 0; j<=6; j++){
        inventory[slot][j] = shopitem[currentitem][j];
        }
        int ATTACK = stoi(shopitem[currentitem][1]);
        int DEFENSE = stoi(shopitem[currentitem][2]);
        setstats(0, playerclass, slot, ATTACK, DEFENSE);
                }else if(currentitem == 8){
            int DEFENSE = stoi(shopitem[currentitem][2]);
            manaBOOST = manaBOOST + DEFENSE;
            gold = gold - prices[currentitem];
            cout << endl << "Mana DMG boosted by  " << DEFENSE << "!" << endl;
            system("pause");
            }else if (currentitem ==7) {
            int DEFENSE = stoi(shopitem[currentitem][2]);
            gold = gold - prices[currentitem];
            maxhp = maxhp + DEFENSE;
            cout << endl << "Max HP increased by " << DEFENSE << "!" << endl;
            system("pause");
            }
        }else if(currentitem == 9 && gold >= prices[currentitem] && playerclass == 2){ //MECHATRON--------------------------
            int hasrobot;
            for(int j = 0; j<=6; j++){
                if(inventory[j][6] == "3"){
                    cout << endl << "You already have a robot. Discard it to add a new one." << endl;
                    hasrobot = 1;
                    system("pause");
                }else{
                    if(hasrobot != 1){
                    hasrobot = 0;
                    }
                }
                }
                if(hasrobot == 0){
                int slot = 0;
                cout << endl << "Buying: " << shopitem[currentitem][0] << " for " << prices[currentitem];
                gold = gold - prices[currentitem];
                do{
                cout << endl << "Select which inventory slot to replace:" << endl;
                cin >> slot;
                }while(!(slot >= 1 && slot <= 6));
                slot--;
                for(int j = 0; j<=6; j++){
                inventory[slot][j] = shopitem[currentitem][j];
                hasrobot = 0;
                }
                }
            }else{
    cout << endl << "Buying cancelled!" << endl;
    system("pause");
    }
    break;
}

default:{
    break;
}
}
system("cls"); //repeat
cout << endl << "GOLD | " << gold <<  endl;
cout << endl << "ITEMS | VVV |" << endl;
        for(int i = 0; i+1<=invsize; i++){
            cout << "Item " << i +1 << ": " << inventory[i][0];
            if(inventory[i][0] != ""){
            int TYPE = stoi(inventory[i][6]);
            int HEALAMOUNT = stoi(inventory[i][3]);
            int MANAAMOUNT = stoi(inventory[i][4]);
            if(TYPE == 0 && HEALAMOUNT >= 1){
                cout << " Heals: " << inventory[i][3] << " HP";
            }else if(TYPE == 0 && MANAAMOUNT >= 1){
                cout << " Refills: " << inventory[i][4] << " MANA";
            }else if(TYPE == 1){
                cout << " ATK: " << inventory[i][1] << " DEF: " << inventory[i][2];
            }else if(TYPE == 2){
                cout << " ADDED TO MAX: " << inventory[i][2];
            }
            }
            cout << endl;
        }
cout << endl << "Do you wish to leave, or to buy? |2 (Remove) / 1 (Buy) / 0 (Leave)|" << endl;
cout << endl << "!;-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=;!" << endl;
cin >> inshop;
}else{ //remove items section
cout << endl << "Which item would you like to remove?" << endl;
int slot = 0;
do{
cin >> slot;
}while(!(slot >= 1 && slot <= 6));
slot--;
int ATTACK = stoi(inventory[slot][1]);
int DEFENSE = stoi(inventory[slot][2]);
setstats(2, playerclass, slot, ATTACK, DEFENSE);
for(int j = 0; j<=6; j++){
        inventory[slot][j] = "";
        }
system("cls");
slot++;
cout << "Item " << slot << " removed.";
cout << endl << "GOLD | " << gold <<  endl;
cout << endl << "ITEMS | VVV |" << endl;
        for(int i = 0; i+1<=invsize; i++){
            cout << "Item " << i +1 << ": " << inventory[i][0];
            if(inventory[i][0] != ""){
            int TYPE = stoi(inventory[i][6]);
            int HEALAMOUNT = stoi(inventory[i][3]);
            int MANAAMOUNT = stoi(inventory[i][4]);
            if(TYPE == 0 && HEALAMOUNT >= 1){
                cout << " Heals: " << inventory[i][3] << " HP";
            }else if(TYPE == 0 && MANAAMOUNT >= 1){
                cout << " Refills: " << inventory[i][4] << " MANA";
            }else if(TYPE == 1){
                cout << " ATK: " << inventory[i][1] << " DEF: " << inventory[i][2];
            }else if(TYPE == 2){
                cout << " ADDED TO MAX: " << inventory[i][2];
            }
            }
            cout << endl;
        }
cout << endl << "Do you wish to leave, or to buy? |2 (Remove) / 1 (Buy) / 0 (Leave)|" << endl;
cout << endl << "!;-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=;!" << endl;
cin >> inshop;
}

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
begingame = "";
playerclass = 0;
monsters = 4;
village = 2;

atk = 0;
def = 0;
gold = 0;
maxhp = 20;
hp = maxhp;
maxmana = 20;
mana = maxmana;
manaBOOST = 3;
worldprogress = 1;
areaprogress = 1;
currentmap = 1;
maxmap = 0;
randomevent = 0;
expcurrent = 0;
expneed = 4;
LV = 0;

int atkboost = 0;
string inventory[6][7]= {
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""}
};
    system("cls");
    cout << endl << "Before the story may begin, you must pick your class." << endl;
    cout << endl << "Please choose carefully as you will not be able to change it later." << endl;
    cout << endl << "Enter any number linked with the class you like." << endl;
    cout << endl << "CLASSES: SWORDSMAN, MECHATRON, PEACEBRINGER, DUSTSETTLER";
    cout << endl << "1|SWORDSMAN:| ATK 5| DEF 3| HP 20| NO MAGIC| 'Classic and reliable. Wields a simple sword.'"; //relies on you leveling up
    cout << endl << "2|MECHATRON:| ATK 2| DEF 4| HP 15| NO MAGIC| 'Benefits heavily from inventions.'"; //relies heavily on shop (you defend and eat coins up till you can afford op items)
    cout << endl << "3|PEACEBRINGER:| ATK 1| DEF 5| HP 50| 150 MANA| 'Violence brings it control.'"; //will roll better chances on his attacks the less hp the enemies have
    cout << endl << "4|DUSTSETTLER:| ATK 3| DEF 3| HP 10| 250 MANA| 'As the dust settles... It moves on.'"; //will gain a dmg and hp boost that stacks if you go to the next encounter right away
    cout << endl << "Enter your desired class:";
    cin >> playerclass;

    setstats(1, playerclass,0 ,0 ,0);

    monsters = 4;

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
    int goback = 0;
    do{ // cykl chozeni
        cout << endl << "You continue walking through. Your current progress is: " << currentmap << "/" << maxmap << "." <<  endl;
        cout << endl << "Your current statistics are:" <<  endl;
        cout << endl << "WORLD | " << worldprogress <<  endl;
        cout << endl << "ATK | " << atk <<  endl;
        cout << endl << "DEF | " << def <<  endl;
        cout << endl << "GOLD | " << gold <<  endl;
        cout << endl << "HP | " << hp << "/" << maxhp <<  endl;
        cout << endl << "MANA | " << mana << "/" << maxmana <<  endl;
        if(playerclass == 1){
        cout << endl << "EXP| " << expcurrent;
        cout << endl << "EXP NEEDED| " << expneed;
        cout << endl << "LV | " << LV <<  endl;
        }
        cout << endl << "ITEMS | VVV |" << endl;
        for(int i = 0; i+1<=invsize; i++){
            cout << "Item " << i +1 << ": " << inventory[i][0] << endl;
        }
//---------------------------------------------scenarios
        srand(time(0));  // inicializace generatoru nahodných cisel
        randomevent = rand() % 100 + 1;  // cisla od 0 až do 100
        system("pause");

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
//------------------------------------------------map check
        if(currentmap < maxmap-1){
            currentmap++;
        }else if (currentmap >= maxmap-1 && monsters >= 0){
        cout << endl << "You may have made it to the end, but there are still " << monsters << " monsters blocking your way." << endl;
        cout << endl << "You decide to run back to not get overwhelmed and beat them off one by one." << endl;
        currentmap = 0;
        system("pause");
        }
        if(currentmap >= maxmap-1 && monsters <= 0){
            cout << endl << "You made it to the end and all monsters have been wiped, however you may choose to continue to grind here if you wish." << endl;
            cout << endl << "|1 Go Back / 2 Continue In Your Journey|" << endl;
            do{
            cin >> goback;
            }while(!(goback == 1 || goback == 2));
            if(goback == 1){
            currentmap = 0;
            }
        }
        if(expcurrent >= expneed && playerclass == 1){
            LV++;
            atk++;
            def++;
            atk++;
            def++;
            expcurrent = expcurrent - expneed;
            expneed = expneed*2;
        }

    }while(currentmap != maxmap && hp >= 1 && goback != 2);
    system("cls");
    if(hp <= 0){
        system("cls");
        cout << endl << "GAME OVER." << endl;
        system("pause");
        ingame();
    }
    //SNOWDIN ----------------------------------------------------------------------- SNOWDIN ------------------------------------------------------------------- SNOWDIN
    worldprogress++;
    monsters = 6;
    goback = 0;

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
    if(playerclass != 4){
    store(inventory, invsize, gold, worldprogress, areaprogress);
    }else{
    cout << endl << "You reply back, stating that you'd rather put your anger towards something that has actual worth and move on instantly." << endl;
    }
    cout << endl << "And so... You ventured on into the unknown." << endl;
    system("pause");
    cout << endl << "You seem to be almost out of these broken catacombs... You can see a glimmer of shining light." << endl;
    system("pause");
    cout << endl << "But before you could even ponder about what lies after it, a goat-like creature steps in and blocks your way." << endl;
    system("pause");
    cout << endl << "It traps the exit behind you, and summons a bunch of fireballs, which begin to revolve ominously around it." << endl;
    system("pause");
    cout << endl << "There's only one thing you can do now." << endl;
    system("pause");
    bossbattle(1);
    if(hp <= 0){
        system("cls");
        cout << endl << "GAME OVER." << endl;
        system("pause");
        ingame();
    }
    cout << endl << "You come out of your first big battle victorious." << endl;
    system("pause");
    cout << endl << "However, you feel as if troubles aren't over just yet." << endl;
    system("pause");
    cout << endl << "From the distance you can see a bunch of vague figures, they seem a lot stronger..." << endl;
    system("pause");
    cout << endl << "At least you can return to the shop now anytime your low on supplies." << endl;
    system("pause");
    cout << endl << "Either way, you figure it's about time you'd get moving." << endl;
    system("pause");
    cout << endl << "And move on to..." << endl;
    system("pause");
    system("cls");
    cout << endl;
    cout << endl << "ZONE 2 - SNOWDIN";
    currentmap = 0;
    maxmap = 50;
    cout << endl;
    system("pause");
    cout << endl << "You stumble upon a snowy forest, filled with occasional housing and structures here and there." << endl;
    system("pause");
    cout << endl << "Despite the cold empty tone it gave you before, you start to feel like this part of the underground is more alive than the last." << endl;
    system("pause");
    cout << endl << "Either way, you walk along the snowy but walked out path infront of you, and continue on in your journey." << endl;
    system("pause");
    if(playerclass == 4){
        cout << endl << "You also decide to take a rest from your massacre. You may feel well rested, but your statistics have reset...";
        system("pause");
        atk = 3;
        atk = atk*worldprogress;
        hp = maxhp;
        mana = maxmana;
        maxhp = 10*worldprogress;
        hp = maxhp;
        def = 3;
        def = def*worldprogress;
    }
    system("cls");
    goback = 0;
    do{ // cykl chozeni
        string gotoshop = "0";
        cout << endl << "You continue walking through. Your current progress is: " << currentmap << "/" << maxmap << "." <<  endl;
        cout << endl << "Press 1 to open shop" <<  endl;
        cout << endl << "Your current statistics are:" <<  endl;
        cout << endl << "WORLD | " << worldprogress <<  endl;
        cout << endl << "ATK | " << atk <<  endl;
        cout << endl << "DEF | " << def <<  endl;
        cout << endl << "GOLD | " << gold <<  endl;
        cout << endl << "HP | " << hp << "/" << maxhp <<  endl;
        cout << endl << "MANA | " << mana << "/" << maxmana <<  endl;
        if(playerclass == 1){
        cout << endl << "EXP| " << expcurrent;
        cout << endl << "EXP NEEDED| " << expneed;
        cout << endl << "LV | " << LV <<  endl;
        }
        cout << endl << "ITEMS | VVV |" << endl;
        for(int i = 0; i+1<=invsize; i++){
            cout << "Item " << i +1 << ": " << inventory[i][0] << endl;
        }
        cin >> gotoshop;
        if(gotoshop == "1"){
            currentmap = 0;
            store(inventory, invsize, gold, worldprogress, areaprogress);
            gotoshop = "";
        }else{
//---------------------------------------------scenarios
        srand(time(0));  // inicializace generatoru nahodných cisel
        randomevent = rand() % 100 + 1;  // cisla od 0 až do 100
        system("pause");

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

//------------------------------------------------map check
        if(currentmap < maxmap-1){
            currentmap++;
        }else if (currentmap >= maxmap-1 && monsters >= 0){
        cout << endl << "You may have made it to the end, but there are still " << monsters << " monsters blocking your way." << endl;
        cout << endl << "You decide to run back to not get overwhelmed and beat them off one by one." << endl;
        currentmap = 0;
        system("pause");
        }
        if(currentmap >= maxmap-1 && monsters <= 0){
            cout << endl << "You made it to the end and all monsters have been wiped, however you may choose to continue to grind here if you wish." << endl;
            cout << endl << "|1 Go Back / 2 Continue In Your Journey|" << endl;
            do{
            cin >> goback;
            }while(!(goback == 1 || goback == 2));
            if(goback == 1){
            currentmap = 0;
            }
        }
        if(expcurrent >= expneed && playerclass == 1){
            LV++;
            atk++;
            def++;
            expcurrent = expcurrent - expneed;
            expneed = expneed*2;
        }
        }
    }while(currentmap != maxmap && hp >= 1 && goback != 2);
    worldprogress++;
    system("cls");
    if(hp <= 0){
        system("cls");
        cout << endl << "GAME OVER." << endl;
        system("pause");
        ingame();
    }
    cout << endl << "You've finally made it past the dark cold forest, and finally get to move on to another area..." << endl;
    system("pause");
    cout << endl << "However, you maybe wish you hadn't, as two mysterious figures appear before you." << endl;
    system("pause");
    cout << endl << "They once again stop you in your tracks, craving bloodlust this time instead of the mercy they offered in the town before." << endl;
    system("pause");
    cout << endl << "You dont know why, but that doesn't matter now." << endl;
    system("pause");
    cout << endl << "If you want to see the light of day ever again, you must go forward..." << endl;
    system("pause");
    cout << endl << "But first, you must get through the figures infront of you." << endl;
    system("pause");
    cout << endl << "An armored skeleton named Papyrus, and a strong fish-like creature named Undyne." << endl;
    system("pause");
    bossbattle(2);
    if(hp <= 0){
        system("cls");
        cout << endl << "GAME OVER." << endl;
        system("pause");
        ingame();
    }
    if(playerclass != 4){
    store(inventory, invsize, gold, worldprogress, areaprogress);
    }
    cout << endl << "After what seems like an eternity, you finally kill them both and get to see the next area." << endl;
    system("pause");
    cout << endl << "As you walk through, your surroundings change from cold to hot, the air feeling heavier than before." << endl;
    system("pause");
    cout << endl << "Looking around, you find yourself in..." << endl;
    cout << endl;
    cout << endl << "ZONE 3 - HOTLAND";
    currentmap = 0;
    maxmap = 100;
    monsters = 12;
    cout << endl;
    cout << endl << "It's a steamy, hot, lava filled biome filled with more dangerous enemies." << endl;
    system("pause");
    cout << endl << "I guess it isn't over just yet." << endl;
    system("pause");
    cout << endl << "However, that doesn't discourage you, so you continue on, for hopefully, the last time." << endl;
    system("pause");
    if(playerclass == 4){
        cout << endl << "You also decide to take a rest from your massacre. You may feel well rested, but your statistics have reset...";
        system("pause");
        atk = 3;
        atk = atk*worldprogress;
        hp = maxhp;
        mana = maxmana;
        maxhp = 10*worldprogress;
        hp = maxhp;
        def = 3;
        def = def*worldprogress;
    }
    system("cls");
    do{ // cykl chozeni
        string gotoshop = "0";
        cout << endl << "You continue walking through. Your current progress is: " << currentmap << "/" << maxmap << "." <<  endl;
        cout << endl << "Press 1 to open shop" <<  endl;
        cout << endl << "Your current statistics are:" <<  endl;
        cout << endl << "WORLD | " << worldprogress <<  endl;
        cout << endl << "ATK | " << atk <<  endl;
        cout << endl << "DEF | " << def <<  endl;
        cout << endl << "GOLD | " << gold <<  endl;
        cout << endl << "HP | " << hp << "/" << maxhp <<  endl;
        cout << endl << "MANA | " << mana << "/" << maxmana <<  endl;
        if(playerclass == 1){
        cout << endl << "EXP| " << expcurrent;
        cout << endl << "EXP NEEDED| " << expneed;
        cout << endl << "LV | " << LV <<  endl;
        }
        cout << endl << "ITEMS | VVV |" << endl;
        for(int i = 0; i+1<=invsize; i++){
            cout << "Item " << i +1 << ": " << inventory[i][0] << endl;
        }
        cin >> gotoshop;
        if(gotoshop == "1"){
            currentmap = 0;
            store(inventory, invsize, gold, worldprogress, areaprogress);
            gotoshop = "";
        }else{
//---------------------------------------------scenarios
        srand(time(0));  // inicializace generatoru nahodných cisel
        randomevent = rand() % 100 + 1;  // cisla od 0 až do 100
        system("pause");

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

//------------------------------------------------map check
        if(currentmap < maxmap-1){
            currentmap++;
        }else if (currentmap >= maxmap-1 && monsters >= 0){
        cout << endl << "You may have made it to the end, but there are still " << monsters << " monsters blocking your way." << endl;
        cout << endl << "You decide to run back to not get overwhelmed and beat them off one by one." << endl;
        currentmap = 0;
        system("pause");
        }
        if(currentmap >= maxmap-1 && monsters <= 0){
            cout << endl << "You made it to the end and all monsters have been wiped, however you may choose to continue to grind here if you wish." << endl;
            cout << endl << "|1 Go Back / 2 Continue In Your Journey|" << endl;
            do{
            cin >> goback;
            }while(!(goback == 1 || goback == 2));
            if(goback == 1){
            currentmap = 0;
            }
        }
        if(expcurrent >= expneed && playerclass == 1){
            LV++;
            atk++;
            def++;
            expcurrent = expcurrent - expneed;
            expneed = expneed*2;
        }
        }
    }while(currentmap != maxmap && hp >= 1 && goback != 2);
    worldprogress++;
    system("cls");
    if(hp <= 0){
        system("cls");
        cout << endl << "GAME OVER." << endl;
        system("pause");
        ingame();
    }
    cout << endl << "You've made it, you see the light." << endl;
    system("pause");
    cout << endl << "Victory... Just within your rea-" << endl;
    _sleep(700);
    cout << endl << "Aaaand would you look at that, another boss!" << endl;
    system("pause");
    cout << endl << "...Is it a boss?" << endl;
    system("pause");
    cout << endl << "It has a few dice and cards, a funny looking top hat and suit... Surely, it can't be that bad." << endl;
    system("pause");
    cout << endl << "It literally looks like it's just here to play a game of poker or some other stupid chance game!" << endl;
    system("pause");
    cout << endl << "...Hey wait isn't this game entirely up to chance?" << endl;
    system("pause");
    cout << endl << "Oh no." << endl;
    system("pause");
    bossbattle(3);
    if(hp <= 0){
        system("cls");
        cout << endl << "GAME OVER." << endl;
        system("pause");
        ingame();
    }
    system("cls");
    cout << endl << "The shuffler takes it's last breath as you best it's unfair game of chance." << endl;
    system("pause");
    cout << endl << "Finally, with him gone, you can finish this journey once and for all and finally..." << endl;
    system("pause");
    cout << endl << "Escape." << endl;
    system("pause");
    cout << endl << "THE";
    _sleep(1000);
    cout << " END.";
    _sleep(3000);
    cout << endl << endl << "-CREDITS-" << endl << endl;
    cout << "Who i'd like to thank:" << endl;
    _sleep(1000);
    cout << "Me" << endl;
    _sleep(1000);
    cout << "You" << endl;
    _sleep(1000);
    cout << "...Toby Fox?" << endl;
    _sleep(1000);
    cout << "Um... Who else uhh..." << endl;
    _sleep(1000);
    cout << "My teacher!!! Yeah!!!" << endl;
    _sleep(1000);
    cout << "Aaand...You again, for playing. :D" << endl;
    system("pause");
    cout << "Press any key to start the game over." << endl;
    system("pause");
    ingame();

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
