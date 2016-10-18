#include <jni.h>
#define LOG_TAG "HelloWorld"
#include<android/log.h>

#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt, ##args)

/* Native interface, it will be call in java code */
JNIEXPORT jstring JNICALL Java_com_example_helloworld_MainActivity_printJNI(JNIEnv *env, jobject obj,jstring inputStr)
{
	LOGI("dufresne Hello World From libhelloworld.so!");
	const char *str = (const char*)(*env)->GetStringUTFChars(env,inputStr,JNI_FALSE);
	(*env)->ReleaseStringUTFChars(env, inputStr, (const char *)str);
	return (*env)->NewStringUTF(env, "Hello World! I am Native interface");
}

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	LOGI("dufresne----->JNI_OnLoad!");
	void *venv;
	if ((*vm)->GetEnv(vm,(void**)&venv, JNI_VERSION_1_4) != JNI_OK) {
		LOGE("dufresne--->ERROR: GetEnv failed");
		return -1;
	}
	return JNI_VERSION_1_4;
}