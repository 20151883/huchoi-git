#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include <memory>
#include <iterator> // distance()
#include "../etc/etc.hpp"
#include "../vector/vector.hpp"
namespace ft
{
	//여기서 Compare == "operator()가 정의되어있는 클래스"임 그리고 이 클래스로부터 나온 객체는 당연히 함수객체임.
	template <typename Key, typename T, class Compare = std::less<Key>, class Allocator = std::allocator< pair< const Key, T > > >
	class map
	{
		public:
			//Memeber type
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename ft::pair<const Key, T> value_type; //value가 페어 한쌍을 뜻하고 있었음..
			typedef	typename std::size_t size_type;
			typedef int difference_type;
			typedef Compare key_compare;//()연산자가 정의되어있는 클래스.
			//이 위에 것들을 자주 사용함.(key_type mapped_type & value_type, key_compare 이건 무조건 외우기.)
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			/*
			typedef iterator iterator;
			typedef const iterator const_iterator;
			typedef reverse_iterator reverse_iterator;
			typedef const reverse_iterator const_reverse_iterator;
			*/

		private: //외부에서 BTreeNode 구조체를 사용할 방법이 없는듯..? typedef도 없고
			typedef pair<key_type, mapped_type> BTData;
			typedef BTData	BSTData;

			struct BTreeNode 
			{
				BSTData 	value; // value_type value가 더 나을듯..?
				BTreeNode * left;
				BTreeNode * right;
				BTreeNode * parent;
				BTreeNode ** root;
			};
			//Member classes
			//근데 얘는 어디다가 써먹는거지..?
		public:
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
					value_compare():comp() {} // 레퍼런스사이트에는 디폴트생성자가 없음.. 근데 디폴트 생성자 안만들고 어떻게 할 수있는 방법이 없음
					bool operator()( const value_type& lhs, const value_type& rhs ) const { return comp(lhs.first, rhs.first); }
			};
		private:
			
			Allocator 			_allocator;
			BTreeNode			*_endNode;//생성자 이니셜라이져 쪽에서 할당받기, 현재 노드를 새로 생성하면 left = NULL, right = NULL로 초기화 되는데 이거 바꿔주어야함. 이에 연관되는 코드들도....
			BTreeNode			*_RNode;//이것도 생성자쪽에서 할당 받자. 그리고 data는 초기화 하지 말자. 할당 안받는다. 그냥 이 포인터를 NULL로 초기화 하면 된다.
			key_compare			_kcompare;
			size_type			_size;
			value_compare		_vcompare;
		
		private:

			//BST를 위한 함수들 구현.

			BTreeNode * MakeBTreeNode()//malloc 할당해서 반환.
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
			
