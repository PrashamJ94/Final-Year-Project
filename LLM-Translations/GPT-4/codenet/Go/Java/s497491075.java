
import java.io.*;
import java.util.*;
import java.lang.Math;

public class s497491075 {
    public static void main(String[] args) {
        run(System.in, System.out);
    }

    public static void run(InputStream r, PrintStream w) {
        Scanner sc = new Scanner(r);

        int[] a = readLine(sc).toInts();
        int N = a[0], D = a[1];

        List<int[]> lines = readLines(sc, N).toInts();

        int count = 0;
        for (int[] line : lines) {
            double d = Math.sqrt(line[0] * line[0] + line[1] * line[1]);
            if ((double) D >= d) {
                count++;
            }
        }
        w.println(count);
    }

    public static Value readLine(Scanner sc) {
        if (sc.hasNextLine()) {
            return new Value(sc.nextLine());
        }
        throw new IllegalStateException("scan error");
    }

    public static Values readLines(Scanner sc, int n) {
        List<Value> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(readLine(sc));
        }
        return new Values(a);
    }
}

class Value {
    private String value;

    public Value(String value) {
        this.value = value;
    }

    public String toString() {
        return value;
    }

    public int toInt() {
        return Integer.parseInt(value);
    }

    public double toDouble() {
        return Double.parseDouble(value);
    }

    public String[] toStrings() {
        return value.split(" ");
    }

    public int[] toInts() {
        String[] strings = toStrings();
        int[] a = new int[strings.length];
        for (int i = 0; i < strings.length; i++) {
            a[i] = Integer.parseInt(strings[i]);
        }
        return a;
    }

    public double[] toDoubles() {
        String[] strings = toStrings();
        double[] a = new double[strings.length];
        for (int i = 0; i < strings.length; i++) {
            a[i] = Double.parseDouble(strings[i]);
        }
        return a;
    }
}

class Values {
    private List<Value> values;

    public Values(List<Value> values) {
        this.values = values;
    }

    public List<String[]> toStrings() {
        List<String[]> a = new ArrayList<>();
        for (Value value : values) {
            a.add(value.toStrings());
        }
        return a;
    }

    public List<int[]> toInts() {
        List<int[]> a = new ArrayList<>();
        for (Value value : values) {
            a.add(value.toInts());
        }
        return a;
    }

    public List<double[]> toDoubles() {
        List<double[]> a = new ArrayList<>();
        for (Value value : values) {
            a.add(value.toDoubles());
        }
        return a;
    }
}

// 
