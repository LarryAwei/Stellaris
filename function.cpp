
//
// Created by awei
//
#include "function.h"
// 5 types of species
std::string speciesName[5][2] = {{"wali", "like_combat"}, {"timi", "like_conflict"}, {"maya", "like_trade"}, {"halo", "no_trade"}, {"bla", "no_diplomacy"}};


// generate random int number
int randomInt(int a, int b){
    return rand()%(b-a+1)+a;
}
//species

Species::Species(){}
void Species::setSpecies(std::string *a) {
    name = a[0];
    trait = a[1];
}

std::string Species::getName() {
    return name;
}
std::string Species::getTrait(){
    return trait;
}
void Species::show(){
    std::cout << name << " " << trait << std::endl;
}

//planet
Planet::Planet(){
    species.setSpecies(speciesName[randomInt(0,4)]);
    std::cout << "it is a planet. the owner is " << species.getName() << std::endl;
}
std::string Planet::getTrait(){ return species.getTrait();}

//trading station

tradingStation::tradingStation(){money = randomInt(1,100);}
int tradingStation::getMoney(){return money;}

//officer's ability

    Ability::Ability(){
        diplomacy = randomInt(1, 7);
        trading = randomInt(1, 7);
        travelEfficiency = randomInt(1, 7);
        combatManeuvers = randomInt(1, 7);
        conflictEvasion = randomInt(1, 7);
        defensivePerformance = randomInt(1, 7);
        systemsRecovery = randomInt(1, 7);
        mining = randomInt(1, 7);
        offensivePerformance = randomInt(1, 7);
    }
    void Ability::setAbility(std::string position){
        if(position == "Captain"){
            diplomacy = randomInt(8, 9);
            trading = randomInt(8, 9);
        }
        else if(position == "Pilot"){
            travelEfficiency = randomInt(8, 9);
            combatManeuvers = randomInt(8, 9);
            conflictEvasion = randomInt(8, 9);
        }
        else if(position == "Engineering"){
            travelEfficiency = randomInt(8, 9);
            combatManeuvers = randomInt(8, 9);
            conflictEvasion = randomInt(8, 9);
            defensivePerformance = randomInt(8, 9);
            systemsRecovery = randomInt(8, 9);
        }
        else if(position == "Mining"){
            mining = randomInt(8, 9);
        }
        else if(position == "Weapons"){
            offensivePerformance = randomInt(8, 9);
            defensivePerformance = randomInt(8, 9);
        }
    }
    void Ability::newAbility(){
        diplomacy=diplomacy-1>0?diplomacy-1:0;
        trading=trading-1>0?trading-1:0;
        travelEfficiency=travelEfficiency-1>0?travelEfficiency-1:0;
        combatManeuvers=combatManeuvers-1>0?combatManeuvers-1:0;
        conflictEvasion=conflictEvasion-1>0?conflictEvasion-1:0;
        defensivePerformance=defensivePerformance-1>0?defensivePerformance:0;
        systemsRecovery=systemsRecovery-1>0?defensivePerformance-1:0;
        mining=mining-1>0?mining-1:0;
        offensivePerformance=offensivePerformance-1>0?offensivePerformance:0;
    }
    int Ability::getDiplomacy(){ return diplomacy; }
    int Ability::getTrading(){ return trading; }
    int Ability::getTravelEfficiency(){return travelEfficiency;}
    int Ability::getCombatManeuvers(){ return combatManeuvers; }
    int Ability::getDefensivePerformance(){ return defensivePerformance; }
    int Ability::getSysRecovery(){ return systemsRecovery;}
    int Ability::getConflictEvasion(){return conflictEvasion;}
    int Ability::getMining(){ return mining; }
    int Ability::getOffensivePerformance(){return offensivePerformance;}

    void Ability::showAbility(){
        std::cout<<"diplomacy:"<<diplomacy<<"  trading:"<<trading<<"  travel efficiency:"<<travelEfficiency<<std::endl;
        std::cout<<"combat maneuvers:"<<combatManeuvers<<"  conflict evasion:"<<conflictEvasion<<"  defensive performance:"<<defensivePerformance<<std::endl;
        std::cout<<"system recovery:"<<systemsRecovery<<"  mining:"<<mining<<"  offensive performance:"<<offensivePerformance<<std::endl;
    }

