package question1003;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int total = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < total; i++) {
            StringBuilder stringBuilder = new StringBuilder(scanner.nextLine());
            if(conditionFirst(stringBuilder)){
                if(conditionSecond(stringBuilder)){
                    System.out.println("YES");
                }else{
                    if(conditionThird(stringBuilder)){
                        System.out.println("YES");
                    }else{
                        System.out.println("NO");
                    }
                }
            }else{
                System.out.println("NO");
            }
        }
    }

    private static boolean conditionFirst(StringBuilder stringBuilder){
        for (int i = 0; i < stringBuilder.length(); i++) {
            char letter = stringBuilder.charAt(i);
            if(letter != 'P' && letter != 'A' && letter != 'T'){
                return false;
            }
        }
        return true;
    }

    private static boolean conditionSecond(StringBuilder stringBuilder){
        int indexP = stringBuilder.indexOf("PAT");
        if(indexP == -1){
            return false;
        }
        for (int i = 0; i < indexP; i++) {
            if(stringBuilder.charAt(i) != 'A'){
                return false;
            }
        }
        for (int i = indexP + 3; i < stringBuilder.length(); i++) {
            if(stringBuilder.charAt(i) != 'A'){
                return false;
            }
        }
        if(stringBuilder.substring(0, indexP).equals(stringBuilder.substring(indexP + 3))){
            return true;
        }else {
            return false;
        }
    }

    private static boolean conditionThird(StringBuilder stringBuilder){
        int indexAT = stringBuilder.indexOf("AT");
        if(indexAT == -1){
            return false;
        }
        int indexP = stringBuilder.indexOf("P");
        if(indexP == -1){
            return false;
        }
        String a = stringBuilder.substring(0, indexP);
        String b = stringBuilder.substring(indexP + 1, indexAT);
        String ca = stringBuilder.substring(indexAT + 2, stringBuilder.length());
        if(ca.length() < a.length()){
            return false;
        }
        String c = ca.substring(0, ca.length() - a.length());
        StringBuilder temp = new StringBuilder(a + "P" + b + "T" + c);
        if(conditionFirst(temp)){
            if(conditionSecond(temp)){
                return true;
            }else{
                if(conditionThird(temp)){
                    return true;
                }else{
                    return false;
                }
            }
        }else{
            return false;
        }
    }
}
