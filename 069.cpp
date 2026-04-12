// Q: WA C++ program to returns day based on the numeric value.

#include<iostream>
using namespace std;

class Day
{
    private:
        int day;
        
    public:
        void set_data()
        {
            cout<<"Enter no of day you want to display: ";
            cin>>day;
        }
        
        void display_day()
        {
            switch (day) 
            {
                case 1:
                    cout<<"MONDAY";
                    break;

                case 2:
                    cout<<"TUESDAY"; 
                    break;
            
                case 3:
                    cout<<"WEDNESDAY"; 
                    break;

                case 4:
                    cout<<"THURSDAY"; 
                    break;
    
                case 5:
                    cout<<"FRIDAY"; 
                    break;

                case 6:
                    cout<<"SATURDAY";
                    break;

                case 7:
                    cout<<"SUNDAY";
                    break;
                
                default:
                    cout<<"INVALID INPUT";
                    break;
            }
        }
};

main()
{
    Day d1;
    
    d1.set_data();
    d1.display_day();
    
    return 0;
}
