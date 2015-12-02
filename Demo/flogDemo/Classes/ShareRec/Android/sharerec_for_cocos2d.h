#ifndef _Included_cn_sharerec_sharerec_for_cocos2d_h
#define _Included_cn_sharerec_sharerec_for_cocos2d_h

#ifndef WIN32
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
USING_NS_CC;
#else
#define jlong long long
#define jboolean bool
#define jobject int
typedef struct JniMethodInfo_{} JniMethodInfo;
#endif

#ifndef WIN32
#define  LOG_TAG    "sharerec"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#else
#define  LOGD(...)
#endif

namespace cn {
	namespace sharerec {

		#define STATE_IDLE 0
		#define STATE_STARTING 1
		#define STATE_STARTED 2
		#define STATE_PAUSING 3
		#define STATE_PAUSED 4
		#define STATE_RESUMING 5
		#define STATE_RESUMED STATE_STARTED
		#define STATE_STOPING 7
		#define STATE_STOPPED STATE_IDLE
		
		#ifdef __cplusplus
		extern "C" {	
		#endif
#ifndef WIN32

			JNIEXPORT void JNICALL Java_cn_sharerec_recorder_impl_Cocos2DRecorder_onStateChange
					(JNIEnv* env, jobject thiz, jint listener, jint state);
#endif

		#ifdef __cplusplus
		}
		#endif

		class ShareRec {
		public:
			
			 enum LevelMaxFrameSize{
				LEVEL_480_360 = 0,
				LEVEL_1280_720 = 1,
				LEVEL_1920_1080 = 2,
				LEVEL_2048_1152 = 3,
				LEVEL_3840_2160 = 4
			 };
			
			typedef void(*OnRecorderStateListener) (int state);

			/**
			  * ������Ʒֱ��� (Set design resolution)
			  */
			static void setDesignResolution();
		
			/**
			  * �ж�ShareRec�Ƿ�֧�ֵ�ǰ���豸(Determines whether ShareRec is available for the current device.)
			  */
			static bool isAvailable();
			
			/**
			  * ����¼��ģ�� (Start the recorder module)
			  */
			static void startRecorder();
			
			/**
			  * ��ͣ¼��ģ�� (Pause the recorder module)
			  */
			static void pauseRecorder();
			
			/**
			  * �ָ�¼��ģ�� (Resume the recorder module)
			  */
			static void resumeRecorder();
		
			/**
			  * ֹͣ¼��ģ�� (Stop the recorder module)
			  */
			static void stopRecorder();
		
			/**
			  * ����Ƶ����(Shows the video center.)
			  */
			static void showVideoCenter();
			
			/**
			  * ��ʾ�û�����(Shows the user profile.)
			  */
			static void showProfile();
		
			/**
			  * ������Ƶ����(Sets the description of the video.)
			  */
			static void setText(const char* text);
		
			/**
			  * �����Ƶ���Զ�������(Adds the custom attributes of the video.)
			  */
			static void addCustomAttr(const char* key, const char* value);
		
			/**
			  * ��ʾ����ҳ��(Shows the share page.)
			  */
			static void showShare();
		
			/**
			  * ���ShareRec�Ļ���Ŀ¼(Clears the cache folder of ShareRec.)
			  */
			static void clearCache();

			/**
			  * ����״̬�ص� (Add a recording state listener)
			  */
			static void setOnRecorderStateListener(OnRecorderStateListener listener);

			/**
			  * ��ʾ�쳣��־(Show exception loggs)
			  */
			static void setDebuggable();
			
			/**
			  * �������¼���ֱ��ʣ�0--��480*360��1--��1280*720��2--��1920*1080��
			  */
			static void setMaxFrameSize(LevelMaxFrameSize level);

			/**
			  * �г������Ѿ��������Ƶ(Lists the local videos.)
			  */
			static void listLocalVideos(jlong** list, int* len);

			/**
			  * ͨ���������ƵID��ȡ����·��(Gets the local video path by its ID.)
			  */
			static bool getLocalVideoPath(jlong videoId, char** path);

			/**
			  * ɾ��������Ƶ(Deletes the local video by its ID.)
			  */
			static void deleteLocalVideo(jlong videoId);

			/**
			  * �����Ƿ�ʹ��opengl3.0 �ķ�ʽ¼��.
			  */
			static void setUseES3( jboolean bES3 );
			
			/**
			  * �����Ƿ���Ҫ¼������
			*/
			static void setRecordAudio( jboolean isRecordAudio );
			
		 /**
			* ������Ҫ¼�Ƶ����ʱ��
			*/
			static void setMinDuration( jlong duration );

		private:

			static jobject getRecorder();
			
			static bool getMethod(JniMethodInfo& mi, const char* name, const char* sig);

			static void releaseMethod(JniMethodInfo& mi);

		};
	}
}

#endif
