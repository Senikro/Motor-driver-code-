import RPi.GPIO as GPIO
import time

# Define GPIO pins for BTS7960
RPWM_PIN = 32  # Right PWM pin for forward rotation
LPWM_PIN = 33 # Left PWM pin for reverse rotation

# Setup GPIO
GPIO.setmode(GPIO.BOARD)  # Use Broadcom pin numbering
GPIO.setup(RPWM_PIN, GPIO.OUT)
GPIO.setup(LPWM_PIN, GPIO.OUT)
# Set up PWM on both pins
frequency = 1000  # PWM frequency in Hz
pwm_r = GPIO.PWM(RPWM_PIN, frequency)
pwm_l = GPIO.PWM(LPWM_PIN, frequency)

# Start PWM with 0% duty cycle (motor off)
pwm_r.start(0)
pwm_l.start(0)
def set_motor_speed_Left(speed):
    left = set_motor_speed_Left
    """
    Set motor speed and direction.
    :param speed: Integer from 0 to 100
                   0: Stop
                  100: Full speed left
    """
    if speed > 0:  # Left
        pwm_r.ChangeDutyCycle(speed)  # Set RPWM to speed%
        pwm_l.ChangeDutyCycle(-speed)      # Set LPWM to 0%
    else:  # Stop
        pwm_r.ChangeDutyCycle(0)
        pwm_l.ChangeDutyCycle(0)
left = set_motor_speed_Left()
def set_motor_speed_Right(speed):
    Right = set_motor_speed_Right
    """
    Set motor speed and direction.
    :param speed: Integer from 0 to 100
                   0: Stop
                  100: Full speed Right
    """
    if speed > 0:  # Right
        pwm_r.ChangeDutyCycle(-speed)  # Set RPWM to speed%
        pwm_l.ChangeDutyCycle(speed)      # Set LPWM to 0%
    else:  # Stop
        pwm_r.ChangeDutyCycle(0)
        pwm_l.ChangeDutyCycle(0)
right = set_motor_speed_Right()
def set_motor_speed_Forward(speed):
    """
    Set motor speed and direction.
    :param speed: Integer from 0 to 100
                   0: Stop
                  100: Full speed left
    """
    if speed > 0:  # Forward
        pwm_r.ChangeDutyCycle(speed)  # Set RPWM to speed%
        pwm_l.ChangeDutyCycle(speed)      # Set LPWM to 0%
    else:  # Stop
        pwm_r.ChangeDutyCycle(0)
        pwm_l.ChangeDutyCycle(0)
forward = set_motor_speed_Forward()
        
def set_motor_speed_Backward(speed):
    back = set_motor_speed_Backward
    """
    Set motor speed and direction.
    :param speed: Integer from 0 to 100
                   0: Stop
                  100: Full speed left
    """
    if speed > 0:  # Backward
        pwm_r.ChangeDutyCycle(-speed)  # Set RPWM to speed%
        pwm_l.ChangeDutyCycle(-speed)      # Set LPWM to 0%
    else:  # Stop
        pwm_r.ChangeDutyCycle(0)
        pwm_l.ChangeDutyCycle(0)
Back = set_motor_speed_Backward()
try:
    print("Motor running...")
    
    for sp in range(0, 101, 30):#Right
        set_motor_speed_Left(sp)
        set_motor_speed_Right(-sp)

        time.sleep(1)
    for sp in range(0, 101, 30):#Left
        set_motor_speed_Left(-sp)
        set_motor_speed_Right(sp)

        time.sleep(1)
    for sp in range(0, 101, 30):#Forward
        set_motor_speed_Left(sp)
        set_motor_speed_Right(sp)
        time.sleep(1)
    for sp in range(0, 101, 30):#Backward
        set_motor_speed_Left(-sp)
        set_motor_speed_Right(-sp)
        time.sleep(1)

finally:
    print("Stopping motor...")
    set_motor_speed_Left(0)  
    set_motor_speed_Right(0)  
    set_motor_speed_Backward(0)
    set_motor_speed_Forward(0)
    pwm_r.stop()
    pwm_l.stop()
    GPIO.cleanup()
