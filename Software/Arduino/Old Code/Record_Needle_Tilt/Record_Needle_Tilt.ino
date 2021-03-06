/* Record Needle Tilt
 *  One Servo with function that tilts from horizontal to vertical
 *  by Sophia Nielsen
 *  modified 6 Nov 2017
 */

#include <Servo.h>

Servo needle_tilt_servo; // creates servo object

int pos = 0; // position, for servo sweep iterator
float servo_step = 1; // step size for servo sweep
const int min_pos = 20;
const int max_pos = 110;
unsigned int servo_delay = 20;
unsigned int prev_millis = 0;
unsigned int cur_millis = millis();

void setup() {
  needle_tilt_servo.attach(6); // attaches servo to pin 5
}

void loop() {
    new_song_tilt(needle_tilt_servo, servo_delay);

//  new_song_tilt(needle_tilt_servo, servo_delay);
  delay(500);
  
}

void new_song_tilt(Servo needle_tilt_servo, unsigned int servo_delay) {
  tilt_up(needle_tilt_servo, servo_delay, min_pos, max_pos);
  tilt_down(needle_tilt_servo, 100, min_pos, max_pos);
}

void tilt_up(Servo needle_tilt_servo, unsigned int servo_delay, const int min_pos, const int max_pos) {
  unsigned int prev_millis = 0;
  boolean servo_step_move_done = false;
  boolean running_correctly = true;
  boolean needle_move_up_done = false;
  int pos = min_pos;
  while(!needle_move_up_done){
    unsigned int cur_millis = millis(); 
    // if it has, check that the delay has passed
    if (cur_millis - prev_millis >= servo_delay) {
      // update prev_millis
      prev_millis += servo_delay;
      if (++pos > max_pos) {
        needle_move_up_done = true;
      }
      else {
        needle_tilt_servo.write(pos);
        servo_step_move_done = true;
        pos ++;
      }
    }
}
}

void tilt_down(Servo needle_tilt_servo, unsigned int servo_delay, const int min_pos, const int max_pos) {
  unsigned int prev_millis = 0;
  boolean servo_step_move_done = false;
  boolean needle_move_down_done = false;
  int pos = max_pos;
  while(!needle_move_down_done){
    unsigned int cur_millis = millis();
    // if it has, check that the delay has passed
    if (cur_millis - prev_millis >= servo_delay) {
      // update prev_millis
      prev_millis += servo_delay;
      if (--pos < min_pos) {
        needle_move_down_done = true;
      }
      else {
        needle_tilt_servo.write(pos);
        servo_step_move_done = true;
        pos --;
      }
    }
}
}
