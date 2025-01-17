#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include <memory>
#include <iterator> // distance()
#include "../etc/etc.hpp"

namespace ft
{
	//여기서 Compare == "operator()가 정의되어있는 클래스"임 그리고 이 클래스로부터 나온 객체는 당연히 함수객체임.
	template <typename Key, typename T, class Compare = std::less<Key>, class Allocator = std::allocator<pair< const Key, T> > >
	class map
	{
		
		public:
			//Memeber type
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename ft::pair<const Key, T> value_type; //헷갈리기 쉬운듯.
			typedef	typename std::size_t size_type;
			typedef int difference_type;
			typedef Compare key_compare;//()연산자가 정의되어있는 클래스.
			//이 위에 것들을 자주 사용함.(key_type mapped_type & value_type, key_compare 이건 무조건 외우기.)
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			/*typedef iterator iterator;
			typedef const iterator const_iterator;
			typedef reverse_iterator reverse_iterator;
			typedef const reverse_iterator const_reverse_iterator;*/
		private:
			typedef pair<key_type, mapped_type> BTData;
			typedef BTData	BSTData;

			struct BTreeNode 
			{
				BSTData 	value; // value_type value가 더 나을듯..?
				BTreeNode * left;
				BTreeNode * right;
			};

		private:
			
			Allocator 			_allocator;
			BTreeNode			*_endNode;//생성자 이니셜라이져 쪽에서 할당받기, 현재 노드를 새로 생성하면 left = NULL, right = NULL로 초기화 되는데 이거 바꿔주어야함. 이에 연관되는 코드들도....
			BTreeNode			*_RNode;//이것도 생성자쪽에서 할당 받자. 그리고 data는 초기화 하지 말자. 할당 안받는다. 그냥 이 포인터를 NULL로 초기화 하면 된다.
			key_compare			_kcompare;
			size_type			_size;
			//value_compare		_vcompare;
		
		private:

			//BST를 위한 함수들 구현.

			
			
			BTreeNode * MakeBTreeNode()//malloc 할당해서 반환.
			{
				BTreeNode *nd = new BTreeNode;

				nd->left = _endNode;
				nd->right = _endNode;
				return nd;
			}

			
			BTData GetData(BTreeNode * bt)
			{
				return bt->value;
			}

			void SetData(BTreeNode * bt, const BTData &value)
			{
				bt->value = value;
			}

			BTreeNode * GetLeftSubTree(BTreeNode * bt)
			{
				return bt->left;
			}

			BTreeNode * GetRightSubTree(BTreeNode * bt)
			{
				return bt->right;
			}
			
			void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)//쓸일이 없을듯?
			{
				if(main->left != _endNode)
					delete main->left;
				main->left = sub;
			}

