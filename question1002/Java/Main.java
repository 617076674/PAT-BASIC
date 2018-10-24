package question1002;

import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        int sum = 0;
        for (int i = 0; i < input.length(); i++) {
            sum += input.charAt(i) - '0';
        }
        String[] numbers = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
        Stack<Integer> stack = new Stack<>();
        while(sum > 0){
            int num = sum % 10;
            sum /= 10;
            stack.push(num);
        }
        StringBuilder stringBuilder = new StringBuilder();
        while(!stack.isEmpty()){
            stringBuilder.append(numbers[stack.pop()]);
            stringBuilder.append(" ");
        }
        System.out.println(stringBuilder.substring(0, stringBuilder.length() - 1));
    }
}
