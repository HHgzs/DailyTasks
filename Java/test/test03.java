package test;
public class test03 {
    public static void main(String[] args) {

        // 创建学生对象
        Student s1 = new Student("itheima", "14");
        Student s2 = new Student("itheima", "14");

        // 调用toString方法获取s1对象的字符串表现形式
        String result1 = s1.toString();

        // 输出结果
        System.out.println("s1对象的字符串表现形式为：" + result1);

        boolean result = s1.equals(s2);
        System.out.println(result);
    }

}

class Student {

    private String name; // 姓名
    private String age; // 年龄

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