			void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)//쓸일이 없을듯?
			{
				if(main->right != _endNode)
					free(main->right);

				main->right = sub;
			}
			
			/*void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action)
			{
				if(bt == _endNode)
					return;

				action(bt->data);
				PreorderTraverse(bt->left, action);
				PreorderTraverse(bt->right, action);
			}

			void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
			{
				if(bt == _endNode)
					return;

				InorderTraverse(bt->left, action);
				action(bt->data);
				InorderTraverse(bt->right, action);
			}*/

			

			BTreeNode * _RemoveLeftSubTree(BTreeNode * bt)//delete가 아니라 remove임..
			{
				BTreeNode * delNode;

				if(bt != _endNode) {
					delNode = bt->left;
					bt->left = _endNode;
				}
				return delNode;
			}

			BTreeNode * RemoveRightSubTree(BTreeNode * bt)
			{
				BTreeNode * delNode;

				if(bt != _endNode) {
					delNode = bt->right;
					bt->right = _endNode;
				}
				return delNode;
			}

			void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub) 
			{
				main->left = sub;
			}
			
			void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub)
			{
				main->right = sub;
			}
			
			void BSTMakeAndInit(BTreeNode ** pRoot)
			{
				//*pRoot = _endNode;
				*pRoot = NULL; // 이게 맞을듯 <- BSTInsert()함수 마지막 else문때문에.
			}

			BSTData BSTGetNodeData(BTreeNode * bst)
			{
				return GetData(bst);
			}

			void BSTInsert(BTreeNode ** pRoot, BSTData data)
			{
				BTreeNode * pNode = NULL;    // parent node //null로 하는게 더 직관적.
				BTreeNode * cNode = *pRoot;    // current node
				BTreeNode * nNode = NULL;    // new node

				while(cNode != _endNode)
				{
					if(data == GetData(cNode))
						return;    

					pNode = cNode;

					if(_kcompare(data.first, GetData(cNode).first) == true)
						cNode = GetLeftSubTree(cNode);
					else
						cNode = GetRightSubTree(cNode);
				}
				
				nNode = MakeBTreeNode();
				SetData(nNode, data);
				
				if(pNode != NULL)
				{
					if(_kcompare(data.first, GetData(cNode).first) == true)
						MakeLeftSubTree(pNode, nNode);
					else
						MakeRightSubTree(pNode, nNode);
				}
				else
				{
					//기존의 pRoot 메모리 해제 해줘야 되자 않나..? 안해줘도 되게 처리가 되어 있음. (makebodeandinit함수 보기.)
					*pRoot = nNode;//검증됨.
				}
			}

			BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
			{
				BTreeNode * cNode = bst;    // current node
				BSTData cd;    // current data
				if (bst == NULL)
					return _endNode;
				while(cNode != _endNode)
				{
					cd = GetData(cNode);

					if(!_kcompare(target.first, GetData(cNode).first) && !_kcompare(GetData(cNode).first, target.first))
						return cNode;
					//else if(target < cd)
					else if (_kcompare(target.first, cd.first) == true)
						cNode = GetLeftSubTree(cNode);
					else
						cNode = GetRightSubTree(cNode);
				}

				//return NULL;
				return _endNode; 
				//둘 중 뭐가 좋을지 판단이 안됨. return _endNode;이 좋아보임
			}

			BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)//이 함수는 완전히 노드기반으로 작동함. 여기서 수정할건 data 참조하는걸 key참조하게끔 바꿔주는 작업뿐.
			{
				BTreeNode * pVRoot = MakeBTreeNode();//이 함수안에 malloc -> new 로 바꿔줬음.

				BTreeNode * pNode = pVRoot;    // parent node
				BTreeNode * cNode = *pRoot;    // current node
				BTreeNode * dNode;    // delete node

				ChangeRightSubTree(pVRoot, *pRoot);
				
				
				while(cNode != _endNode && !(!_kcompare(target.first, GetData(cNode).first) && !_kcompare(GetData(cNode).first, target.first)))
				{
					pNode = cNode;

					if (_kcompare(target.first, GetData(cNode).first) == true)
						cNode = GetLeftSubTree(cNode);
					else
						cNode = GetRightSubTree(cNode);
				}

				if(cNode == _endNode)
					return NULL;//return _endNode가 좋아보이긴함... 결국 find 작업을 한거니까... find 못하면 결국 _endNode반환하는게 직관적이여 보임.

				dNode = cNode;

				if(GetLeftSubTree(dNode) == _endNode && GetRightSubTree(dNode) == _endNode)
				{
					if(GetLeftSubTree(pNode) == dNode)
						RemoveLeftSubTree(pNode);// delete RemobeLeftSubTree(Node); 가 좋아보이긴함. -> 맨 마지막에서 dNode 반환하고 있음. 따라서 BSTRemove() 함수 호출 지점에서 delete 수행하는게 좋아보임.
					else
						RemoveRightSubTree(pNode);// 위와 동일.
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
					BTreeNode * mNode = GetRightSubTree(dNode);    // mininum node
					BTreeNode * mpNode = dNode;    // mininum node�� �θ� ���
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
					*pRoot = GetRightSubTree(pVRoot);

				delete pVRoot;
				return dNode;
			}

			//NULL -> _endNode 로 변경 완료.

			//**************
			//아래는 내가 만든함수
			//**************

			/* 					샘플코드임
				if(_kcompare(data.first, GetData(cNode).first) == true)
						cNode = GetLeftSubTree(cNode);
				if(!_kcompare(data.first, GetData(cNode).first) && !_kcompare(GetData(cNode).first, data.first))
						return cNode;
			*/
			 void _deleteAllNode(BTreeNode * bt)//후위 순회 방법을 이용해서 _deleteAllNode()함수 구현하자.
			{
				if (bt->left == _endNode)
				{
					delete bt;
					return;
				}
				else
					PostorderTraverse(bt->left);
				if (bt->right == _endNode)
				{
					delete bt;
					return;
				}
				else
					PostorderTraverse(bt->right);
				delete bt;
			}

			 bool _this_node_is_left(BTreeNode *c) //양방향 노드 기반으로 한다면 이 함수 필요없을듯.
			{
				BTreeNode *Node = c;
				BTreeNode *pNode = _findParent(_RNode, Node);
				if (pNode == NULL)
					return false;// return true..???
				else if (pNode == Node)
					return false;// return true..???
				if (c == pNode.left)
					return true;
				else
					return false;
			}
			 bool _this_node_is_right(BTreeNode *c) //양방향 노드 기반으로 한다면 이 함수 필요없을듯.
			{
				BTreeNode *Node = c;
				BTreeNode *pNode = _findParent(_RNode, Node);
				if (pNode == NULL)
					return false;// return true..???
				else if (pNode == Node)
					return false;// return true..???
				if (c == pNode.right)
					return true;
				else
					return false;
			}
			 BTreeNode *_findParent(BTreeNode *Root, BTreeNode *current )//양방향 노드 기반으로 한다면 이 함수 필요없을듯. //NULL을 반환하면 부모노드가 없는 경우임
			{
				BTreeNode *pNode = NULL;
				BTreeNode *Node = Root;
				if (current == _endNode)
					return NULL;//
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
				//return _endNode;//부모를 찾는건데 부모가 _endNode인건 좀 이상함.
			}
			 BTreeNode *_nextElement(BTreeNode *Root, BTreeNode *current) //유망함을 파악해서 증명해봄..
			{
				BTreeNode *pNode;//필요가 없는듯..?
				BTreeNode *Node = current;
				if (current == _endNode)
					return _endNode;
				if (Node->right != _endNode)//쉬운경우
				{
					Node = Node->right;
					while (Node->left != _endNode)
						Node = Node->left;
					return Node;
				}
				else //인터페이스 잘 구현해놓으면 구현이 편해짐
				{
					while (Node != NULL && _this_node_is_right(Node))
						Node = _findParent(Node);
					if (Node == NULL)
						return _endNode;//이 부분 중요함
					return Node;
				}
			}
			 BTreeNode *_beforeElement(BTreeNode *Root, BTreeNode *current)
			{
				BTreeNode *Node = current;
				if (Node == NULL || _LeftestNode(Root) == Node) // current가 NULL인 경우는 없을듯..?
					return NULL;
				else if (Node == _endNode)
					return _RightestNode(Root);
				if (Node->left != _endNode)//쉬운경우
				{
					Node = Node->left;
					while (Node->right != _endNode)
						Node = Node->right;
					return Node;
				}
				else //인터페이스 잘 구축해놓으면 구현이 편해짐
				{
					while (Node != NULL && _this_node_is_left(Node))
						Node = _findParent(Node);
					if (Node == NULL)
						return NULL;//이 부분 중요함
					return Node;
				}
			}
			 BTreeNode *_LeftestNode(BTreeNode *root)//minimum maxmum이라는 단어보다는 left, right가 더 확장성 있는 단어인듯.
			{
				BTreeNode *pNode = NULL; // _endNode로 초기화 하고 싶은데 _endNode참조가 불가능한 상황임. -> 가능한데...? "iterator만 참조못한다"라고 외워두자.
				BTreeNode *Node = root;
				while (Node->left != Node)//_endNode를 직접참조 하지 않고도 _endNode에 도달했는지 아는 방법.
				{
					pNode = Node;
					Node = pNode->left;
				}
				if (pNode == NULL)
					return Node;//
				return PNode;
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
				return PNode;
			}
		public:

			

			//iterator_system //(bi-direction이라서 구현은 수월할듯.)

			class iterator  // iterator(어댑터의 성격을 띰)가 품고있는것은? NODE(의 주소값) 그리고 내뱉는 것은? ft::pair<key_type, mapped_type>
			{
				public:
					typedef std::bidirectional_iterator_tag iterator_category;
					typedef pair<key_type, mapped_type> value_type;
					typedef long int difference_type;
					typedef pair<key_type, mapped_type>* pointer;
					typedef pair<key_type, mapped_type>& reference;

				private:
					BTreeNode *_NodePtr;
					
				public:
					//***********************
					//legacy쪽 찬찬히 살펴보면 됨.(legacy 완벽히 읽어본건 아님...) (legacy에는 "이런 표현식이 가능해야하고 이 표현식이 컴파일 되어 실행되었을때 이런식으로 동작하는게 맞다"의 내용이 들어가 있음.)
					//***********************
					iterator() { _NodePtr = NULL;  }
					iterator(BTreeNode *p_node) :_NodePtr(p_node) { }
					iterator(const iterator &other):_NodePtr(other._NodePtr) { }
					iterator &operator=(const iterator &other) { _NodePtr = other._NodePtr; }
					BTreeNode *base() { return _NodePtr; }//**********************************납득...
					~iterator() { }

					bool operator==(const iterator &rhs) { return _NodePtr == rhs._NodePtr; }
					value_type operator*() { return _NodePtr->unit; }
					iterator &operator++()
					{
						BTreeNode *nextElement = _nextElement(_NodePtr);//_nextElement()함수 잘 정의해주기. 시그니쳐 어떻게 하지..?
						if (_NodePtr == nextElement) // _endNode에서 ++을 진행하려는 경우 여기에 들어오게됨.
							throw std::runtime_error("( iterator operator++()함수에서 발생 ) _endNode이상은 ++못함.");
						_NodePtr = nextElement; // nextElement가 endNode일때도 이 표현식으로 커버 가능함
						return (*this); // *연산자 정의한거랑 이거랑 전혀 상관이 없는데, 계속 헷갈림...
					}
					bool operator!=(const iterator &rhs) { return !(*this == rhs); }
					value_type *operator->() { return &(_NodePtr->unit); }
					const iterator &operator++(int)//이게 input_iterator쪽에서 필요한건지 아니면 forward쪽에서 필요한건지...? 독해가 잘 안됨.
					{
						iterator ret(*this);//순간 operator*() 정의한 순간 왼쪽 구문 못쓰는거 아닌가 생각함..
						++(*this);
						return ret;
					}
					iterator &operator--() //만약 *this == *begin() 인 상황에서, 이 함수를 호출하면 segmentation fault 뜨는게 표준에 맞는거임.
					{
						BTreeNode *beforeElement = _beforeElement(_NodePtr);
						// BTreeNode *beforeElement = _beforeElement(*this) <- 이거 아님... 계속 헷갈림.
						if (beforeElement == NULL) //_beforElement()함수가 NULL을 반환해 줘야함. iterator class 에서 _endNode참조를 못함.
							throw std::runtime_error("( iterator operator--()함수에서 발생 ) begin()에 해당하는 것 이상은 -- 못함.");
						_NodePtr = beforeElement;
						return (*this);
					}
					const iterator &operator--(int)
					{
						iterator ret(*this);
						--(*this);
						return ret;
					}
			};
			class reverse_iterator
			{

			};
			typedef iterator iterator;
			typedef const iterator const_iterator;
			typedef reverse_iterator reverse_iterator;
			typedef const reverse_iterator const_reverse_iterator;

			

			//Member classes
			//근데 얘는 어디다가 써먹는거지..?
			class value_compare//함수객체를 위한 클래스 이겠다. 근데 생성자쪽이 많이 거슬리긴 하는데... 
			{
				public:
					typedef bool result_type;
					typedef Key first_argument_type;
					typedef T second_argument_type;
				protected:
					Compare comp;
					value_compare(Compare c):comp(c) {}//생성자를 왜 protected에다가...? 자식에서 바꾸게 하려고.. 근데 이 프로젝트에서는 상속이 없으니까, comp 절대 안바꾼다고 보면 될듯.
				public:
					bool operator()( const value_type& lhs, const value_type& rhs ) const { return comp(lhs.first, rhs.first); }
			};
		
		
		public:
			//Member functions
			map();
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() ):_allocator(alloc), _endNode(), _RNode(NULL), _kcompare(comp), _size(0)
			{
				_endNode = new BTreeNode;//사용 잘 하고 나중에 메모리 해제 꼭 해줘야함.
				_RNode = _endNode;//얘도 어쩃거나 소멸자 쪽에서 delete해줄텐데, (_RNode == _endNode) 인 경우 생각하기
			}
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
			map( const map& other );
			~map() { delete _endNode; _endNode = NULL; }//일단 _endNode빼고 다 delete 하는걸 먼저하고, 그다음에 _endNode delete 하는게 나을듯.
			map operator=(const map &src)
			{
				_allocator = src._allocator;
				/*
				_RNode = src._RNode;//얕은복사하면 안될거같은데...? -> clear() 먼저 하고, 값 하나씩 참조해가면서 현재 객체에 insert해줘야함.
				_endNode = src._endNode;//얕은복사하면 안될거같은데...? -> endNode 새로 할당 받아야함.(그냥 현재 객체(src말고)가 가지고 있는 _endNdoe 그대로 사용해도 무방할듯?) -> 표준에서도 새로 할당 받지는 않음. 그냥 원래의 _endNode 그대로 사용.
				*/
				clear();
				for (iterator i = src.begin(); i != src.end(); i++)
					insert(*i); //함수 매개변수쪽에서는 웬만하면 작은걸 받는게 좋긴한데... insert()는 어쩔수 없는듯.
				_kcompare = src._kcompare;
			}
			Allocator get_allocator() { return _allocator; }
			
			//Element access

			mapped_type &at (key_type i) 
			{ 
				iterator iter = find(i);//find()함수는 iterator을 반환한다
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
			mapped_type &operator[] (key_type i) //매우 신기하게 동작함.. lvalue일때나 rvalue일때나... rvalue일때 특히 좀 특이한듯..?
			{
				pair<iterator, bool> check;//insert는 이터레이터와 성공여부를 반환해준다.
				iterator iter = find(i);
				if (iter == end())
				{
					check = insert(make_pair(i, mapped_type()));//이렇게 하는게 맞음.
					return (check.first)->second;
				}
				else
					return iter->second;
			}
			const mapped_type &operator[] (key_type i) const
			{
				pair<iterator, bool> check;//insert는 이터레이터와 성공여부를 반환해준다.
				iterator iter = find(i);
				if (iter == end())
				{
					check = insert(make_pair(i, mapped_type()));//이렇게 하는게 맞음.
					return (check.first)->second;
				}
				else
					return iter->second;
			}

			//Iterators

			iterator begin()//_RNode를 넣어줄게 아니라 제일 작은값을 가지는 노드의 주소값을 넣어줘여함.
			{//begin()은 make_iterator()함수같음
				/*
				BTreeNode *cNode = _RNode;
				while (cNode->left != _endNode)
					cNode = cNode->left;
				return iterator(cNode);
				*/
				return iterator(_LeftestNode(_RNode));
			}
			iterator end() { return iterator(_endNode); }
			reverse_iterator rbegin() { return reverse_iterator(_endNode); }
			reverse_iterator rend() 
			{
				/*
				BTreeNode *cNode = _RNode;
				while (cNode->left != _endNode)
					cNode = cNode->left;
				return iterator(cNode);
				*/
				return reverse_iterator(_LeftestNode(_RNode));
			}

			//Capacity

			bool empty() const { return _size == 0; }
			size_type size() const { return _size; } // 그냥 순회하면서 count를 세거나 아니면 멤버변수로 _size를 두거나.. 후자가 좋을듯?
			size_type max_size() const;

			//Modifiers

			//key 같은지 다른지 검사할때, 샌드위치 정리 써서 해야함.(key_comp 활용해서)

			void clear() //누수없이 잘 작동하는지 점검해보기
			{
				_deleteAllNode(_RNode);
				_RNode = NULL;
				_size = 0;
			}
			pair<iterator, bool> insert( const value_type& value )//value_type == unit 헷갈리지 말기.
			{
				pair<iterator, bool> ret;
				iterator pos = find(value.first);
				ret.first = pos;

				if (end() == pos)
				{
					BSTInsert(_RNode, value);
					ret.second = true;
					_size++;
					ret.first = find(value,first);
				}
				else
					ret.second = false;
				return ret;
			}
			/* 					샘플코드임
				if(_kcompare(data.first, GetData(cNode).first) == true)
						cNode = GetLeftSubTree(cNode);
				if(!_kcompare(data.first, GetData(cNode).first) && !_kcompare(GetData(cNode).first, data.first))
						return cNode;
			*/

			iterator insert( iterator hint, const value_type& value )//어질어질하다... 어떻게 동작하는지 파악할 방법이 없음... -> 걍 대충해봄
			{
				iterator terminal = end();
				//BSTInsert()함수 활용하면 될듯?
				if (_kcompare(hint->first, value.first) == true)//적어도 이 조건문은 검증됨
				{
					iterator phint;
					while (hint != terminal && _kcompare(hint->first, value.first))//*********** 로직 제대로 된거 아닌듯 iterator가 위에서 아래로 내려가는게 아닌데 위->아래를 가정하고 짠 로직임...
					{
						phint = hint;
						hint++;
					}
					BTreeNode *parent;
					//!_kcompare(hint->first, value.first) && !_kcompare(value.first, hint->first)
					if (!_kcompare(hint->first, value.first) && !_kcompare(value.first, hint->first))
						return hint;
					else if (hint == terminal)
						parent = phint.base();
					else // hint->first > value.first
						parent = phint.base();
					BSTInsert(&parent, value);//BSTInsert()함수 잘 구현한듯
				}
				else // 위의것과 정반대로 진행하면 됨.
				{
					
				}
			}
			template< class InputIt >
			void insert( InputIt first, InputIt last )
			{
				if (first > last)
					throw runtime_error("( void insert( InputIt first, InputIt last )함수에서 발생 ) first가 last보다 큽니다.");
				for (; first != last; first++)
				{
					insert(*first);
				}
			}
			void erase( iterator pos )//이 함수만 잘 구현해 놓으면 됨.인터페이스를 잘 활용하자 //iterator가 품고있는것은? NODE(의 주소값)
			{
				BSTRemove(&_RNode, *pos);
			}
			void erase( iterator first, iterator last ) //반개구간.
			{
				for (; first != last; first++)//이것도 위->아래를 전제로 짠 코드라서 로직 수정이 필요해 보임
					erase(first);
			}
			size_type erase( const key_type& k ) //삭제된 노드의 개수를 반환 (0 or 1)
			{
				if (_endNode == BSTRemove(_RNode, k))//delete도 진행해야할듯...? //서브 함수는 최대한 작은걸 받는게 좋은듯.. 구조체를 받기보단 구조체 멤버를 받을수 있으면 그게 좋음.
					return 0;
				else
					return 1;
			}
			void swap( map& other )
			{
				map temp;
				temp = *this;
				*this = other;
				other = temp;
			}

			//Lookup
			size_type count( const Key& key ) const 
			{ 
				return (find(key) != _endNode);
			}
			iterator find( const Key& key ) //못찾으면 return end(); 와 같음
			{
				return iterator(BSTSearch(_RNode, key));//sub함수가 뭘 반환할때는 큰걸 반환하는게 좋은듯. 구조체 멤버보다는 구조체를 반환하는게 좋음.
			}
			const_iterator find( const Key& key ) const;
			ft::pair<iterator,iterator> equal_range( const Key& key );
			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
			iterator lower_bound( const Key& key );
			const_iterator lower_bound( const Key& key ) const;
			iterator upper_bound( const Key& key );
			const_iterator upper_bound( const Key& key ) const;

			//Observers

		
	};
}
#endif