using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using WrapDll;

namespace TestConnect
{
    class Program
    {
        static void Main(string[] args)
        {
            string portName = "\\FileEncryptPort";
            byte[] uniString = Encoding.Unicode.GetBytes(portName);
            
            bool bRet;

            bRet = Communicate.ConnectPort(uniString);
            if(!bRet)
            {
                Console.WriteLine("Cannot connect the sys");
            }
            Console.ReadKey();
        }
    }
}
