#!/usr/bin/ruby
if ARGV.length != 1 then return -1 end
if ARGV[0].include?(",,") then return -1 end
states = {
	"Oregon" => "OR",
	"Alabama" => "AL",
	"New Jersey" => "NJ",
	"Colorado" => "CO"
}
capitals_cities = {
	"OR" => "Salem",
	"AL" => "Montgomery",
	"NJ" => "Trenton",
	"CO" => "Denver"
}
arr = ARGV[0].split(",")
arr.each do |var|
	if var.delete(" ") != "" then puts var.delete(" ") end
end
##캐피탈라이즈 사용해야함.
