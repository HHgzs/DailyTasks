package test;
public class test03 {
    public static void main(String[] args) {

        // ����ѧ������
        Student s1 = new Student("itheima", "14");
        Student s2 = new Student("itheima", "14");

        // ����toString������ȡs1������ַ���������ʽ
        String result1 = s1.toString();

        // ������
        System.out.println("s1������ַ���������ʽΪ��" + result1);

        boolean result = s1.equals(s2);
        System.out.println(result);
    }

}

class Student {

    private String name; // ����
    private String age; // ����

    public Student(String name, String age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "Student{" + "name='" + name + '\'' + ", age='" + age + '\'' +
                '}';
    }

}