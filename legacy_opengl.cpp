#include <glfw3.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

// Uses Legacy OpenGL and GLFW to display random triangles


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "Mesmerizing Triangles!", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// Loops continuously until the screen is closed manually
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);	// Clears the screen


		float v1x, v1y;	// One of three vertices for triangle
		float v2x, v2y;
		float v3x, v3y;
		float r, g, b;	// Color of triangle; values 0.0 through 1.0

		srand(time(NULL));	// Seeding random variable with system time

		// Will generate i amount of triangles on the screen per screen refresh
		for (int i = 0; i < 10; i++)
		{
			// Random vertices from -1.0 to 1.0
			v1x = 2.0 * (static_cast <float> (rand() / static_cast <float> (RAND_MAX))) - 1.0;
			v1y = 2.0 * (static_cast <float> (rand() / static_cast <float> (RAND_MAX))) - 1.0;

			v2x = 2.0 * (static_cast <float> (rand() / static_cast <float> (RAND_MAX))) - 1.0;
			v2y = 2.0 * (static_cast <float> (rand() / static_cast <float> (RAND_MAX))) - 1.0;

			v3x = 2.0 * (static_cast <float> (rand() / static_cast <float> (RAND_MAX))) - 1.0;
			v3y = 2.0 * (static_cast <float> (rand() / static_cast <float> (RAND_MAX))) - 1.0;

			// Random RGB color values from 0.0 to 1.0
			r = static_cast <float> (rand() / static_cast <float> (RAND_MAX));
			g = static_cast <float> (rand() / static_cast <float> (RAND_MAX));
			b = static_cast <float> (rand() / static_cast <float> (RAND_MAX));

			// Draw a single triangle
			glColor3f(r, g, b);
			glBegin(GL_TRIANGLES);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}