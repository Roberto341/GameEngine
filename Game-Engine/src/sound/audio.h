#pragma once

#include "fmod.hpp"
#include "fmod_errors.h"
#include <iostream>

class Audio {
public:
	Audio(const char* path);
	~Audio();
	const char* Common_MediaPath(const char* fileName);
	void play();
	void stop();
	void pause();
	FMOD::System* sys;
	FMOD_RESULT result;
};