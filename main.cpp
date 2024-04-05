#include <GL/glew.h>
#include <GLFW/glfw3.h>

int screen_width = 960, screen_height = 640;

static void drawPoint(GLfloat x, GLfloat y)
{
	GLfloat testPoint[] = { x, y };

	glEnableClientState(GL_VERTEX_ARRAY);
	glPointSize(20);
	glColor3f(1, 0, 0);
	glVertexPointer(2, GL_FLOAT, 0, testPoint);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableClientState(GL_VERTEX_ARRAY);

}

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(screen_width, screen_height, "Hello, GLFW!", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glViewport(0, 0, screen_width, screen_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, screen_width, 0, screen_height, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		drawPoint(screen_width / 2.0f, screen_height / 2.0f);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;

}





