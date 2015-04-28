package visitorPattern;

/**
 * Created by rdimri on 4/26/15.
 */
public interface VisitableElement {
    public void accept(Visitor v);
}
