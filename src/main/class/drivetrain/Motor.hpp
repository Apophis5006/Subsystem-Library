
/*
An abstraction layer for interfacing with the TalonFX motor controller
*/
class Motor : public BaseMotor {
protected:
    TalonFX motorController;

    bool enabled = true;

public:
    //Constructors
    /*
    Constructs a Motor object

    @param motorId the port id of the connected talon
    @param originPercentOutput the base PercentOutput the motor defaults to
    @param setPercentOutput the targeted PercentOutput the motor attempts to maintain (offset from originPercentOutput)

    @returns Motor
    */
    Motor(int motorId = 0, double originPercentOutput = 0, double setPercentOutput = 0) : motorController(motorId) {
        baseOutput = originPercentOutput;
        targetOutput = setPercentOutput;
    }

    //Methods
    //Updates the motor controller to maintain current target value
    void Update() {
        this->motorController.Set(TalonFXControlMode::PercentOutput, this->GetAbsoluteTargetOutput());
    }

    //Enables or disables the talon
    void SetEnabled(bool enabled = false) {
        if (enabled) {
            this->motorController.Set(TalonFXControlMode::PercentOutput, this->GetAbsoluteTargetOutput());
        } else {
            this->motorController.Set(TalonFXControlMode::Disabled, 0);
        }
        this->enabled = enabled;
    }

    /*
    Calculates the rotations per minute of the talon

    @returns Talon RPM
    */
    double GetRPM() {
        return this->motorController.GetSelectedSensorVelocity() * 600 / 4096;
    }
};