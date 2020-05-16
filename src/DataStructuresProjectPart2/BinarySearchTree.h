#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "EqualityCompare.h"
#include "KeyNotFoundException.h"
#include <iostream>

#include "DuplicateKeyException.h"

using namespace std;

template <class TValue>
class BinarySearchTree
{
private:
	class TreeNode
	{
	private:
		
	public:
		int _key;
		TValue _value;
		TreeNode* _left;
		TreeNode* _right;

		TreeNode(int key, TValue value) : _key(key), _value(value), _left(nullptr), _right(nullptr)
		{
		}

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

			if (_right != nullptr)
			{
				return _right->Find(key);
			}

			throw KeyNotFoundException();
		}

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

		TreeNode& operator=(TreeNode* other)
		{
			_key = other->_key;
			_value = other->_value;
			_left = other->_left;
			_right = other->_right;

			return *this;
		}

		void Delete(int key, TreeNode** pointerToThis)
		{
			int compare = EqualityComparer::Instance.Compare(key, _key);
			if (compare == 0)
			{
				if(_left==nullptr&&_right==nullptr)
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
			else if(compare < 0)
			{
				_left->Delete(key, &_left);
			}
			else
			{
				_right->Delete(key, &_right);
			}
		}

		TreeNode* FindMax()
		{
			if(_right!=nullptr)
			{
				return _right->FindMax();
			}
			return this;
		}
		
		void PrintUntilKey(int key)
		{
			if (_left != nullptr)
			{
				_left->PrintUntilKey(key);
			}
			
			if (EqualityComparer::Instance.Compare(key,_key) <= 0)
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
	BinarySearchTree(): _root(nullptr)
	{
	}

	~BinarySearchTree()
	{
		MakeEmpty();
	}

	bool IsEmpty() const
	{
		return _root == nullptr;
	}

	void MakeEmpty()
	{
		if (_root != nullptr)
		{
			_root->MakeEmpty();
		}
	}

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


	void Delete(int key)
	{
		if (IsEmpty())
		{
			throw KeyNotFoundException();
		}

		_root->Delete(key, &_root);
	}

	TValue Find(int key) const noexcept(false)
	{
		if (IsEmpty())
		{
			throw KeyNotFoundException();
		}

		return _root->Find(key);
	}

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

	void PrintUntilKey(int key)
	{
		if (!IsEmpty())
		{
			_root->PrintUntilKey(key);
		}
	}
};
#endif // BINARYSEARCHTREE_H
