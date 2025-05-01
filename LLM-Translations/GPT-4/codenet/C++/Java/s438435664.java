import java.util.*;
import java.math.*;

public class s438435664 {
    public static long gcd(long x, long y) {
        long tmp = 0;
        if (x < y){
            tmp=x;
            x=y;
            y=tmp;
        }
        while (y > 0) {
            long r = x % y;
            x = y;
            y = r;
        }
        return x;
    }

    public static long lcm(long x,long y){
        return x/gcd(x,y)*y;
    }

    public static long kaijo(long k){
        long sum = 1;
        for (long i = 1; i <= k; ++i)
        {
            sum *= i;
            sum%=1000000000+7;
        }
        return sum;
    }

    public static long lmax(long s,long t){
        if(s>t){
            return s;
        }
        else{
            return t;
        }
    }

    public static long lmin(long s,long t){
        if(s<t){
            return s;
        }
        else{
            return t;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long sum = 0;
        for(int b = 1; b <= n; b++){
            int cnt = (n+1)/b;
            int md = (n+1)%b;
            sum+=cnt*Math.max((b-k),0)+Math.max((md-k),0);
            if(k==0) sum--;
        }
        System.out.println(sum);
    }
} // 
