import ThrustRTC as trtc

d_keys = trtc.device_vector_from_list([0, 0, 0, 1, 1, 2, 3, 3, 3, 3], 'int32_t')

d_values = trtc.device_vector_from_list([1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ], 'int32_t')
trtc.Inclusive_Scan_By_Key(d_keys, d_values, d_values)
print (d_values.to_host())

d_values = trtc.device_vector_from_list([1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ], 'int32_t')
trtc.Exclusive_Scan_By_Key(d_keys, d_values, d_values)
print (d_values.to_host())

d_values = trtc.device_vector_from_list([1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ], 'int32_t')
trtc.Exclusive_Scan_By_Key(d_keys, d_values, d_values, trtc.DVInt32(5))
print (d_values.to_host())
