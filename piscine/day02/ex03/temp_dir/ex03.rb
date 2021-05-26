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
		src.each {|var| @content << var}
	end

	def to_s
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
				ret << var.to_s
			end
		end
		ret << "</#{@tag_type}>" if @double == "double"
		ret[0] = "" if !st && ret[0] = "\n"
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
