/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class JThrustRTC_Native */

#ifndef _Included_JThrustRTC_Native
#define _Included_JThrustRTC_Native
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     JThrustRTC_Native
 * Method:    set_libnvrtc_path
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_set_1libnvrtc_1path
  (JNIEnv *, jclass, jstring);

/*
 * Class:     JThrustRTC_Native
 * Method:    set_verbose
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_set_1verbose
  (JNIEnv *, jclass, jboolean);

/*
 * Class:     JThrustRTC_Native
 * Method:    add_include_dir
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_add_1include_1dir
  (JNIEnv *, jclass, jstring);

/*
 * Class:     JThrustRTC_Native
 * Method:    add_built_in_header
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_add_1built_1in_1header
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     JThrustRTC_Native
 * Method:    add_include_filename
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_add_1include_1filename
  (JNIEnv *, jclass, jstring);

/*
 * Class:     JThrustRTC_Native
 * Method:    add_code_block
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_add_1code_1block
  (JNIEnv *, jclass, jstring);

/*
 * Class:     JThrustRTC_Native
 * Method:    kernel_create
 * Signature: ([Ljava/lang/String;Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_kernel_1create
  (JNIEnv *, jclass, jobjectArray, jstring);

/*
 * Class:     JThrustRTC_Native
 * Method:    kernel_destroy
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_kernel_1destroy
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    kernel_num_params
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_JThrustRTC_Native_kernel_1num_1params
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    kernel_calc_optimal_block_size
 * Signature: (J[JI)I
 */
JNIEXPORT jint JNICALL Java_JThrustRTC_Native_kernel_1calc_1optimal_1block_1size
  (JNIEnv *, jclass, jlong, jlongArray, jint);

/*
 * Class:     JThrustRTC_Native
 * Method:    kernel_calc_number_blocks
 * Signature: (J[JII)I
 */
JNIEXPORT jint JNICALL Java_JThrustRTC_Native_kernel_1calc_1number_1blocks
  (JNIEnv *, jclass, jlong, jlongArray, jint, jint);

/*
 * Class:     JThrustRTC_Native
 * Method:    kernel_launch
 * Signature: (J[I[I[JI)Z
 */
JNIEXPORT jboolean JNICALL Java_JThrustRTC_Native_kernel_1launch
  (JNIEnv *, jclass, jlong, jintArray, jintArray, jlongArray, jint);

/*
 * Class:     JThrustRTC_Native
 * Method:    for_create
 * Signature: ([Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_for_1create
  (JNIEnv *, jclass, jobjectArray, jstring, jstring);

/*
 * Class:     JThrustRTC_Native
 * Method:    for_destroy
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_for_1destroy
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    for_num_params
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_JThrustRTC_Native_for_1num_1params
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    for_launch
 * Signature: (JII[J)Z
 */
JNIEXPORT jboolean JNICALL Java_JThrustRTC_Native_for_1launch
  (JNIEnv *, jclass, jlong, jint, jint, jlongArray);

/*
 * Class:     JThrustRTC_Native
 * Method:    for_launch_n
 * Signature: (JI[J)Z
 */
JNIEXPORT jboolean JNICALL Java_JThrustRTC_Native_for_1launch_1n
  (JNIEnv *, jclass, jlong, jint, jlongArray);

/*
 * Class:     JThrustRTC_Native
 * Method:    dv_name_view_cls
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_JThrustRTC_Native_dv_1name_1view_1cls
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    dv_destroy
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_dv_1destroy
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvint8_create
 * Signature: (B)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvint8_1create
  (JNIEnv *, jclass, jbyte);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvint8_value
 * Signature: (J)B
 */
JNIEXPORT jbyte JNICALL Java_JThrustRTC_Native_dvint8_1value
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvint16_create
 * Signature: (S)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvint16_1create
  (JNIEnv *, jclass, jshort);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvint16_value
 * Signature: (J)S
 */
JNIEXPORT jshort JNICALL Java_JThrustRTC_Native_dvint16_1value
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvint32_create
 * Signature: (I)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvint32_1create
  (JNIEnv *, jclass, jint);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvint32_value
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_JThrustRTC_Native_dvint32_1value
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvint64_create
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvint64_1create
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvint64_value
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvint64_1value
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvfloat_create
 * Signature: (F)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvfloat_1create
  (JNIEnv *, jclass, jfloat);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvfloat_value
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_JThrustRTC_Native_dvfloat_1value
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvdouble_create
 * Signature: (D)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvdouble_1create
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvdouble_value
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_JThrustRTC_Native_dvdouble_1value
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvectorlike_name_elem_cls
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_JThrustRTC_Native_dvvectorlike_1name_1elem_1cls
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvectorlike_size
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_JThrustRTC_Native_dvvectorlike_1size
  (JNIEnv *, jclass, jlong);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvrange_create
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvrange_1create
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_create
 * Signature: (Ljava/lang/String;I)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvvector_1create__Ljava_lang_String_2I
  (JNIEnv *, jclass, jstring, jint);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_create
 * Signature: ([B)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvvector_1create___3B
  (JNIEnv *, jclass, jbyteArray);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_create
 * Signature: ([S)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvvector_1create___3S
  (JNIEnv *, jclass, jshortArray);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_create
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvvector_1create___3I
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_create
 * Signature: ([J)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvvector_1create___3J
  (JNIEnv *, jclass, jlongArray);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_create
 * Signature: ([F)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvvector_1create___3F
  (JNIEnv *, jclass, jfloatArray);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_create
 * Signature: ([D)J
 */
JNIEXPORT jlong JNICALL Java_JThrustRTC_Native_dvvector_1create___3D
  (JNIEnv *, jclass, jdoubleArray);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_to_host
 * Signature: (J[BII)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_dvvector_1to_1host__J_3BII
  (JNIEnv *, jclass, jlong, jbyteArray, jint, jint);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_to_host
 * Signature: (J[SII)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_dvvector_1to_1host__J_3SII
  (JNIEnv *, jclass, jlong, jshortArray, jint, jint);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_to_host
 * Signature: (J[III)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_dvvector_1to_1host__J_3III
  (JNIEnv *, jclass, jlong, jintArray, jint, jint);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_to_host
 * Signature: (J[JII)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_dvvector_1to_1host__J_3JII
  (JNIEnv *, jclass, jlong, jlongArray, jint, jint);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_to_host
 * Signature: (J[FII)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_dvvector_1to_1host__J_3FII
  (JNIEnv *, jclass, jlong, jfloatArray, jint, jint);

/*
 * Class:     JThrustRTC_Native
 * Method:    dvvector_to_host
 * Signature: (J[DII)V
 */
JNIEXPORT void JNICALL Java_JThrustRTC_Native_dvvector_1to_1host__J_3DII
  (JNIEnv *, jclass, jlong, jdoubleArray, jint, jint);

#ifdef __cplusplus
}
#endif
#endif