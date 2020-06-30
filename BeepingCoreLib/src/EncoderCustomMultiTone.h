
#ifndef __ENCODERCUSTOMMLTITONE__
#define __ENCODERCUSTOMMLTITONE__

#include "Encoder.h"

namespace BEEPING
{
  class EncoderCustomMultiTone : public Encoder
  {
  public:
    EncoderCustomMultiTone(float samplingRate, int windowSize);
    ~EncoderCustomMultiTone(void);

    float* mCurrentFreqs;
    float* mCurrentFreqsLoudness;

    int EncodeDataToAudioBuffer(const char *stringToEncode, int type, int size, const char *melodyString, int melodySize);
  };
}

#endif //__ENCODERCUSTOMMLTITONE__