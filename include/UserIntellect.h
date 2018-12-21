#include "Intellect.h"

using namespace std;


#ifndef SEABATTLE_USERINTELLECT_H
#define SEABATTLE_USERINTELLECT_H


class UserIntellect : public Intellect {
public:
    vector< vector<int> > user_map_for_user, computer_map_for_user;					//maps
    void initialize(vector< vector<int> > &map);									//инициализирование	
    int make_turn(vector<vector<int>> &map1, vector<vector<int>> &map);	//сделать ход
    int answer(pair<int, int> coords, vector<vector<int>> &map);					//
    UserIntellect();
	int getShipsKilled();
protected:
	int ships_killed;
};


#endif //SEABATTLE_USERINTELLECT_H
