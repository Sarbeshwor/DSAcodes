interface A{
    int a=10;
    void print();
    
}
interface  B extends A{
    int b = a+10;
    void show();
}
class My implements A{
    public void print(){
        System.out.println("Hello");
    }
}

class Myclass implements B{
    public void show(){
        System.out.println(B.a);
        System.out.println(B.b);

    }
    
}
public class p{
    public static void main(String[] args){
        B obj = new Myclass();
        obj.show(); 
        obj.print();

    }
}