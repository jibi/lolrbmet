require 'lolrbmet/alut_ext'

class LolRbMet
	TickFile = "#{File.dirname(__FILE__)}/../../data/tick.wav"
	TockFile = "#{File.dirname(__FILE__)}/../../data/tock.wav"

	def initialize sheet
		@sheet = sheet
		@tempo = 140

		init_player
	end

	def start 
		File.open(@sheet).each do |l|
			if m = l.match(/t (\d+)/)
				@tempo = m[1].to_i
			elsif m = l.match(/(\d+) (\d+) (\d+)/)
				play m[1], m[2], m[3]
			elsif m = l.match(/(\d+) (\d+)/)
				play m[1], m[2]
			else
				puts 'invalid time signature'
			end
		end
	end

	def play num, den, rep=1
		@usleep_t = (60 * 1000000) / (@tempo / 4) / den.to_i

		rep.to_i.times {
			print "[#{@tempo} bpm] #{num}/#{den} |"
			$stdout.flush

			_play 'tick' 
			(num.to_i - 1).times { _play 'tock' } 

			print "#{27.chr}[2K\r"
		}
	end

	def _play wat
		print " #"
		$stdout.flush

		send '_play_' + wat
	end
end

