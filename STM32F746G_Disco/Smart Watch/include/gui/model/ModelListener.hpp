#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void SendTimeToPres(int hours, int minutes, int seconds) {}

    virtual void SendAlphaToSleepScreen(int alpha){}

    virtual void SendInfoWifiToPresenter(int wifi_activ){}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
