#include <PeachPit/PeachPit.h>

#include "CoolLayer.h"

class MyApp : public Peach::Application
{
public:
	MyApp()
		: Application()
	{
		// Attach a CoolLayer
		std::shared_ptr<CoolLayer> layer = std::make_shared<CoolLayer>();
		PushLayer(layer);
	}
};

int main()
{
	MyApp app = MyApp();

	app.Run();
}