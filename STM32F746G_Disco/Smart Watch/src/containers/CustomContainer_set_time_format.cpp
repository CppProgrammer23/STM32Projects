#include <gui/containers/CustomContainer_set_time_format.hpp>

CustomContainer_set_time_format::CustomContainer_set_time_format()
{

}

void CustomContainer_set_time_format::initialize()
{
    CustomContainer_set_time_formatBase::initialize();
}
void CustomContainer_set_time_format::Cancel_Format()
{
    Container::setVisible(false);
    Container::invalidate();
}
