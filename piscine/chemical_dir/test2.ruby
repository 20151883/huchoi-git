#!/usr/bin/ruby
hash_arr = Array.new
file = File.open ("periodic_table.txt")
text = file.read
big_arr = text.split("\n")
#puts arr
big_arr.each do |var|
	temp_hash = Hash.new
	arr = var.split(" = ")
	new_arr = Array.new
	new_arr << arr[0]
	new_arr.concat(arr[1].split(", "))
	#new_arr = new_arr.delete(" ")
	new_arr.each_with_index do |var, index|
		if index == 0 then temp_hash["name".to_sym] = var
		else test = var.split(":")
			if index == 3 then temp_hash["small".to_sym] = test[1].to_s.delete(" ")
			elsif index == 5 then temp_hash["electron".to_sym] = test[1].to_s.split(" ")
			else temp_hash[test[0].to_sym] = test[1].to_i
			end
		end
	end
	hash_arr << temp_hash
end
puts hash_arr
puts hash_arr[0].class
