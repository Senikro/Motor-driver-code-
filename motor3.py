import RPi.GPIO as GPIO
import time
# Define GPIO pins for BTS7960
LPWM1_PIN = 16  # Left PWM pin for reverse rotation
RPWM1_PIN = 17
RPWM2_PIN = 18  # Right PWM pin for forward rotation
LPWM2_PIN = 19  # Left PWM pin for reverse rotation

# Setup GPIO
GPIO.setmode(GPIO.BCM)  # Use Broadcom pin numbering
GPIO.setup(RPWM1_PIN, GPIO.OUT)
GPIO.setup(LPWM1_PIN, GPIO.OUT)
GPIO.setup(LPWM2_PIN, GPIO.OUT)
GPIO.setup(RPWM2_PIN, GPIO.OUT)
# Set up PWM on both pins
frequency = 1000  # PWM frequency in Hz
pwm_r1 = GPIO.PWM(RPWM1_PIN, frequency)
pwm_l1 = GPIO.PWM(LPWM1_PIN, frequency)
pwm_r2 = GPIO.PWM(RPWM2_PIN, frequency)
pwm_l2 = GPIO.PWM(LPWM2_PIN, frequency)
# Start PWM with 0% duty cycle (motor off)
pwm_r1.start(0)
pwm_l1.start(0)
pwm_r2.start(0)
pwm_l2.start(0)
def set_motor_speed_Forward(speed):
    """
    Set motor speed .
    :param speed: Integer from 0 to 100
                   0: Stop
                  100: Full speed forward
    """
    if speed > 0:  # Forward
        pwm_r1.ChangeDutyCycle(speed)  
        pwm_l1.ChangeDutyCycle(speed)     
        pwm_r2.ChangeDutyCycle(speed)  
        pwm_l2.ChangeDutyCycle(speed)      
    else:  # Stop
         pwm_r1.ChangeDutyCycle(0)  
         pwm_l1.ChangeDutyCycle(0)     
         pwm_r2.ChangeDutyCycle(0)  
         pwm_l2.ChangeDutyCycle(0)      
def set_motor_speed_Backward(speed):
    """
    Set motor speed .
    :param speed: Integer from 0 to 100
                   0: Stop
                  100: Full speed backward
    """
    if speed > 0:  # Forward
        pwm_r1.ChangeDutyCycle(-speed)  
        pwm_l1.ChangeDutyCycle(-speed)     
        pwm_r2.ChangeDutyCycle(-speed)  
        pwm_l2.ChangeDutyCycle(-speed)      
    else:  # Stop
         pwm_r1.ChangeDutyCycle(0)  
         pwm_l1.ChangeDutyCycle(0)     
         pwm_r2.ChangeDutyCycle(0)  
         pwm_l2.ChangeDutyCycle(0)  
def set_motor_speed_Right(speed):
    """
    Set motor speed .
    :param speed: Integer from 0 to 100
                   0: Stop
                  100: Full speed right
    """
    if speed > 0:  # Forward
        pwm_r1.ChangeDutyCycle(-speed)  
        pwm_l1.ChangeDutyCycle(speed)     
        pwm_r2.ChangeDutyCycle(-speed)  
        pwm_l2.ChangeDutyCycle(speed)      
    else:  # Stop
         pwm_r1.ChangeDutyCycle(0)  
         pwm_l1.ChangeDutyCycle(0)     
         pwm_r2.ChangeDutyCycle(0)  
         pwm_l2.ChangeDutyCycle(0)  
def set_motor_speed_Left(speed):
    """
    Set motor speed .
    :param speed: Integer from 0 to 100
                   0: Stop
                  100: Full speed left
    """
    if speed > 0:  # Forward
        pwm_r1.ChangeDutyCycle(speed)  
        pwm_l1.ChangeDutyCycle(-speed)     
        pwm_r2.ChangeDutyCycle(speed)  
        pwm_l2.ChangeDutyCycle(-speed)      
    else:  # Stop
         pwm_r1.ChangeDutyCycle(0)  
         pwm_l1.ChangeDutyCycle(0)     
         pwm_r2.ChangeDutyCycle(0)  
         pwm_l2.ChangeDutyCycle(0)  
try:
    print("Motor running...")
    for forward in range(0, 100, 10):
        set_motor_speed_Forward(forward)
        time.sleep(0.5)
    for backward in range (0 , 100 , 10 ) :
         set_motor_speed_Backward(backward)
         time.sleep(0.5)
finally:
    print("Stopping motor...")
    set_motor_speed_Forward(0)  # Stop motor
    set_motor_speed_Backward(0)
    set_motor_speed_Right(0)
    set_motor_speed_Left(0)
    pwm_r1.stop()
    pwm_l1.stop()
    pwm_r2.stop()
    pwm_l2.stop()
    GPIO.cleanup()