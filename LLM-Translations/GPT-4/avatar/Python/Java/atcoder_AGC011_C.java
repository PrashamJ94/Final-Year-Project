import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
    static int n, m, vis[], ci, cb, cc;
    static ArrayList<Integer> g[];
    
    static boolean dfs(int x) {
        Stack<int[]> stk = new Stack<>();
        boolean flag = true;
        stk.push(new int[]{x, 1});
        while(!stk.isEmpty()) {
            int[] top = stk.pop();
            int u = top[0], col = top[1];
            if(vis[u] != 0) {
                flag &= (vis[u] == col);
                continue;
            }
            vis[u] = col;
            for(int i : g[u]) {
                stk.push(new int[]{i, 3 - col});
            }
        }
        return flag;
    }
    
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        m = input.nextInt();
        vis = new int[n + 1];
        ci = cb = cc = 0;
        g = new ArrayList[n + 1];
        for(int i = 0; i <= n; i++) {
            g[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++) {
            int u = input.nextInt(), v = input.nextInt();
            g[u].add(v);
            g[v].add(u);
        }
        for(int i = 1; i <= n; i++) {
            if(vis[i] == 0) {
                if(g[i].size() == 0) {
                    ci++;
                }
                else {
                    if(dfs(i)) {
                        cb++;
                    }
                    else {
                        cc++;
                    }
                }
            }
        }
        System.out.println(ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
    }
}

// End of Code
