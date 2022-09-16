#include <iostream>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include<windows.h>

#include <cstdlib>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include <gl/glut.h>
#include <string.h>
#include <stdio.h>
#include <cmath>
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void DrawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);

GLfloat Xrotation = 0.0f;
GLfloat Yrotation = 0.0f;

int main(void)
{
    GLFWwindow* window;

    
    if (!glfwInit())
    {
        return -1;
    }

    
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ChessBoard", NULL, NULL);

    glfwSetKeyCallback(window, keyCallback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);


    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    
    glfwMakeContextCurrent(window);

    glViewport(0.0f, 0.0f, screenWidth, screenHeight); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1920); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 

    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;


    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

       





        glPushMatrix();
        glTranslatef(halfScreenWidth, halfScreenHeight, -500);
        glRotatef(Xrotation, 1, 0, 0);
        glRotatef(Yrotation, 0, 1, 0);
        glScalef(0.5, 0.2, 0.5);
        glTranslatef(-halfScreenWidth, -halfScreenHeight, 500);

        DrawCube(halfScreenWidth, halfScreenHeight, -500, 200);
        DrawCube(halfScreenWidth, halfScreenHeight, -300, 200);
        DrawCube(halfScreenWidth, halfScreenHeight, -100, 200);
        DrawCube(halfScreenWidth, halfScreenHeight,  100, 200);
        DrawCube(halfScreenWidth, halfScreenHeight, -700, 200);
        DrawCube(halfScreenWidth, halfScreenHeight, -900, 200);
        DrawCube(halfScreenWidth, halfScreenHeight, -1100, 200);
        DrawCube(halfScreenWidth, halfScreenHeight, -1300, 200);
        
        DrawCube(760, halfScreenHeight, -500, 200);
        DrawCube(560, halfScreenHeight, -500, 200);
        DrawCube(360, halfScreenHeight, -500, 200);
        DrawCube(1160, halfScreenHeight, -500, 200);
        DrawCube(1360, halfScreenHeight, -500, 200);
        DrawCube(1560, halfScreenHeight, -500, 200);
        DrawCube(1760, halfScreenHeight, -500, 200);

        DrawCube(760, halfScreenHeight, -700, 200);
        DrawCube(560, halfScreenHeight, -700, 200);
        DrawCube(360, halfScreenHeight, -700, 200);
        DrawCube(1160, halfScreenHeight, -700, 200);
        DrawCube(1360, halfScreenHeight, -700, 200);
        DrawCube(1560, halfScreenHeight, -700, 200);
        DrawCube(1760, halfScreenHeight, -700, 200);

        DrawCube(760, halfScreenHeight, -900, 200);
        DrawCube(560, halfScreenHeight, -900, 200);
        DrawCube(360, halfScreenHeight, -900, 200);
        DrawCube(1160, halfScreenHeight, -900, 200);
        DrawCube(1360, halfScreenHeight, -900, 200);
        DrawCube(1560, halfScreenHeight, -900, 200);
        DrawCube(1760, halfScreenHeight, -900, 200);

        DrawCube(760, halfScreenHeight, -1100, 200);
        DrawCube(560, halfScreenHeight, -1100, 200);
        DrawCube(360, halfScreenHeight, -1100, 200);
        DrawCube(1160, halfScreenHeight, -1100, 200);
        DrawCube(1360, halfScreenHeight, -1100, 200);
        DrawCube(1560, halfScreenHeight, -1100, 200);
        DrawCube(1760, halfScreenHeight, -1100, 200);

        DrawCube(760, halfScreenHeight, -1300, 200);
        DrawCube(560, halfScreenHeight, -1300, 200);
        DrawCube(360, halfScreenHeight, -1300, 200);
        DrawCube(1160, halfScreenHeight, -1300, 200);
        DrawCube(1360, halfScreenHeight, -1300, 200);
        DrawCube(1560, halfScreenHeight, -1300, 200);
        DrawCube(1760, halfScreenHeight, -1300, 200);

        DrawCube(760, halfScreenHeight, -300, 200);
        DrawCube(560, halfScreenHeight, -300, 200);
        DrawCube(360, halfScreenHeight, -300, 200);
        DrawCube(1160, halfScreenHeight, -300, 200);
        DrawCube(1360, halfScreenHeight, -300, 200);
        DrawCube(1560, halfScreenHeight, -300, 200);
        DrawCube(1760, halfScreenHeight, -300, 200);

        DrawCube(760, halfScreenHeight, -100, 200);
        DrawCube(560, halfScreenHeight, -100, 200);
        DrawCube(360, halfScreenHeight, -100, 200);
        DrawCube(1160, halfScreenHeight, -100, 200);
        DrawCube(1360, halfScreenHeight, -100, 200);
        DrawCube(1560, halfScreenHeight, -100, 200);
        DrawCube(1760, halfScreenHeight, -100, 200);

        DrawCube(760, halfScreenHeight, 100, 200);
        DrawCube(560, halfScreenHeight, 100, 200);
        DrawCube(360, halfScreenHeight, 100, 200);
        DrawCube(1160, halfScreenHeight,100, 200);
        DrawCube(1360, halfScreenHeight,100, 200);
        DrawCube(1560, halfScreenHeight,100, 200);
        DrawCube(1760, halfScreenHeight,100, 200);


        



        
       

        glPopMatrix();


        
        glfwSwapBuffers(window);

        
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}



void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    

    const GLfloat rotationSpeed = 5;

    
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
        case GLFW_KEY_UP:
            Xrotation -= rotationSpeed;
            break;
        case GLFW_KEY_DOWN:
            Xrotation += rotationSpeed;
            break;
        case GLFW_KEY_RIGHT:
            Yrotation += rotationSpeed;
            break;
        case GLFW_KEY_LEFT:
            Yrotation -= rotationSpeed;
            break;
        }


    }
}


void DrawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength)
{
    GLfloat halfSideLength = edgeLength * 0.5f;

    
    
   

    GLfloat vertices[] =
    {
        
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, 
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, 
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, 
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, 

        
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, 
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, 
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, 
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, 

       
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, 
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, 
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,

        
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, 
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, 
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, 
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, 

        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, 
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, 
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, 


        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, 
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, 
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, 
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength  


       

    };

    GLfloat colour[] =
    {
        255, 0, 0,
        0, 255, 0,
        0, 0, 255
    };

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    //glColorPointer(3, GL_FLOAT,0, colour);
    
    
    
    glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_VERTEX_ARRAY);

}