#ifndef PLAYER_H
#define PLAYER_H
#include <string>

#include "BinarySearchTree.h"

using namespace std;

//Player data class
class Player
{
private:
	//existing player ids dictionary
	static BinarySearchTree<int> _existingPlayerIdsMapping;
	
	int _id;
	string _firstName;
	string _lastName;

	//ctor
	Player(const int& id, const string& firstName, const string& lastName) noexcept(false);
	
public:
	//static method to create a player from user input
	static Player* CreatePlayerFromUserInput() noexcept(false);

	//gets player id
	int GetId() const;
	//gets player first name
	string GetFirstName() const;
	//gets player last name
	string GetLastName() const;

	//ostream operator
	friend ostream& operator<<(ostream& os, const Player& player);

	//< operator
	bool operator<(const Player& other) const;
	//> operator
	bool operator>(const Player& other) const;

	//dtor
	~Player();
};
#endif // PLAYER_H
