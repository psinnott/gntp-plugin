#include <string>
#include <stdio.h>

class Growl 
{
	private:
		char *application;
		char *password;
	public:
		Growl(std::string  _application , std::string _icon , std::string _password);
		~Growl();
		void Notify(std::string title, std::string message , std::string icon );

};


