#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>



class Span{
	private:
		std::vector <int> vec;
		int size;
		int count;
	public:
		Span(int n) :size(n), count(0)
		{
			if (n < 0)
				throw std::runtime_error("size is too lower");
		}
		bool is_dup(int num)
		{
			for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
			{
				if (*i == num)
					return true;
			}
			return false;
		}
		void addNumber(int num)
		{
			if (size == count || is_dup(num))
				throw std::runtime_error("elements is now too many or duplicated member is exist");
			else
				vec.push_back(num);
				count++;
		}
		int shortestSpan()
		{
			if (count <= 1)
				throw std::runtime_error("elements is too fewer to call shortestSpan fucntion");
			int min = abs(*(vec.begin() + 1) - *(vec.begin()));
			for(std::vector<int>::iterator i = this->vec.begin(); i != this->vec.end(); i++)
			{
				int cmp = abs(*(i + 1) - *(i));
				if (cmp < min)
					min = cmp;
			}
			return min;
		}
		int longestSpan()
		{
			if (count <= 1)
				throw std::runtime_error("elements is too fewer to call longestSpan fucntion");
			int max = 0;
			for(std::vector<int>::iterator i = this->vec.begin(); i != this->vec.end(); i++)
			{
				int cmp = abs(*(i + 1) - *(i));
				if (cmp > max)
					max = cmp;
			}
			return max;
		}
};

