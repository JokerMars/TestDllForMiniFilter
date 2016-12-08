using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace WrapDll
{
    public class Communicate
    {
        [DllImport("CommunicateDll.dll", EntryPoint = "ConnectPort",
            ExactSpelling = false, CallingConvention = CallingConvention.Cdecl)]
        public extern static bool ConnectPort(byte[] lpPortName);

        [DllImport("CommunicateDll.dll", EntryPoint = "ClosePort",
            ExactSpelling = false, CallingConvention = CallingConvention.Cdecl)]
        public extern static void ClosePort();

        [DllImport("CommunicateDll.dll", EntryPoint = "OpenSystem",
            ExactSpelling = false, CallingConvention = CallingConvention.Cdecl)]
        public extern static bool OpenSystem();


        [DllImport("CommunicateDll.dll", EntryPoint = "CloseSystem",
            ExactSpelling = false, CallingConvention = CallingConvention.Cdecl)]
        public extern static bool CloseSystem();


        [DllImport("CommunicateDll.dll", EntryPoint = "IsSystemRunning",
            ExactSpelling = false, CallingConvention = CallingConvention.Cdecl)]
        public extern static bool IsSystemRunning();

        [DllImport("CommunicateDll.dll", EntryPoint = "SendKey",
            ExactSpelling = false, CallingConvention = CallingConvention.Cdecl)]
        public extern static bool SendKey(string key);

        [DllImport("CommunicateDll.dll", EntryPoint = "SendStrategy",
            ExactSpelling = false, CallingConvention = CallingConvention.Cdecl)]
        public extern static bool SendStrategy(string strategy);


    }
}
