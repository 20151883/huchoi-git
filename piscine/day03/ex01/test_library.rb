#! /usr/bin/env ruby
require 'nokogiri'
require 'open-uri'
class Ft_wikipedia
  def initialize
	#@count = 0
	@searched_keyword = []
	@key = nil
  end
  def search(keyword)
	begin
	@key = keyword if @key == nil
	link = "https://en.wikipedia.org/wiki/#{keyword}"
	print "First @ :" if @searched_keyword.empty?
	puts "#{link}"
	doc = Nokogiri::HTML(URI.open(link))
	data = doc.search('div.mw-parser-output p a', 'div.mw-parser-output ul a')
	first = nil
	raise StandardError, "nodata" if data.empty?
	data.each do |var|
		first = var if var.to_s.include?("/wiki")
		break if first != nil
	end
	#puts first
    first.to_s.split("\"").each do |x|
      @parse = x if x.include?("wiki")
	end
	search_value = @parse.split("/")[2] if @parse.is_a?(String)
	raise StandardError, "loop" if @searched_keyword.include?(search_value)
	@searched_keyword << search_value
	#puts @searched_keyword[-1]
    search("#{@searched_keyword[-1]}")

	rescue OpenURI::HTTPError => var
		puts var.class
		puts var.message
		exit
	rescue StandardError=>var
		puts "Loop detected there is no way to #{@key} here" if var.message == "loop"
		puts "Dead end page reached" if var.message == "nodata"
		exit
	end
	return 1
  end
end
a = Ft_wikipedia.new
a.search("position")


