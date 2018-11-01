//
// EPITECH PROJECT, 2018
// port_audio.hpp
// File description:
// 
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include "portaudio.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "opus.h"
#include  <sys/types.h>


#ifndef _SOUND_HPP
#define _SOUND_HPP


/* #define SAMPLE_RATE  (17932) // Test failure to open with this value. */
#define SAMPLE_RATE  (24000)
#define FRAMES_PER_BUFFER (480)
#define NUM_CHANNELS    (2)
#define NUM_SECONDS     (1)
/* #define DITHER_FLAG     (paDitherOff) */
#define DITHER_FLAG     (0) /**/
/** Set to 1 if you want to capture the recording to a file. */
#define WRITE_TO_FILE   (0)

/* Select sample format. */
#if 1
#define PA_SAMPLE_TYPE  paFloat32
typedef float SAMPLE;
#define SAMPLE_SILENCE  (0.0f)
#define PRINTF_S_FORMAT "%.8f"
#elif 1
#define PA_SAMPLE_TYPE  paInt16
typedef short SAMPLE;
#define SAMPLE_SILENCE  (0)
#define PRINTF_S_FORMAT "%d"
#elif 0
#define PA_SAMPLE_TYPE  paInt8
typedef char SAMPLE;
#define SAMPLE_SILENCE  (0)
#define PRINTF_S_FORMAT "%d"
#else
#define PA_SAMPLE_TYPE  paUInt8
typedef unsigned char SAMPLE;
#define SAMPLE_SILENCE  (128)
#define PRINTF_S_FORMAT "%d"
#endif

typedef struct
{
    int          frameIndex;  /* Index into sample array. */
    int          maxFrameIndex;
    SAMPLE      *recordedSamples;
}
paTestData;

class Sound
{
public:
	Sound();
	~Sound();
	void	recordSound();
	void	playSound();
	void	setSound(float*);
	float*	getSound();
	void    stopStream();
	void   	startStream();
	void    closeStream();
	void	resetIndex();
private:
	PaStream*	stream;
	static int	setDataCallback(unsigned int framesLeft, paTestData *data, void *outputBuffer, unsigned long framesPerBuffer);
	static int	registerDataCallback(paTestData *data, void *outputBuffer, unsigned long framesPerBuffer);
	static int	recordDataCallback(const void *inputBuffer, paTestData *data, long frames, int res);
	static int	saveDataCallback(const void *inputBuffer, paTestData *data, long frames, int res);
	static int	recordCallback( const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *userData );
	static int 	playCallback( const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo* timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData );
	paTestData  data;
	PaStreamParameters	inputParameters;
	PaStreamParameters	outputParameters;
	PaError	err;
	int	i;
	int	totalFrames;
	int	numSamples;
	int	numBytes;
	SAMPLE	max;
	SAMPLE	val;
	double	average;
	int	set = 0;
	int	play;
};

void    recordMySound(Sound *record);
void    playMySound(Sound play);
	
#endif /* _SOUND_HPP_ */
