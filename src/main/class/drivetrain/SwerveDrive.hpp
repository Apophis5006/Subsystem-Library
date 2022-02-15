#include <../class/drivetrain/BaseMotor.hpp>
#include <../class/drivetrain/Motor.hpp>
#include <../class/drivetrain/Servo.hpp>

/*
A controller class for robot swerve drive(s)
*/
class SwerveDrive {
private:
    double emptyState[2] = {0, 0};
    double* pointer = emptyState;

protected:
    //Variables
    double* baseState; //the state of the drive the motors default to
    double* targetState; //the state of the drive the motors are trying to acheive
    
    bool enabled = false; //whether or not the swerve unit is enabled
    
    Motor driveMotor; //the talon for driving the SwerveDrive
    Servo steerMotor; //the talon for steering the SwerveDrive

public:
    //Constructors
    /*
    Creates a SwerveDrive object from the steer motor id, the drive motor id, and the base rotation (steer)

    @param driveMotorId the port id of the talon controlling the SwerveDrive driving (speed)
    @param steerMotorId the port id of the talon controlling the SwerveDrive steering (direction)
    @param originState the base state the drive defaults to
    @param setState the target state the drive runs at relative to the originState
    */
    SwerveDrive(int driveMotorId = 0, int steerMotorId = 1, double originState[2] = {0}, double setState[2] = {0}) : driveMotor(driveMotorId),steerMotor(steerMotorId) {
        baseState = originState;
        targetState = setState;
    }

    //Methods
    /*
    Updates the swerve drive to maintain the current target state
    */
    void Update() {
        double* absoluteState = this->GetAbsoluteTargetState();
        this->driveMotor.Set(absoluteState[0]);
        this->steerMotor.Set(absoluteState[1]);
    }

    /*
    Sets the swerve drive rotation (in radians) and speed (in fps)

    @param state
        [1]: the rotation (in radians) to set the drive at
        - [2]: the speed (in fps) to set the drive at
    */
    void Set(double state[2] = {0}) {
        this->targetState = state;
        this->Update();
    }
    /*
    Sets the swerve drive rotation (in radians) and speed (in fps)

    @param setState
        [1]: the rotation (in radians) to set the drive at
        - [2]: the speed (in fps) to set the drive at
    @originState the base state the drive defaults to
    */
    void Set(double setState[2], double originState[2]) {
        this->targetState = setState;
        this->baseState = originState;
        this->Update();
    }

    /*
    Sets the swerve to enabled or disabled

    @param enabled sets the swerve to enabled if true
    */
    void SetEnabled(bool enabled = false) {
        this->driveMotor.SetEnabled(enabled);
        this->steerMotor.SetEnabled(enabled);
    }
    //@returns boolean value indicating if the drive is enabled
    bool IsEnabled() {
        return this->enabled;
    }

    /*
    Returns the absolute state of the swerve drive (originState + setState)

    @return the absolute rotation (in radians) and speed (in fps) of the swerve drive target state
    */
    double* GetAbsoluteTargetState() {
        double absoluteState[2] = {(this->baseState[0]+this->targetState[0]), (this->baseState[1]+this->targetState[1])};
        
        double* pointer = absoluteState;
        return pointer;
    }
};