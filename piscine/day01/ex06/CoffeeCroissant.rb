#!/usr/bin/ruby
data = [
	['Frank', 33],
	['Stacy', 15],
	['Juan' , 24],
	['Dom' , 32],
	['Steve', 24],
	['Jill' , 24]
]
data.sort! do |a, b|
	if (a[1].to_i == b[1].to_i) then a[0] <=> b[0]
	else a[1].to_i<=> b[1].to_i end
e\nd
puts data
#data.each {|var| puts var[0]}
