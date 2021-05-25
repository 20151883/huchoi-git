# Ruby program to create the user
# defined exception and handling it

# defining a method
def raise_and_rescue
	begin

		puts 'This is Before Exception Arise!'

		# using raise to create an exception
		raise 'Exception Created!'

		puts 'After Exception'

	# using Rescue method
	rescue
		puts 'Finally Saved!'

	end

	puts 'Outside from Begin Block!'

	end

	# calling method
	raise_and_rescue
