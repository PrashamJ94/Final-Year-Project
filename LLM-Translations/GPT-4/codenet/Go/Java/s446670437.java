
import java.util.Scanner;

public class s446670437 {
    static class Dice {
        int[] nums;

        Dice(int[] nums) {
            this.nums = nums;
        }

        void rotate(String direction, int times) {
            times %= 4;
            switch (direction) {
                case "W":
                    for (int i = 0; i < times; i++) {
                        int temp = nums[0];
                        nums[0] = nums[2];
                        nums[2] = nums[5];
                        nums[5] = nums[3];
                        nums[3] = temp;
                    }
                    break;
                case "E":
                    for (int i = 0; i < times; i++) {
                        int temp = nums[0];
                        nums[0] = nums[3];
                        nums[3] = nums[5];
                        nums[5] = nums[2];
                        nums[2] = temp;
                    }
                    break;
                case "N":
                    for (int i = 0; i < times; i++) {
                        int temp = nums[0];
                        nums[0] = nums[1];
                        nums[1] = nums[5];
                        nums[5] = nums[4];
                        nums[4] = temp;
                    }
                    break;
                case "S":
                    for (int i = 0; i < times; i++) {
                        int temp = nums[5];
                        nums[5] = nums[1];
                        nums[1] = nums[0];
                        nums[0] = nums[4];
                        nums[4] = temp;
                    }
                    break;
            }
        }

        void roll(String direction, int times) {
            times %= 4;
            switch (direction) {
                case "R":
                    for (int i = 0; i < times; i++) {
                        int temp = nums[3];
                        nums[3] = nums[1];
                        nums[1] = nums[2];
                        nums[2] = nums[4];
                        nums[4] = temp;
                    }
                    break;
                case "L":
                    for (int i = 0; i < times; i++) {
                        int temp = nums[3];
                        nums[3] = nums[4];
                        nums[4] = nums[2];
                        nums[2] = nums[1];
                        nums[1] = temp;
                    }
                    break;
            }
        }

        boolean isEqual(Dice other) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != other.nums[i]) {
                    return false;
                }
            }
            return true;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] nums1 = new int[6];
        int[] nums2 = new int[6];
        for (int i = 0; i < 6; i++) {
            nums1[i] = sc.nextInt();
        }
        for (int i = 0; i < 6; i++) {
            nums2[i] = sc.nextInt();
        }
        Dice dice1 = new Dice(nums1);
        Dice dice2 = new Dice(nums2);

        String[] directionOrder = {"N", "S", "W", "E"};
        String[] rollOrder = {"R", "L"};
        boolean flag = false;

        CHECK:
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                for (String direction : directionOrder) {
                    for (String roll : rollOrder) {
                        Dice tmp = new Dice(nums2.clone());
                        tmp.rotate(direction, i);
                        tmp.roll(roll, j);
                        if (tmp.isEqual(dice1)) {
                            flag = true;
                            break CHECK;
                        }
                    }
                }
            }
        }
        System.out.println(flag ? "Yes" : "No");
    }
}

// 
