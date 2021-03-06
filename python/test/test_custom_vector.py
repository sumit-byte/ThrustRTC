import ThrustRTC as trtc



darr = trtc.device_vector('int32_t', 2000)
trtc.Sequence(darr)

d_custom_values = trtc.DVCustomVector({'src': darr}, 'idx', 
'''
    unsigned group = idx / src.size();
    unsigned sub_idx = idx % src.size();
    return src[sub_idx] % (group+1) ==0 ? 1: 0;
''', 'uint32_t', darr.size()*10)

d_custom_keys = trtc.DVCustomVector({'src': darr}, 'idx', 
'''
	return idx / src.size();
''', 'uint32_t', darr.size()*10)

d_values_out =  trtc.device_vector('uint32_t', 10)
d_keys_out = trtc.DVDiscard('uint32_t', 10)

trtc.Reduce_By_Key(d_custom_keys, d_custom_values, d_keys_out, d_values_out)

print(d_values_out.to_host())
