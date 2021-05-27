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
#puts hash_arr
#puts hash_arr[0].class

#test3 의 목적은 hash_arr 을 이용해서 테이블그리기
prev_pos = 0
puts "<thead>"
-1.upto(17) do |var|
	puts "<th>#{if var >= 0 then var else nil end}</th>"
end
puts "</thead>"
hash_arr.each_with_index do |var, index|
	puts "</tr>\n" if ((var[:number] != 1) && var[:position] == 0)
	puts "<tr>\n<th>#{var[:electron].size}</th>" if var[:position] == 0

	if prev_pos != var[:position] - 1 then
		(prev_pos + 1).upto(var[:position] - 1) do
			puts "<td></td>"
		end
	end

	puts "<td>"
	puts "<ul>"
	puts "<li><h8>#{var[:number]}</h8></li>"
	puts "<li><h8>#{var[:small]}</h8></li>"
	puts "</ul>"
	puts "</td>"

	puts "</tr>" if index == hash_arr.length - 1
	prev_pos = var[:position]
end
