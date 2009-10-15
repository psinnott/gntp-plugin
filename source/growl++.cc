#include <growl++.hpp>
#include <growl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


Growl::Growl(std::string  _application)
{
	char *n[1] = { "web_alert" };

	application = strdup(_application.c_str());
	growl_udp_register( "localhost" , application , (const char**)n , 1 , "password" );
}


Growl::~Growl()
{
	if(application == NULL)
	{
		free(application);
	}
}


void Growl::Notify(std::string title, std::string message)
{
	growl_udp_notify( "localhost" , application , "web_alert" , title.c_str() , message.c_str() , "password" );
}