//officer

    Officer::Officer(std::string _name, int _age, std::string _position){
        name = _name;
        age = _age;
        position = _position;
        obj.setAbility(position);
    }
    std::string Officer::getName(){
        return name;
    }
    std::string Officer::getPosition(){
        return position;
    }
    int Officer::getDpl(){ return obj.getDiplomacy();}
    int Officer::getTd(){ return obj.getTrading();}
    int Officer::getTE(){ return obj.getTravelEfficiency();}
    int Officer::getCM(){ return obj.getCombatManeuvers();}
    int Officer::getDP(){ return obj.getDefensivePerformance();}
    int Officer::getCE(){return obj.getConflictEvasion();}
    int Officer::getSR(){ return obj.getSysRecovery();}
    int Officer::getMN(){ return obj.getMining();}
    int Officer::getOP(){ return obj.getOffensivePerformance();}
    void Officer::show(){
        std::cout<<"officer:"<<name<<" age:"<<age<<" job:"<<position<<std::endl;
        obj.showAbility();
    }
    void Officer::die(){obj.newAbility();}

//spaceship

    Spaceship::Spaceship(int buildType){
        switch(buildType)
        {
            case 1 :
                cargo = 9;
                combat = randomInt(4, 6);
                mining = randomInt(4, 6);
                travel = randomInt(4, 6);
                speed = randomInt(4, 6);
                HP = 100;
                maxHP = 100;
                break;
            case 2 :
                cargo = randomInt(4, 6);
                combat = 9;
                mining = randomInt(4, 6);
                travel = randomInt(4, 6);
                speed = randomInt(4, 6);
                HP = 140;
                maxHP = 140;
                break;
            case 3 :
                cargo = randomInt(4, 6);
                combat = randomInt(4, 6);
                mining = randomInt(4, 6);
                travel = randomInt(4, 6);
                speed = randomInt(4, 6);
                HP = 150;
                maxHP = 150;
                break;
            case 4 :
                cargo = randomInt(4, 6);
                combat = randomInt(4, 6);
                mining = randomInt(4, 6);
                travel = 9;
                speed = randomInt(4, 6);
                HP = 120;
                maxHP = 120;
                break;
            case 5 :
                cargo = randomInt(4, 6);
                combat = randomInt(4, 6);
                mining = randomInt(4, 6);
                travel = randomInt(4, 6);
                speed = 9;
                HP = 60;
                maxHP = 80;
                break;
        }
    }

    Spaceship::Spaceship(int buildType, std::string _name, std::vector<Officer*> staff){
        name = _name;
        crew = staff;
        cmbtManeuvers=std::max(crew[1]->getMN(),crew[2]->getMN());
        sysRecover = crew[2]->getSR();
        switch(buildType)
        {
            case 1 :
                cargo = 9;
                combat = randomInt(4, 6);
                mining = crew[3]->getMN();
                travel = randomInt(4, 6);
                speed = randomInt(4, 6);
                HP = 100;
                maxHP = 100;
                break;
            case 2 :
                cargo = randomInt(4, 6);
                combat = 9;
                mining = crew[3]->getMN();
                travel = randomInt(4, 6);
                speed = randomInt(4, 6);
                HP = 140;
                maxHP = 140;
                break;
            case 3 :
                cargo = randomInt(4, 6);
                combat = randomInt(4, 6);
                mining = crew[3]->getMN();;
                travel = randomInt(4, 6);
                speed = randomInt(4, 6);
                HP = 150;
                maxHP = 150;
                break;
            case 4 :
                cargo = randomInt(4, 6);
                combat = randomInt(4, 6);
                mining = crew[3]->getMN();
                travel = 9;
                speed = randomInt(4, 6);
                HP = 120;
                maxHP = 120;
                break;
            case 5 :
                cargo = randomInt(4, 6);
                combat = randomInt(4, 6);
                mining = crew[3]->getMN();
                travel = randomInt(4, 6);
                speed = 9;
                HP = 60;
                maxHP = 80;
                break;
        }

    }
    void Spaceship::setResource(int _fuel, int _food, int _money, int _ore){
        fuel = _fuel;
        food = _food;
        money = _money;
        ore = _ore;
    }
    std::vector<Officer*> Spaceship::getOfficer(){ return crew;}
    void Spaceship::show(){
        std::cout<<"spaceship name:"<<name<<std::endl;
        std::cout << "resource: fuel:" << fuel << " food:" << food << " money:" << money << " ore:"<<ore<<std::endl;
        std::cout<<"attributes:  cargo:"<<cargo<<" combat:"<<combat<<" mining:"<<mining<<" travel eff:"<<travel<<" speed:"<<speed<<" Combat maneuvers:"<<cmbtManeuvers<<" system recover:"<<sysRecover<<std::endl;
        std::cout<<"HP:"<<HP<<"  crew number:"<<crewNumber<<std::endl;
        crew[0]->show();
        crew[1]->show();
        crew[2]->show();
        crew[3]->show();
        crew[4]->show();
    }
    void Spaceship::result(){
        std::cout<<"spaceship name:"<<name<<std::endl;
        std::cout << "resource: fuel:" << fuel << " food:" << food << " money:" << money << " ore:"<<ore<<std::endl;
        std::cout<<"HP:"<<HP<<"  crew number:"<<crewNumber<<std::endl;
    }
    int Spaceship::getFuel(){return fuel;}
    int Spaceship::getFood(){return food;}
    int Spaceship::getMoney(){return money;}
    int Spaceship::getOre(){return ore;}

    void Spaceship::damage(){
        std::cout<<"HP before:"<<HP<<"  crew number:"<<crewNumber<<std::endl;
        HP -= randomInt(5, 20);
        crewNumber -= randomInt(0, 10);
        std::cout<<"HP now:"<<HP<<"  crew number:"<<crewNumber<<std::endl;
    }
    void Spaceship::repair(){
        if(HP+sysRecover+crewNumber/10<maxHP)
            HP+=sysRecover+crewNumber/10;
        else
            HP=maxHP;
    }
    void Spaceship::cost(){
        food-=crewNumber;
        fuel-=50-travel-speed-crew[1]->getTE();
    }
    int Spaceship::getCombat(){ return combat; }
    int Spaceship::getCargo(){return cargo*100;}
    int Spaceship::getMining(){ return mining;}
    int Spaceship::getCM(){ return cmbtManeuvers+crewNumber/10;}

