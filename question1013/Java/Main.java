package question1013;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        ArrayList<Integer> arrayList = new ArrayList<>();
        int index = 1;
        for (int i = 2; ; i++) {
            if(isPrime(i)){
                if(index >= m){
                    arrayList.add(i);
                }
                if(index == n){
                    break;
                }
                index++;
            }
        }
        for (int i = 0; i < arrayList.size(); i++) {
            System.out.print(arrayList.get(i));
            if(i != arrayList.size() - 1) {
                if ((i + 1) % 10 == 0) {
                    System.out.println();
                } else {
                    System.out.print(" ");
                }
            }
        }
    }

    private static boolean isPrime(int num){
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
}
