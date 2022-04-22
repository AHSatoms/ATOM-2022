#include <kipr/wombat.h>

int RW=1;
int LW=0;
int ARM = 0;
int CLAW = 1;
int timer = 0;

void drive_forward(int ticks);
void hard_right();
void hard_left();

int main() {

    while(digital(0) == 0 ){
        cmpc(RW);
        cmpc(LW);

        enable_servos();
        set_servo_position(ARM,0);
        set_servo_position(CLAW,860);
        hard_right();

        if(timer == 0){
            hard_right();
        }

        if(timer == 1){
            drive_forward(10573);
        }

        if(timer == 2){
            hard_left();
        }

        if(timer == 3){
            drive_forward(5500);
        }

        if(timer == 4){
            set_servo_position(ARM,0);
            set_servo_position(CLAW,860);
        }

    }
    return 0;
}

void drive_forward(int ticks){
    cmpc(RW);
    cmpc(LW);
    while(gmpc(RW) < ticks && gmpc(LW) < ticks){
        motor(RW,100);
        motor(LW,100);
        
        if(gmpc(RW) < ticks && gmpc(LW) < ticks){
        	timer=timer+1;
        	ao();
        	break;
        }
    }
}

void hard_right(){
    cmpc(RW);
    cmpc(LW);

    while(gmpc(RW) < 4712 || gmpc(LW) < 2356){
        motor(RW,-66.66);
        motor(LW,33.33);
        
        if(gmpc(RW) < 4712 || gmpc(LW) < 2356){
        	timer=timer+1;
        	ao(); // Stop the motors
        	break;
        }
    }
        
}

void hard_left(){
    cmpc(RW);
    cmpc(LW);

    while(gmpc(LW) < 4712 || gmpc(RW) < 2356){
        motor(RW,33.33);
        motor(LW,-66.66);
        
        if(gmpc(LW) < 4712 || gmpc(RW) < 2356){
            timer=timer+1;
            ao(); // Stop the motors
            break;
        }
    }
}