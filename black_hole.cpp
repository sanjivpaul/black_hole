#define GLEW_STATIC
#define GLEW_NO_GLU
#define GL_SILENCE_DEPRECATION

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <chrono>
#include <fstream>
#include <sstream>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
using namespace glm;
using namespace std;
using Clock = std::chrono::high_resolution_clock;

struct BlackHole {
    vec2 position;
    double mass;
    double radius;
    double r_s;

    BlackHole(vec3 pos, float m) : position(pos), mass(m) {r_s = 2.0 * G * mass / (c*c);}

    void draw() {
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(position.x, position.y);


        for(int i = 0; i <=100; i++){
            float angle= 2.0f * M_PI * i / 100;
            float x = cos(angle) * r_s + position.x;
            float y = sin(angle) * r_s + position.y;
            glVertex2f(x, y);

        }
        glEnd();
    }

};


struct Engine {
    GLFWwindow* window;

    int WIDTH = 800;  // Window width
    int HEIGHT = 600; // Window height
    float width = 100000000000.0f; // Width of the viewport in meters
    float height = 75000000000.0f; // Height of the viewport in meters

    Engine() {
        if (!glfwInit()) {
            cerr << "GLFW init failed\n";
            exit(EXIT_FAILURE);
        }
        window = glfwCreateWindow(WIDTH, HEIGHT, "Black Hole", nullptr, nullptr);
        if (!window) {
            cerr << "Failed to create GLFW window\n";
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        glfwMakeContextCurrent(window);
        glViewport(0, 0, WIDTH, HEIGHT);
    }

    void run() {
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        double left = -width;
        double right = width;
        double bottom = -height;
        double top = height;
        glOrtho(left, right, bottom, top, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

};

Engine engine;


struct Ray {

};

int main(){
    while(!glfwWindowShouldClose(engine.window)){
        engine.run();


        glfwSwapBuffers(engine.window);
        glfwPollEvents();
    }

    return 0;
}