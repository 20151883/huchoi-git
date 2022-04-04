#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include <memory>
#include <iterator>
#include "etc/etc.hpp"
#include "vector.hpp"
namespace ft
{
	template <typename Key, typename T, class Compare = std::less<Key>, class Allocator = std::allocator< pair< const Key, T > > >
	class map
	{
		public:
			//Memeber type
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename ft::pair<const Key, T> value_type;
			typedef	typename std::size_t size_type;
			typedef int difference_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;

		private:
			typedef pair<key_type, mapped_type> BTData;
			typedef BTData	BSTData;

			struct BTreeNode
			{
				BSTData 	value;
				BTreeNode * left;
				BTreeNode * right;
				BTreeNode * parent;
				BTreeNode ** root;
			};
		public:
			class value_compare
			{
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
				protected:
					Compare comp;
					value_compare(Compare c):comp(c) {}
				public:
					value_compare():comp() {}
					bool operator()( const value_type& lhs, const value_type& rhs ) const { return comp(lhs.first, rhs.first); }
			};
		private:

			Allocator 			_allocator;
			BTreeNode			*_endNode;
			BTreeNode			*_RNode;
			key_compare			_kcompare;
			size_type			_size;
			value_compare		_vcompare;

		private:

			BTreeNode * MakeBTreeNode()
			{
				BTreeNode *nd = new BTreeNode;

				nd->left = _endNode;
				nd->right = _endNode;
				nd->parent = NULL;
				return nd;
			}

			BTData GetData(BTreeNode * bt) const
			{
				return bt->value;
			}

			void SetData(BTreeNode * bt, const BTData &value)
			{
				bt->value = value;
			}

			BTreeNode * GetLeftSubTree(BTreeNode * bt) const
			{
				return bt->left;
			}

			BTreeNode * GetRightSubTree(BTreeNode * bt) const
			{
				return bt->right;
			}

			void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
			{
				BTreeNode *Root = main;
				while (Root->parent != NULL)
					Root = Root->parent;
				sub->root = &_RNode;
				_endNode->root = &_RNode;
				if(main->left != _endNode)
					delete main->left;
				main->left = sub;
				if (sub != _endNode)
					sub->parent = main;
			}

			void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
			{
				BTreeNode *Root = main;
				while (Root->parent != NULL)
					Root = Root->parent;
				sub->root = &_RNode;
				_endNode->root = &_RNode;
				if(main->right != _endNode)
					delete main->right;
				main->right = sub;
				if (sub != _endNode)
					sub->parent = main;
			}

			BTreeNode * RemoveLeftSubTree(BTreeNode * bt)
			{
				BTreeNode * delNode = NULL;

				if(bt != _endNode) {
					delNode = bt->left;
					bt->left = _endNode;
				}
				return delNode;
			}

			BTreeNode * RemoveRightSubTree(BTreeNode * bt)
			{
				BTreeNode * delNode = NULL;

				if(bt != _endNode) {
					delNode = bt->right;
					bt->right = _endNode;
				}
				return delNode;
			}

			void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub)
			{
				main->left = sub;
				if (sub != _endNode)
					sub->parent = main;
			}

