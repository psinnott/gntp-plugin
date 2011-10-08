#include <growl++.hpp>
#include <growl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


Growl::Growl(std::string  _application , std::string _icon , std::string _password)
{
	char *n[1] = { "web_alert" };

	application = strdup(_application.c_str());
	if( _password.compare("NULL") == 0 )
	{
		password = NULL;
	}
	else
	{
		password = strdup(_password.c_str());
	}

	const char *icon;
	if( _icon.compare("NULL") == 0 )
	{
		icon = NULL;
	}
	else
	{
		icon = _icon.c_str();
	}

	growl_tcp_register( "localhost" , application , (const char**)n , 1 , password , icon );
}


Growl::~Growl()
{
	if(application != NULL)
	{
		free(application);
	}
	if( password != NULL )
	{
		free(password);
	}
}


void Growl::Notify(std::string title, std::string message , std::string _icon )
{
	const char *icon;
	if( _icon.compare("NULL") == 0 )
	{
		icon = NULL;
	}
	else
	{
		icon = _icon.c_str();
	}

	growl_tcp_notify( "localhost" , application , "web_alert" , title.c_str() , message.c_str() , password , NULL , icon );
}