			void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)//ChangeLeftSubTree()함수와 비교해서 생각해보자.
																	//RemoveLeftSubTree()함수도 있음 이것도 비교해보자.
			{
				BTreeNode *Root = main;
				while (Root->parent != NULL)
					Root = Root->parent;
				sub->root = &_RNode;
				_endNode->root = &_RNode;
				if(main->left != _endNode)
					delete main->left;//main->left가 단일 노드라는게 보장 되어 있을때만 쓸 수 있겠다. (main->left가 어떤 놈인가에 따라서 3개의 함수로 나눴구나 하고 생각하자)
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

			BTreeNode * RemoveLeftSubTree(BTreeNode * bt)//delete가 아니라 remove임.. 이 함수의 목적은? 서브트리를 떼어내버림.
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

			void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub)// 자식노드가 _endNode라는게 보장되어 있을때, 이 함수 호출
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
			
			void BSTMakeAndInit(BTreeNode ** pRoot)// 이 함수 이제 안쓰기로 함. 원래는 생성자에서 이 함수호출했는데, 그렇게 안하고 _RNode = _endNode; 로 대신하기로 함
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
					if(data.first == GetData(cNode).first)
						return;    
					pNode = cNode;
					if(_kcompare(data.first, GetData(cNode).first) == true) // 이 표현식 추상화 시키기(->설명할때 쉽게 설명해야함..)
						{cNode = GetLeftSubTree(cNode); }
					else
						cNode = GetRightSubTree(cNode);
				}
				nNode = MakeBTreeNode();
				SetData(nNode, data);
				//std::cout << data.first << "        " << GetData(cNode).first << std::endl;
				if(pNode != NULL) //pNode 라는 변수 없애버리고 대신 cNode->parent 를 사용하면 안된다. cNode가 _endNode가 되는순간 부모노드가 누구인지 기억을 못하기때문.. -> _endNode가 되어도 부모가 누구인지 알수있게끔 설계를 바꾸긴 했음...
				{
					if(_kcompare(data.first, GetData(pNode).first) == true) //여기서 GetData(pNode).first 가 아니라 GetData(cNode).first였어서 트리가 이상하게 만들어짐...
					{	MakeLeftSubTree(pNode, nNode);}// changeLeftSubTree() 함수호출이 더 낫지않나..? (어짜피 endNode인거 보장된 상황이니까) -> changeLeftSubTree()함수는 BSTRemove()함수를 위해 만든 함수라는게 책의 설명..
					else
						MakeRightSubTree(pNode, nNode);
				}
				else
				{
					//기존의 pRoot 메모리 해제 해줘야 되자 않나..? 안해줘도 되게 처리가 되어 있음. (makebodeandinit함수 보기.)
					*pRoot = nNode;//확실히 검증됨(포인터 그림 그려가면서 검증)
					nNode->root = &_RNode;
					_endNode->root = &_RNode;
				}
			}

			BTreeNode * BSTSearch(BTreeNode * bst, Key target) const //정말 간단하게 생각하기: 찾으면 해당 노드의 주소값, 못찾으면 endNode의 주소값을 반환
			{
				BTreeNode * cNode = bst;    // current node
				BSTData cd;    // current data
				if (bst == NULL || bst == _endNode) // 모든 case 다 생각해서 만든 조건문..!
					return _endNode;
				while(cNode != _endNode)
				{
					cd = GetData(cNode);

					if(!_kcompare(target, GetData(cNode).first) && !_kcompare(GetData(cNode).first, target))
						return cNode;
					// else if(target < cd)
					else if (_kcompare(target, cd.first) == true)
						cNode = GetLeftSubTree(cNode);
					else
						cNode = GetRightSubTree(cNode);
				}
				return _endNode; 
			}

			//나중에 각잡고 리팩토링하기....
			BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)//이 함수는 완전히 노드기반으로 작동함. 여기서 수정할건 data 참조하는걸 key참조하게끔 바꿔주는 작업뿐.
			{
				
				BTreeNode * pVRoot = MakeBTreeNode();//이 함수안에 malloc -> new 로 바꿔줬음.
				//std::cout << "0번 test입니다  " << _RNode->parent << std::endl;
				BTreeNode * pNode = pVRoot;    // parent node
				BTreeNode * cNode = *pRoot;    // current node
				BTreeNode * dNode;    // delete node

				ChangeRightSubTree(pVRoot, *pRoot);//여기서 문제가 발생하고 있었음.
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
					return NULL;//return _endNode가 좋아보이긴함... 결국 find 작업을 한거니까... find 못하면 결국 _endNode반환하는게 직관적이여 보임.

				dNode = cNode;
				//std::cout << "1번 test입니다  " << _RNode->parent << std::endl;

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
				//std::cout << "2번 test입니다  " << _RNode->parent << std::endl;
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
			
			//**************
			//아래는 내가 만든함수
			//**************

			/* 					샘플코드임
				if(_kcompare(data.first, GetData(cNode).first) == true)
						cNode = GetLeftSubTree(cNode);
				if(!_kcompare(data.first, GetData(cNode).first) && !_kcompare(GetData(cNode).first, data.first))
						return cNode;
			*/

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

			void _deleteAllNode(BTreeNode * bt)//후위 순회 방법을 이용해서 _deleteAllNode()함수 구현하자.
			{ // 이 함수안에서 BSTRemove()함수를 호출할 필요는 없다고 봄. 괜히 시간복잡도만 늘어남.
				if (bt == _endNode || bt == NULL)
					return ;
				
				_deleteAllNode(bt->left);
				_deleteAllNode(bt->right);
				
				delete bt;
			}
			BTreeNode *_LeftestNode(BTreeNode *root) const//minimum maxmum이라는 단어보다는 left, right가 더 확장성 있는 단어인듯.
			{
				BTreeNode *pNode = NULL; // _endNode로 초기화 하고 싶은데 _endNode참조가 불가능한 상황임. -> 가능한데...? "iterator만 참조못한다"라고 외워두자.
				BTreeNode *Node = root;
				while (Node->left != Node)//_endNode를 직접참조 하지 않고도 _endNode에 도달했는지 아는 방법.
				{
					pNode = Node;
					Node = pNode->left;
				}
				if (pNode == NULL)
				{	return Node; }
				return pNode;
			}
			 BTreeNode *_findParent(BTreeNode *Root, BTreeNode *current )//양방향 노드 기반으로 한다면 이 함수 필요없을듯. //NULL을 반환하면 부모노드가 없는 경우임
			{//_findParent()함수는 왜 안좋은 인터페이스인가?에 대해 생각해보기
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
				//return _endNode;//부모를 찾는건데 부모가 _endNode인건 좀 이상함.
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
					typedef const pair<key_type, mapped_type>* const_pointer;
					typedef const pair<key_type, mapped_type>& const_reference;

				private:
					BTreeNode *_NodePtr;
					
				public:
					//***********************
					//legacy쪽 찬찬히 살펴보면 됨.(legacy 완벽히 읽어본건 아님...) (legacy에는 "이런 표현식이 가능해야하고 이 표현식이 컴파일 되어 실행되었을때 이런식으로 동작하는게 맞다"의 내용이 들어가 있음.)
					//***********************
					iterator() { _NodePtr = NULL;  }
					iterator(BTreeNode *p_node) :_NodePtr(p_node) { }
					iterator(const iterator &other):_NodePtr(other._NodePtr) { }
					//iterator(const const_iterator &other):_NodePtr(other._NodePtr) { }
					iterator &operator=(const iterator &other) { _NodePtr = other._NodePtr; return *this; }
					//iterator &operator=(const const_iterator &other) { _NodePtr = other.base(); return *this; }
					BTreeNode *base() const { return _NodePtr; }//**********************************납득...
					~iterator() { }

					bool operator==(const iterator &rhs) const { return _NodePtr == rhs._NodePtr; }
					reference operator*() { return _NodePtr->value; } // 이거 반환형이 referenece가 아니라 value-type이여서 다른데 엄청난 영향을 미쳤음..
					iterator &operator++()
					{
						BTreeNode *nextElement = _nextElement(_NodePtr);
						if (_NodePtr == nextElement) // _endNode에서 ++을 진행하려는 경우 여기에 들어오게됨.
							throw std::runtime_error("( iterator operator++()함수에서 발생 ) _endNode이상은 ++못함.");
						_NodePtr = nextElement; // nextElement가 endNode일때도 이 표현식으로 커버 가능함
						return (*this); // *연산자 정의한거랑 이거랑 전혀 상관이 없는데, 계속 헷갈림...
					}
					bool operator!=(const iterator &rhs) const { return !(*this == rhs); }
					pointer operator->() const { return &(_NodePtr->value); }
					const iterator operator++(int)//이게 input_iterator쪽에서 필요한건지 아니면 forward_iterator쪽에서 필요한건지...? 독해가 잘 안됨.
					{
						iterator ret(*this);//순간 operator*() 정의한 순간 왼쪽 표현식 못쓰는거 아닌가 생각함..
						++(*this);
						return ret;
					}
					iterator &operator--() // *this == *begin() 인 상황에서, 이 함수를 호출하면 segmentation fault 뜨는게 정상임
					{
						BTreeNode *beforeElement = _beforeElement(_NodePtr);
						// BTreeNode *beforeElement = _beforeElement(*this) <- 이거 아님... 계속 헷갈림.
						if (beforeElement == NULL) //_beforElement()함수가 NULL을 반환해 줘야함. iterator class 에서 _endNode참조를 못함.
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
							if (pNode == NULL)//Node가 Root이거나 _endNode일때, false를 반환(함수호출 맥락에 맞게 구현한것)
								return false;
							if (c == pNode->left)
								return true;
							else
								return false;
						}
						bool _this_node_is_right(BTreeNode *c) //양방향 노드 기반으로 한다면 이 함수 필요없을듯.(판단의 근거: 여러상황에서 쓰기에는 반환값이 모호한 느낌이 있어서)
						{
							if (c == NULL)
								return false;
							BTreeNode *pNode = c->parent;
							if (pNode == NULL)//Node가 Root이거나 _endNode일때, false를 반환(함수호출 맥락에 맞게 구현한것)
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
						BTreeNode *getEndNode(BTreeNode *c)//NULL이나 endNode이면 이 함수 호출 못하게 처리 해줘야함
						{
							BTreeNode *target = c;
							while (target->left != target)
								target = target->left;
							return target;
						}

						BTreeNode *_nextElement(BTreeNode *current) //이 함수는 이터레이터를 위해서 존재함 //NULL을 반환하면 에러를 뜻함 //유망함을 파악해서 증명해봄..
						{
							BTreeNode *Node = current;
							if (is_endNode(current))
								return NULL; //return _endNode; 아님 
							BTreeNode *termainalNode = getEndNode(Node);
							if (Node->right != termainalNode) //쉬운경우
							{
								Node = Node->right;
								while (Node->left != termainalNode)
									Node = Node->left;
								return Node;
							}
							else //인터페이스 잘 구축해놓으면 구현이 편해짐 // 이 블럭 로직 문제있어서 수정함
							{
								while (_this_node_is_right(Node))
									Node = Node->parent;
								if (Node->parent == NULL)
									return termainalNode;//이 부분 중요함 endNode 반환하는게 확실함
								return Node->parent;
							}
						}
						BTreeNode *_beforeElement(BTreeNode *current) //이 함수는 이터레이터를 위해서 존재함 //NULL을 반환하면 에러를 뜻함
						{
							BTreeNode *Node = current;
							if (Node == NULL) // || _LeftestNode(Root) == Node) 후자 케이스는 아래의 else문에서 걸러짐
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
									return NULL;//이 부분 중요함 //그냥 여기서 에러를 던지는게 나을듯? // 인터페이스 자체의 예외클래스를 던질수도 있으니... 그냥 NULL반환하는게 나은듯
								return Node->parent;
							}
						}
						BTreeNode *_LeftestNode(BTreeNode *root)//minimum maxmum이라는 단어보다는 left, right가 더 확장성 있는 단어인듯.
						{
							BTreeNode *pNode = NULL; // _endNode로 초기화 하고 싶은데 _endNode참조가 불가능한 상황임. -> 가능한데...? "iterator만 참조 못 한다"라고 외워두자.
							BTreeNode *Node = root;
							while (Node->left != Node)//_endNode를 직접 참조 하지 않고도 _endNode에 도달했는지 아는 방법.
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
							//std::cout << root << std::endl;
							//std::cout << "reach" << std::endl;
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
					const_iterator() { _NodePtr = NULL;  }
					const_iterator(BTreeNode *p_node) :_NodePtr(p_node) { }
					const_iterator(const const_iterator &other):_NodePtr(other._NodePtr) { }
					const_iterator(const iterator &other):_NodePtr(other.base()) { }
					const_iterator &operator=(const const_iterator &other) { _NodePtr = other._NodePtr; return *this; }
					const_iterator &operator=(const iterator &other) { _NodePtr = other.base(); return *this; }
					BTreeNode *base() { return _NodePtr; }
					~const_iterator() { }

					bool operator==(const const_iterator &rhs) const { return _NodePtr == rhs._NodePtr; }
					value_type &operator*() const { return _NodePtr->value; }
					const_iterator &operator++()
					{
						BTreeNode *beforeElement = _nextElement(_NodePtr);
						// BTreeNode *beforeElement = _beforeElement(*this) <- 이거 아님... 계속 헷갈림.
						if (beforeElement == NULL) //_beforElement()함수가 NULL을 반환해 줘야함. iterator class 에서 _endNode참조를 못함.
							throw std::runtime_error("( iterator operator--()함수에서 발생 ) begin()에 해당하는 것 이상은 -- 못함.");
						_NodePtr = beforeElement;
						return (*this);
					}
					bool operator!=(const const_iterator &rhs) const { return !(*this == rhs); }
					value_type *operator->() const { return &(_NodePtr->value); }
					const const_iterator operator++(int)//이게 input_const_iterator쪽에서 필요한건지 아니면 forward_const_iterator쪽에서 필요한건지...? 독해가 잘 안됨.
					{
						const_iterator ret(*this);//순간 operator*() 정의한 순간 왼쪽 표현식 못쓰는거 아닌가 생각함..
						++(*this);
						return ret;
					}
					const_iterator &operator--() // *this == *begin() 인 상황에서, 이 함수를 호출하면 segmentation fault 뜨는게 정상임
					{
						BTreeNode *nextElement = _beforeElement(_NodePtr);
						if (_NodePtr == nextElement) // _endNode에서 ++을 진행하려는 경우 여기에 들어오게됨.
							throw std::runtime_error("( iterator operator++()함수에서 발생 ) _endNode이상은 ++못함.");
						_NodePtr = nextElement; // nextElement가 endNode일때도 이 표현식으로 커버 가능함
						return (*this); // *연산자 정의한거랑 이거랑 전혀 상관이 없는데, 계속 헷갈림...
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
							if (pNode == NULL)//Node가 Root이거나 _endNode일때, false를 반환(함수호출 맥락에 맞게 구현한것)
								return false;
							if (c == pNode->left)
								return true;
							else
								return false;
						}
						bool _this_node_is_right(BTreeNode *c) const//양방향 노드 기반으로 한다면 이 함수 필요없을듯.(판단의 근거: 여러상황에서 쓰기에는 반환값이 모호한 느낌이 있어서)
						{
							if (c == NULL)
								return false;
							BTreeNode *pNode = c->parent;
							if (pNode == NULL)//Node가 Root이거나 _endNode일때, false를 반환(함수호출 맥락에 맞게 구현한것)
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
						BTreeNode *getEndNode(BTreeNode *c)const//NULL이나 endNode이면 이 함수 호출 못하게 처리 해줘야함
						{
							BTreeNode *target = c;
							while (target->left != target)
								target = target->left;
							return target;
						}

						BTreeNode *_nextElement(BTreeNode *current) const//이 함수는 이터레이터를 위해서 존재함 //NULL을 반환하면 에러를 뜻함 //유망함을 파악해서 증명해봄..
						{
							BTreeNode *Node = current;
							if (is_endNode(current))
								return NULL; //return _endNode; 아님 
							BTreeNode *termainalNode = getEndNode(Node);
							if (Node->right != termainalNode) //쉬운경우
							{
								Node = Node->right;
								while (Node->left != termainalNode)
									Node = Node->left;
								return Node;
							}
							else //인터페이스 잘 구축해놓으면 구현이 편해짐 // 이 블럭 로직 문제있어서 수정함
							{
								while (_this_node_is_right(Node))
									Node = Node->parent;
								if (Node->parent == NULL)
									return termainalNode;//이 부분 중요함 endNode 반환하는게 확실함
								return Node->parent;
							}
						}
						BTreeNode *_beforeElement(BTreeNode *current) const //이 함수는 이터레이터를 위해서 존재함 //NULL을 반환하면 에러를 뜻함
						{
							BTreeNode *Node = current;
							if (Node == NULL) // || _LeftestNode(Root) == Node) 후자 케이스는 아래의 else문에서 걸러짐
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
									return NULL;//이 부분 중요함 //그냥 여기서 에러를 던지는게 나을듯? // 인터페이스 자체의 예외클래스를 던질수도 있으니... 그냥 NULL반환하는게 나은듯
								return Node->parent;
							}
						}
						BTreeNode *_LeftestNode(BTreeNode *root) const//minimum maxmum이라는 단어보다는 left, right가 더 확장성 있는 단어인듯.
						{
							BTreeNode *pNode = NULL; // _endNode로 초기화 하고 싶은데 _endNode참조가 불가능한 상황임. -> 가능한데...? "iterator만 참조 못 한다"라고 외워두자.
							BTreeNode *Node = root;
							while (Node->left != Node)//_endNode를 직접 참조 하지 않고도 _endNode에 도달했는지 아는 방법.
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
							//std::cout << root << std::endl;
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
				//_endNode = MakeBTreeNode(); <- 잘못됨!!!! 이거 때문에 begin()함수도 제대로 동작 못하고 있었음(정확히 말하면 _LeftestNode()함수가 제대로 동작못함 종료조건이 성립이 안됨)
				_endNode = new BTreeNode;
				_endNode->parent = NULL;
				_endNode->left = _endNode;
				_endNode->right = _endNode;
				//_endNode->left = endNode; <-이건 MakeBTreeNode()함수에서 이미 되어진 상태
				_RNode = _endNode; //얘도 어쩃거나 소멸자 쪽에서 delete해줄텐데, (_RNode == _endNode) 인 경우 생각하기
				//_endNode->first = &_RNode; // 설계 -> 이렇게 하면 자료형 안맞아서 컴파일 에러뜸
				_endNode->root = &_RNode;
				//_endNode->right = &_RNode; // 설계 -> 이렇게 해도 자료형 안맞아서 컴파일 에러뜸
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
			~map() { clear(); delete _endNode; /*delete _RNode;*/ _endNode = NULL; }//일단 _endNode빼고 다 delete 하는걸 먼저하고, 그다음에 _endNode delete 하는게 나을듯.
			map operator=(const map &src)
			{
				_allocator = src._allocator;
				_vcompare = src._vcompare;
				clear();
				for (const_iterator i = src.begin(); i != src.end(); i++)
					insert(*i); //함수 매개변수쪽에서는 웬만하면 작은걸 받는게 좋긴한데... insert()는 어쩔수 없는듯.
				_kcompare = src._kcompare;
				return *this;
			}
			Allocator get_allocator() { return _allocator; }
			
			//Element access

			mapped_type &at (key_type i) 
			{ 
				iterator iter = find(i); //find()함수는 iterator을 반환한다
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
				pair<iterator, bool> check; //insert는 이터레이터와 성공여부를 반환해준다.
				iterator iter = find(i);
				if (iter == end())
				{
					check = insert(ft::make_pair(i, mapped_type()));//이렇게 하는게 맞음.
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

			iterator begin()  //_RNode를 넣어줄게 아니라 제일 작은값을 가지는 노드의 주소값을 넣어줘여함.
			{//begin()은 make_iterator()함수같음
				return iterator(_LeftestNode(_RNode));
			}
			iterator end() { return iterator(_endNode); }
			const_iterator begin() const //_RNode를 넣어줄게 아니라 제일 작은값을 가지는 노드의 주소값을 넣어줘여함.
			{//begin()은 make_iterator()함수같음
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
			size_type size() const { return _size; } // 그냥 순회하면서 count를 세거나 아니면 멤버변수로 _size를 두거나.. 후자가 좋을듯?
			size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(value_type); }

			//Modifiers

			//key 같은지 다른지 검사할때, 샌드위치 정리 써서 해야함.(key_comp 활용해서)

			void clear() //누수없이 잘 작동하는지 점검해보기
			{
				_deleteAllNode(_RNode);
				_RNode = _endNode;
				_size = 0;
			}
			pair<iterator, bool> insert( const value_type& value ) //value_type == unit 헷갈리지 말기.
			{
				//std::cout << (_endNode->root) << "       " << _RNode->value.first << std::endl;<-그냥 남겨두자
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
			void erase( iterator pos )//이 함수만 잘 구현해 놓으면 됨.인터페이스를 잘 활용하자 //iterator가 품고있는것은? NODE(의 주소값)
			{
				delete (BSTRemove(&_RNode, *pos));
				_size--;
			}
			void erase( iterator first, iterator last ) //반개구간.
			{
				//for(iterator++) 하면서 size_type erase( const key_type& k ); 함수 호출해나가면 될듯??????
				iterator iter = find(first->first);
				ft::vector<Key> vec;
				for (; first!= last; first++)
					vec.push_back(first->first);
				for (typename ft::vector<Key>::iterator i = vec.begin(); i != vec.end(); i++)
					erase(*i);
				/*for (; first!= last; )
				{
					std::cout << iter->first << "  ";
					first++;
					erase(iter->first);
					iter = find(first->first);
				}
				std::cout << std::endl;*/
				//erase(iter->first);
			}
			size_type erase( const key_type& k ) //삭제된 노드의 개수를 반환 (0 or 1)
			{
				BTreeNode *dNode = BSTRemove(&_RNode, *find(k));
				if (_endNode == dNode || dNode == NULL)//delete도 진행해야할듯...? //서브 함수는 최대한 작은걸 받는게 좋은듯.. 구조체를 받기보단 구조체 멤버를 받을수 있으면 그게 좋음.
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
				BTreeNode	*endNode = other._endNode;//생성자 이니셜라이져 쪽에서 할당받기, 현재 노드를 새로 생성하면 left = NULL, right = NULL로 초기화 되는데 이거 바꿔주어야함. 이에 연관되는 코드들도....
				BTreeNode	*RNode = other._RNode;//이것도 생성자쪽에서 할당 받자. 그리고 data는 초기화 하지 말자. 할당 안받는다. 그냥 이 포인터를 NULL로 초기화 하면 된다.
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
			iterator find( const Key& key ) //못찾으면 return end(); 와 같음
			{
				return iterator(BSTSearch(_RNode, key));//sub함수가 뭘 반환할때는 큰걸 반환하는게 좋은듯. 구조체 멤버보다는 구조체를 반환하는게 좋음.
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
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs ) // 이게 std::swap의 템플릿특수화는 아닌거같은데..
	{
		lhs.swap(rhs);
	} 
}
#endif