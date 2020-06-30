
#ifndef __ENCODERAUDIBLEMULTITONE__
#define __ENCODERAUDIBLEMULTITONE__

#include "Encoder.h"

namespace BEEPING
{
  class EncoderAudibleMultiTone : public Encoder
  {
  public:
    EncoderAudibleMultiTone(float samplingRate, int windowSize);
    ~EncoderAudibleMultiTone(void);

    float* mCurrentFreqs;
    float* mCurrentFreqsLoudness;

    int EncodeDataToAudioBuffer(const char *stringToEncode, int type, int size, const char *melodyString, int melodySize);
  };
}

#endif //__ENCODERAUDIBLEMULTITONE__