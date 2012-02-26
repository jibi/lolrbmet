require 'mkmf'

have_library 'openal'
have_library 'alut'

create_makefile 'lolrbmet/alut_ext'
