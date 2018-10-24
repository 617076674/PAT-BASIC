package question1001;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int count = 0;
        while(num != 1){
            if(num % 2 == 0){
                num /= 2;
            }else{
                num = (3 * num + 1) / 2;
            }
            count++;
        }
        System.out.println(count);
    }
}
