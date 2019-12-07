//
// Created by awei
//

#ifndef STELLARIS_FUNCTION_H
#define STELLARIS_FUNCTION_H

#endif //STELLARIS_FUNCTION_H
#include <iostream>
#include<ctime>
#include <vector>

class Species{
private:
    std::string name;
    std::string trait;
public:
    Species();
    void setSpecies(std::string a[2]);
    std::string getName();
    std::string getTrait();
    void show();
};
class Planet{
private:
    Species species;
public:
    Planet();
    std::string getTrait();

};
class tradingStation{
private:
    int money;
public:
    tradingStation();
    int getMoney();
};
class Ability{
private:
    int diplomacy;
    int trading;
    int travelEfficiency;
    int combatManeuvers;
    int conflictEvasion;
    int defensivePerformance;
    int systemsRecovery;
    int mining;
    int offensivePerformance;
public:
    Ability();
    void setAbility(std::string position);
    void newAbility();
    int getDiplomacy();
    int getTrading();
    int getTravelEfficiency();
    int getCombatManeuvers();
    int getDefensivePerformance();
    int getSysRecovery();
    int getConflictEvasion();
    int getMining();
    int getOffensivePerformance();

    void showAbility();
};
class Crew{};
class Officer:public Crew{
private:
    std::string name;
    int age;
    std::string position;
    Ability obj;
public:
    Officer(std::string _name, int _age, std::string _position);
    std::string getName();
    std::string getPosition();
    int getDpl();
    int getTd();
    int getTE();
    int getCM();
    int getDP();
    int getCE();
    int getSR();
    int getMN();
    int getOP();
    void show();
    void die();
};
class Spaceship{
protected:
    std::string name;
    int fuel;
    int food;
    int money;
    int ore;
    std::string moneyType;
    int cargo;
    int combat;
    int mining;
    int travel;
    int speed;
    int sysRecover;
    int cmbtManeuvers;
    int maxHP;
    std::vector<Officer*> crew;
public:
    int HP;
    int crewNumber;
    Spaceship(int buildType);

    Spaceship(int buildType, std::string _name, std::vector<Officer*> staff);
    void setResource(int _fuel, int _food, int _money, int _ore);
    std::vector<Officer*> getOfficer();
    void show();
    void result();
    int getFuel();
    int getFood();
    int getMoney();
    int getOre();

    void damage();
    void repair();
    void cost();
    int getCombat();
    int getCargo();
    int getMining();
    int getCM();

};
class otherSpaceship: public Spaceship{
private:
    Species species;
    int dpl;

public:
    otherSpaceship(char buildType);
    std::string getTrait();
    int getdpl();

};

int randomInt(int a, int b);
void trading(Spaceship &s);
bool fighting(Spaceship &a, Spaceship &b);
void mining(Spaceship &s);
void PlanetEncounter(Spaceship &s);
void SpaceshipEncounter(Spaceship &s);