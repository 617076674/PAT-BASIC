package question1040;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        long countP = 0;
        long countPA = 0;
        long countPAT = 0;
        for (int i = 0; i < input.length(); i++) {
            if(input.charAt(i) == 'P'){
                countP++;
                countP %= 1000000007;
            }else if(input.charAt(i) == 'A'){
                countPA += countP;
                countPA %= 1000000007;
            }else if(input.charAt(i) == 'T'){
                countPAT += countPA;
                countPAT %= 1000000007;
            }
        }
        System.out.print(countPAT % 1000000007);
    }
}



