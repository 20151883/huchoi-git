#include <iostream>
#include <cstring>

namespace MyNamespace
{
	class string{
		private:
			char *str;
		public:
			string(const char *src)
			{
				int len = strlen(src);
				str = new char[len + 1];
				strcpy(str, src);
				str[len] = '\0';
			}
			string(string &src)
			{
				int len = strlen(src);
				str = new char[len + 1];
				strcpy(str, src);
				str[len] = '\0';
			}
			void operator=()
			{

			}
			void operator==()
			{

			}
			void operator+()
			{

			}
			void operator+=()
			{

			}
			void operator<<()
			{

			}
			void operator>>()
			{

			}
	};
}

int main(void)
{

}
