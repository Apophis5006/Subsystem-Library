
/*
An abstract class for interfacing with Phoenix motor controllers
*/
class BaseMotor {
protected:
    //Variables
    bool enabled = false; //whether or not the motor is enabled

    double baseOutput = 0; //the base output the motor defaults to
    double targetOutput = 0; //the target output the motor attempts to maintain (offset from baseOutput)

public:
    //Methods
    //Updates the motor controller to maintain current target value
    virtual void Update() = 0;

    /*
    Sets the target output

    @param output the targeted output the motor attempts to maintain (offset from originOutput)
    */
    void Set(double output = 0) {
        this->targetOutput = output;
    }
    /*
    Sets the target output and the origin output

    @param the targeted output the motor attempts to maintain (offset from originOutput)
    @param originOutput the base output the motor defaults to
    */
    void Set(double output, double originOutput) {
        this->targetOutput = output;
        this->baseOutput = originOutput;
    }

    //@returns boolean value indicating if the motor is enabled
    bool IsEnabled() {
        return this->enabled;
    }
    //Enables or disables the talon
    virtual void SetEnabled(bool enabled = false) = 0;

    /*
    Calculates the absolute target output

    @returns absolute value of target output
    */
    double GetAbsoluteTargetOutput() {
        return (this->targetOutput)+(this->baseOutput);
    }
};
