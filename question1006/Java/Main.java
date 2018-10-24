package question1006;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        String[] strings = {"1", "12", "123", "1234", "12345", "123456", "1234567", "12345678", "123456789"};
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        ArrayList<Integer> arrayList = new ArrayList<>();
        while(num > 0){
            arrayList.add(num % 10);
            num /= 10;
        }
        StringBuilder stringBuilder = new StringBuilder();
        if(arrayList.size() == 3){
            for (int i = 0; i < arrayList.get(2); i++) {
                stringBuilder.append("B");
            }
            for (int i = 0; i < arrayList.get(1); i++) {
                stringBuilder.append("S");
            }
            if(arrayList.get(0) != 0) {
                stringBuilder.append(strings[arrayList.get(0) - 1]);
            }
        }else if(arrayList.size() == 2){
            for (int i = 0; i < arrayList.get(1); i++) {
                stringBuilder.append("S");
            }
            if(arrayList.get(0) != 0) {
                stringBuilder.append(strings[arrayList.get(0) - 1]);
            }
        }else{
            if(arrayList.get(0) != 0) {
                stringBuilder.append(strings[arrayList.get(0) - 1]);
            }
        }
        System.out.println(stringBuilder.toString());
    }
}
