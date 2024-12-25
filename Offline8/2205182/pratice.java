interface A {
    void show();
    int a =10;
}
class Myclass implements A{
    public void show(){
        System.out.println("Hello");
    }
    void dont(){
        System.out.println("World");
    }
}
class Om{

    interface a {
        void show();
        int a =10;
    }
    interface B {
        void show();
        int a =10;
    }

}
class My implements Om.a{
    public void show(){
        System.out.println("Hello");
    }
    void dont(){
        System.out.println("World");
    }
}
public class pratice{
    public static void main(String[] args){
        System.out.println("Hello World");
        A obj = new Myclass();
        obj.show();
        Myclass obj1 = new Myclass();
        obj1.dont();
        System.out.println(A.a);
        
        Om.a obj2 = new My();
        obj2.show();
    
    }
    
    // obj.dont();


}