			void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub)
			{
				main->right = sub;
				if (sub != _endNode)
					sub->parent = main;
			}

			void BSTMakeAndInit(BTreeNode ** pRoot)
			{
				*pRoot = NULL;
			}

			BSTData BSTGetNodeData(BTreeNode * bst)
			{
				return GetData(bst);
			}

			void BSTInsert(BTreeNode ** pRoot, BSTData data)
			{
				BTreeNode * pNode = NULL;
				BTreeNode * cNode = *pRoot;
				BTreeNode * nNode = NULL;

				while(cNode != _endNode)
				{
					if(data.first == GetData(cNode).first)
						return;
					pNode = cNode;
					if(_kcompare(data.first, GetData(cNode).first) == true)
						{cNode = GetLeftSubTree(cNode); }
					else
						cNode = GetRightSubTree(cNode);
				}
				nNode = MakeBTreeNode();
				SetData(nNode, data);

				if(pNode != NULL)
				{
					if(_kcompare(data.first, GetData(pNode).first) == true)
					{	MakeLeftSubTree(pNode, nNode);}
					else
						MakeRightSubTree(pNode, nNode);
				}
				else
				{
					*pRoot = nNode;
					nNode->root = &_RNode;
					_endNode->root = &_RNode;
				}
			}

			BTreeNode * BSTSearch(BTreeNode * bst, Key target) const
			{
				BTreeNode * cNode = bst;
				BSTData cd;
				if (bst == NULL || bst == _endNode)
					return _endNode;
				while(cNode != _endNode)
				{
					cd = GetData(cNode);

					if(!_kcompare(target, GetData(cNode).first) && !_kcompare(GetData(cNode).first, target))
						return cNode;
					else if (_kcompare(target, cd.first) == true)
						cNode = GetLeftSubTree(cNode);
					else
						cNode = GetRightSubTree(cNode);
				}
				return _endNode;
			}


			BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
			{

				BTreeNode * pVRoot = MakeBTreeNode();
				BTreeNode * pNode = pVRoot;
				BTreeNode * cNode = *pRoot;
				BTreeNode * dNode;

				ChangeRightSubTree(pVRoot, *pRoot);
				_RNode->parent = NULL;
				while( cNode != _endNode && ((_kcompare(target.first, GetData(cNode).first) || _kcompare(GetData(cNode).first, target.first))) )
				{
					pNode = cNode;

					if (_kcompare(target.first, GetData(cNode).first) == true)
						cNode = GetLeftSubTree(cNode);
					else
						cNode = GetRightSubTree(cNode);
				}

				if(cNode == _endNode)
					return NULL;

				dNode = cNode;
				if(GetLeftSubTree(dNode) == _endNode && GetRightSubTree(dNode) == _endNode)
				{
					if(GetLeftSubTree(pNode) == dNode)
						RemoveLeftSubTree(pNode);
					else
						RemoveRightSubTree(pNode);
				}

				else if(GetLeftSubTree(dNode) == _endNode || GetRightSubTree(dNode) == _endNode)
				{
					BTreeNode * dcNode;

					if(GetLeftSubTree(dNode) != _endNode)
						dcNode = GetLeftSubTree(dNode);
					else
						dcNode = GetRightSubTree(dNode);

					if(GetLeftSubTree(pNode) == dNode)
						ChangeLeftSubTree(pNode, dcNode);
					else
						ChangeRightSubTree(pNode, dcNode);
				}

				else
				{
					BTreeNode * mNode = GetRightSubTree(dNode);
					BTreeNode * mpNode = dNode;
					BSTData delData;

					while(GetLeftSubTree(mNode) != _endNode)
					{
						mpNode = mNode;
						mNode = GetLeftSubTree(mNode);
					}

					delData = GetData(dNode);
					SetData(dNode, GetData(mNode));

					if(GetLeftSubTree(mpNode) == mNode)
						ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
					else
						ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

					dNode = mNode;
					SetData(dNode, delData);
				}
				if(GetRightSubTree(pVRoot) != *pRoot)
				{
					*pRoot = GetRightSubTree(pVRoot);
					_RNode->parent = NULL;
					RenewerRoot(_RNode);
				}
				RenewerRoot(_RNode);
				delete pVRoot;
				return dNode;
			}
			BTreeNode *_utils_for_lower(const key_type &target) const
			{
				BTreeNode * cNode = _RNode;
				BTreeNode * pNode = cNode;   // current node
				BSTData cd;    // current data
				while(cNode != _endNode)
				{
					cd = GetData(cNode);

					if(!_kcompare(target, GetData(cNode).first) && !_kcompare(GetData(cNode).first, target))
						return cNode; // 이때는 cNode 반환하는게 맞음
					else if (_kcompare(target, cd.first) == true)
					{
						pNode = cNode;
						cNode = GetLeftSubTree(cNode);
					}
					else
					{
						pNode = cNode;
						cNode = GetRightSubTree(cNode);
					}
				}
				if (pNode == _RightestNode())
					return _endNode;
				else
					return pNode;
			}
			BTreeNode * _RightestNode() const
			{
				BTreeNode *ret = _RNode;
				while (ret->right != _endNode)
					ret = ret->right;
				return ret;

			}
			void RenewerRoot(BTreeNode * bt)
			{
				if(bt == _endNode || bt == NULL)
					return;
				RenewerRoot(bt->left);
				bt->root = &_RNode;
				RenewerRoot(bt->right);
				_endNode->root = &_RNode;
			}

			void _deleteAllNode(BTreeNode * bt)
			{
				if (bt == _endNode || bt == NULL)
					return ;

				_deleteAllNode(bt->left);
				_deleteAllNode(bt->right);

				delete bt;
			}
			BTreeNode *_LeftestNode(BTreeNode *root) const
			{
				BTreeNode *pNode = NULL;
				BTreeNode *Node = root;
				while (Node->left != Node)
				{
					pNode = Node;
					Node = pNode->left;
				}
				if (pNode == NULL)
				{	return Node; }
				return pNode;
			}
			 BTreeNode *_findParent(BTreeNode *Root, BTreeNode *current )
			{
				BTreeNode *pNode = NULL;
				BTreeNode *Node = Root;
				if (is_endNode(current))
					return NULL;
				else if (current == Root)
					return Root;
				while(Node != _endNode)
				{
					if(current == Node)
						return pNode;
					else if ( _keycompare(current->value.first, Node->value.first) == true )
					{
						pNode = Node;
						Node = Node->left;
					}
					else
					{
						pNode = Node;
						Node = Node->right;
					}
				}
				return NULL;
			}

		public:


			class iterator
			{
				public:
					typedef std::bidirectional_iterator_tag iterator_category;
					typedef pair<key_type, mapped_type> value_type;
					typedef long int difference_type;
					typedef pair<key_type, mapped_type>* pointer;
					typedef pair<key_type, mapped_type>& reference;
					typedef const pair<key_type, mapped_type>* const_pointer;
					typedef const pair<key_type, mapped_type>& const_reference;

				private:
					BTreeNode *_NodePtr;
				public:
					iterator() { _NodePtr = NULL;  }
					iterator(BTreeNode *p_node) :_NodePtr(p_node) { }
					iterator(const iterator &other):_NodePtr(other._NodePtr) { }
					iterator &operator=(const iterator &other) { _NodePtr = other._NodePtr; return *this; }
					BTreeNode *base() const { return _NodePtr; }
					~iterator() { }

					bool operator==(const iterator &rhs) const { return _NodePtr == rhs._NodePtr; }
					reference operator*() { return _NodePtr->value; }
					iterator &operator++()
					{
						BTreeNode *nextElement = _nextElement(_NodePtr);
						if (_NodePtr == nextElement)
							throw std::runtime_error("( iterator operator++()함수에서 발생 ) _endNode이상은 ++못함.");
						_NodePtr = nextElement;
						return (*this);
					}
					bool operator!=(const iterator &rhs) const { return !(*this == rhs); }
					pointer operator->() const { return &(_NodePtr->value); }
					const iterator operator++(int)
					{
						iterator ret(*this);
						++(*this);
						return ret;
					}
					iterator &operator--()
					{
						BTreeNode *beforeElement = _beforeElement(_NodePtr);
						if (beforeElement == NULL)
							throw std::runtime_error("( iterator operator--()함수에서 발생 ) begin()에 해당하는 것 이상은 -- 못함.");
						_NodePtr = beforeElement;
						return (*this);
					}
					const iterator operator--(int)
					{
						iterator ret(*this);
						--(*this);
						return ret;
					}
					private:

						bool _this_node_is_left(BTreeNode *c)
						{
							if (c == NULL)
								return false;
							BTreeNode *pNode = c->parent;
							if (pNode == NULL)
								return false;
							if (c == pNode->left)
								return true;
							else
								return false;
						}
						bool _this_node_is_right(BTreeNode *c)
						{
							if (c == NULL)
								return false;
							BTreeNode *pNode = c->parent;
							if (pNode == NULL)
								return false;
							if (c == pNode->right)
								return true;
							else
								return false;
						}
						bool is_endNode(BTreeNode *c)
						{
							if (c->left == c)
								return true;
							else
								return false;
						}
						BTreeNode *getEndNode(BTreeNode *c)
						{
							BTreeNode *target = c;
							while (target->left != target)
								target = target->left;
							return target;
						}

						BTreeNode *_nextElement(BTreeNode *current)
						{
							BTreeNode *Node = current;
							if (is_endNode(current))
								return NULL;
							BTreeNode *termainalNode = getEndNode(Node);
							if (Node->right != termainalNode)
							{
								Node = Node->right;
								while (Node->left != termainalNode)
									Node = Node->left;
								return Node;
							}
							else
							{
								while (_this_node_is_right(Node))
									Node = Node->parent;
								if (Node->parent == NULL)
									return termainalNode;
								return Node->parent;
							}
						}
						BTreeNode *_beforeElement(BTreeNode *current)
						{
							BTreeNode *Node = current;
							if (Node == NULL)
								return NULL;
							else if (is_endNode(current))
							{
								BTreeNode *Root = *current->root;
								return _RightestNode(Root);
							}
							BTreeNode *termainalNode = getEndNode(Node);
							if (Node->left != termainalNode)
							{
								Node = Node->left;
								while (Node->right != termainalNode)
									Node = Node->right;
								return Node;
							}
							else
							{
								while (_this_node_is_left(Node))
									Node = Node->parent;
								if (Node->parent == NULL)
									return NULL;
								return Node->parent;
							}
						}
						BTreeNode *_LeftestNode(BTreeNode *root)
						{
							BTreeNode *pNode = NULL;
							BTreeNode *Node = root;
							while (Node->left != Node)
							{
								pNode = Node;
								Node = pNode->left;
							}
							if (pNode == NULL)
								return Node;
							return pNode;
						}
						BTreeNode *_RightestNode(BTreeNode *root)
						{
							BTreeNode *pNode = NULL;
							BTreeNode *Node = root;
							while (Node->right != Node)
							{
								pNode = Node;
								Node = pNode->right;
							}

							if (pNode == NULL)
								return Node;
							return pNode;
						}
			};
			class const_iterator
			{
				public:
					typedef std::bidirectional_iterator_tag iterator_category;
					typedef const pair<key_type, mapped_type> value_type;
					typedef long int difference_type;
					typedef const pair<key_type, mapped_type>* pointer;
					typedef const pair<key_type, mapped_type>& reference;
				private:
					BTreeNode *_NodePtr;
				public:
					friend bool operator!=(const const_iterator &lhs, const const_iterator &rhs)  { return !(lhs == rhs); }
					const_iterator() { _NodePtr = NULL;  }
					const_iterator(BTreeNode *p_node) :_NodePtr(p_node) { }
					const_iterator(const const_iterator &other):_NodePtr(other._NodePtr) { }
					const_iterator(const iterator &other):_NodePtr(other.base()) { }
					const_iterator &operator=(const const_iterator &other) { _NodePtr = other._NodePtr; return *this; }
					const_iterator &operator=(const iterator &other) { _NodePtr = other.base(); return *this; }
					BTreeNode *base() { return _NodePtr; }
					~const_iterator() { }
					friend bool operator==(const const_iterator &lhs, const const_iterator &rhs) { return lhs._NodePtr == rhs._NodePtr; }
					value_type &operator*() const { return _NodePtr->value; }
					const_iterator &operator++()
					{
						BTreeNode *beforeElement = _nextElement(_NodePtr);
						if (beforeElement == NULL)
							throw std::runtime_error("( iterator operator--()함수에서 발생 ) begin()에 해당하는 것 이상은 -- 못함.");
						_NodePtr = beforeElement;
						return (*this);
					}
					value_type *operator->() const { return &(_NodePtr->value); }
					const const_iterator operator++(int)
					{
						const_iterator ret(*this);
						++(*this);
						return ret;
					}
					const_iterator &operator--()
					{
						BTreeNode *nextElement = _beforeElement(_NodePtr);
						if (_NodePtr == nextElement)
							throw std::runtime_error("( iterator operator++()함수에서 발생 ) _endNode이상은 ++못함.");
						_NodePtr = nextElement;
						return (*this);
					}
					const const_iterator operator--(int)
					{
						const_iterator ret(*this);
						--(*this);
						return ret;
					}



					private:

						bool _this_node_is_left(BTreeNode *c) const
						{
							if (c == NULL)
								return false;
							BTreeNode *pNode = c->parent;
							if (pNode == NULL)
								return false;
							if (c == pNode->left)
								return true;
							else
								return false;
						}
						bool _this_node_is_right(BTreeNode *c) const
						{
							if (c == NULL)
								return false;
							BTreeNode *pNode = c->parent;
							if (pNode == NULL)
								return false;
							if (c == pNode->right)
								return true;
							else
								return false;
						}
						bool is_endNode(BTreeNode *c)const
						{
							if (c->left == c)
								return true;
							else
								return false;
						}
						BTreeNode *getEndNode(BTreeNode *c)const
						{
							BTreeNode *target = c;
							while (target->left != target)
								target = target->left;
							return target;
						}

						BTreeNode *_nextElement(BTreeNode *current) const
						{
							BTreeNode *Node = current;
							if (is_endNode(current))
								return NULL;
							BTreeNode *termainalNode = getEndNode(Node);
							if (Node->right != termainalNode)
							{
								Node = Node->right;
								while (Node->left != termainalNode)
									Node = Node->left;
								return Node;
							}
							else
							{
								while (_this_node_is_right(Node))
									Node = Node->parent;
								if (Node->parent == NULL)
									return termainalNode;
								return Node->parent;
							}
						}
						BTreeNode *_beforeElement(BTreeNode *current) const
						{
							BTreeNode *Node = current;
							if (Node == NULL)
								return NULL;
							else if (is_endNode(current))
							{
								BTreeNode *Root = *current->root;
								return _RightestNode(Root);
							}
							BTreeNode *termainalNode = getEndNode(Node);
							if (Node->left != termainalNode)
							{
								Node = Node->left;
								while (Node->right != termainalNode)
									Node = Node->right;
								return Node;
							}
							else
							{
								while (_this_node_is_left(Node))
									Node = Node->parent;
								if (Node->parent == NULL)
									return NULL;
								return Node->parent;
							}
						}
						BTreeNode *_LeftestNode(BTreeNode *root) const
						{
							BTreeNode *pNode = NULL;
							BTreeNode *Node = root;
							while (Node->left != Node)
							{
								pNode = Node;
								Node = pNode->left;
							}
							if (pNode == NULL)
								return Node;
							return pNode;
						}
						BTreeNode *_RightestNode(BTreeNode *root) const
						{
							BTreeNode *pNode = NULL;
							BTreeNode *Node = root;
							while (Node->right != Node)
							{
								pNode = Node;
								Node = pNode->right;
							}

							if (pNode == NULL)
								return Node;
							return pNode;
						}
			};
			typedef iterator iterator;
			typedef const_iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		public:
			//Member functions
			map():_allocator(), _endNode(), _RNode(), _kcompare(), _size(0), _vcompare()
			{
				_endNode = new BTreeNode;
				_endNode->parent = NULL;
				_endNode->left = _endNode;
				_endNode->right = _endNode;
				_RNode = _endNode;
				_endNode->root = &_RNode;
			}
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() ):_allocator(alloc), _endNode(), _RNode(), _kcompare(comp), _size(0), _vcompare()
			{
				_endNode = new BTreeNode;
				_endNode->parent = NULL;
				_endNode->left = _endNode;
				_endNode->right = _endNode;
				_RNode = _endNode;
				_endNode->root = &_RNode;
			}
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):_allocator(alloc), _endNode(), _RNode(), _kcompare(comp), _size(0), _vcompare()
			{
				_endNode = new BTreeNode;
				_endNode->parent = NULL;
				_endNode->left = _endNode;
				_endNode->right = _endNode;
				_RNode = _endNode;
				_endNode->root = &_RNode;
				if (std::distance(first, last) < 0 )
					throw std::runtime_error("( void insert( InputIt first, InputIt last )함수에서 발생 ) first가 last보다 큽니다.");
				for (; first != last; first++)
				{
					insert(*first);
				}

			}
			map( const map& other ):_allocator(other._allocator), _endNode(), _RNode(), _kcompare(other._kcompare), _size(0), _vcompare(other._vcompare)
			{
				_endNode = new BTreeNode;
				_endNode->parent = NULL;
				_endNode->left = _endNode;
				_endNode->right = _endNode;
				_RNode = _endNode;
				_endNode->root = &_RNode;
				for (const_iterator i = other.begin(); i != other.end(); i++)
					insert(*i);
			}
			~map() { clear(); delete _endNode; _endNode = NULL; }
			map operator=(const map &src)
			{
				_allocator = src._allocator;
				_vcompare = src._vcompare;
				clear();
				for (const_iterator i = src.begin(); i != src.end(); i++)
					insert(*i);
				_kcompare = src._kcompare;
				return *this;
			}
			Allocator get_allocator() { return _allocator; }

			//Element access

			mapped_type &at (key_type i)
			{
				iterator iter = find(i);
				if (iter == end())
					throw std::runtime_error("(at함수에서 발생) 해당 key값이 존재하지 않음");
				return iter->second;
			}
			const mapped_type &at (key_type i) const
			{
				iterator iter = find(i);
				if (iter == end())
					throw std::runtime_error("(at함수에서 발생) 해당 key값이 존재하지 않음");
				return iter->second;
			}
			mapped_type &operator[] (key_type i)
			{
				pair<iterator, bool> check;
				iterator iter = find(i);
				if (iter == end())
				{
					check = insert(ft::make_pair(i, mapped_type()));
					return (check.first)->second;
				}
				else
					return iter->second;
			}
			const mapped_type &operator[] (key_type i) const
			{
				pair<iterator, bool> check;
				iterator iter = find(i);
				if (iter == end())
				{
					check = insert(make_pair(i, mapped_type()));
					return (check.first)->second;
				}
				else
					return iter->second;
			}

			//Iterators

			iterator begin()
			{
				return iterator(_LeftestNode(_RNode));
			}
			iterator end() { return iterator(_endNode); }
			const_iterator begin() const
			{
				return const_iterator(_LeftestNode(_RNode));
			}
			const_iterator end() const{ return const_iterator(_endNode); }
			reverse_iterator rbegin() const { return reverse_iterator(_endNode); }
			reverse_iterator rend() const
			{
				return reverse_iterator(_LeftestNode(_RNode));
			}

			//Capacity

			bool empty() const { return _size == 0; }
			size_type size() const { return _size; }
			size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(value_type); }

			//Modifiers

			void clear()
			{
				_deleteAllNode(_RNode);
				_RNode = _endNode;
				_size = 0;
			}
			pair<iterator, bool> insert( const value_type& value )
			{
				pair<iterator, bool> ret;
				iterator pos = find(value.first);
				ret.first = pos;
				if (_size + 1 > std::numeric_limits<size_type>::max() / sizeof(BTreeNode))
					throw std::runtime_error("할당받을수 있는 크기를 넘어섭니다");
				if (end() == pos)
				{
					BSTInsert(&_RNode, value);
					ret.second = true;
					_size++;
					ret.first = find(value.first);
				}
				else
					ret.second = false;

				return ret;
			}

			iterator insert( iterator hint, const value_type& value )
			{
				iterator terminal = end();
				iterator ret = find(value.first);
				if (ret != end())
					return ret;
				if (_kcompare(hint->first, value.first) == true)
				{
					iterator phint = hint;
					while (hint != terminal && _kcompare(hint->first, value.first))
					{
						phint = hint;
						hint++;
					}

					BTreeNode *parent ;
					if (!_kcompare(hint->first, value.first) && !_kcompare(value.first, hint->first))
						return hint;
					else if (hint == terminal)
						{ parent = phint.base(); }
					else
						parent = hint.base();
					_size++;
					if (parent == _endNode)
						BSTInsert(&_RNode, value);
					BSTInsert(&parent, value);
				}
				else
				{
					iterator phint;
					while (hint != terminal && !_kcompare(hint->first, value.first))
					{
						phint = hint;
						hint--;
					}
					BTreeNode *parent;
					if (!_kcompare(hint->first, value.first) && !_kcompare(value.first, hint->first))
						return hint;
					else if (hint == terminal)
						parent = phint.base();
					else
						parent = hint.base();
					_size++;
					BSTInsert(&parent, value);
				}
				ret = find(value.first);
				return ret;
			}
			template< class InputIt >
			void insert( InputIt first, InputIt last )
			{
				if (std::distance(first, last) < 0 )
					throw std::runtime_error("( void insert( InputIt first, InputIt last )함수에서 발생 ) first가 last보다 큽니다.");
				for (; first != last; first++)
				{
					insert(*first);
				}
			}
			void erase( iterator pos )
			{
				delete (BSTRemove(&_RNode, *pos));
				_size--;
			}
			void erase( iterator first, iterator last )
			{
				iterator iter = find(first->first);
				ft::vector<Key> vec;
				for (; first!= last; first++)
					vec.push_back(first->first);
				for (typename ft::vector<Key>::iterator i = vec.begin(); i != vec.end(); i++)
					erase(*i);
			}
			size_type erase( const key_type& k )
			{
				BTreeNode *dNode = BSTRemove(&_RNode, *find(k));
				if (_endNode == dNode || dNode == NULL)
					return 0;
				else
				{
					_size--;
					delete dNode;
					return 1;
				}
			}
			void swap( map& other )
			{
				Allocator	allocator = other._allocator;
				BTreeNode	*endNode = other._endNode;
				BTreeNode	*RNode = other._RNode;
				key_compare	kcompare = other._kcompare;
				size_type	size = other._size;
				value_compare	vcompare = other._vcompare;

				other._allocator = _allocator;
				other._endNode = _endNode;
				other._RNode = _RNode;
				other._kcompare = _kcompare;
				other._size = _size;
				other._vcompare = _vcompare;

				_allocator = allocator;
				_endNode = endNode;
				_RNode = RNode;
				_kcompare = kcompare;
				_size = size;
				_vcompare = vcompare;
			}

			//Lookup
			size_type count( const Key& key ) const
			{
				return !(find(key) == end());
			}
			iterator find( const Key& key )
			{
				return iterator(BSTSearch(_RNode, key));
			}
			const_iterator find( const Key& key ) const
			{
				return iterator(BSTSearch(_RNode, key));
			}
			ft::pair<iterator,iterator> equal_range( const Key& key ) {	return make_pair(lower_bound(key), upper_bound(key)); }
			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const { return make_pair(lower_bound(key), upper_bound(key)); }
			iterator lower_bound( const Key& key )
			{
				//_utils_for_lower(key);
				iterator check(_utils_for_lower(key));
				return check;
			}
			const_iterator lower_bound( const Key& key ) const
			{
				const_iterator check(_utils_for_lower(key));
				return check;
			}
			iterator upper_bound( const Key& key )
			{
				iterator iter= lower_bound(key);
				if (iter == end())
					return end();
				else if (iter->first == key)
					return ++iter;
				else
					return iter;
			}
			const_iterator upper_bound( const Key& key ) const
			{
				const_iterator iter= lower_bound(key);
				if (iter == end())
					return end();
				else if (iter->first == key)
					return ++iter;
				else
					return iter;

			}

			//Observers
			key_compare key_comp() const
			{
				return _kcompare;
			}
			value_compare value_comp() const
			{
				return _vcompare;
			}
	};
	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		typename ft::map<Key,T,Compare,Alloc>::const_iterator iter1 = lhs.begin(), iter2 = rhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator terminal1 = lhs.end(), terminal2 = rhs.end();
		while (iter1 != terminal1 && iter2 != terminal2)
		{
			if (*iter1 != *iter2)
				return false;
			iter1++; iter2++;
		}
		if (iter1 == terminal1 && iter2 == terminal2)
			return true;
		else
			return false;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		typename ft::map<Key,T,Compare,Alloc>::const_iterator iter1 = lhs.begin(), iter2 = rhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator terminal1 = lhs.end(), terminal2 = rhs.end();
		while (iter1 != terminal1 && iter2 != terminal2)
		{
			if (*iter1 < *iter2)
				return true;
			else if (*iter1 > *iter2)
				return false;
			iter1++;
			iter2++;
		}
		if (iter1 == terminal1 && iter2 == terminal2)
			return false;
		else if (iter1 == terminal1 && iter2 != terminal2)
			return true;
		else
			return false;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (lhs == rhs || lhs < rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs <= rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}
}
#endif
