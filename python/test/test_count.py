import ThrustRTC as trtc

trtc.set_ptx_cache('__ptx_cache__')
ctx = trtc.Context()

op = trtc.Functor( {}, ['x'], 'ret',
'''
         ret = x % 100;
''')


darr = trtc.device_vector(ctx, 'int32_t', 2000)
trtc.Transform(ctx, trtc.DVCounter(ctx, trtc.DVInt32(0), 2000), darr, op)
print(trtc.Count(ctx, darr, trtc.DVInt32(47)))


op2 = trtc.Functor( {}, ['x'], 'ret',
'''
         ret = (x % 100)==47;
''')

trtc.Sequence(ctx, darr)
print(trtc.Count_If(ctx, darr, op2))