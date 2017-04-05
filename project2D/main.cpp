#include "Application2D.h" //vector particles
#include "MatrixGame.h"
int main() {
	

	//auto app = new Application2D();
	auto app = new MatrixGame();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}