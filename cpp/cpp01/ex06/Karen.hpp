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
		/*static func_list arr[4]; = {
			{"DEBUG", &Karen::debug},
			{"INFO", &Karen::info},
			{"WARNING", &Karen::warning},
			{"ERROR", &Karen::error}
		};*/
	public:
		//static func_list arr[];
		static const func_list arr[];/* =
		{
		{"DEBUG", &Karen::debug},
		{"INFO", &Karen::info},
		{"WARNING", &Karen::warning},
		{"ERROR", &Karen::error}
		};*/
		void complain( std::string level );
};
