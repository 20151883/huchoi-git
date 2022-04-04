#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

class Span{
	private:
		std::vector <int> vec;
		unsigned int max_size;
	public:
		Span(unsigned int n = 10);
		~Span();
		Span(const Span &src);
		Span &operator=(const Span &src);
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
};

