#ifndef TESTER_HPP
# define TESTER_HPP

//# warning "C Preprocessor got here!"

# include "stack.hpp"
# include <stack>
# include "map.hpp"
# include <map>
# include "vector.hpp"
# include <vector>

# include <sstream>
# include <algorithm>
# include <cstdlib>

# define UNDEFINED 1
# define DEFINED 0

static int g_test = 0;
static int g_valid = 0;


template <class T>
void put_itr(T ft_map)
{
	std::cout << "----------TEST TREE BEGIN->END----------"<< std::endl;
	typename T::iterator itr = ft_map.begin();
	while(itr != ft_map.end())
	{
		std::cout<<(*itr)->first<< " ";
		itr++;
	}
	std::cout <<std::endl<< "---------TEST TREE RBEGIN->REND----------"<< std::endl;
	typename T::reverse_iterator itr2 = ft_map.rbegin();
	while(itr2 != ft_map.rend())
	{
		std::cout<<(*itr2)->first<< " ";
		itr2++;
	}
	std::cout <<std::endl;
}

class Testclass
{
	public:
		std::string str;
		Testclass()
		{
			str = "string_ICI";
		};
		Testclass(std::string strcp)
		{
			str = strcp;
		};
		~Testclass(){};
};

inline std::ostream &operator<<(std::ostream &o, Testclass const &rhs)
{
	o << rhs.str;
	return o;
};

inline bool operator< (const Testclass& lhs, const Testclass& rhs){ return (lhs.str < rhs.str); };
inline bool operator> (const Testclass& lhs, const Testclass& rhs){ return (lhs.str > rhs.str); };
inline bool operator==(const Testclass& lhs, const Testclass& rhs){ return (lhs.str == rhs.str); };
inline bool operator!=(const Testclass& lhs, const Testclass& rhs){ return (lhs.str != rhs.str); };
inline bool operator<= (const Testclass& lhs, const Testclass& rhs){ return (lhs.str <= rhs.str); };
inline bool operator>= (const Testclass& lhs, const Testclass& rhs){ return (lhs.str >= rhs.str); };

void title(std::string title);
void title(std::string title, int size);
void check(std::stringstream *ss_std, std::stringstream *ss_ft, int flag);
void end_test();

template < class K, class V >
void put_random(std::map<K, V> &std_map, ft::map<K, V> &ft_map)
{
	int k = rand() % 1000;
	int v = rand() % 1000;
	std_map.insert(std::pair<int, int>(k, v));
	ft_map.insert(std::pair<int, int>(k, v));
}

template < class K, class V >
void put_random_str(std::map<K, V> &std_map, ft::map<K, V> &ft_map)
{
	std::string k = "abcdefghijklmnopqrstuvwxyz0123456789";
	std::random_shuffle(k.begin(), k.end());
	std::string v = "abcdefghijklmnopqrstuvwxyz0123456789";
	std::random_shuffle(v.begin(), v.end());
	k = k.substr(0, 5);
	v = v.substr(0, 5);
	std_map.insert(std::pair<std::string, std::string>(k, v));
	ft_map.insert(std::pair<std::string, std::string>(k, v));
}

template < class K, class V >
void put_random_class(std::map<K, V> &std_map, ft::map<K, V> &ft_map)
{
	std::string k = "abcdefghijklmnopqrstuvwxyz0123456789";
	std::random_shuffle(k.begin(), k.end());
	std::string v = "abcdefghijklmnopqrstuvwxyz0123456789";
	std::random_shuffle(v.begin(), v.end());
	k = k.substr(0, 5);
	v = v.substr(0, 5);
	Testclass kc(k);
	Testclass vc(v);
	std_map.insert(std::pair<Testclass, Testclass>(k, v));
	ft_map.insert(std::pair<Testclass, Testclass>(k, v));
}

template < class K, class V >
void describe_map(std::map<K, V> std_map, ft::map<K, V> ft_map)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	if (std_map.empty())
		ss_std << "(empty)";
	else
		for (typename std::map<K, V>::iterator itr = std_map.begin(); itr != std_map.end(); itr++)
			ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	if (ft_map.empty())
		ss_ft << "(empty)";
	else
		for (typename ft::map<K, V>::iterator itr = ft_map.begin(); itr != ft_map.end(); itr++)
			ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
	check(&ss_std, &ss_ft, DEFINED);
}

template < class T >
void describe_vector(std::vector<T> std_vector, ft::vector<T> ft_vector)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_vector.empty())
		ss_std << "(empty)";
	else
		for (typename std::vector<T>::iterator itr = std_vector.begin(); itr != std_vector.end(); itr++)
		{
			ss_std << i << ":[" << *itr << "] ";
			i++;
		}
	i = 0;
	if (ft_vector.empty())
		ss_ft << "(empty)";
	else
		for (typename ft::vector<T>::iterator itr = ft_vector.begin(); itr != ft_vector.end(); itr++)
		{
			ss_ft << i << ":[" << *itr << "] ";
			i++;
		}
	check(&ss_std, &ss_ft, DEFINED);
}

template < class T >
void describe_vector(ft::vector<T> std_vector, ft::vector<T> ft_vector)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_vector.empty())
		ss_std << "(empty)";
	else
		for (typename ft::vector<T>::iterator itr = std_vector.begin(); itr != std_vector.end(); itr++)
		{
			ss_std << i << ":[" << *itr << "] ";
			i++;
		}
	i = 0;
	if (ft_vector.empty())
		ss_ft << "(empty)";
	else
		for (typename ft::vector<T>::iterator itr = ft_vector.begin(); itr != ft_vector.end(); itr++)
		{
			ss_ft << i << ":[" << *itr << "] ";
			i++;
		}
	check(&ss_std, &ss_ft, UNDEFINED);
}

template < class T >
void describe_stack(std::stack<T> std_stack, ft::stack<T> ft_stack)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_stack.empty())
		ss_std << "(empty)";
	else
		while (!std_stack.empty())
		{
			ss_std << i << ":[" << std_stack.top() << "] ";
			std_stack.pop();
			i++;
		}

	i = 0;
	if (ft_stack.empty())
		ss_ft << "(empty)";
	else
		while (!ft_stack.empty())
		{
			ss_ft << i << ":[" << ft_stack.top() << "] ";
			ft_stack.pop();
			i++;
		}
	check(&ss_std, &ss_ft, DEFINED);
}



#endif