package MySBCode;
public class Dmo1{
    public static void main(String args[]){
        Simulator s = new Simulator();
        s.playSound(new Dog());
        s.playSound(new Cat());
    }
}
abstract class Animal{
    protected String name;
    public void cry(){};
    public String getAnimalName(){
        return name;
    }
} 
class Simulator{
    public void playSound(Animal a){
        String s = a.getAnimalName();
        System.out.println("我是"+s);
        a.cry();
    }
}
class Dog extends Animal{
    public Dog(){
        name = "狗";
    }
    public void cry(){
        System.out.println("汪汪汪");
    }
}
class Cat extends Animal{
    public Cat(){
        name = "猫";
    }
    public void cry(){
        System.out.println("喵喵喵");
    }
}