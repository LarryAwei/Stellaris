#include "function.h"

int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL));
    std::vector<Officer*> staff;          //generate officer
    Officer o1("1", 20, "Captain");
    Officer o2("2", 20, "Pilot");
    Officer o3("3", 20, "Engineering");
    Officer o4("4", 20, "Mining");
    Officer o5("5", 20, "Weapons");
    staff.push_back(&o1);
    staff.push_back(&o2);
    staff.push_back(&o3);
    staff.push_back(&o4);
    staff.push_back(&o5);
    Spaceship s(randomInt(1,5), "hali", staff);
    s.setResource(200,200,0,0);
    s.crewNumber = 50;
    s.show();
    std::cout<<"-----------------------information end---------------------------"<<std::endl;
    std::string arg=std::string(argv[1]);
    int j = atoi(arg.c_str());
    int i=0;
    //std::cin>> i;
    while(i++<j){
        std::cout<<"day"<< i<<":  ";
        int tmp = randomInt(1,100);
        if(tmp>90){
            std::cout << "Some other space thing" << std::endl;
            if(randomInt(1,5)>3){
                std::cout<< "falling stone！！！"<<std::endl;
                std::cout << "Game Over!" << std::endl;
                break;
            } else
                std::cout<<"nothing happen."<<std::endl;
        }
        else if(tmp>75){
            std::cout << "Empty sector" << std::endl;
        }
        else if(tmp>60){
            std::cout << "Trading station" << std::endl;
            trading(s);
        }
        else if(tmp>35){
            std::cout << "Planet encounter" << std::endl;
            PlanetEncounter(s);

        }
        else {
            std::cout << "Spaceship encounter" << std::endl;
            SpaceshipEncounter(s);
        }
        if(s.HP<=0||s.getFood()<=0||s.getFuel()<=0||s.crewNumber<=0){
            std::cout << " GAME OVER "<< std::endl;

            break;
        }
        s.repair();
        s.cost();
        std::cout<<"----------------------------------------"<<std::endl;
    }
    std::cout<<"result:"<<std::endl;
    s.result();

    return 0;
}