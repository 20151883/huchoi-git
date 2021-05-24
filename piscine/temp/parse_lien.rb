hash_arr = Array.new
file = File.open ("periodic_table.txt")
str = "Hydrogen = position:0, number:1, small: H, molar:1.00794, electron:1"
arr = str.split(" = ")
new_arr = Array.new
new_arr << arr[0]
new_arr.concat(arr[1].split(", "))
#p new_arr
temp_hash = Hash.new
new_arr.each_with_index do |var, index|
	if index == 0 then temp_hash["name"] = var
	else test = var.split(":")
		temp_hash[test[0].to_s] = test[1].to_s
	end
end
#p temp_hash
#puts temp_hash["name"]



hash_arr = Array.new
temp_hash = Hash.new
file = File.open ("periodic_table.txt")
text = file.read
big_arr = text.split("\n")
#puts arr
big_arr.each do |var|
	arr = var.split(" = ")
	new_arr = Array.new
	new_arr << arr[0]
	new_arr.concat(arr[1].split(", "))
	new_arr.each_with_index do |var, index|
	if index == 0 then temp_hash["name"] = var
	else test = var.split(":")
		temp_hash[test[0].to_s] = test[1].to_s
	end
	hash_arr << temp_hash
end
end
