package MySBCode;
public class Dmo2{
    public static void main(String args[]){
        Simulator s = new Simulator();
        s.playSound(new Dog());
        s.playSound(new Cat());
    }
}
interface Animal{
    public void cry();
    public String getAnimalName();
} 
class Simulator{
    public void playSound(Animal a){
        String s = a.getAnimalName();
        System.out.println("我是"+s);
        a.cry();
    }
}
class Dog implements Animal{
    public String name;
    public Dog(){
        name = "狗";
    }
    public void cry(){
        System.out.println("汪汪汪");
    }
    public String getAnimalName(){
        return name;
    }
}
class Cat implements Animal{
    public String name;
    public Cat(){
        name = "猫";
    }
    public void cry(){
        System.out.println("喵喵喵");
    }
    public String getAnimalName(){
        return name;
    }
}