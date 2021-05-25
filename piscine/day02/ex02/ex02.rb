#!/usr/bin/ruby -w

class Dup_file < StandardError

end

class Body_closed < StandardError

end

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
		raise "A file named #{@page_name} already exist!" if File.exist?(@page_name)
		rescue =>var
			puts "#{var.class}: #{var.exception(var.message)}"
			#puts var.inspect
			puts var.backtrace.select{|var| var.include?("head")}
			return -1
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
		raise "Body has already been closed in #{@page_name}" if (file_data.include?("</body>"))
		rescue =>var
			puts "#{var.class}: #{var.exception(var.message)}"
			puts var.backtrace.select{|var| var.include?("head")}
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
		rescue =>var
			puts "#{var.class}: #{var.exception(var.message)}"
			puts var.backtrace.select{|var| var.include?("head")}
			fp.close

		else
			fp.syswrite ("</body>\n")
			fp.close
		end
	end
end
