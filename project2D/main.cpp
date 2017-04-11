#include "Application2D.h" //vector particles
#include "MatrixGame.h"
#include "PhysicsGame.h"
int main() {
	

	//auto app = new Application2D();
	//auto app = new MatrixGame();
	auto app = new PhysicsGame();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}