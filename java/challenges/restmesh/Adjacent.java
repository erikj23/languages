
package restmesh;

import java.util.List;
import java.util.ArrayList;

class Adjacent
{
    static List<Integer> solution(List<String> list, int length)
    {
        ArrayList<Integer> minimum_edits = new ArrayList<Integer>(length);
        for(int i = 0; i < length; ++i) minimum_edits.add(0);

        for(int i = 0; i < length; ++i)
        {   
            int adjacent = 1;
            char[] characters = list.get(i).toCharArray(); 
            for(int j = 0; j < characters.length-1; ++j)
            {
                if(characters[j] == characters[j+1])
                {
                    adjacent++;   
                }
                else
                {
                    int new_value = minimum_edits.get(i)+adjacent/2;
                    minimum_edits.remove(i);
                    minimum_edits.add(i, new_value);
                    adjacent = 1;
                }
            }
            if(adjacent > 1)
            {   
                int new_value = minimum_edits.get(i)+adjacent/2;
                minimum_edits.remove(i);
                minimum_edits.add(i, new_value);
            }
        }
        return minimum_edits;
    }

    public static void main(String[] args)
    {
        List<String> list = new ArrayList<String>();
        list.add("ab");
        list.add("aab");
        list.add("abb");
        list.add("abab");
        list.add("abaaaba");
        List<Integer> return_value = Adjacent.solution(list, list.size());
        for(Integer value:return_value) System.out.println(value);
    }
}
