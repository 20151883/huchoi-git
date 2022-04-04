#include <iostream>

inline bool IsFloatFinite(float d)
{
    return ((*(int32_t*)(&d) & 0x7f800000) != 0x7f800000);
}

inline bool IsDoubleFinite(double d)
{
    return ((*(int64_t*)(&d) & 0x7ff0000000000000L) != 0x7ff0000000000000L);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout<<"argument is too many or too small!!!"<<std::endl;
	}

}
