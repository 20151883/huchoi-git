#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout<<"too few or too many argument"<<std::endl;
        return (1);
    }
    std::ifstream readfile;
    std::ofstream writefile;
    std::string s, s1(argv[2]), s2(argv[3]);
    readfile.open(argv[1], std::ios_base::in);
    writefile.open(std::string(argv[1]).substr(0, std::string(argv[1]).find(".")).append(".replace").c_str(), std::ios_base::out);
    if (!writefile.is_open())
    {
        if (readfile.is_open())
            readfile.close();
        std::cout<<"outputfile is not opened..."<<std::endl;
        return (1);
    }
    if (readfile.is_open())
    {
        readfile.seekg(0, std::ios::end);
        int size = readfile.tellg();
        s.resize(size);
        readfile.seekg(0, std::ios::beg);
        readfile.read(&s[0], size);
        unsigned int pos = 0;
        while (pos < s.size())
        {
            if (s.compare(pos, s1.size(), s1) == 0)
            {
                s.replace(pos, s1.size(), s2);
                pos += s2.size();
            }
            else
                pos++;
        }
    }
    else
    {
        writefile.close();
        std::cout<<"open "<<argv[1]<<" is failed!!!"<<std::endl;
        return (1);
    }
    writefile.write(s.c_str(), s.size());
    readfile.close();
    writefile.close();
    return (0);
}
