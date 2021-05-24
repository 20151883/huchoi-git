#!/usr/bin/ruby -w
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
puts states.key(capitals_cities.key(ARGV[0]))
