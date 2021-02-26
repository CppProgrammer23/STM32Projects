#ifndef CUSTOMCONTAINER_TIME_HPP
#define CUSTOMCONTAINER_TIME_HPP

#include <gui_generated/containers/CustomContainer_timeBase.hpp>

class CustomContainer_time : public CustomContainer_timeBase
{
public:
    CustomContainer_time();
    virtual ~CustomContainer_time() {}

    virtual void initialize();

    void Cancel_Update_Time()override;

    void TimeToContainer(int hours,int minutes);

    void Button_delete_Clicked()override;

    void handleTickEvent()override;
protected:
    int ncs = 1, ncm = 1;
};

#endif // CUSTOMCONTAINER_TIME_HPP
