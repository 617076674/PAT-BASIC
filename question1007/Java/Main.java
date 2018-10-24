package question1007;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int index = 0;
        int result = 0;
        int[] primes = new int[num];
        for (int i = 2; i <= num; i++) {
            if (isPrime(i)) {
                primes[index++] = i;
                if (index < 2) {
                    continue;
                }
                if (primes[index - 1] - primes[index - 2] == 2) {
                    result++;
                }
            }
        }
        System.out.println(result);
    }

    private static boolean isPrime(int num) {
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}
