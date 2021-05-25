# Ruby program to illustrate
# use of catch and throw statement

# defining a method
def catch_and_throw(value)

	puts value
	a = readline.chomp

	# using throw statement
	throw :value_e if a == "!"
	return a

	end

	# using catch statement
	catch :value_e do

	# enter number
	number = catch_and_throw("Enter Number: ")
	end
