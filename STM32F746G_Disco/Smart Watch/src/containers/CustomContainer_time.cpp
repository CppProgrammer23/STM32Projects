#include <gui/containers/CustomContainer_time.hpp>

CustomContainer_time::CustomContainer_time()
{

}

void CustomContainer_time::initialize()
{
    CustomContainer_timeBase::initialize();
}
void CustomContainer_time::Cancel_Update_Time()
{
    Container::setVisible(false);
    Container::invalidate();
}
void CustomContainer_time::TimeToContainer(int hours, int minutes)
{
    Unicode::snprintf(textArea1Buffer1, TEXTAREA1BUFFER1_SIZE, "%d", hours);
    Unicode::snprintf(textArea1Buffer2, TEXTAREA1BUFFER2_SIZE, "%d", minutes);
    textArea1.invalidate();
}
void CustomContainer_time::Button_delete_Clicked()
{
    if (textArea1Buffer2[ncs] != '\0')
    {
        textArea1Buffer2[ncs] = '\0';
        textArea1.invalidate();
        ncs--;
    }
    else if (textArea1Buffer2[0] == '\0' && textArea1Buffer2[1] == '\0')
    {
        if (textArea1Buffer1[ncm] != '\0')
        {
            textArea1Buffer1[ncm] = '\0';
            textArea1.invalidate();
        }
        ncm--;
    }
    if (ncs == -1)
        ncs = 1;
    if (textArea1Buffer2[0] == '\0' && textArea1Buffer2[1] == '\0' && textArea1Buffer1[0] == '\0' && textArea1Buffer1[1] == '\0')
    {
        ncs = 1; ncm = 1;
    }
        
}

void CustomContainer_time::handleTickEvent()
{
    if (CustomContainer_time::isVisible() == 0)
    {
        ncs = 1; ncm = 1;
        //&CustomContainer_time::TimeToContainer;
    }
}
