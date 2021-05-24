#!/usr/bin/ruby -w
file = File.open("numbers.txt")
data = file.read
temp = data.split(",\n")
arr = []
temp.each do |var|

	arr << var.to_i
end
puts arr.sort
