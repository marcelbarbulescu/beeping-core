#ifndef __ENCODERAUDIBLE__
#define __ENCODERAUDIBLE__

#include "Encoder.h"

namespace BEEPING
{
  class EncoderAudible : public Encoder
  {
  public:
    EncoderAudible(float samplingRate, int windowSize);
    ~EncoderAudible(void);

    int EncodeDataToAudioBuffer(const char *stringToEncode, int type, int size, const char *melodyString, int melodySize);
  };
}

#endif //__ENCODERAUDIBLE__