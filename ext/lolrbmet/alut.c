#include <ruby.h>
#include <AL/alut.h>

void Init_alut_ext();
VALUE lolrbmet_class;

ALuint tickBuffer, tickSource; 
ALuint tockBuffer, tockSource;

VALUE method_init_player(VALUE self);
VALUE method_play_tick(VALUE self);
VALUE method_play_tock(VALUE self);

void 
Init_alut_ext() {
	lolrbmet_class = rb_define_class("LolRbMet", rb_cObject);

	rb_define_method(lolrbmet_class, "init_player", method_init_player, 0);
	rb_define_method(lolrbmet_class, "play_tick", method_play_tick, 0);
	rb_define_method(lolrbmet_class, "play_tock", method_play_tock, 0);
}


VALUE 
method_init_player(VALUE self) {
	VALUE tick_wav, tock_wav;
	char *tick_wav_str, *tock_wav_str;

	alutInit (NULL, NULL);

	tick_wav = rb_const_get(lolrbmet_class, rb_intern("TickFile"));
	tick_wav_str = rb_string_value_cstr(&tick_wav);

	tock_wav = rb_const_get(lolrbmet_class, rb_intern("TockFile"));
	tock_wav_str = rb_string_value_cstr(&tock_wav);

	tickBuffer = alutCreateBufferFromFile (tick_wav_str);
	tockBuffer = alutCreateBufferFromFile (tock_wav_str);

	alGenSources (1, &tickSource);
	alGenSources (1, &tockSource);

	alSourcei (tickSource, AL_BUFFER, tickBuffer);
	alSourcei (tockSource, AL_BUFFER, tockBuffer);
}

VALUE
method_play_tick(VALUE self) {
	alSourcePlay(tickSource); 
	usleep (FIX2INT(rb_iv_get(self, "@usleep_t")));
}

VALUE
method_play_tock(VALUE self) {
	alSourcePlay(tockSource); 
	usleep (FIX2INT(rb_iv_get(self, "@usleep_t")));
}

