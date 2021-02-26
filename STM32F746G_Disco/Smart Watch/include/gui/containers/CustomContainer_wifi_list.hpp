#ifndef CUSTOMCONTAINER_WIFI_LIST_HPP
#define CUSTOMCONTAINER_WIFI_LIST_HPP

#include <gui_generated/containers/CustomContainer_wifi_listBase.hpp>

class CustomContainer_wifi_list : public CustomContainer_wifi_listBase
{
public:
    CustomContainer_wifi_list();
    virtual ~CustomContainer_wifi_list() {}

    virtual void initialize();

    void Cancel_wifi_choice()override;
protected:
};

#endif // CUSTOMCONTAINER_WIFI_LIST_HPP
