import java.lang.reflect.Array;
import java.util.ArrayList;

/**
 * DayofYearSet
 */
public class DayofYearSet {

    
    /** */
    public static class DayofYear {
        
        private int day;
        private int month;

        public DayofYear() {
            this.day = 1;
            this.month = 1;       
        }

        public DayofYear(int day, int month) {
            this.day = day;
            this.month = month;
        }

        /**
         * Get day
         * @return day
         */
        public int getDay() {
            return day;
        }

        public int getMonth() {
            return month;
        }

        public void setDay(int day) {
            this.day = day;
        }

        public void setMonth(int month) {
            this.month = month;
        }

        @Override
        public String toString() {
            String rString = "";
            rString += "Day:" + day + " Month:" + month;

            return rString;

        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof DayofYear) {
                DayofYear other = (DayofYear) obj;

                if (this.day == other.day && this.month == other.month)
                    return true;
            }
            return false;
        }
  
    }

    // data fields
    private DayofYear[] days;
    private int size;    
    private int capacity;

    public DayofYearSet() {
        this.capacity = 10;
        this.days = new DayofYear[capacity];
        this.size = 0;
    }

    public DayofYearSet(ArrayList<DayofYear> obj) {
        this.size = obj.size();
        this.capacity = size + 10;
        this.days = new DayofYear[capacity];
        for(int i = 0; i < obj.size(); ++i)
        {
            this.days[i] = obj.get(i);
        }
    }
    
    public DayofYear[] getDays()
    {
        return this.days;
    }

    public int size()
    {
        return this.size;
    }

    public int getCapacity()
    {
        return this.capacity;
    }

    public DayofYear get(int index) {

        if(index < 0 && index >= this.size)
        {
            System.out.println("Exceed the boundry of size");
            return null;
        }   
        else
        {
            return days[index];
        }  
    }

    

    @Override
    public String toString() {
        String rString = "";
        for(int i = 0; i < size; ++i)
        {
            rString += days[i].toString() + "\n";
            if(i == size - 1)
            {
                rString += days[i].toString();
            }

        }

        return rString;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof DayofYearSet)
        {
            DayofYearSet other = (DayofYearSet) obj;
            for(int i = 0; i < size; ++i)
            {
                if(days[i].equals(other.get(i)) != true)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    
    //helper function 
    private int contain(DayofYear day) {
        for(int i = 0; i < size; ++i)
        {
            if(this.days[i].equals(day))
                return i;
        }
        return -1;
    }

    public void add(DayofYear day) {
        if(contain(day) != -1)
            return;
        this.days[size] = day;
        size++;
        if(size == capacity)
        {
            capacity *= 2;
            DayofYear[] day2 = new DayofYear[capacity];
            for(int i = 0; i < size; ++i)
            {
                day2[i] = days[i];
            }
            days = day2;
        }
    }

    public void remove(DayofYear day) {
        int index = contain(day);
        if(index != -1)
        {
            for(int i = index; i < size; ++i)
            {
                days[i] = days[i + 1]; 
            }
            size--;
        }
    }

    public DayofYearSet setUnion(DayofYearSet other_days) {
        DayofYearSet union = new DayofYearSet();
        int size = this.size();
        for(int i = 0; i < size; ++i)
        {
            union.add(this.days[i]);
        }
        for(int i = 0; i < other_days.size(); ++i)
        {
            union.add(other_days.get(i));
        }

        return union;

    }

    public void setIntersection(DayofYear days) {

    }


    
    
    
    
    
    public static void main(String[] args) {
        DayofYear obj = new DayofYear(23,1);
        ArrayList<DayofYearSet.DayofYear> days = new ArrayList<>(); 
        days.add(obj);
        days.add(new DayofYear(19,12));
        days.add(new DayofYear(14,12));

        DayofYearSet set = new DayofYearSet(days);
        DayofYearSet set2 = new DayofYearSet(days);
       

        set.add(new DayofYear(20,8));
        set.add(new DayofYear(24,5));
        set.add(new DayofYear(25,7));
        set.add(new DayofYear(26,8));
        System.out.println(set);
        System.out.println("size:"+set.size());

        set2.add(new DayofYear(19,8));
        set2.add(new DayofYear(10,5));
        System.out.println(set2);
        System.out.println("size:"+set2.size());

        DayofYearSet uni = set.setUnion(set2);
        System.out.println(uni);
        System.out.println("size:"+uni.size());
      
    }
}