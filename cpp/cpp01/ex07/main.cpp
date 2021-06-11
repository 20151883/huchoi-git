#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout<<"too few or too many argument"<<std::endl;
        return (1);
    }
    std::ifstream readfile;
    std::ofstream writefile;
    std::string s1, s2, buf, temp;
    s1 = argv[2];
    s2 = argv[3];
    readfile.open(argv[1], std::ios_base::in);
    std::string filename(argv[1]);
	std::string test = filename.substr(0, filename.find(".")).append(".replace");
    writefile.open(test.c_str(), std::ios_base::out);//파일이 없을시 자동으로 생성해줌.
    if (!writefile.is_open())
    {
        if (readfile.is_open())
            readfile.close();
        std::cout<<"outputfile is not opened..."<<std::endl;
        return (1);
    }
    if (readfile.is_open())
    {
        char c;
        while (readfile.get(c))
        {
            if (buf.size() == s1.size())
            {
                if (!buf.compare(s1))
                {
                    writefile.write(s2.c_str(), s2.size());
                    buf.clear();
                    buf.push_back(c);
                }
                else
                {
                    temp = buf;
                    temp.resize(1);
                    writefile.write(temp.c_str(), 1);
                    buf.erase(buf.begin());
                    buf.push_back(c);
                }
            }
            else
                buf.push_back(c);
        }
    }
    else
    {
        writefile.close();
        std::cout<<"open "<<argv[1]<<" is failed!!!"<<std::endl;
        return (1);
    }
    writefile.write(buf.c_str(), buf.size());
    readfile.close();
    writefile.close();
    return (0);
}
