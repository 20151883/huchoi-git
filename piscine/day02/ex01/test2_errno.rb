# Ruby program to illustrate
# use of retry statement

begin
	puts "first"
	# using raise to create an exception
	raise 'Exception Created!'

	puts 'After Exception'

# using Rescue method
#rescue
	puts 'Finally Saved!'
	sleep 3
# using retry statement
#retry
end
