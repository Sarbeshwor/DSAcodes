interface A{
    int getnumber();
    default void show(){
        System.out.println("Hello");
    }
}
class myA implements A{
    public int getnumber(){
        return 10;
    }
}
public class Dfal{
    public static void main(String[] args){
        A obj = new myA();
        obj.show();
    }
}