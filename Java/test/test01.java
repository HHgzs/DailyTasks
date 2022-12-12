package test;

public class test01 {
    public static void main(String[] args) {
        long a1 = 10000000000000L;
        float a2 = 1.25F;
        System.out.println(a1);
        System.out.println(a2);
        int a3 = (int) a2;
        System.out.println(a3);
        System.out.println(a3 ^ (int) a2);
    }

}

