/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class lzzy_soft_lamemp3_JNIMp3Encode */

#ifndef _Included_lzzy_soft_lamemp3_JNIMp3Encode
#define _Included_lzzy_soft_lamemp3_JNIMp3Encode
#ifdef __cplusplus
extern "C" {
#endif

#include "libmp3lame/lame.h"
#define BUFFER_SIZE 4096

lame_t lame;
/*
 * Class:     lzzy_soft_lamemp3_JNIMp3Encode
 * Method:    init
 * Signature: (III)V
 */
JNIEXPORT void JNICALL Java_lzzy_soft_lamemp3_JNIMp3Encode_init
(JNIEnv *env, jobject obj, jint channel, jint sampleRate, jint brate)
{
	lame = lame_init();
	lame_set_num_channels(lame, channel);
	lame_set_in_samplerate(lame, sampleRate);
	lame_set_brate(lame, brate);
	lame_set_mode(lame, 1);
	lame_set_quality(lame, 2);
	lame_init_params(lame);
}

/*
 * Class:     lzzy_soft_lamemp3_JNIMp3Encode
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_lzzy_soft_lamemp3_JNIMp3Encode_destroy
(JNIEnv *env, jobject obj)
{
	lame_close(lame);
}


/*
 * Class:     lzzy_soft_lamemp3_JNIMp3Encode
 * Method:    encode
 * Signature: ([SI)[B
 */
JNIEXPORT jbyteArray JNICALL Java_lzzy_soft_lamemp3_JNIMp3Encode_encode
(JNIEnv *env, jobject obj, jshortArray buffer, jint len)
{
	int nb_write = 0;
	char output[BUFFER_SIZE];

	// 杞崲涓烘湰鍦版暟缁�	jshort *input = (*env)->GetShortArrayElements(env, buffer, NULL);

	// 鍘嬬缉mp3
	nb_write = lame_encode_buffer(lame, input, input, len, output, BUFFER_SIZE);

	// 灞�儴寮曠敤锛屽垱寤轰竴涓猙yte鏁扮粍
	jbyteArray result = (*env)->NewByteArray(env, nb_write);

	// 缁檅yte鏁扮粍璁剧疆鍊�	(*env)->SetByteArrayRegion(env, result, 0, nb_write, (jbyte *)output);

	// 閲婃斁鏈湴鏁扮粍(閬垮厤鍐呭瓨娉勯湶)
	(*env)->ReleaseShortArrayElements(env, buffer, input, 0);

	return result;
}

#ifdef __cplusplus
}
#endif
#endif
