package question1011;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = Integer.parseInt(scanner.nextLine());
        for (int i = 1; i <= count; i++) {
            String[] strings = scanner.nextLine().split("\\s+");
            Long[] nums = new Long[3];
            for(int j = 0; j < 3; j++){
                nums[j] = Long.parseLong(strings[j]);
            }
            if(nums[0] + nums[1] > nums[2]){
                System.out.print("Case #" + i + ": " + true);
            }else{
                System.out.print("Case #" + i + ": " + false);
            }
            if(i != count){
                System.out.println();
            }
        }
    }
}
