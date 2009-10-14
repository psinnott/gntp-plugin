#include <WebGrowl.hpp>

WebGrowl::WebGrowl(int a)
{
	printf("WEBGROWL\n");
	char *n[2] = { "WebNotification" };
	growl = new Growl(GROWL_UDP,"localhost","password","WebGrowl",(const char **const)n,1);
}


void WebGrowl::Notify(std::string title, std::string message)
{
	printf("WEBNOTIFY\n");
	growl->Notify("WebNotification",title.c_str(),message.c_str());
}


WebGrowl::~WebGrowl()
{
	delete(growl);
}	
