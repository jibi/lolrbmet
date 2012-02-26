#include <ruby.h>
#include <AL/alut.h>

#define TICK_WAV "data/snd/tick.wav"
#define TOCK_WAV "data/snd/tock.wav"

void Init_lolrbmet_alut();
ALuint tickBuffer, tickSource; 
ALuint tockBuffer, tockSource;

VALUE method_init_player(VALUE self);
VALUE method_play_tick(VALUE self);
VALUE method_play_tock(VALUE self);

void 
Init_lolrbmet_alut() {
	VALUE my_class = rb_define_class("LolRbMet", rb_cObject);

	rb_define_method(my_class, "init_player", method_init_player, 0);
	rb_define_method(my_class, "play_tick", method_play_tick, 0);
	rb_define_method(my_class, "play_tock", method_play_tock, 0);
}


VALUE 
method_init_player(VALUE self) {
	alutInit (NULL, NULL);

	tickBuffer = alutCreateBufferFromFile (TICK_WAV);
	tockBuffer = alutCreateBufferFromFile (TOCK_WAV);

	alGenSources (1, &tickSource);
	alGenSources (1, &tockSource);

	alSourcei (tickSource, AL_BUFFER, tickBuffer);
	alSourcei (tockSource, AL_BUFFER, tockBuffer);
}

VALUE
method_play_tick(VALUE self) {
	int usleep_t = FIX2INT(rb_iv_get(self, "@usleep_t"));

	alSourcePlay(tickSource); 
	usleep (usleep_t);
}

VALUE
method_play_tock(VALUE self) {
	int usleep_t = FIX2INT(rb_iv_get(self, "@usleep_t"));

	alSourcePlay(tockSource); 
	usleep (usleep_t);
}

