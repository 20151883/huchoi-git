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
puts capitals_cities[states[ARGV[0]]]
