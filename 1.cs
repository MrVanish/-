using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1
{
    class Program
    {
        static List<bool> used;
        static int N;
        static int M;
        static List<List<int>> g;

        static void DFS(int v)
        {
            used[v] = true;
            for (int i = 0; i < g[v].Count; ++i)
            {
                if (used[g[v][i]] == false)
                    DFS(g[v][i]);
            }
        }

        static void Main(string[] args)
        {

            string[] s = Console.ReadLine().Split(' ');
            N = int.Parse(s[0]);
            M = int.Parse(s[1]);
            string[] s2;
            g = new List<List<int>>(N);
            used = new List<bool>(new bool[N]);
            for (int i = 0; i < N; ++i)
                g.Add(new List<int>());
            int v1, v2;
            for (int i = 0; i < M; ++i)
            {
                s2 = Console.ReadLine().Split(' ');
                v1 = int.Parse(s2[0]);
                v2 = int.Parse(s2[1]);
                v2--;
                v1--;
                g[v1].Add(v2);
                g[v2].Add(v1);
            }
            int x = 0;
            for (int i = 0; i < N; ++i)
                if (used[i] == false)
                {
                    DFS(i);
                    x++;
                }
            Console.WriteLine(x - 1);
            Console.ReadKey();
        }

    }
}