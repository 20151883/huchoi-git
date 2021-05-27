class Elem
	attr_reader :tag_type, :content ,:double ,:opt
	def initialize(tag_type="", con_arr= [], double = 'double', opt={})
		@tag_type = tag_type
		if con_arr.class == Text
			@content = con_arr
		else
			@content = []
			@content << con_arr if !con_arr.empty?
		end
		@double = double
		@opt = opt
	end

	def tag
		return @tag_type
	end
	def tag_type
		return @double
	end
	def add_content(*src)
		src.each do|var|
			if var.is_a?(Array)
				var.each {|var2| @content << var2}
			else
				@content << var
			end
		end
	end

	def to_s(st = nil)
		ret = ""
		ret << "\n" if !@content.is_a?(Text)
		ret <<"<#{@tag_type}"
		if !@opt.empty?
			opt.each do |key, value|
				ret <<" #{key.to_s}='#{value}' "
			end
		end
		ret << "/" if double == "simple"
		ret << ">"
		if @content.is_a?(Text)
			ret << @content.to_s
		else
			ret << "\n" if ret[-1] != "\n" && ret.size != 0
			@content.each do |var|
				ret << var.to_s(true) if var.is_a?(Elem)
				ret << var.to_s if !var.is_a?(Elem)
			end
		end
		ret << "</#{@tag_type}>" if @double == "double"
		ret << "\n" if (st != nil and (ret[-1] != "\n" || ret[0][0] == "\n") )
		ret[0] = "" if (st == nil and (ret[0] == "\n" || ret[0][0] == "\n"))
		1.upto(ret.size) do |idx|
			ret[idx-1..idx] = "\n" if ret[idx-1..idx] == "\n\n"
		end
		return ret
	end

	def open_tag_type
		ret = ""
		ret << "\n" if !@content.is_a?(Text)
		ret <<"<#{@tag_type}"
		if !@opt.empty?
			opt.each do |key, value|
				ret <<" #{key.to_s}='#{value}' "
			end
		end
		ret << "/" if double == "simple"
		ret << ">"
		#end
		ret[0] = "" if ret[0] == "\n"
		return ret
	end

	def close_tag_type
		ret = ""
		ret << "</#{@tag_type}>" if @double == "double"
		ret
	end
end

class Text
	def initialize(src)
	 @name = src
 	end
	 def to_s
		return @name if @name.is_a?(String)
	 end
end

html = Elem.new("html")
head = Elem.new("head")
body = Elem.new("body")
title = Elem.new(Text.new("blah blah"))
head.add_content(title)
html.add_content([head, title, body])
puts html
