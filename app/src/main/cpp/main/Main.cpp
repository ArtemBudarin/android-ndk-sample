#include "Main.h"
#include <jni.h>
#include <string>
#include <android/log.h>

static JNIEnv *env = NULL;
static const char *TAG = "Main.cpp";

void app::showPoint(int x, int y) {
    jclass cls = env->FindClass("ru/madbrains/ndksample/JSampleJniCalls");
    jmethodID method = env->GetStaticMethodID(cls, "showPoint", "(II)V");
    env->CallStaticVoidMethod(cls, method, x, y);
}

void app::showToast(const char *message) {
    jclass cls = env->FindClass("ru/madbrains/ndksample/SampleJniCalls");
    jmethodID method = env->GetStaticMethodID(cls, "showToast", "(Ljava/lang/String;)V");
    jstring jMessage = env->NewStringUTF(message);
    env->CallStaticVoidMethod(cls, method, jMessage);
}

extern "C" JNIEXPORT jobject JNICALL Java_ru_madbrains_ndksample_SampleJniCalls_getRepository(JNIEnv *pEnv, jobject instance) {

    jclass clsRepository = env->FindClass("ru/madbrains/ndksample/Repository");
    jobject objRepository = env->AllocObject(clsRepository);

    jfieldID repositoryName = env->GetFieldID(clsRepository, "name", "Ljava/lang/String;");
    jfieldID repositoryStarCount = env->GetFieldID(clsRepository, "starCount", "I");

    env->SetObjectField(objRepository, repositoryName, env->NewStringUTF("Hippo Card Android"));
    env->SetIntField(objRepository, repositoryStarCount, 214);

    __android_log_print(ANDROID_LOG_INFO, TAG, "Repository loaded");
    app::showToast("Repository loaded");

    return objRepository;
}

extern "C" JNIEXPORT jobject JNICALL Java_ru_madbrains_ndksample_SampleJniCalls_getCommits(JNIEnv *pEnv, jobject instance) {

    const char *messages[4] = {"init", "add readme", "add gitignore", "work on architecture"};

    jclass clsArrayList = env->FindClass("java/util/ArrayList");
    jmethodID constructor = env->GetMethodID(clsArrayList, "<init>", "()V");
    jobject objArrayList = env->NewObject(clsArrayList, constructor);
    jmethodID arrayListAdd = env->GetMethodID(clsArrayList, "add", "(Ljava/lang/Object;)Z");

    for (int i = 0; i < 4; ++i) {
        jclass clsCommit =  env->FindClass("ru/madbrains/ndksample/Commit");
        jobject objCommit = env->AllocObject(clsCommit);

        jfieldID commitAuthor = env->GetFieldID(clsCommit, "author2", "Ljava/lang/String;");
        jfieldID commitMessage = env->GetFieldID(clsCommit, "message", "Ljava/lang/String;");

        env->SetObjectField(objCommit, commitAuthor, env->NewStringUTF("Artem Alekseevich Budarin"));
        env->SetObjectField(objCommit, commitMessage, env->NewStringUTF(messages[i]));

        env->CallBooleanMethod(objArrayList, arrayListAdd, objCommit);
    }

    __android_log_print(ANDROID_LOG_INFO, TAG, "Commits loaded");
    app::showToast("Commits loaded");

    return objArrayList;
}

extern "C" JNIEXPORT void JNICALL Java_ru_madbrains_ndksample_JSampleJniCalls_initJni(JNIEnv *pEnv, jclass type) {
    env = pEnv;
    __android_log_print(ANDROID_LOG_INFO, TAG, "Initialized");
    app::showPoint(20, 4);
}

extern "C" JNIEXPORT void JNICALL Java_ru_madbrains_ndksample_SampleJniCalls_initJni(JNIEnv *pEnv, jobject instance) {
    env = pEnv;
    __android_log_print(ANDROID_LOG_INFO, TAG, "Initialized");
    app::showPoint(1, 4);
}

