// CPP program to serialize and
// deserialize the array of string

#include<iostream>

using namespace std;

// Function to serialized the array of string
string serialize(string str[], int ln)
{
	string temp = "";
	for (int i=0; i<ln; i++)
	{
		int ln = str[i].length();
		temp.push_back('0' + ln);
		temp = temp + "~" + str[i];
	}
	return temp;
}

// Function to deserialize the string
void deserialized(string str, string deserialize[], int ln)
{
	int len, pos=0;
	string temp = "";
	int i = 0;
	while(pos>-1)//종료조건
	{
		pos = str.find("~", pos+1);
		if(pos>0)
		{
			len = str[pos-1] - 48;
			temp.append(str, pos+1, len);
			deserialize[i++] = temp;
			temp = "";
		}
	}
}

// Driver function
int main()
{
	string str[] = {"geeks", "are", "awesome"};

	int ln = sizeof(str)/sizeof(str[0]);
	string serializedstr = serialize(str, ln);

	cout << "Serialized String : " << serializedstr <<endl;

	string deserialize[ln];
	deserialized(serializedstr,deserialize,ln);

	cout << "Deserialized String : ";
	for(int i=0; i<ln; i++)
		cout << deserialize[i] << " ";

	return 0;
}
