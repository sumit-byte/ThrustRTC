﻿using System;
using ThrustRTCSharp;

namespace test_for
{
    class test_for
    {
        static void Main(string[] args)
        {
            For ker = new For(new string[] { "arr_in", "arr_out", "k" }, "idx",
                "    arr_out[idx] = arr_in[idx]*k;\n");

            DVVector dvec_in_f = new DVVector(new float[] { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f });
            DVVector dvec_out_f = new DVVector("float", 5);
            DVFloat k1 = new DVFloat(10.0f);
            DeviceViewable[] args_f = new DeviceViewable[] { dvec_in_f, dvec_out_f, k1 };
            ker.launch_n(5, args_f);
            print_array((float[])dvec_out_f.to_host());

            DVVector dvec_in_i = new DVVector(new int[] { 6, 7, 8, 9, 10 });
            DVVector dvec_out_i = new DVVector("int32_t", 5);
            DVInt32 k2 = new DVInt32(5);
            DeviceViewable[] args_i = new DeviceViewable[] { dvec_in_i, dvec_out_i, k2 };
            ker.launch_n(5, args_i);
            print_array((int[])dvec_out_i.to_host());

        }

        static void print_array<T>(T[] arr)
        {
            foreach (var item in arr)
            {
                Console.Write(item.ToString());
                Console.Write(" ");
            }
            Console.WriteLine("");
        }
    }
}
