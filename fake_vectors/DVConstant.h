#ifndef _DVConstant_h
#define _DVConstant_h

#include "DVVector.h"

template<class _T>
struct ConstantView
{
	typedef _T value_t;
	typedef const _T& ref_t;

	size_t _size;
	value_t _value;

#ifdef DEVICE_ONLY
	__device__ size_t size() const
	{
		return _size;
	}

	__device__ ref_t operator [](size_t)
	{
		return _value;
	}
#endif
};


#ifndef DEVICE_ONLY

class THRUST_RTC_API DVConstant : public DVVectorLike
{
public:
	ViewBuf value() const { return m_value; }
	DVConstant(TRTCContext& ctx, const DeviceViewable& dvobj, size_t size = (size_t)(-1));
	virtual std::string name_view_cls() const;
	virtual ViewBuf view() const;

private:
	ViewBuf m_value;
	size_t m_offsets[3];
};

#endif 

#endif
