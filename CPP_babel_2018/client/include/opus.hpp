//
// EPITECH PROJECT, 2018
// opus.hpp
// File description:
// 
//

#include "port_audio.hpp"

#ifndef _OPUS_HPP
#define _OPUS_HPP

class Opus
{
public:
	Opus();
	~Opus();
	char	*encodeSound(float *);
	float	*decodeSound(char*);
private:
	int	error;
	int	decodesize;
	opus_int32	rate;
	int	size;
	OpusEncoder	*op;
	OpusDecoder	*dop;
	int	totalFrames;
	int	numSamples;
	int	numBytes;
	int	len;
};

#endif /* _OPUS_HPP_ */
