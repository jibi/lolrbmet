Gem::Specification.new {|s|
	s.name = 'lolrbmet'
	s.version = '0.0.1'
	s.author = 'jcjh'
	s.email = 'jcjh@paranoici.org'
	s.homepage = 'http://github.com/jcjh/lolrbmet'
	s.platform = Gem::Platform::RUBY
	s.summary = 'Fail ruby metronome'
	s.files = Dir['ext/**/*.{c,rb}'] + Dir['lib/**/*.rb'] + Dir['data/*.wav']
	s.executables = 'lolrbmet'
	s.extensions = 'ext/lolrbmet/extconf.rb'
}
