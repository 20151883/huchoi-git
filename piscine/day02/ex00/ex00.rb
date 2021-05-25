#!/usr/bin/ruby -w
class Html
	attr_reader :page_name
	def initialize(file_name)
		@page_name = file_name.to_s
		fp = File.new(@page_name, "w+")
		fp.close
		head()
	end

	def head()
		puts "head call"
		fp = File.new(@page_name, "a+")
		fp.syswrite("<!DOCTYPE html>\n")
		fp.syswrite("<html>\n")
		fp.syswrite("<head>\n")
		fp.syswrite("<title>#{@page_name}</title>\n")
		fp.syswrite("</head>\n")
		fp.syswrite("<body>\n")
		fp.close
	end

	def dump(str)
		fp = File.new(@page_name, "a+")
		fp.syswrite ("\t<p>#{str}<\p>\n")
		fp.close
	end

	def finish()
		fp = File.new(@page_name, "a+")
		fp.syswrite ("</body>\n")
		fp.close
	end
end
