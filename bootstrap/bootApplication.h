#pragma once
struct GLFWwindow; //window object
class bootApplication
{
public:
	bootApplication(); // constructor for class
	virtual ~bootApplication(); // destructor for class

	void run(const char* title, unsigned int width, unsigned int height, bool fullscreen); //function for running application
	virtual void startup() = 0;
	virtual void shutdown() = 0;
	virtual void update(float) = 0;
	virtual void draw() = 0;


protected:
	GLFWwindow* m_window; // to refer to the window
	bool m_check; // check for loop statement.

};

