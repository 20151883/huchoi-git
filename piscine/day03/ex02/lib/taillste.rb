require "colorize"

class Taillste

	VERSION = 1
	class Drum
		def initialize
			@arr = [1,4,9]
		end
		def beat
			return @arr
		end
		def shuffle
			temp = @arr[0]
			@arr[0] = @arr[1]
			@arr[1] = temp
			return @arr
		end
		def	count
			ret = ""
			1.upto(9) do |var|
				ret << var.to_s + "\n" if @arr.include?(var)
				ret << ".\n" if !@arr.include?(var)
			end
			return ret
		end
		def played_with
			return "Both arms and legs"
		end
	end

	class Beat_box < Drum
		def initialize
			@beat_arr = [1,5,7]
		end
		def beat
			return @beat_arr
		end
		def shuffle
			temp = @beat_arr[0]
			@beat_arr[0] = @beat_arr[1]
			@beat_arr[1] = temp
			return @beat_arr
		end
		def count
			ret = ""
			1.upto(7) do |var|
				ret << var.to_s + "\n" if @beat_arr.include?(var)
				ret << ".\n" if !@beat_arr.include?(var)
			end
			return ret
		end
		def played_with
			return "Mouth"
		end
	end

	class Clap < Drum
		def initialize
			@clap_arr = [2, 3, 7, 8]
		end

		def beat
			return @clap_arr
		end

		def shuffle
			temp = @clap_arr
			temp << temp.shift
			return temp.rotate(1)
		end
		def count
			ret = ""
			2.upto(8) do |var|
				ret << var.to_s + "\n" if @clap_arr.include?(var)
				ret << ".\n" if !@clap_arr.include?(var)
			end
		end
		def played_with#정의 안해줘도 될텐데..?
			return "Both_hands"
		end
	end

end
