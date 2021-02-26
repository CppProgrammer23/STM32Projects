#include <gui/containers/CustomContainer_Music.hpp>

CustomContainer_Music::CustomContainer_Music()
{

}

void CustomContainer_Music::initialize()
{
    CustomContainer_MusicBase::initialize();
}

void CustomContainer_Music::Return_To_Music_Screen()
{
    Container::setVisible(false);
    Container::invalidate();
}
