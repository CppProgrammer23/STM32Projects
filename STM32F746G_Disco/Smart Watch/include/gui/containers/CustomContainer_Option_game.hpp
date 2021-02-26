#ifndef CUSTOMCONTAINER_OPTION_GAME_HPP
#define CUSTOMCONTAINER_OPTION_GAME_HPP

#include <gui_generated/containers/CustomContainer_Option_gameBase.hpp>
#include <memory>

class CustomContainer_Option_game : public CustomContainer_Option_gameBase
{
public:
    CustomContainer_Option_game();
    virtual ~CustomContainer_Option_game() {}

    virtual void initialize();
    void Save_Option_Game()override;
    void Apply_Dra_Name()override;
    void Apply_26I_Name()override;
    void Apply_Colored_Version()override;
    void Apply_XO_Version()override;
protected:
    static int Dra;
    static int col;
};

#endif // CUSTOMCONTAINER_OPTION_GAME_HPP
