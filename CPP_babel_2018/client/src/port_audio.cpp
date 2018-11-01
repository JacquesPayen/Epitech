//
// EPITECH PROJECT, 2018
// port_audio.cpp
// File description:
// 
//

#include "../include/port_audio.hpp"

Sound::Sound()
{
	set = 0;
	play = 0;
  	err = Pa_Initialize();
	inputParameters.device = Pa_GetDefaultInputDevice();
	inputParameters.channelCount = 2;
	inputParameters.sampleFormat = PA_SAMPLE_TYPE;
	inputParameters.suggestedLatency = Pa_GetDeviceInfo( inputParameters.device )->defaultLowInputLatency;
	inputParameters.hostApiSpecificStreamInfo = NULL;
	outputParameters.device = Pa_GetDefaultOutputDevice();
	outputParameters.channelCount = 2;              
	outputParameters.sampleFormat =  PA_SAMPLE_TYPE;
	outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultLowOutputLatency;
	outputParameters.hostApiSpecificStreamInfo = NULL;
}

Sound::~Sound()
{
	err = Pa_StopStream(stream);
	err = Pa_CloseStream(stream);
}

int Sound::recordCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
				const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,
				void *userData)
{
    	paTestData *data = (paTestData*)userData;
    	long 	frames;
    	int	res;
    	unsigned long	framesLeft = data->maxFrameIndex - data->frameIndex;
    	if( framesLeft < framesPerBuffer )
   	{
        	frames = framesLeft;
        	res = paComplete;
    	}
	else
	{
		frames = framesPerBuffer;
        	res = paContinue;
	}
	if(inputBuffer == NULL)
		return (recordDataCallback(inputBuffer, data, frames, res));
	else
		return (saveDataCallback(inputBuffer, data, frames, res));

}

int	Sound::recordDataCallback(const void *inputBuffer, paTestData *data, long frames, int res)
{
	const SAMPLE	*rptr = (const SAMPLE*)inputBuffer;
    	SAMPLE	*wptr = &data->recordedSamples[data->frameIndex * NUM_CHANNELS];
	int	i = 0;

	while (i < frames)
        {
		*wptr++ = SAMPLE_SILENCE;
        	*wptr++ = SAMPLE_SILENCE;
		i++;
        }
	data->frameIndex = data->frameIndex+ frames;
    	return res;
}

int	Sound::saveDataCallback(const void *inputBuffer, paTestData *data, long frames, int res)
{
	const SAMPLE	*rptr = (const SAMPLE*)inputBuffer;
    	SAMPLE	*wptr = &data->recordedSamples[data->frameIndex * NUM_CHANNELS];
	int	i = 0;

	while (i < frames)
        {
        	*wptr++ = *rptr++;
        	*wptr++ = *rptr++;
		i++;
        }
	data->frameIndex = data->frameIndex + frames;
    	return res;
}

int	Sound::playCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
				const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,
				void *userData)
{
    	paTestData *data = (paTestData*)userData;
    	unsigned int	framesLeft = data->maxFrameIndex - data->frameIndex;
    	if( framesLeft < framesPerBuffer )
		return (setDataCallback(framesLeft, data, outputBuffer, framesPerBuffer));
    	else
    		return (registerDataCallback(data, outputBuffer, framesPerBuffer));
}

int	Sound::setDataCallback(unsigned int framesLeft, paTestData *data, void *outputBuffer, unsigned long framesPerBuffer)
{
	SAMPLE *rptr = &data->recordedSamples[data->frameIndex * NUM_CHANNELS];
    	SAMPLE *wptr = (SAMPLE*)outputBuffer;
	unsigned int	i = 0;
	int	res;

        while (i < framesLeft)
        {
            	*wptr++ = *rptr++;
		*wptr++ = *rptr++;
		i++;
        }
        while (i < framesPerBuffer)
        {
            	*wptr++ = 0;
		*wptr++ = 0;
		i++;
        }
        data->frameIndex = data->frameIndex + framesLeft;
        res = paComplete;
	return res;
}

int	Sound::registerDataCallback(paTestData *data, void *outputBuffer, unsigned long framesPerBuffer)
{
	int	res;
	SAMPLE *rptr = &data->recordedSamples[data->frameIndex * NUM_CHANNELS];
    	SAMPLE *wptr = (SAMPLE*)outputBuffer;
	unsigned int	i = 0;

	while (i < framesPerBuffer)
        {
		*wptr++ = *rptr++;
		*wptr++ = *rptr++;
		i++;
        }
	data->frameIndex =  data->frameIndex + framesPerBuffer;
        res = paContinue;
	return res;
}

void	Sound::startStream()
{
   	err = Pa_StartStream(stream);
}

void    Sound::stopStream()
{
	err = Pa_StopStream(stream);
}

void    Sound::closeStream()
{
    	err = Pa_StopStream(stream);
}

void	Sound::recordSound()
{
	set = 1;
	int	i = 0;
	err = paNoError;
	data.maxFrameIndex = totalFrames = NUM_SECONDS * SAMPLE_RATE;
	data.frameIndex = 0;
	numSamples = totalFrames * NUM_CHANNELS;
	numBytes = numSamples * sizeof(SAMPLE);
	data.recordedSamples = (SAMPLE *) malloc(numBytes);
	while (i < numSamples)
	{
		data.recordedSamples[i] = 0;
		i++;
	}
	err = Pa_OpenStream(
		&stream,
		&inputParameters,
		NULL,
		SAMPLE_RATE,
		FRAMES_PER_BUFFER,
		paClipOff,
		recordCallback,
		&data );
	err = Pa_StartStream(stream);
}

void	Sound::playSound()
{
	if (set == 0)
		return;
	if (play == 1)
		return;
	err = paNoError;
	data.frameIndex = 0;
	data.maxFrameIndex = totalFrames = NUM_SECONDS * SAMPLE_RATE * 1000;
	err = Pa_OpenStream(
		&stream,
		NULL, 
        &outputParameters,
		SAMPLE_RATE,
		FRAMES_PER_BUFFER,
		paClipOff,
		playCallback,
		&data );
	if( stream )
	{
		err = Pa_StartStream(stream);
	}
	play = 1;
}

void	Sound::resetIndex()
{
	data.frameIndex = 0;
}

void	Sound::setSound(float* sample)
{
	set = 1;
	resetIndex();
	data.recordedSamples = sample;
}

float*	Sound::getSound()
{
	resetIndex();
	return data.recordedSamples;
}
