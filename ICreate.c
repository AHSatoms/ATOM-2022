#include <kipr/botball.h>

int main()
{	
    create_connect();
    wait_for_light(2);
    shut_down_in(60);

	while (digital(0) == 0)
    {
    	if (analog(3) > 3850)
        {
    	create_drive_direct(100, 80);
    	}
    	else 
        {
    	create_drive_direct(80, 100);
    	}
    	
    }
    create_stop ();
    create_disconnect ();
	return 0;
	

monkey
