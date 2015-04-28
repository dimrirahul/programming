package visitorPattern;

/**
 * Created by rdimri on 4/26/15.
 */
public class Main {
    public static void main (String[] args) {
        AbstractElementContainer aec = new AbstractElementContainer();
        ClassA obj1 = new ClassA(34);
        ClassA obj2 = new ClassA(56);
        ClassA obj3 = new ClassA(93);
        ClassB obj4 = new ClassB("Obj4");
        ClassB obj5 = new ClassB("Obj5");
        aec.addElement(obj1);
        aec.addElement(obj4);
        aec.addElement(obj5);
        aec.addElement(obj3);
        aec.addElement(obj2);
        PrintVisitorImpl printVisitor = new PrintVisitorImpl();
        aec.accept(printVisitor);
    }
}
