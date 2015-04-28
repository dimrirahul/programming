package visitorPattern;

/**
 * Created by rdimri on 4/26/15.
 */
public abstract  class AbstractElement implements VisitableElement {
    public abstract void accept(Visitor v);
}
