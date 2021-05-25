#!/usr/bin/ruby
def draw_chemical_table
	hash_arr = Array.new
	file = File.open ("periodic_table.txt")
	text = file.read
	big_arr = text.split("\n")
	big_arr.each do |var|
		temp_hash = Hash.new
		arr = var.split(" = ")
		new_arr = Array.new
		new_arr << arr[0]
		new_arr.concat(arr[1].split(", "))
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
end

puts "<!doctype html>
<html lang=\"ko\">
<head>
	<title>huchoi's work</title>
	<meta charset=\"UTF-8\">
  	<meta name=\"author\" content=\"홍길동\">
  	<meta name=\"description\" content=\"우리 사이트가 최고!\">
	<style>
		table {
		  width: 100%;
		}
		table, th, td {
		border: 1px solid #bcbcbc;
		border-collapse: collapse;
		}
		img {
		  width: 100px;
		  height: 200px;
		}
		p {
		  font-size: 20px;
		  font-weight: bold;
		}
	  </style>
</head>"

puts "<body>"
puts "<table style = \"border-color: rgb(54, 54, 156);\">"
draw_chemical_table
puts "</body>"
puts "</html>"
