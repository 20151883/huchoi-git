#!/usr/bin/ruby

class Html
	attr_reader :page_name
	def initialize(file_name)
		begin
		@page_name = file_name.to_s
		#fp = File.new(@page_name, "w+")
		#fp.close
		raise " " if head() == -1
		rescue
			return -1
		end
	end

	def head()
		begin
		#raise Dup_file.new, "msg is A file named #{@page_name} already there: #{File.expand_path(@page_name)}" if File.exist?(@page_name)
		raise Dup_file.new, "#{@page_name}" if File.exist?(@page_name)
		rescue =>var
			var.show_state

			#retry if nil == var.correct
			@page_name = var.correct
			var.explain()
			#4.times {@page_name.chop!}
			#@page_name = @page_name << "new.html"
			#puts "Appended .new in order to create requested file: /home/desktop/folder_2/#{@page_name}"
			retry
		else
			fp = File.new(@page_name, "w+")
			fp.syswrite("<!DOCTYPE html>\n")
			fp.syswrite("<html>\n")
			fp.syswrite("<head>\n")
			fp.syswrite("<title>#{@page_name}</title>\n")
			fp.syswrite("</head>\n")
			fp.syswrite("<body>\n")
			fp.close
		end
	end

	def dump(str)
		begin
		fp = File.open(@page_name, "a+")
		file_data = fp.readlines.map(&:chomp)
		raise Dup_file.new, "There is no body tag in #{@page_name}" if !(file_data.include?("<body>"))
		raise @page_name if (file_data.include?("</body>"))
		rescue Body_closed=>var
			#puts "#{var.class}: #{var.exception(var.message)}"
			#puts var.message
			fp.close
			var.show_state(file_data)
			var.correct(str)
			var.explain
			#file_data.each_with_index do |var, index|
			#	if var == "</body>"
			#		puts "	> In :#{index + 1} #{var} : text has been inserted and tag moved at the end of it."
			#end
		#end
			file_data.select{|var| var.include?("</body>")}
			fp.close

		else
			fp.syswrite ("\t<p>#{str}<\p>\n")
			fp.close
		end
	end

	def finish()
		begin
		fp = File.new(@page_name, "a+")
		#retry if !file_data = fp.readlines.map(&:chomp)
		raise "#{@page_name} has already been closed." if (file_data.include?("</body>"))
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
			#puts "here1"
			puts "A file named #{self.message} already there: #{File.expand_path(self.message)}"
			#puts "#{@page_name}"
			#puts "here2"
		end
		def	correct
			page_name = self.message
			#4.times {page_name.chop!}
			@page = page_name << ".new.html"
			return @page if File.exist?(@page)
		end
		def	explain()
			return if(File.exist?(@page))
			temp = File.expand_path(self.message).split("/")
			temp.pop
			abs_path = temp.join("/")
			puts "Appended .new in order to create requested file: #{abs_path}/#{@page}"
		end
	end

	class Body_closed < StandardError
		def show_state(arr)
			@arr = arr
			puts "In #{self.message} body was closed :"
		end
		def	correct(str)
			fp = File.open(self.message, "wr")
			@file_data = fp.readlines.map(&:chomp)
			@file_data.pop
			@file_data << str
			@file_data.each {|var| fp.write(var)}
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
a = Html.new("test")
a.dump("test")
a.finish
