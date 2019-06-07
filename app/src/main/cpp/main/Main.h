#include <jni.h>

extern "C" {

namespace app {
    void showPoint(int x, int y);
    void showToast(const char *id);
}

JNIEXPORT void JNICALL Java_ru_madbrains_ndksample_SampleJniCalls_initJni(JNIEnv *pEnv, jobject pThis);

JNIEXPORT void JNICALL Java_ru_madbrains_ndksample_JSampleJniCalls_initJni(JNIEnv *pEnv, jclass pThis);

JNIEXPORT jobject JNICALL Java_ru_madbrains_ndksample_SampleJniCalls_getRepository(JNIEnv *pEnv, jobject pThis);

JNIEXPORT jobject JNICALL Java_ru_madbrains_ndksample_SampleJniCalls_getCommits(JNIEnv *pEnv, jobject pThis);

}