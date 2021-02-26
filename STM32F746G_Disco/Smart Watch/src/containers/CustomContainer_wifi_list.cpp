#include <gui/containers/CustomContainer_wifi_list.hpp>

CustomContainer_wifi_list::CustomContainer_wifi_list()
{

}

void CustomContainer_wifi_list::initialize()
{
    CustomContainer_wifi_listBase::initialize();
}
void CustomContainer_wifi_list::Cancel_wifi_choice()
{
    Container::setVisible(false);
    Container::invalidate();
}
