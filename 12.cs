using System;
namespace _12
{
    class Program
    {
        static void Main(string[] args)
        {
            long ch = long.Parse(Console.ReadLine());
            if (ch % 10 == 0)
                Console.WriteLine("NO");
            else
                Console.WriteLine(ch%10);
            Console.ReadKey();
        }
    }
}
