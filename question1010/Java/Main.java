package question1010;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] strings = scanner.nextLine().split("\\s+");
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < strings.length; i += 2) {
            int num1 = Integer.parseInt(strings[i]);
            int num2 = Integer.parseInt(strings[i + 1]);
            if(i == 0 && num2 == 0){
                stringBuilder.append("0 0");
                break;
            }
            int newNum1 = num1 * num2;
            int newNum2 = num2 - 1;
            if(newNum1 == 0){
                continue;
            }
            stringBuilder.append(newNum1 + " " + newNum2 + " ");
        }
        System.out.print(stringBuilder.toString().trim());
    }
}
