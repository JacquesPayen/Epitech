//
// EPITECH PROJECT, 2018
// opus.cpp
// File description:
// 
//

#include "../include/opus.hpp"

Opus::Opus()
{
	len = 0;
	decodesize = opus_decoder_get_size(2);
	dop = opus_decoder_create(SAMPLE_RATE, 2, &error);
	rate = SAMPLE_RATE;
	size = opus_encoder_get_size(2);
	op = opus_encoder_create(rate, 2, OPUS_APPLICATION_VOIP, &error);
	opus_encoder_ctl(op, OPUS_SET_BITRATE(rate));
	opus_encoder_ctl(op, OPUS_SET_COMPLEXITY(10));
	opus_decoder_ctl(dop, OPUS_SET_BITRATE(rate));
	opus_decoder_ctl(dop, OPUS_SET_COMPLEXITY(10));
	totalFrames = NUM_SECONDS * SAMPLE_RATE;
	numSamples = totalFrames * NUM_CHANNELS;
	numBytes = numSamples * sizeof(SAMPLE);
}

Opus::~Opus()
{
	opus_encoder_destroy(op);
	opus_decoder_destroy(dop);
}

char 	*Opus::encodeSound(float *sound)
{
	unsigned char   *data = (unsigned char*) malloc( 40000);
	char	*res;

	len = opus_encode_float(op, sound, 480, data, totalFrames);
	res = static_cast<char*>(static_cast<void *>(data));
	return (res);
}

float	*Opus::decodeSound(char *sound)
{
	float *test = (SAMPLE *) malloc( numBytes + 100);
	unsigned char	*str;
	int	res = 0;

	str = reinterpret_cast<unsigned char *>(sound);
	while (str[res] != '\0')
		res++;
	len = opus_decode_float(dop, str, res, test, 480, 0);
	free(sound);
	return test;
}
