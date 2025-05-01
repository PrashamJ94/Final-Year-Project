
import java.util.*;

class City implements Comparable<City> {
    int prefecture;
    int position;
    int year;

    public City(int prefecture, int year, int position) {
        this.prefecture = prefecture;
        this.year = year;
        this.position = position;
    }

    @Override
    public int compareTo(City other) {
        return Integer.compare(this.year, other.year);
    }
}

public class s865387202 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        HashMap<Integer, ArrayList<City>> h = new HashMap<>();

        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            h.putIfAbsent(x, new ArrayList<>());
            h.get(x).add(new City(x, y, i));
        }

        String[] results = new String[m];

        for (ArrayList<City> cities : h.values()) {
            Collections.sort(cities);
            for (int idx = 0; idx < cities.size(); idx++) {
                City ci = cities.get(idx);
                results[ci.position] = String.format("%06d%06d", ci.prefecture, idx + 1);
            }
        }
        System.out.println(String.join("\n", results));
    }
}


