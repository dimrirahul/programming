package visitorPattern;

/**
 * Created by rdimri on 4/26/15.
 */
public interface Visitor {
    void visit(ClassA aObj);
    void visit(ClassB bObj);
}
