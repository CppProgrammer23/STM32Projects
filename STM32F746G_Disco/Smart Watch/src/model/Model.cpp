#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>



Model::Model() : modelListener(0),tic(0),hours(2),minutes(21),seconds(55), wifi_activ(0),Air_Cond(false),lamp(false)
{

}
// Get System time // to activate the "warning treated as an error: proprieties > C/C++ > Treated warning as error (set it to no)
//don't forget to include ctime and cstdlib
/*
char hour[2], mini[2], seco[2];
time_t mytime = time(0);
char* t = std::ctime(&mytime);
for (int i = 11; i <= 12; i++)
{
	hour[i - 11] = t[i];
}
for (int j = 14; j <= 15; j++)
{
	mini[j - 14] = t[j];
}
for (int o = 17; o <= 18; o++)
{
	seco[o - 17] = t[o];
}
hours = atoi(hour);
minutes = atoi(mini);
seconds = atoi(seco);
*/
void Model::tick()
{
	static int alpha=250, add;
	tic++;
	if (tic > 59)
	{
		tic = 0;
		seconds++;
		if (seconds > 59)
		{
			seconds = 0;
			minutes++;
			if (minutes > 59)
			{
				minutes = 0;
				hours++;
				if (hours > 23)
					hours = 0;
			}
		}
	}
	if (alpha >= 250)
		add = -3;
	else if (alpha <= 40)
		add = 3;
	alpha += add;
	modelListener->SendAlphaToSleepScreen(alpha);
	modelListener->SendTimeToPres(hours, minutes, seconds);
	modelListener->SendInfoWifiToPresenter(wifi_activ);
}

void Model::SendInfoWifiModelScreenSettings(int activate_wifi)
{
	wifi_activ = activate_wifi;
}
void Model::SendAirConditionerValueToModel(bool air_cond)
{
	Air_Cond = air_cond;
}
void Model::SendLampeValueToModel(bool lampe)
{
	lamp = lampe;
}