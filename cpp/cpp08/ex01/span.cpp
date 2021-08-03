#include "span.hpp"

Span::Span(unsigned int n) :max_size(n)
{}
Span::~Span()
{}
Span::Span(const Span &src)
{
    this->vec = src.vec;
    this->max_size = src.max_size;
}
Span &Span::operator=(const Span &src)
{
    this->vec = src.vec;
    this->max_size = src.max_size;
    return *this;
}
void Span::addNumber(int num)
{
    if (max_size == vec.size())
        throw std::runtime_error("elements is now too many can't add NEW number");
    else
        vec.push_back(num);
}
int Span::shortestSpan()
{
    std::vector<int> temp = vec;
    if (temp.size() == 0)
        return 0;
    if (temp.size() == 1)
        return temp[0];
    std::sort(temp.begin(), temp.end(), std::less<int>());
    for (unsigned int i = 1; i < temp.size(); i++)
        temp[i-1] = temp[i] - temp[i - 1];
    temp.pop_back();
    temp.shrink_to_fit();
    std::sort(temp.begin(), temp.end(), std::less<int>());
    return temp[0];
}

int Span::longestSpan()
{
    std::vector<int> temp = vec;
    if (temp.size() == 0)
        return 0;
    if (temp.size() == 1)
        return temp[0];
    std::sort(temp.begin(), temp.end(), std::less<int>());
    return (temp[temp.size() - 1] - temp[0]);
}