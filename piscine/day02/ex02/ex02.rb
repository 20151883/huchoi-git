#!/usr/bin/ruby

class Html
	attr_reader :page_name
	def initialize(file_name)
		begin
		@page_name = file_name.to_s
		#fp = File.new(@page_name, "w+")
		#fp.close
		if head() == -1
		raise " "
		end
		rescue
			return -1
		end
	end

	def head()
		begin
		#raise Dup_file.new, "msg is A file named #{@page_name} already there: #{File.expand_path(@page_name)}" if File.exist?(@page_name)
		raise Dup_file.new, "#{@page_name}" if File.exist?(@page_name+".html")
		rescue =>var
			var.show_state
			@page_name = var.correct
			var.explain()
			retry
		else
			fp = File.new(@page_name<<".html", "w+")
			fp.syswrite("<!DOCTYPE html>\n")
			fp.syswrite("<html>\n")
			fp.syswrite("<head>\n")
			fp.syswrite("<title>#{@page_name}</title>\n")
			fp.syswrite("</head>\n")
			fp.syswrite("<body>\n")
			fp.close
			#puts @page_name
		end
	end

	def dump(str)
		begin
		fp = File.new(@page_name, "a+")
		file_data = fp.readlines.map(&:chomp)
		raise Body_closed.new, @page_name if (file_data.include?("</body>"))
		rescue Body_closed=>var
			fp.close
			var.show_state(file_data)
			var.correct(str)
			var.explain
		else
			fp.syswrite ("\t<p>#{str}</p>\n")
			fp.close
		end
	end

	def finish()
		begin
		fp = File.new(@page_name, "a+")
		file_data = fp.readlines.map(&:chomp)
		raise @page_name if (file_data.include?("</body>"))
		rescue =>var
			puts "#{var.class}: #{var.exception(var.message)}"
			puts var.backtrace.select{|var| var.include?("head")}
			fp.close
		else
			fp.syswrite ("</body>\n")
			fp.close
		end
	end

	class Dup_file < StandardError
		def show_state
			@page = self.message
			puts "A file named #{self.message+".html"} already there: #{File.expand_path(self.message)+".html"}"
		end
		def	correct
			page_name = self.message
			@page = page_name << ".new"
			return @page
		end
		def	explain()
			return if(File.exist?(@page+".html"))
			temp = File.expand_path(self.message).split("/")
			temp.pop
			abs_path = temp.join("/")
			puts "Appended .new in order to create requested file: #{abs_path}/#{@page+".html"}"
		end
	end

	class Body_closed < StandardError
		def show_state(arr)
			@arr = arr
			puts "In #{self.message} body was closed :"
		end
		def	correct(str)
			fp = File.open(self.message, "r")
			@file_data = fp.readlines.map(&:chomp)
			@file_data.pop
			@file_data << "\t<p>#{str}</p>"
			@file_data << "</body>"
			fp.close
			fp = File.open(self.message, "w")
			@file_data.each {|var| fp.puts(var)}
		end
		def	explain
			@file_data.each_with_index do |var, index|
			if var == "</body>"
				puts "	> In :#{index + 1} #{var} : text has been inserted and tag moved at the end of it."
			end
		end
	end
end
end
if __FILE__ == $0 then
	a = Html.new("test")
	a.dump("testsadasdasdasdasd")
	a.finish
	a.dump("append")
end
