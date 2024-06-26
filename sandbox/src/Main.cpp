#include <PeachPit.h>

class MyApp : public Peach::Application
{
public:
	MyApp()
		: Application()
	{
		LOG_INFO("MyApp started");
	}
};

int main()
{
	MyApp app = MyApp();

	app.Run();
}