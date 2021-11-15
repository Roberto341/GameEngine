#include "audio.h"
#include <vector>
using namespace FMOD;
const int MAX_CHANNELS = 64;
Channel* channel = 0;
Sound* sound;
static std::vector<char*> gPathList;
unsigned int ms = 0;
unsigned int lenms = 0;
bool playing = 0;
bool paused = 0;
int channelsplaying = 0;
Audio::Audio(const char* path)
{	
	result = System_Create(&sys);
	if (result != FMOD_OK) {
		printf("Error creating system\n");
	}
	else {
		sys->init(MAX_CHANNELS, FMOD_INIT_NORMAL, NULL);
	}

	result = sys->createSound(Common_MediaPath(path), FMOD_DEFAULT, 0, &sound);

	if (result != FMOD_OK){
		std::cout << "Error " << FMOD_ErrorString(result) << std::endl;
	}

	result = sound->setMode(FMOD_LOOP_OFF);
	if (result != FMOD_OK) {
		std::cout << "Error " << FMOD_ErrorString(result) << std::endl;
	}
}
Audio::~Audio() 
{
	stop();
}
void Audio::play() 
{
		result = sys->playSound(sound, 0, false, &channel);

		result = sys->update();
		{
			
			if (channel)
			{
				Sound* curentsound = 0;
				result = channel->isPlaying(&playing);
				if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
				{
					std::cout << "Error " << FMOD_ErrorString(result) << std::endl;
				}

				result = channel->getPaused(&paused);
				if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
				{
					std::cout << "Error " << FMOD_ErrorString(result) << std::endl;
				}
				result = channel->getPosition(&ms, FMOD_TIMEUNIT_MS);
				if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
				{
					std::cout << "Error " << FMOD_ErrorString(result) << std::endl;
				}
				channel->getCurrentSound(&curentsound);
				if (curentsound) {
					result = curentsound->getLength(&lenms, FMOD_TIMEUNIT_MS);
					if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
					{
						std::cout << "Error " << FMOD_ErrorString(result) << std::endl;
					}
				}
			}
			sys->getChannelsPlaying(&channelsplaying, NULL);

			printf("Channels playing %d\n", channelsplaying);
		}
}
// pause
void Audio::pause() {
	result = sys->playSound(sound, 0, true, &channel);
	std::cout << "Error " << FMOD_ErrorString(result) << std::endl;
}
// shutdown
void Audio::stop()
{
	result = sound->release();
	std::cout << "Error " << FMOD_ErrorString(result) << std::endl;
	result = sys->close();
	std::cout << "Error " << FMOD_ErrorString(result) << std::endl;
	result = sys->release();
	std::cout << "Error " << FMOD_ErrorString(result) << std::endl;
}
const char* Audio::Common_MediaPath(const char* fileName) {
		char* filePath = (char*)calloc(256, sizeof(char));

		static const char* pathPrefix = nullptr;
		if (!pathPrefix)
		{
			const char* emptyPrefix = "";
			const char* mediaPrefix = "../media/";
			FILE* file = fopen(fileName, "r");
			if (file)
			{
				fclose(file);
				pathPrefix = emptyPrefix;
			}
			else
			{
				pathPrefix = mediaPrefix;
			}
		}

		strcat(filePath, pathPrefix);
		strcat(filePath, fileName);

		gPathList.push_back(filePath);

		return filePath;
}