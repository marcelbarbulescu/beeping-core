#include <jni.h>
#include <string>
#include "BeepingCoreLib_api.h"

#ifdef __cplusplus
extern "C"
{
#endif

JNIEXPORT jlong JNICALL
Java_com_beeping_AndroidBeepingCore_BeepingCoreJNI_create(JNIEnv *env, jobject thiz)
{
  return (long)BEEPING_Create();
}

JNIEXPORT jint JNICALL
Java_com_beeping_AndroidBeepingCore_BeepingCoreJNI_configure(JNIEnv *env, jobject, jint mode, jfloat samplingRate, jlong obj)
{
  return BEEPING_Configure(mode, samplingRate, (void *)obj);
}

JNIEXPORT jint JNICALL
Java_com_beeping_AndroidBeepingCore_BeepingCoreJNI_decodeAudioBuffer(JNIEnv *env, jobject, jfloatArray audioBuffer, jint size, jlong obj)
{
  auto *nativeAudioBuffer = (jfloat *)env->GetPrimitiveArrayCritical(audioBuffer, nullptr);
  int ret = BEEPING_DecodeAudioBuffer(nativeAudioBuffer, size, (void *)obj);
  env->ReleasePrimitiveArrayCritical(audioBuffer, nativeAudioBuffer, 0);
  return ret;
}

JNIEXPORT jstring JNICALL
Java_com_beeping_AndroidBeepingCore_BeepingCoreJNI_getDecodedData(JNIEnv *env, jobject, jlong obj)
{
  char stringDecoded[16];
  return BEEPING_GetDecodedData(stringDecoded, (void *)obj) > 0 ? env->NewStringUTF(stringDecoded) : nullptr;
}

JNIEXPORT jint JNICALL
Java_com_beeping_AndroidBeepingCore_BeepingCoreJNI_encodeDataToAudioBuffer(JNIEnv *env, jobject, jstring stringToEncode, jint type, jstring melodyString, jlong obj)
{
  const char *nativeStringToEncode = env->GetStringUTFChars(stringToEncode, nullptr);
  const char *nativeMelodyString = melodyString != nullptr ? env->GetStringUTFChars(melodyString, nullptr) : nullptr;
  int ret = BEEPING_EncodeDataToAudioBuffer(nativeStringToEncode, strlen(nativeStringToEncode), type, nativeMelodyString, nativeMelodyString != nullptr ? strlen(nativeMelodyString) : 0, (void *)obj);
  env->ReleaseStringUTFChars(stringToEncode, nativeStringToEncode);
  if (nativeMelodyString != nullptr)
    env->ReleaseStringUTFChars(melodyString, nativeMelodyString);
  return ret;
}

JNIEXPORT jint JNICALL
Java_com_beeping_AndroidBeepingCore_BeepingCoreJNI_getEncodedAudioBuffer(JNIEnv *env, jobject, jfloatArray audioBuffer, jint size, jlong obj)
{
  auto *nativeAudioBuffer = (jfloat *)env->GetPrimitiveArrayCritical(audioBuffer, nullptr);
  int ret = BEEPING_GetEncodedAudioBuffer(nativeAudioBuffer, size, (void *)obj);
  env->ReleasePrimitiveArrayCritical(audioBuffer, nativeAudioBuffer, 0);
  return ret;
}

#ifdef __cplusplus
}
#endif
