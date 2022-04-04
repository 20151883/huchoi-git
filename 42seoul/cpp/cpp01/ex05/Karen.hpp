#include <iostream>

class Karen
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		typedef struct func_list{
			std::string lv;
			void (Karen::*func)();
		}func_list;
	public:
		static const func_list arr[];
		void complain( std::string level );
};
