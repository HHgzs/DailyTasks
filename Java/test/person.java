package test;

public class person {
    public String name;
    protected int age;
    public int num = 1;

    public person(int age) {
        this.age = age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getAge() {
        return age;
    }

    public void polymorphism() {
        System.out.println("First");
    }
}

class student extends person {

    public int num = 2;

    public student(int age) {
        super(age);
    }

    public void name_change() {
        System.out.println(name);
        name = new StringBuilder(name).append(" Student").toString();
        System.out.println(name);
    }

    public void test_super() {
        System.out.println(this.num);
        System.out.println(super.num);
    }

    @Override
    public void polymorphism() {
        System.out.println("Second");
    }
}