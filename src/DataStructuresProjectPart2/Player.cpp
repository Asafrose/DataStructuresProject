#include "Player.h"
#include "Exception.h"

#include <iostream>
#include <sstream>


BinarySearchTree<int> Player::_existingPlayerIdsMapping;

Player::Player(const int& id, const string& firstName, const string& lastName) noexcept(false) : _id(id)
{
	if (firstName.empty())
	{
		throw Exception("first name is empty");
	}
	if (lastName.empty())
	{
		throw Exception("last name is empty");
	}

	_firstName = firstName;
	_lastName = lastName;
	
	if (_existingPlayerIdsMapping.IsKeyExist(_id))
	{
		stringstream stringStream;
		stringStream << "player with same Id already exists [id=" << id << "]";
		throw Exception(stringStream.str());
	}
	else
	{
		_existingPlayerIdsMapping.Insert(id, id);
	}
}

Player* Player::CreatePlayerFromUserInput() noexcept(false)
{
	int id;
	string firstName, lastName;
	cin >> id >> firstName >> lastName;
	return new Player(id, firstName, lastName);
}

int Player::GetId() const
{
	return _id;
}

string Player::GetFirstName() const
{
	return _firstName;
}

string Player::GetLastName() const
{
	return _lastName;
}

bool Player::operator<(const Player& other) const
{
	return _id < other.GetId();
}

bool Player::operator>(const Player& other) const
{
	return _id > other.GetId();
}

Player::~Player()
{
	_existingPlayerIdsMapping.Delete(_id);
}

ostream& operator<<(ostream& os, const Player& player)
{
	os << player._id << " " << player._firstName << " " << player._lastName;
	return os;
}
