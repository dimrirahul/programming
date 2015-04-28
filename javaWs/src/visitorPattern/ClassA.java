package visitorPattern;

/**
 * Created by rdimri on 4/26/15.
 */
public class ClassA extends AbstractElement implements VisitableElement {
    private final int v;
    public ClassA(int _v) {
        v = _v;
    }
    public void accept(Visitor v) {
        v.visit(this);
    }

    public int getV() {
        return v;
    }
}
