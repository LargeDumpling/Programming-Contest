import sun.awt.image.PixelConverter;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Random;
import java.util.StringTokenizer;

public class Solution {
    static BufferedReader reader;
    static PrintWriter writer;
    static StringTokenizer tokenizer;

    public static void main(String[] args) throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
        writer = new PrintWriter(System.out);

        Solution solution = new Solution();

        solution.read();
        solution.run();

        reader.close();
        writer.close();
    }

    ArrayList<Integer> primes;

    void genPrimes(int n) {
        primes = new ArrayList<Integer>();
        boolean npr[] = new boolean[n + 1];
        npr[0] = npr[1] = true;

        for (int i = 0; i < npr.length; i++) {
            if(npr[i])
                continue;

            primes.add(i);

            for(long j = (long) i * i; j < npr.length; j += i)
                npr[(int)j] = true;
        }
    }

    int n, m, b;
    int[] a;

    void read() throws IOException {
        n = nextInt();
        m = nextInt();
        b = nextInt();

        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
    }

    void run() throws IOException {
        genPrimes(n);

        int k = 0, l = 0;
        long sumA = 0, sumB = 0;

        for (int i = 0; i < n; i++) {
            if(a[i] <= b){
                k++;
                sumA += a[i];
            } else {
                l++;
                sumB += a[i];
            }
        }

        if(k == 0 || l == 0) {
            BigInteger num = BigInteger.valueOf((sumA + sumB) * m);
            BigInteger den = BigInteger.valueOf(n);
            BigInteger g = num.gcd(den);

            num = num.divide(g);
            den = den.divide(g);

            writer.println(num);
            writer.println(den);

            return;
        }

        if(m >= l) {
            BigInteger num1 = BigInteger.valueOf(sumA * m);
            BigInteger den1 = BigInteger.valueOf(k);

            BigInteger num2 = BigInteger.valueOf(l).multiply(BigInteger.valueOf(sumB * k - sumA * l));
            BigInteger den2 = BigInteger.valueOf((long) k * l * (k + 1));

            BigInteger num = num1.multiply(den2).add(num2.multiply(den1));
            BigInteger den = den1.multiply(den2);

            BigInteger g = num.gcd(den);

            num = num.divide(g);
            den = den.divide(g);

            writer.println(num);
            writer.println(den);

            return;
        }

        BigInteger[] val = calc(n, l, m);
        System.err.println("ok");

        val = mul(val, getPair(n - m, k + 1));
        val = sub2(getPair(l, k + 1), val);
        val = mul(val, getPair(sumB * k - sumA * l, k * 1l * l));
        val = add2(getPair(sumA * m, k), val);

//        writer.println("ok");
        writer.println(val[0]);
        writer.println(val[1]);
    }

    long gcd(long a, long b) {
        if(a == 0)
            return b;
        return gcd(b % a, a);
    }

    BigInteger[] getPair(long a, long b) {
        long g = gcd(a, b);
        a /= g; b /= g;
        return new BigInteger[] {BigInteger.valueOf(a), BigInteger.valueOf(b)};
    }

    BigInteger[] mul(BigInteger[] a, BigInteger[] b) {
        BigInteger g = a[0].gcd(b[1]);
        a[0] = a[0].divide(g);
        b[1] = b[1].divide(g);

        g = b[0].gcd(a[1]);
        b[0] = b[0].divide(g);
        a[1] = a[1].divide(g);

        return new BigInteger[] {a[0].multiply(b[0]), a[1].multiply(b[1])};
    }

    BigInteger[] sub(BigInteger[] a, BigInteger[] b) {
        BigInteger num = a[0].multiply(b[1]).subtract(a[1].multiply(b[0]));
        BigInteger den = a[1].multiply(b[1]);

        BigInteger g = num.gcd(den);
        num = num.divide(g);
        den = den.divide(g);

        return new BigInteger[] {num, den};
    }

    BigInteger[] add(BigInteger[] a, BigInteger[] b) {
        BigInteger num = a[0].multiply(b[1]).add(a[1].multiply(b[0]));
        BigInteger den = a[1].multiply(b[1]);

        BigInteger g = num.gcd(den);
        num = num.divide(g);
        den = den.divide(g);

        return new BigInteger[] {num, den};
    }

    BigInteger[] sub2(BigInteger[] aa, BigInteger[] bb) {
        BigInteger[] a = aa.clone();
        BigInteger[] b = bb.clone();

        BigInteger g = a[1].gcd(b[1]);
        a[1] = a[1].divide(g);
        b[1] = b[1].divide(g);

        BigInteger num = a[0].multiply(b[1]).subtract(b[0].multiply(a[1]));
        BigInteger g2 = num.gcd(g);

        num = num.divide(g2);
        g = g.divide(g2);

        return new BigInteger[]{num, g.multiply(a[1]).multiply(b[1])};
    }

    BigInteger[] add2(BigInteger[] aa, BigInteger[] bb) {
        BigInteger[] a = aa.clone();
        BigInteger[] b = bb.clone();

        BigInteger g = a[1].gcd(b[1]);
        a[1] = a[1].divide(g);
        b[1] = b[1].divide(g);

        BigInteger num = a[0].multiply(b[1]).add(b[0].multiply(a[1]));

        BigInteger g2 = num.gcd(g);
        num = num.divide(g2);
        g = g.divide(g2);

        return new BigInteger[]{num, g.multiply(a[1]).multiply(b[1])};
    }

    int calcPw(int mx, int p) {
        int ans = 0;
        while(mx > 0) {
            mx /= p;
            ans += mx;
        }
        return ans;
    }

    ArrayList<int[]> getF(int lf, int rg) {
        ArrayList<int[]> ans = new ArrayList<int[]>();
        for (int i = 0; i < primes.size(); i++) {
            int cnt = calcPw(rg - 1, primes.get(i)) - calcPw(lf - 1, primes.get(i));

            if(cnt > 0)
                ans.add(new int[]{primes.get(i), cnt});
        }
        return ans;
    }

    ArrayList<int[]> upd(ArrayList<int[]> v) {
        ArrayList<int[]> ans = new ArrayList<int[]>();
        for (int i = 0; i < v.size(); i++) {
            if(v.get(i)[1] == 0)
                continue;
            ans.add(v.get(i));
        }
        return ans;
    }

    BigInteger calcMul(ArrayList<int[]> p) {
        if(p.size() == 0)
            return BigInteger.ONE;

        ArrayList<Integer> vals = new ArrayList<Integer>();

        for (int i = 0; i < p.size(); i++) {
            int cp = p.get(i)[0];
            int cpw = p.get(i)[1];

            int cnt = 0;
            long cv = 1;
            while(cv * cp <= n) {
                cnt++;
                cv *= cp;
            }

            for (int j = 0; j < cpw / cnt; j++) {
                vals.add((int)cv);
            }

            if(cpw % cnt > 0) {
                cv = 1;
                for (int j = 0; j < cpw % cnt; j++) {
                    cv *= cp;
                }
                assert(cv <= n);

                vals.add((int)cv);
            }
        }

        ArrayList<BigInteger> els = new ArrayList<BigInteger>();

        for (int i = 0; i < vals.size(); i++) {
            els.add(BigInteger.valueOf(vals.get(i)));
        }

        while(els.size() > 1) {
            ArrayList<BigInteger> ne = new ArrayList<BigInteger>();

            for(int i = 0; i < els.size(); i += 2) {
                if(i + 1 < els.size())
                    ne.add(els.get(i).multiply(els.get(i + 1)));
                else
                    ne.add(els.get(i));
            }

            els = ne;
        }

        return els.get(0);
    }

    BigInteger[] calc(int n, int l, int m) {
        ArrayList<int[]> num = getF(l - m, l + 1);
        ArrayList<int[]> den = getF(n - m, n + 1);

        int u = 0, v = 0;
        while(u < num.size() && v < den.size()) {
            if(num.get(u)[0] == den.get(v)[0]) {
                int mn = Math.min(num.get(u)[1], den.get(v)[1]);
                num.get(u)[1] -= mn;
                den.get(v)[1] -= mn;

                u++; v++;
                continue;
            }

            if(num.get(u)[0] < den.get(v)[0])
                u++;
            else
                v++;
        }

        num = upd(num);
        den = upd(den);

        return new BigInteger[] {calcMul(num), calcMul(den)};
    }

    String nextToken() throws IOException {
        if (tokenizer == null || !tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(reader.readLine());
        return tokenizer.nextToken();
    }

    String nextString() throws IOException {
        return nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    BigInteger nextBigInteger() throws IOException {
        return new BigInteger(nextToken());
    }
}