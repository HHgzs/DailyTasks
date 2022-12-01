
/**
 * 计算1-100之间的素数和
 *
 * @author soberw
 */

public class PrimeFor3 {
    public static void main(String[] args) {
        int sum = 0;
        int counter = 0;
        label:
        for (int i = 2; i <= 1000000; i++) {
            if (i != 2 && i % 2 == 0) {
                continue;
            }
            for (int j = 2; j <= Math.sqrt(i); j++) {
                counter++;
                if (i % j == 0) {
                    continue label;
                }
            }
            sum += i;
        }
        System.out.println(sum);
        System.out.println(counter);
    }

}

