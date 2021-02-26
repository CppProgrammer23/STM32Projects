#ifndef CUSTOMCONTAINER_SET_TIME_FORMAT_HPP
#define CUSTOMCONTAINER_SET_TIME_FORMAT_HPP

#include <gui_generated/containers/CustomContainer_set_time_formatBase.hpp>

class CustomContainer_set_time_format : public CustomContainer_set_time_formatBase
{
public:
    CustomContainer_set_time_format();
    virtual ~CustomContainer_set_time_format() {}

    virtual void initialize();

    void Cancel_Format()override;

protected:
};

#endif // CUSTOMCONTAINER_SET_TIME_FORMAT_HPP
