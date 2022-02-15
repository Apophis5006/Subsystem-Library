
class Joystick {
protected:
    frc::Joystick joystick;

    enum inputs {X,Y,Z,Button,Twist,Throttle,Channel};

public:
    Joystick(int port = 0) : joystick(port) {}

    double Get(inputs input, int button = 0){
       //find actual values of buttons later
       switch(input) {
           case inputs::X: return joystick.GetX(); break;
           case inputs::Y: return joystick.GetY(); break;
           case inputs::Z: return joystick.GetZ(); break;
           case inputs::Twist: return joystick.GetTwist();
           case inputs::Button: return joystick.GetRawButton(button); break;
           default: return -1; break;
       }
    }

    //@returns returns an array (double[2]) containing the x and y values
    double* GetPosition() {
        double position[2] = {this->joystick.GetX(),this->joystick.GetY()};
        return position;
    }

    double GetChannel(inputs Channel){
        switch(Channel) {
            case inputs::X: return joystick.GetXChannel(); break;
            case inputs::Y: return joystick.GetYChannel(); break;
            case inputs::Z: return joystick.GetZChannel(); break;
            case inputs::Throttle: return joystick.GetThrottleChannel(); break;
            case inputs::Twist: return joystick.GetTwistChannel(); break;
            default: return -1.0; break;
        }
    }
};