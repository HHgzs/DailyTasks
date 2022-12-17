package test;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class test04 {
    public static void main(String[] args) {
        //method 1
        System.out.println("3166237354@qq.com".matches("\\w+@[\\w&&[^_]]{2,6}(\\.[a-zA-Z]{2,3}){1,2}"));

        //method 2
        String str = "Java�Դ�95�����������������˺ܶ�汾��Ŀǰ��ҵ���õ�������Java8��Java11";

        Pattern p = Pattern.compile("Java\\d{0,2}");
        Matcher m = p.matcher(str);

        while (m.find()) {
            String s = m.group();
            System.out.println(s);
        }

    }
}
