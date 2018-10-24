package question1005;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = scanner.nextInt();
        int[] nums = new int[count];
        for (int i = 0; i < count; i++) {
            nums[i] = scanner.nextInt();
        }
        ArrayList<Integer> result = new ArrayList<>();
        ArrayList<Integer> overridedNums = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            overridedNums.addAll(overridedNumbers(nums[i]));
        }
        for (int i = 0; i < count; i++) {
            if(overridedNums.contains(nums[i])){
                continue;
            }
            result.add(nums[i]);
        }
        Collections.sort(result);
        Collections.reverse(result);
        for (int i = 0; i < result.size(); i++) {
            System.out.print(result.get(i));
            if(i != result.size() - 1){
                System.out.print(" ");
            }
        }
    }

    private static ArrayList<Integer> overridedNumbers(int num){
        ArrayList<Integer> arrayList = new ArrayList<>();
        while(num > 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num = (3 * num + 1) / 2;
            }
            arrayList.add(num);
        }
        return arrayList;
    }
}
