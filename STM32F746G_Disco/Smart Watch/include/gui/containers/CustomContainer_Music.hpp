#ifndef CUSTOMCONTAINER_MUSIC_HPP
#define CUSTOMCONTAINER_MUSIC_HPP

#include <gui_generated/containers/CustomContainer_MusicBase.hpp>


class CustomContainer_Music : public CustomContainer_MusicBase
{
public:
    CustomContainer_Music();
    virtual ~CustomContainer_Music() {}

    virtual void initialize();

    void Return_To_Music_Screen()override;

protected:
};

#endif // CUSTOMCONTAINER_MUSIC_HPP
