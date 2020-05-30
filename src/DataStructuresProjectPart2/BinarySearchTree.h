#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "EqualityCompare.h"
#include "KeyNotFoundException.h"
#include <iostream>

#include "DuplicateKeyException.h"

using namespace std;

//Dictionary implementation using a binary search tree
template <class TValue>
class BinarySearchTree
{
private:
	//Private TreeNode class
	class TreeNode
	{
	private:
		int _key;
		TValue _value;
		TreeNode* _left;
		TreeNode* _right;

	public:

		//ctor
		TreeNode(int key, TValue value) : _key(key), _value(value), _left(nullptr), _right(nullptr)
		{
		}

		//Find value for given key.
		TValue Find(int key) noexcept(false)
		{
			const int diff = EqualityComparer::Instance.Compare(key, _key);
			if (diff == 0)
			{
				return _value;
			}

			if (diff < 0 && _left != nullptr)
			{
				return _left->Find(key);
			}

			if (diff > 0 && _right != nullptr)
			{
				return _right->Find(key);
			}

			throw KeyNotFoundException();
		}

		//Adds a new child TreeNode recursively according to the TreeNode key.
		void Add(TreeNode* newNode)
		{
			const int diff = EqualityComparer::Instance.Compare(newNode->_key, _key);

			if (diff == 0)
			{
				throw DuplicateKeyException();
			}

			if (diff < 0)
			{
				if (_left == nullptr)
				{
					_left = newNode;
				}
				else
				{
					_left->Add(newNode);
				}
			}
			else
			{
				if (_right == nullptr)
				{
					_right = newNode;
				}
				else
				{
					_right->Add(newNode);
				}
			}
		}

		//Clears the TreeNode and its childs recursively.
		void MakeEmpty()
		{
			if (_left != nullptr)
			{
				_left->MakeEmpty();
			}
			if (_right != nullptr)
			{
				_right->MakeEmpty();
			}
			delete this;
		}

		//delete this node or a child node with a given key
		void Delete(int key, TreeNode** pointerToThis)
		{
			const int compare = EqualityComparer::Instance.Compare(key, _key);
			if (compare == 0)
			{
				if (_left == nullptr && _right == nullptr)
				{
					*pointerToThis = nullptr;
					delete this;
				}
				else if (_left == nullptr)
				{
					*pointerToThis = _right;
					delete this;
				}
				else if (_right == nullptr)
				{
					*pointerToThis = _left;
					delete this;
				}
				else
				{
					TreeNode* max = _left->FindMax();
					_key = max->_key;
					_value = max->_value;
					_left->Delete(max->_key, &_left);
				}
			}
			else if (compare < 0)
			{
				_left->Delete(key, &_left);
			}
			else
			{
				_right->Delete(key, &_right);
			}
		}

		//Finds the child with biggest key.
		TreeNode* FindMax()
		{
			if (_right != nullptr)
			{
				return _right->FindMax();
			}
			return this;
		}

		//prints all child values where their Key is lower than given key
		void PrintUntilKey(int key)
		{
			if (_left != nullptr)
			{
				_left->PrintUntilKey(key);
			}

			if (EqualityComparer::Instance.Compare(key, _key) <= 0)
			{
				return;
			}

			cout << *_value << endl;

			if (_right != nullptr)
			{
				_right->PrintUntilKey(key);
			}
		}
	};

	TreeNode* _root;
public:
	//ctor
	BinarySearchTree(): _root(nullptr)
	{
	}

	//dtor
	~BinarySearchTree()
	{
		MakeEmpty();
	}

	//Returns true if tree is empty
	bool IsEmpty() const
	{
		return _root == nullptr;
	}

	//Clears the tree from data
	void MakeEmpty()
	{
		if (IsEmpty())
		{
			return;
		}

		_root->MakeEmpty();
		_root = nullptr;
	}

	//Insert new key and value to tree
	void Insert(int key, TValue value)
	{
		TreeNode* newNode = new TreeNode(key, value);
		if (IsEmpty())
		{
			_root = newNode;
		}
		else
		{
			_root->Add(newNode);
		}
	}

	//Delete key from tree
	void Delete(int key)
	{
		if (IsEmpty())
		{
			throw KeyNotFoundException();
		}

		_root->Delete(key, &_root);
	}

	//Get value from tree by key
	TValue Find(int key) const noexcept(false)
	{
		if (IsEmpty())
		{
			throw KeyNotFoundException();
		}

		return _root->Find(key);
	}

	//Returns true if a certain key exists
	bool IsKeyExist(int key) const
	{
		try
		{
			Find(key);
			return true;
		}
		catch (KeyNotFoundException)
		{
			return false;
		}
	};

	//Prints tree values in order until reaching a certain key
	void PrintUntilKey(int key)
	{
		if (IsEmpty())
		{
			return;
		}
		
		_root->PrintUntilKey(key);
	}
};
#endif // BINARYSEARCHTREE_H
