#include <string>
#include <stdio.h>

class Growl 
{
	private:
		char *application;
	public:
		Growl(std::string _application);
		~Growl();
		void Notify(std::string title, std::string message);

};


