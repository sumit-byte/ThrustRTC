#ifndef _TRTC_transform_scan_h
#define _TRTC_transform_scan_h

#include "TRTC_api.h"
#include "TRTCContext.h"
#include "DeviceViewable.h"
#include "DVVector.h"
#include "functor.h"

bool THRUST_RTC_API TRTC_Transform_Inclusive_Scan(const DVVectorLike& vec_in, DVVectorLike& vec_out, const Functor& unary_op, const Functor& binary_op);
bool THRUST_RTC_API TRTC_Transform_Exclusive_Scan(const DVVectorLike& vec_in, DVVectorLike& vec_out, const Functor& unary_op, const DeviceViewable& init, const Functor& binary_op);


#endif