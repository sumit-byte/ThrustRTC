#ifndef _DVReverse_h
#define _DVReverse_h

#include "DVVector.h"

template<class _TVVALUE>
struct ReverseView
{
	typedef typename _TVVALUE::value_t value_t;
	typedef typename _TVVALUE::ref_t ref_t;
	_TVVALUE _view_vec_value;

#ifdef DEVICE_ONLY
	__device__ size_t size() const
	{
		return _view_vec_value.size();
	}

	__device__ value_t& operator [](size_t idx)
	{
		return _view_vec_value[size()-1-idx];
	}
#endif
};


#ifndef DEVICE_ONLY

class THRUST_RTC_API DVReverse : public DVVectorLike
{
public:
	std::string cls_value() const { return m_cls_value; }
	ViewBuf view_value() const { return m_view_value; }

	DVReverse(TRTCContext& ctx, const DVVectorLike& vec_value);
	virtual std::string name_view_cls() const;
	virtual ViewBuf view() const;
	virtual bool is_readable() const { return m_readable; }
	virtual bool is_writable() const { return m_writable; }

private:
	bool m_readable;
	bool m_writable;
	std::string m_name_view_cls;
	std::string m_cls_value;
	ViewBuf m_view_value;
};

#endif 

#endif
