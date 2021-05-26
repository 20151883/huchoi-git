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
		#puts File.exist?(@page_name)
		raise Dup_file.new if File.exist?(@page_name)
		rescue Dup_file=>var
			#puts var.message
			var.show_state
			var.correct
			var.explain
			retry
			#puts "Appended .new in order to create requested file: /home/desktop/folder_2/#{@page_name}"
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
		fp = File.new(@page_name, "a+")
		file_data = fp.readlines.map(&:chomp)
		raise "There is no body tag in #{@page_name}" if !(file_data.include?("<body>"))
		raise "In #{@page_name} body was closed :" if (file_data.include?("</body>"))
		rescue =>var
			#puts "#{var.class}: #{var.exception(var.message)}"
			puts var.message
			file_data.each_with_index do |var, index|
				if var == "</body>"
					puts "	> In :#{index + 1} #{var} : text has been inserted and tag moved at the end of it."
			end
		end
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
		file_data = fp.readlines.map(&:chomp)
		raise "#{@page_name} has already been closed." if (file_data.include?("</body>"))
		rescue Body_closed=>var
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
			"A file named #{@page_name} already there: #{File.expand_path(@page_name)}"
		end
		def	correct
			abs_path = File.expand_path(@page_name)
			4.times {@page_name.chop!}
			@page_name = @page_name << "new.html"
			puts "Appended .new in order to create requested file: #{abs_path}"
		end
		def	explain
			puts @page_name
		end
	end

	class Body_closed < StandardError
		def show_state

		end
		def	correct

		end
		def	explain

		end
	end
end
a = Html.new("test.html")
a.dump("test")
#a.finish
#a.dump("af finish")
