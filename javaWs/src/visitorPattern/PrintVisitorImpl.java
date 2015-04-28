package visitorPattern;

/**
 * Created by rdimri on 4/26/15.
 */
public class PrintVisitorImpl implements Visitor {
    @Override
    public void visit(ClassA aObj) {
        System.out.println("Type of Object A value: " +aObj.getV());

    }

    @Override
    public void visit(ClassB bObj) {
        System.out.println("Type of Object B name: " + bObj.getName());
    }
}
