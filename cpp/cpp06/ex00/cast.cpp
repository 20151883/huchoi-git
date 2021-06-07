#include <iostream>
#include <stdexcept>
#include <cctype>
#include <limits>
using namespace std;

inline bool IsFloatFinite(float d)
{
    return ((*(int32_t*)(&d) & 0x7f800000) != 0x7f800000);
}

inline bool IsDoubleFinite(double d)
{
    return ((*(int64_t*)(&d) & 0x7ff0000000000000L) != 0x7ff0000000000000L);
}

void convert_char(std::string test)
{
	cout<<"char: ";
	try
	{
		char c = static_cast<char> (stoi(test));
		if (isprint(c))
				cout<<c<<endl;
		else
			cout<<"Non displayable"<<endl;
	}
	catch(std::exception &e)
	{
		cout<<"impossible"<<endl;
	}
}

void convert_int(std::string test)
{
	cout<<"int: ";
	try{
		int i = stoi(test);
		cout<<i<<endl;
	}
	catch(std::exception &e)
	{
		cout<<"impossible"<<endl;
	}
}

void convert_float(std::string test)
{
	cout<<"float: ";
	try
	{
		long  double ld = stold(test);//에러가 발생한다면 이 함수에서 발생함.
		float f = static_cast<float>(ld);
		if (!IsFloatFinite(static_cast<float>(ld)) && test != std::string("nan"))
		{
			if (ld > 0)
				cout<<"+INF"<<endl;
			else
				cout<<"-INF"<<endl;
		}
		else if (f == static_cast<int>(f))
			cout<<std::fixed<<static_cast<int>(f)<<".0f"<<endl;
		else
			cout<<std::fixed<<f<<"f"<<endl;
	}
	catch(std::exception &e)
	{
		cout<<"impossible"<<endl;
	}
}

void convert_double(std::string test)
{
	cout<<"double: ";
	try{
		long  double ld = stold(test);
		double d =static_cast<double>(ld);
		if (!IsDoubleFinite(static_cast<double>(ld)) && test != std::string("nan"))
		{
			if (ld > 0)
				cout<<"+INF"<<endl;
			else
				cout<<"-INF"<<endl;
		}
		else if (d == static_cast<long long int>(d))
			cout<<std::fixed<<static_cast<long long int>(d)<<".0"<<endl;
		else
			cout<<std::fixed<<d<<endl;
	}
	catch (std::exception &e)
	{
		cout<<"impossible"<<endl;
	}
}

int main(int argc, char *argv[])
{
	//cout<<INT_MAX<<endl;
	//cout<<std::fixed<<std::numeric_limits<float>::max()<<endl;//긴 숫자를 온전히 출력하기 위해
	if (argc != 2)
		return -1;
	string test(argv[1]);
	//std::getline(std::cin, test);
	convert_char(test);
	convert_int(test);
	convert_float(test);
	convert_double(test);
	return (0);
}
