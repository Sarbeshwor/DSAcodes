interface Animal {
    void makeSound(); // Abstract method
    void move(); // Abstract method
}

interface Swimmer {
    void move(); // Abstract method
    void swim(); // Abstract method
}

abstract class Mammal implements Animal, Swimmer {
    @Override
    public void makeSound() { // Implementing the makeSound method
        System.out.println("Mammal makes sound");
    }

    @Override
    public void move() {  // Resolving the conflict and providing a default implementation
        System.out.println("Mammal moves");
    }
}

public class Dolphin extends Mammal {
    @Override
    public void makeSound() { 
        System.out.println("Dolphin makes a clicking sound");
    }

    @Override
    public void move() {  // Dolphin can override the move method
        System.out.println("Dolphin swims");
    }

    @Override
    public void swim() { // Implementing swim from Swimmer interface
        System.out.println("Dolphin is swimming");
    }
}

public class Test {
    public static void main(String[] args) {
        Dolphin dolphin = new Dolphin();
        dolphin.makeSound(); // Calls Dolphin's makeSound
        dolphin.move(); // Calls Dolphin's move method
        dolphin.swim(); // Calls Dolphin's swim method
    }
}
