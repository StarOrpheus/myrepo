import java.awt.image.AreaAveragingScaleFilter;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class Main
{
    static class Bor
    {
        public class vertex
        {
            int         next[];
            boolean     leaf;
            int         p;
            int         pch;
            int         link;
            int         go[];
            int         bc;
            vertex(){}
        }
        public vertex t[];
        public boolean good[];
        public int k    = 1;
        public int ans  = 0;
        public int bc   = 0;
        public void init(int v)
        {
//        Arrays.fill(t[v].next, -1);
//        Arrays.fill(t[v].go, -1);
            t[v].next   = new int[26];
            t[v].go     = new int[26];
            for(int i = 0; i < 26; i++)
            {
                t[v].next[i]    = -1;
                t[v].go[i]      = -1;
            }
            t[v].p      = -1;
            t[v].leaf   = false;
        }
        public int VertexCount()
        {
            return k;
        }
        public void add_string(final String s)
        {
            int v = 0;
            for(int i = 0; i < s.length(); i++)
            {
                int c = (int) s.charAt(i) - 'a';
                if(t[v].next[c] == -1)
                {
                    init(k);
                    t[v].next[c]    = k;
                    t[k].p          = v;
                    t[k].pch        = c;
                    t[k].bc         = t[v].bc + ((good[c]) ? 0 : 1);
                    ans             += (t[k].bc <= bc) ? 1 : 0;
                    k++;
                }
                v = t[v].next[c];
            }
            t[v].leaf = true;
        }
        public int link(int v)
        {
            if(t[v].link == -1)
            {
                if(v == 0 || t[v].p == 0)
                    t[v].link = 0;
                else t[v].link = go(link(t[v].p), t[v].pch);
            }
            return t[v].link;
        }
        public int go(int v, int c)
        {
            if(t[v].go[c] == -1)
            {
                if(t[v].next[c] != -1)
                    t[v].go[c] = t[v].next[c];
                else if(v == 0)
                    t[v].go[c] = 0;
                else
                    t[v].go[c] = go(link(v), c);
            }
            return t[v].go[c];
        }
        Bor()
        {
            t = new vertex[2000500];
            for(int i = 0; i < t.length; i++)
                t[i] = new vertex();
            good = new boolean[26];
            Arrays.fill(good, false);
            init(0);
        }
    }

    public static void main(String[] argc)
    {
        Scanner sc      = new Scanner(System.in);
        PrintWriter pw  = new PrintWriter(System.out);
        Bor b = new Bor();
        String s1 = sc.next(), s2 = sc.next();
        int k   = sc.nextInt();
        b.bc    = k;
        for(int i = 0; i < 26; i++)
        {
            b.good[i] = (s2.charAt(i) - '0' != 0);
        }
        for(int i = 0; i < s1.length(); i++)
        {
            b.add_string(s1.substring(i));
        }
        pw.println(b.ans);
        sc.close();
        pw.close();
    }
}
