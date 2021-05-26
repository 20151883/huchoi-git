class Elem
	attr_reader :name
	def initialize(tag="default", con_arr= [], couple = 'couple', hash={})
		#@head = []
		#@title = []
		#@body = []
		@variale = con_arr.to_s
		if tag == "head"
			@head =
		elsif tag == "body"

		else
			puts "err tag"
		end

		if
	end

	def add_content(src)
		if (src.class == Elem)
			@head = @head + src.head if !src.head.empty?
			@title = @title + src.title if !src.title.empty?
			@body = @body + src.body if !src.body.empty?
		elsif (src.class == Array)
			src.each_with_index do |var, index|
				@head = @head + var.head if !var.head.empty?
				@title = @title + var.title if !var.title.empty?
				@body = @body + var.body if !var.body.empty?
			end
		end
	end

	def to_str

	end
end

class Text < String
end

a = Elem.new("head", "test content")
b = Elem.new("body", "<tr>test</tr>")
a.add_content(b)
#a.add_content(["1213", 23])
#p Text.new("test text")