//alien's spaceship

    otherSpaceship::otherSpaceship(char buildType) : Spaceship(buildType){
        species.setSpecies(speciesName[randomInt(0,4)]);
        dpl = randomInt(1, 9);

    }
    std::string otherSpaceship::getTrait(){
        return species.getTrait();
    }
    int otherSpaceship::getdpl(){ return dpl;}

//trading
void trading(Spaceship &s){
    tradingStation t;
    int a=s.getFuel(),b=s.getFood(),c=s.getMoney(),d=s.getOre();
    std::cout<< "our resource before: fuel:"<< a<<" food:"<< b<<" money:" <<c<<" ore:"<<d<<std::endl;
    if(t.getMoney()>=d){
        c+=d;
        d=0;
    }
    else{
        c+=t.getMoney();
        d-=t.getMoney();
    }

    a+=c/2*(10+s.getOfficer()[0]->getTd());      //half money to buy fuel
    b+=(c-c/2)*(10+s.getOfficer()[0]->getTd());   //half money to buy food
    c=0;
    s.setResource(a,b,c,d);
    std::cout<< "our resource now: fuel:"<< a<<" food:"<< b<<" money:" <<c<<" ore:"<<d<<std::endl;
}
//fighting
bool fighting(Spaceship &a, Spaceship &b){  // a is our spaceship
    int reduceA = a.getCombat()+a.getOfficer()[4]->getOP()-b.getCombat();  //our attack
    int reduceB = b.getCombat()*4-a.getOfficer()[2]->getDP()-a.getOfficer()[4]->getDP()-a.getCM(); //alien's attack
    reduceB = reduceB>0?reduceB:0;
    while(1){
        std::cout << "offence! enemy's HP -" << reduceA << "        ";
        b.HP -= reduceA;
        if(b.HP<=0){
            std::cout<<"we win! ... but ";
            int died = randomInt(0, 50);        //crew die
            died = died>a.crewNumber?a.crewNumber:died;
            std::cout<<died<<" people died. "<< std::endl;
            a.crewNumber-=died;
            return true;
        }
        std::cout<< "defence! our HP -" << reduceB << std::endl;
        a.HP-=reduceB;
        if(a.HP<=0){
            std::cout<<"we lose!"<<std::endl;
            return false;
        }
    }
}
//mining in planet
void mining(Spaceship &s){
    std::cout<< "before mining, our resource: fuel:"<< s.getFuel()<<" food:"<< s.getFood()<<" ore:"<<s.getOre()<<std::endl;
    int _fuel = s.getFuel()+s.getMining()+s.crewNumber;
    int _food = s.getFood()+s.getMining()+s.crewNumber;
    int _money = s.getMoney();
    int _ore = (s.getOre()+s.getMining()+s.crewNumber) < s.getCargo()? (s.getOre()+s.getMining()+s.crewNumber):s.getCargo();
    s.setResource(_fuel,_food,_money,_ore);
    std::cout<< "after mining, our resource now: fuel:"<< _fuel<<" food:"<< _food<<" ore:"<<_ore<<std::endl;
}

