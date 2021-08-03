#include "iter.hpp"

std::ostream &operator<<(std::ostream &ost, int ptr[])
{
	ost<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3];
	return ost;
}

std::ostream &operator<<(std::ostream &ost, float ptr[])
{
	ost<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3];
	return ost;
}

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }
int main() {
	const int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	const Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );
	return 0;
}