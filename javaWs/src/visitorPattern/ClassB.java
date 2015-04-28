package visitorPattern;

/**
 * Created by rdimri on 4/26/15.
 */
public class ClassB extends AbstractElement implements VisitableElement {
    private final String name;
    public ClassB(String _name) {
        name = _name;
    }
    String getName() {
        return name;
    }
    public void accept(Visitor v) {
        v.visit(this);
    }
}
