#ifndef PLAYER_H
#define PLAYER_H
#include <string>

#include "BinarySearchTree.h"

using namespace std;

class Player
{
private:
	static BinarySearchTree<int> _existingPlayerIdsMapping;
	
	int _id;
	string _firstName;
	string _lastName;

	Player(const int& id, const string& firstName, const string& lastName) noexcept(false);
	
public:
	static Player* CreatePlayerFromUserInput() noexcept(false);

	int GetId() const;
	string GetFirstName() const;
	string GetLastName() const;

	friend ostream& operator<<(ostream& os, const Player& player);

	bool operator<(const Player& other) const;
	bool operator>(const Player& other) const;
	~Player();
};
#endif // PLAYER_H
