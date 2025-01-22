import RPi.GPIO as GPIO
import time

# Define GPIO pins for BTS7960
RPWM_PIN = 18  # Right PWM pin for forward rotation
LPWM_PIN = 19  # Left PWM pin for reverse rotation

# Setup GPIO
GPIO.setmode(GPIO.BCM)  # Use Broadcom pin numbering
GPIO.setup(RPWM_PIN, GPIO.OUT)
GPIO.setup(LPWM_PIN, GPIO.OUT)

# Set up PWM on both pins
frequency = 1000  # PWM frequency in Hz
pwm_r = GPIO.PWM(RPWM_PIN, frequency)
pwm_l = GPIO.PWM(LPWM_PIN, frequency)

# Start PWM with 0% duty cycle (motor off)
pwm_r.start(0)
pwm_l.start(0)

def set_motor_speed(speed):
    """
    Set motor speed and direction.
    :param speed: Integer from -100 to 100
                  -100: Full speed backward
                   0: Stop
                  100: Full speed forward
    """
    if speed > 0:  # Forward
        pwm_r.ChangeDutyCycle(speed)  # Set RPWM to speed%
        pwm_l.ChangeDutyCycle(0)      # Set LPWM to 0%
    elif speed < 0:  # Backward
        pwm_r.ChangeDutyCycle(0)      # Set RPWM to 0%
        pwm_l.ChangeDutyCycle(-speed) # Set LPWM to abs(speed)%
    else:  # Stop
        pwm_r.ChangeDutyCycle(0)
        pwm_l.ChangeDutyCycle(0)

try:
    print("Motor running...")
    
    # Example: Ramp up forward
    for speed in range(0, 101, 10):  # Speed from 0 to 100
        set_motor_speed(speed)
        time.sleep(0.5)

    # Example: Ramp down forward
    for speed in range(100, -1, -10):  # Speed from 100 to 0
        set_motor_speed(speed)
        time.sleep(0.5)

    # Example: Ramp up backward
    for speed in range(0, -101, -10):  # Speed from 0 to -100
        set_motor_speed(speed)
        time.sleep(0.5)

    # Example: Ramp down backward
    for speed in range(-100, 1, 10):  # Speed from -100 to 0
        set_motor_speed(speed)
        time.sleep(0.5)

finally:
    print("Stopping motor...")
    set_motor_speed(0)  # Stop motor
    pwm_r.stop()
    pwm_l.stop()
    GPIO.cleanup()
