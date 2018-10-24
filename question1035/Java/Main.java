package question1035;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] input1 = scanner.nextLine().split("\\s+");
        int[] array1 = new int[n];
        for (int i = 0; i < n; i++) {
            array1[i] = Integer.parseInt(input1[i]);
        }
        String[] input2 = scanner.nextLine().split("\\s+");
        int[] array2 = new int[n];
        for (int i = 0; i < n; i++) {
            array2[i] = Integer.parseInt(input2[i]);
        }
        if(isInsertionSort(array1, array2)){
            System.out.println("Insertion Sort");
            nextInsertionArray(array1, array2);
            for (int k = 0; k < n; k++) {
                System.out.print(array2[k]);
                if(k != n - 1){
                    System.out.print(" ");
                }
            }
        }else{
            System.out.println("Merge Sort");
            nextMergeArray(array1, array2);
            for (int k = 0; k < n; k++) {
                System.out.print(array2[k]);
                if(k != n - 1){
                    System.out.print(" ");
                }
            }
        }
    }

    private static boolean isInsertionSort(int[] array1, int[] array2){
        int i = array1.length - 1;
        for (; i >= 0; i--) {
            if(array1[i] != array2[i]){
                break;
            }
        }
        for (int j = 0; j < i; j++) {
            if(array2[j + 1] < array2[j]){
                return false;
            }
        }
        return true;
    }

    private static void nextInsertionArray(int[] array1, int[] array2){
        //the key of next array of Merge Sort is to determine we have visited to which place in array2
        int i = 1;
        for (; i < array2.length; i++) {
            if(array2[i] < array2[i - 1]){
                break;
            }
        }
        int temp = array2[i];
        int j = i;
        for (; j - 1 >= 0 && array2[j - 1] >= temp; j--) {
            array2[j] = array2[j - 1];
        }
        array2[j] = temp;
    }

    private static void nextMergeArray(int[] array1, int[] array2){
        //the key of next array of Merge Sort is to determine the merge size
        int size = 1;
        while(true) {
            //we set a variable flag to judge is this size has been sorted
            boolean flag = true;
            size *= 2;
            for (int i = 0; i < array2.length; i += size) {
                for (int j = i; j < i + size - 1; j++) {
                    if(j + 1 < array2.length && array2[j + 1] < array2[j]){
                        flag = false;
                    }
                }
            }
            //if this size has not been sorted, we break
            if(!flag){
                break;
            }
        }
        //now, the variable size represents the unsorted size, we need to divide it by 2. Then the size is the sorted size.
        size /= 2;
        int[] tempArray = new int[array2.length];
        for (int i = 0; i < array2.length; i++) {
            tempArray[i] = array2[i];
        }
        for(int i = 0; i < array2.length; i += size * 2){
            int index1 = i;
            int index2 = i + size;
            int index = i;
            //pay attention to avoid IndexOutOfBoundsException
            while(index1 < Math.min(i + size, array2.length) || index2 < Math.min(i + 2 * size, array2.length)){
                if(index1 >= i + size || index1 >= array2.length){
                    array2[index++] = tempArray[index2++];
                }else if(index2 >= i + 2 * size || index2 >= array2.length){
                    array2[index++] = tempArray[index1++];
                }else if(tempArray[index1] <= tempArray[index2]){
                    array2[index++] = tempArray[index1++];
                }else{
                    array2[index++] = tempArray[index2++];
                }
            }
        }
    }
}
