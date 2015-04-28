package visitorPattern;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by rdimri on 4/26/15.
 */
public class AbstractElementContainer implements VisitableElement{
    List<AbstractElement> elementList = new ArrayList<AbstractElement>();
    public AbstractElementContainer() {}

    void addElement(AbstractElement abstractElement) {
        elementList.add(abstractElement);
    }

    public void accept(Visitor v) {
        for (AbstractElement ae: elementList) {
            ae.accept(v);
        }
    }
}
