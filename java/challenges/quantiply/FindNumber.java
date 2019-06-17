
package quantiply;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class FindNumber
{

    FindNumber(List<Integer> list, int target)
    {
        Collections.sort(list);
        Collections.binarySearch(list, target, null);
        
    }
    public static void main(String[] arguments)
    {
        new FindNumber(new ArrayList<Integer>(), 0);
    }
}
