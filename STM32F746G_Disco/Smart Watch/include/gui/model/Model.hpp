#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void SendInfoWifiModelScreenSettings(int activate_wifi);

    void SendAirConditionerValueToModel(bool air_cond);

    void SendLampeValueToModel(bool lampe);
protected:
    ModelListener* modelListener;
    int tic, hours, minutes, seconds, wifi_activ;
    bool Air_Cond, lamp;
};

#endif // MODEL_HPP
