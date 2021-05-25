#!/usr/bin/ruby

class MyLibrary
	class Error < RuntimeError
	end

	class A_ExceptionClass < Error   #Error에 대한 클래스 정의들..
	end

	class B_ExceptionClass < Error
	end
end

def test(num)
	begin
		puts "the first of test func"
		if num.to_i < 0
			raise A_ExceptionClass.new, "this is msg" end
	rescue A_ExceptionClass=> exception
		puts exception.message
	rescue B_ExceptionClass => exception
		puts exception.message

	else

	ensure
		puts "this is ensure block"
	end
end

test(1)
