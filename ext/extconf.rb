require 'mkmf'

have_library 'openal'
have_library 'alut'

extension_name = 'lolrbmet_alut'
dir_config(extension_name)
create_makefile(extension_name)
