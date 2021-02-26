#include <gui/containers/CustomContainer_Option_game.hpp>
#include <gui/screen_game_screen/Screen_gameView.hpp>
#include <gui/screen_tic_tao_screen/Screen_TIC_TAOView.hpp>

CustomContainer_Option_game::CustomContainer_Option_game()
{
    if (Dra == 2)
    {
        if (flexButton_26I.getPressed() == true)
        {
            flexButton_26I.setPressed(false);
            flexButton_26I.invalidate();
        }
        flexButton_Dra.setPressed(true);
    }
    else if (Dra == 1)
    {
        if (flexButton_Dra.getPressed() == true)
        {
            flexButton_Dra.setPressed(false);
            flexButton_Dra.invalidate();
        }
        flexButton_26I.setPressed(true);
    }
    if (col == 1)
    {
        if (flexButton_Color.getPressed() == true)
        {
            flexButton_Color.setPressed(false);
            flexButton_Color.invalidate();
        }
        flexButton_X_O.setPressed(true);
    }
    else
    {
        if (flexButton_X_O.getPressed() == true)
        {
            flexButton_X_O.setPressed(false);
            flexButton_X_O.invalidate();
        }
        flexButton_Color.setPressed(true);
    }
}
int CustomContainer_Option_game::col;
void CustomContainer_Option_game::initialize()
{
    CustomContainer_Option_gameBase::initialize();
}

void CustomContainer_Option_game::Save_Option_Game()
{
    std::shared_ptr <Screen_gameView> g(new Screen_gameView);
    Container::setVisible(false);
    Container::invalidate();
    g->SendValuesToGameView(true);
}
int CustomContainer_Option_game::Dra;
void CustomContainer_Option_game::Apply_Dra_Name()
{
    Dra = 2;
    Screen_TIC_TAOView Tic;
    Tic.SetDraName("Dra");
    if (flexButton_26I.getPressed() == true)
    {
        flexButton_26I.setPressed(false);
        flexButton_26I.invalidate();
    }
    flexButton_Dra.setPressed(true);
}

void CustomContainer_Option_game::Apply_26I_Name()
{
    Dra = 1;
    Screen_TIC_TAOView Tic;
    Tic.Send26IName("26_I");
    if (flexButton_Dra.getPressed() == true)
    {
        flexButton_Dra.setPressed(false);
        flexButton_Dra.invalidate();
    }
    flexButton_26I.setPressed(true);
    //flexButton_26I.invalidate();
}
void CustomContainer_Option_game::Apply_Colored_Version()
{
    col = 1;
    Screen_TIC_TAOView Tic;
    Tic.SetXO_Ver(true);
    if (flexButton_X_O.getPressed() == true)
    {
        flexButton_X_O.setPressed(false);
        flexButton_X_O.invalidate();
    }
    flexButton_Color.setPressed(true);
}
void CustomContainer_Option_game::Apply_XO_Version()
{
    col = 0;
    Screen_TIC_TAOView Tic;
    Tic.SetColored_Ver(false);
    if (flexButton_Color.getPressed() == true)
    {
        flexButton_Color.setPressed(false);
        flexButton_Color.invalidate();
    }
    flexButton_X_O.setPressed(true);
}