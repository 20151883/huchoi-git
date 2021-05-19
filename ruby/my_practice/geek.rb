#puts ((1.upto(10){|value| value.times{puts("*")}))
arr = Array.new
arr<<gets.chomp
if (str = gets)
	if str[0...(str.size > arr[0].size ? arr[0].size : str.size)] == arr[0][0...(str.size > arr[0].size ? arr[0].size : str.size)]
		puts "uuuuuuuuuuu"
	end
end
