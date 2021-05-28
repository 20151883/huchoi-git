#! /usr/bin/env ruby
require 'nokogiri'
require 'open-uri'
class Ft_wikipedia
  def initialize
	@count = 0
	@searched_keyword = []
  end
  def search(keyword)
	begin
	link = "https://en.wikipedia.org/wiki/#{keyword}"
	print "first @ :" if @searched_keyword.empty?
	puts "#{link}"
	doc = Nokogiri::HTML(URI.open(link))
	#raise StandardError, "ead search #{@link}" if !doc#굳이 raise 발생 안시켜도 됨
	data = doc.search('div.mv-parser-output p a')
	#raise StandardError, "Dead search #{@link}" if !data#굳이 raise 발생 안시켜도 됨

	first = nil
	raise StandardError, "nodata" if data.empty?
	data.each do |var|
		first = var if var.to_s.include?("/wiki")
		break if first != nil
	end
	puts first
    first.to_s.split("\"").each do |x|
      @parse = x if x.include?("wiki")
	end
	search_value = @parse.split("/")[2] if @parse.is_a?(String)
	raise StandardError, "loop" if @searched_keyword.include?(search_value)
	@searched_keyword << search_value
	puts @searched_keyword[-1]
    @count += 1
    search("#{@searched_keyword[-1]}")
	#puts @count

	rescue OpenURI::HTTPError => var
		puts var.class
		puts var.message
	rescue StandardError=>var
		puts var.message
	end
  end
end
a = Ft_wikipedia.new
#puts a.class
a.search("User:Thangmayducminh")


