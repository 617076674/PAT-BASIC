package question1012;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] strings = scanner.nextLine().split("\\s+");
        int[] nums = new int[strings.length];
        for (int i = 0; i < strings.length; i++) {
            nums[i] = Integer.parseInt(strings[i]);
        }
        ArrayList<Integer> arrayList1 = conditionA1(nums);
        if(arrayList1.size() == 0){
            System.out.print("N ");
        }else{
            int sum = 0;
            for (int i = 0; i < arrayList1.size(); i++) {
                sum += arrayList1.get(i);
            }
            System.out.print(sum + " ");
        }
        ArrayList<Integer> arrayList2 = conditionA2(nums);
        if(arrayList2.size() == 0){
            System.out.print("N ");
        }else{
            int sum = 0;
            for (int i = 0; i < arrayList2.size(); i++) {
                if(i % 2 == 0){
                    sum += arrayList2.get(i);
                }else{
                    sum -= arrayList2.get(i);
                }
            }
            System.out.print(sum + " ");
        }
        ArrayList<Integer> arrayList3 = conditionA3(nums);
        if(arrayList3.size() == 0){
            System.out.print("N ");
        }else {
            System.out.print(arrayList3.size() + " ");
        }
        ArrayList<Integer> arrayList4 = conditionA4(nums);
        if(arrayList4.size() == 0){
            System.out.print("N ");
        }else{
            int sum = 0;
            for (int i = 0; i < arrayList4.size(); i++) {
                sum += arrayList4.get(i);
            }
            double average = 1.0 * sum / arrayList4.size();
            System.out.printf("%.1f ", average);
        }
        ArrayList<Integer> arrayList5 = conditionA5(nums);
        if(arrayList5.size() == 0){
            System.out.print("N");
        }else{
            int max = arrayList5.get(0);
            for (int i = 1; i < arrayList5.size(); i++) {
                if(arrayList5.get(i) > max){
                    max = arrayList5.get(i);
                }
            }
            System.out.print(max);
        }
    }

    private static ArrayList<Integer> conditionA1(int[] nums){
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i = 1; i < nums.length; i++) {
            if(nums[i] % 2 == 0 && nums[i] % 5 == 0){
                arrayList.add(nums[i]);
            }
        }
        return arrayList;
    }

    private static ArrayList<Integer> conditionA2(int[] nums){
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i = 1; i < nums.length; i++) {
            if(nums[i] % 5 == 1){
                arrayList.add(nums[i]);
            }
        }
        return arrayList;
    }

    private static ArrayList<Integer> conditionA3(int[] nums){
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i = 1; i < nums.length; i++) {
            if(nums[i] % 5 == 2){
                arrayList.add(nums[i]);
            }
        }
        return arrayList;
    }

    private static ArrayList<Integer> conditionA4(int[] nums){
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i = 1; i < nums.length; i++) {
            if(nums[i] % 5 == 3){
                arrayList.add(nums[i]);
            }
        }
        return arrayList;
    }

    private static ArrayList<Integer> conditionA5(int[] nums){
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i = 1; i < nums.length; i++) {
            if(nums[i] % 5 == 4){
                arrayList.add(nums[i]);
            }
        }
        return arrayList;
    }
}
