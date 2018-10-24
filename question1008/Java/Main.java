package question1008;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        if(m >= n){
            m = m % n;
        }
        boolean[] flag = new boolean[n];
        for (int i = 0; i < n; i++) {
            if(flag[i]){
                continue;
            }
            ArrayList<Integer> arrayList = new ArrayList<>();
            arrayList.add(i);
            for (int j = 1;; j++) {
                if((i + j * m) % n == i){
                    break;
                }
                arrayList.add((i + j * m) % n);
            }
            remove(nums, arrayList);
            for (int j = 0; j < arrayList.size(); j++) {
                flag[arrayList.get(j)] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.print(nums[i]);
            if(i != n - 1){
                System.out.print(" ");
            }
        }
    }

    private static void remove(int[] nums, ArrayList<Integer> arrayList){
        int temp = nums[arrayList.get(arrayList.size() - 1)];
        for (int i = arrayList.size() - 1; i >= 1; i--) {
            nums[arrayList.get(i)] = nums[arrayList.get(i - 1)];
        }
        nums[arrayList.get(0)] = temp;
    }
}
