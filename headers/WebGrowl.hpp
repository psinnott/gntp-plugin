#ifndef WEBGROWL_H
#define WEBGROWL_H

#include <growl++.hpp>
#include <string>

class WebGrowl
{
	private:
	Growl *growl;

	public:
		WebGrowl(int a);
		void Notify( std::string title , std::string message );
		~WebGrowl();

};

#endif 
