package question1009;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] strings = input.split(" ");
        for (int i = strings.length - 1; i >= 0; i--) {
            System.out.print(strings[i]);
            if(i != 0){
                System.out.print(" ");
            }
        }
    }
}
