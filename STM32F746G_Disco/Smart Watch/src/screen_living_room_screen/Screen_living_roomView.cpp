#include <gui/screen_living_room_screen/Screen_living_roomView.hpp>
#include <touchgfx/Color.hpp>

Screen_living_roomView::Screen_living_roomView():air_cond(false),lampe(false)
{

}

void Screen_living_roomView::setupScreen()
{
    Screen_living_roomViewBase::setupScreen();
}

void Screen_living_roomView::tearDownScreen()
{
    Screen_living_roomViewBase::tearDownScreen();
}
void Screen_living_roomView::Air_Conditioner()
{
    if (air_cond == 0)
    {
        scalableImage4.setVisible(false);
        scalableImage4.invalidate();
        scalableImage3.setVisible(true);
        scalableImage3.invalidate();
        air_cond = 1;
    }
    else
    {
        scalableImage3.setVisible(false);
        scalableImage3.invalidate();
        scalableImage4.setVisible(true);
        scalableImage4.invalidate();
        air_cond = 0;
    }
    presenter->SendInfoAirConditioner(air_cond);
}
void Screen_living_roomView::Lampe()
{
    if (lampe == 0)
    {
        scalableImage1.setVisible(false);
        scalableImage1.invalidate();
        box_lampe.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
        box_lampe.invalidate();
        scalableImage2.setVisible(true);
        scalableImage2.invalidate();
        lampe = 1;
    }
    else
    {  
        scalableImage2.setVisible(false);
        scalableImage2.invalidate();
        box_lampe.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
        box_lampe.invalidate();
        scalableImage1.setVisible(true);
        scalableImage1.invalidate();
        lampe = 0;
    }
    presenter->SendInfoLampe(lampe);
}