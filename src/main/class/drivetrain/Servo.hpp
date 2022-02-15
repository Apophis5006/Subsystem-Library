
/*
An abstraction layer for interfacing with the TalonSRX motor controller
*/
class Servo : public BaseMotor {
protected:
    TalonSRX motorController;

public:
    //Constructors
    /*
    Constructs a Motor object

    @param motorId the port id of the connected talon
    @param originPosition the base output the motor defaults to
    @param position the targeted position the motor attempts to maintain (offset from originPosition)

    @returns Servo
    */
    Servo(int motorId = 1, double originPosition = 0, double position = 0) : motorController(motorId) {
        baseOutput = originPosition;
        targetOutput = position;
    }

    //Updates the motor controller to maintain current target value
    void Update() {
        this->motorController.Set(TalonSRXControlMode::Position, this->GetAbsoluteTargetOutput());
    }
    
    //Enables or disables the talon
    void SetEnabled(bool enabled = false) {
        if (enabled) {
            this->motorController.Set(TalonSRXControlMode::Position, this->GetAbsoluteTargetOutput());
        } else {
            this->motorController.Set(TalonSRXControlMode::Disabled, 0);
        }
        this->enabled = enabled;
    }
};