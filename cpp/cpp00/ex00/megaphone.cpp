#include <iostream>

using namespace std;
char	*alpha_upper(char *str);
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		int idx = 1;
		char *upper;
		while (argv[idx])
		{
			upper = alpha_upper(argv[idx]);
			cout<<upper;
			delete []upper;
			idx++;
		}
	}
	cout<<endl;
}
char	*alpha_upper(char *str)
{
	int idx = 0;
	int size = strlen(str) + 1;
	char *ret = new char[size];
	int diff = 'a' - 'A';
	while (str[idx])
	{
		if ('a' <= str[idx] && str[idx] <= 'z')
		{
			ret[idx] = str[idx] - diff;
		}
		else
			ret[idx] = str[idx];
		idx++;
	}
	return (ret);
}
