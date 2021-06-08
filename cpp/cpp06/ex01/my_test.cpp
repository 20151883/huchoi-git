#include <iostream>
#include <cstring>
#include <ctime>
#include <unistd.h>
#define BUFSIZE 512
#define PACKETSIZE sizeof(DATA)

using namespace std;

typedef struct DATA
{
    std::string *s1;
    int num;
    std::string *s2;
}DATA;

static string *gen_random(const int len) {

    string *t = new string("");
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    srand( (unsigned) time(NULL) * getpid());

    (*t).reserve(len);

    for (int i = 0; i < len; ++i)
        *t += alphanum[rand() % (sizeof(alphanum) - 1)];


    return t;
}

void serialize(DATA* DATAPacket, char *data);
void deserialize(char *data, DATA* DATAPacket);
void printDATA(DATA* DATAPacket);

int main()
{
	DATA* newDATA = new DATA;
	newDATA->s1 = (gen_random(6));
	newDATA->num = 42;
	newDATA->s2 = (gen_random(7));
	printDATA(newDATA);

	char data[PACKETSIZE];

	serialize(newDATA, data);

	//DATA* temp = new DATA;
	//deserialize(data, temp);
	//printDATA(temp);

	return 0;
}

void serialize(DATA* DATAPacket, char *data)
{
    std::string *q = (std::string *)data;
    *q = DATAPacket->s1;       q++;

    int *p = (int*)q;
	*p = DATAPacket->num;      p++;
	q = (std::string *)p;
    *q = DATAPacket->s2;//       q++;
}

/*void deserialize(char *data, DATA* DATAPacket)
{
    int *q = (int*)data;
    DATAPacket->type = *q;       q++;
    DATAPacket->priority = *q;   q++;
    DATAPacket->sender = *q;     q++;

    char *p = (char*)q;
    int i = 0;
    while (i < BUFSIZE)
    {
        DATAPacket->message[i] = *p;
        p++;
        i++;
    }
}
*/
void printDATA(DATA* DATAPacket)
{
    cout << DATAPacket->s1 << endl;
    cout << DATAPacket->num << endl;
    cout << DATAPacket->s2 << endl;
}