void PlanetEncounter(Spaceship &s){
    Planet p;
    if(p.getTrait()=="no_diplomacy"){
        std::cout << "They don't like diplomacy. we should leave." << std::endl;
    }
    else if(p.getTrait()=="like_trade"){
        std::cout << "we can trade with them." << std::endl;
        trading(s);
        mining(s);
    }
    else if(p.getTrait()=="like_conflict"){
        std::cout << "They like conflict. warning!" << std::endl;
        if(randomInt(1,10)<=std::max(s.getOfficer()[1]->getCE(), s.getOfficer()[2]->getCE())){
            std::cout << "we run away!" << std::endl;
        }
        else{
            std::cout<<"conflict happened."<<std::endl;
            s.damage();

        }
    } else {
        mining(s);
    }
}

void SpaceshipEncounter(Spaceship &s){

    otherSpaceship alien(randomInt(1,5));
    if(alien.getTrait()=="no_diplomacy"){
        std::cout << "They don't like diplomacy. we should leave." << std::endl;
        return;
    }
    else if(alien.getTrait()=="like_trade"){
        std::cout << "we can trade with them." << std::endl;
        trading(s);
    }
    else if(alien.getTrait()=="like_conflict"){
        std::cout << "They like conflict. warning!" << std::endl;
        if(randomInt(1,10)<=std::max(s.getOfficer()[1]->getCE(), s.getOfficer()[2]->getCE())){
            std::cout << "we run away!" << std::endl;
        }
        else{
            std::cout << "fighting!" << std::endl;
            if(fighting(s,alien)){
                int p = randomInt(1,10);
                if(p>=7){     // one of officers die randomly
                    int num = randomInt(0,4);
                    std::cout << s.getOfficer()[num]->getName() << " died! we need a new "<<s.getOfficer()[num]->getPosition()<<std::endl;
                    s.crewNumber-=1;
                    s.getOfficer()[num]->die();
                }

            }
        }
    }
    else{
        std::cout << "try Diplomacy... ";
        if(s.getOfficer()[0]->getDpl()>alien.getdpl()){
            std::cout << "success!" << std::endl;
            trading(s);
        }
        else{
            std::cout << "failed!"<<std::endl;
            if(randomInt(1,10)<=std::max(s.getOfficer()[1]->getCE(), s.getOfficer()[2]->getCE())){
                std::cout << "run away! avoid conflict!" << std::endl;
            }
            else{
                std::cout << "fighting!" << std::endl;
                if(fighting(s,alien)){
                    int p = randomInt(1,10);
                    if(p>=7){
                        int num = randomInt(0,4);
                        std::cout << s.getOfficer()[num]->getName() << " died! we need a new "<<s.getOfficer()[num]->getPosition()<<std::endl;
                        s.crewNumber-=1;
                        s.getOfficer()[num]->die();
                    }

                }
            }
        }
    }

}

