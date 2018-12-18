#include "../include/UserIntellect.h"
#include "../include/ComputerIntellect.h"
#include "../include/PresentationController.h"
#include <ctime>


using namespace std;

int main() {
	srand(time(NULL));
    vector< vector<int> > empty(12, vector<int>(12, 0));
    UserIntellect userInt;
    ComputerIntellect pcInt;
    PresentationController presentationController(30, 10);
	pcInt.initialize(pcInt.computer_map_for_comp);
    if(!presentationController.start_of_the_game("Do you want to get a random map?"))
	{
		userInt.initialize(userInt.user_map_for_user);
		pcInt.initialize(pcInt.computer_map_for_comp);
        presentationController.print(userInt.user_map_for_user, pcInt.computer_map_for_comp);
    }
	else 
	{
        int counter = 0;
        do {
			userInt.user_map_for_user = empty;
			pcInt.computer_map_for_comp = empty;
			pcInt.initialize(userInt.user_map_for_user);
			pcInt.initialize(pcInt.computer_map_for_comp);
            presentationController.print(userInt.user_map_for_user, userInt.computer_map_for_user);
            counter++;
        } while(!presentationController.start_of_the_game("This one?"));
    }

	do {
		userInt.make_turn(userInt.computer_map_for_user, pcInt.computer_map_for_comp, 0);
		pcInt.make_turn(pcInt.user_map_for_comp, userInt.user_map_for_user, 4);
		presentationController.print(userInt.user_map_for_user, userInt.computer_map_for_user);
	} while (true);
    return 0;
}