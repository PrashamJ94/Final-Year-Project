//java
import java.util.*;

public class s875904659 {

    public static void bubbleSort(Card[] cards) {
        int n = cards.length;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                if (cards[j].getValue() < cards[j - 1].getValue()) {
                    Card temp = cards[j];
                    cards[j] = cards[j - 1];
                    cards[j - 1] = temp;
                }
            }
        }
        System.out.println(Arrays.toString(cards));
    }

    public static void selectionSort(Card[] cards) {
        int n = cards.length;
        for (int i = 0; i < n; i++) {
            int minIndex = i;
            for (int j = i; j < n; j++) {
                if (cards[j].getValue() < cards[minIndex].getValue()) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                Card temp = cards[i];
                cards[i] = cards[minIndex];
                cards[minIndex] = temp;
            }
        }
        System.out.println(Arrays.toString(cards));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String[] input = sc.nextLine().split(" ");
        Card[] cards = new Card[n];
        Card[] cards2 = new Card[n];
        for (int i = 0; i < n; i++) {
            cards[i] = new Card(input[i].charAt(0), Character.getNumericValue(input[i].charAt(1)));
            cards2[i] = new Card(input[i].charAt(0), Character.getNumericValue(input[i].charAt(1)));
        }

        bubbleSort(cards);
        System.out.println("Stable");
        selectionSort(cards2);
        if (Arrays.equals(cards, cards2)) {
            System.out.println("Stable");
        } else {
            System.out.println("Not stable");
        }
    }
}

class Card {
    private char suit;
    private int value;

    public Card(char suit, int value) {
        this.suit = suit;
        this.value = value;
    }

    public char getSuit() {
        return suit;
    }

    public int getValue() {
        return value;
    }

    @Override
    public String toString() {
        return String.valueOf(suit) + String.valueOf(value);
    }
}

// 
